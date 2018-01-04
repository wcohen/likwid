/*
 * =======================================================================================
 *
 *      Filename:  perfmon_ivybridgeEP_counters.h
 *
 *      Description: Counter header file of perfmon module for Intel Ivy Bridge EP.
 *
 *      Version:   4.3.1
 *      Released:  04.01.2018
 *
 *      Author:  Jan Treibig (jt), jan.treibig@gmail.com
 *                Thomas Roehl (tr), thomas.roehl@googlemail.com
 *      Project:  likwid
 *
 *      Copyright (C) 2018 RRZE, University Erlangen-Nuremberg
 *
 *      This program is free software: you can redistribute it and/or modify it under
 *      the terms of the GNU General Public License as published by the Free Software
 *      Foundation, either version 3 of the License, or (at your option) any later
 *      version.
 *
 *      This program is distributed in the hope that it will be useful, but WITHOUT ANY
 *      WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 *      PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License along with
 *      this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * =======================================================================================
 */

#define NUM_COUNTERS_CORE_IVYBRIDGEEP 12
#define NUM_COUNTERS_UNCORE_IVYBRIDGEEP 81
#define NUM_COUNTERS_IVYBRIDGEEP 165

#define IVBEP_VALID_OPTIONS_PMC EVENT_OPTION_EDGE_MASK|EVENT_OPTION_COUNT_KERNEL_MASK|EVENT_OPTION_INVERT_MASK|\
            EVENT_OPTION_ANYTHREAD_MASK|EVENT_OPTION_THRESHOLD_MASK
#define IVBEP_VALID_OPTIONS_FIXED EVENT_OPTION_ANYTHREAD_MASK|EVENT_OPTION_COUNT_KERNEL_MASK
#define IVBEP_VALID_OPTIONS_UBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_THRESHOLD_MASK
#define IVBEP_VALID_OPTIONS_CBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_THRESHOLD_MASK|\
            EVENT_OPTION_TID_MASK|EVENT_OPTION_STATE_MASK|EVENT_OPTION_NID_MASK|\
            EVENT_OPTION_OPCODE_MASK|EVENT_OPTION_MATCH0_MASK
#define IVBEP_VALID_OPTIONS_WBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_THRESHOLD_MASK|\
            EVENT_OPTION_OCCUPANCY_MASK|EVENT_OPTION_OCCUPANCY_FILTER_MASK|EVENT_OPTION_OCCUPANCY_EDGE_MASK|\
            EVENT_OPTION_OCCUPANCY_INVERT_MASK
#define IVBEP_VALID_OPTIONS_MBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_THRESHOLD_MASK
#define IVBEP_VALID_OPTIONS_SBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_THRESHOLD_MASK|\
            EVENT_OPTION_MATCH0_MASK|EVENT_OPTION_MATCH1_MASK|EVENT_OPTION_MASK0_MASK|\
            EVENT_OPTION_MASK0_MASK
#define IVBEP_VALID_OPTIONS_BBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_THRESHOLD_MASK|\
            EVENT_OPTION_OPCODE_MASK|EVENT_OPTION_MATCH0_MASK
#define IVBEP_VALID_OPTIONS_PBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_THRESHOLD_MASK
#define IVBEP_VALID_OPTIONS_RBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_THRESHOLD_MASK
#define IVBEP_VALID_OPTIONS_IBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_THRESHOLD_MASK


static RegisterMap ivybridgeEP_counter_map[NUM_COUNTERS_IVYBRIDGEEP] = {
    /* Fixed Counters: instructions retired, cycles unhalted core */
    {"FIXC0", PMC0, FIXED, MSR_PERF_FIXED_CTR_CTRL, MSR_PERF_FIXED_CTR0, 0, 0, IVBEP_VALID_OPTIONS_FIXED},
    {"FIXC1", PMC1, FIXED, MSR_PERF_FIXED_CTR_CTRL, MSR_PERF_FIXED_CTR1, 0, 0, IVBEP_VALID_OPTIONS_FIXED},
    {"FIXC2", PMC2, FIXED, MSR_PERF_FIXED_CTR_CTRL, MSR_PERF_FIXED_CTR2, 0, 0, IVBEP_VALID_OPTIONS_FIXED},
    /* PMC Counters: 4 48bit wide */
    {"PMC0", PMC3, PMC, MSR_PERFEVTSEL0, MSR_PMC0, 0, 0, IVBEP_VALID_OPTIONS_PMC},
    {"PMC1", PMC4, PMC, MSR_PERFEVTSEL1, MSR_PMC1, 0, 0, IVBEP_VALID_OPTIONS_PMC},
    {"PMC2", PMC5, PMC, MSR_PERFEVTSEL2, MSR_PMC2, 0, 0, IVBEP_VALID_OPTIONS_PMC},
    {"PMC3", PMC6, PMC, MSR_PERFEVTSEL3, MSR_PMC3, 0, 0, IVBEP_VALID_OPTIONS_PMC},
    /* Additional PMC Counters: 4 48bit wide if HyperThreading is disabled*/
    {"PMC4", PMC7, PMC, MSR_PERFEVTSEL4, MSR_PMC4, 0, 0, IVBEP_VALID_OPTIONS_PMC},
    {"PMC5", PMC8, PMC, MSR_PERFEVTSEL5, MSR_PMC5, 0, 0, IVBEP_VALID_OPTIONS_PMC},
    {"PMC6", PMC9, PMC, MSR_PERFEVTSEL6, MSR_PMC6, 0, 0, IVBEP_VALID_OPTIONS_PMC},
    {"PMC7", PMC10, PMC, MSR_PERFEVTSEL7, MSR_PMC7, 0, 0, IVBEP_VALID_OPTIONS_PMC},
    /* Temperature Sensor*/
    {"TMP0", PMC11, THERMAL, 0, IA32_THERM_STATUS, 0, 0, EVENT_OPTION_NONE_MASK},
    /* RAPL counters */
    {"PWR0", PMC12, POWER, 0, MSR_PKG_ENERGY_STATUS, 0, 0, EVENT_OPTION_NONE_MASK},
    {"PWR1", PMC13, POWER, 0, MSR_PP0_ENERGY_STATUS, 0, 0, EVENT_OPTION_NONE_MASK},
    {"PWR2", PMC14, POWER, 0, MSR_PP1_ENERGY_STATUS, 0, 0, EVENT_OPTION_NONE_MASK},
    {"PWR3", PMC15, POWER, 0, MSR_DRAM_ENERGY_STATUS, 0, 0, EVENT_OPTION_NONE_MASK},
    /* CBOX counters, 44bits wide*/
    {"CBOX0C0", PMC16, CBOX0, MSR_UNC_C0_PMON_CTL0, MSR_UNC_C0_PMON_CTR0, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX0C1", PMC17, CBOX0, MSR_UNC_C0_PMON_CTL1, MSR_UNC_C0_PMON_CTR1, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX0C2", PMC18, CBOX0, MSR_UNC_C0_PMON_CTL2, MSR_UNC_C0_PMON_CTR2, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX0C3", PMC19, CBOX0, MSR_UNC_C0_PMON_CTL3, MSR_UNC_C0_PMON_CTR3, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX1C0", PMC20, CBOX1, MSR_UNC_C1_PMON_CTL0, MSR_UNC_C1_PMON_CTR0, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX1C1", PMC21, CBOX1, MSR_UNC_C1_PMON_CTL1, MSR_UNC_C1_PMON_CTR1, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX1C2", PMC22, CBOX1, MSR_UNC_C1_PMON_CTL2, MSR_UNC_C1_PMON_CTR2, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX1C3", PMC23, CBOX1, MSR_UNC_C1_PMON_CTL3, MSR_UNC_C1_PMON_CTR3, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX2C0", PMC24, CBOX2, MSR_UNC_C2_PMON_CTL0, MSR_UNC_C2_PMON_CTR0, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX2C1", PMC25, CBOX2, MSR_UNC_C2_PMON_CTL1, MSR_UNC_C2_PMON_CTR1, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX2C2", PMC26, CBOX2, MSR_UNC_C2_PMON_CTL2, MSR_UNC_C2_PMON_CTR2, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX2C3", PMC27, CBOX2, MSR_UNC_C2_PMON_CTL3, MSR_UNC_C2_PMON_CTR3, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX3C0", PMC28, CBOX3, MSR_UNC_C3_PMON_CTL0, MSR_UNC_C3_PMON_CTR0, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX3C1", PMC29, CBOX3, MSR_UNC_C3_PMON_CTL1, MSR_UNC_C3_PMON_CTR1, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX3C2", PMC30, CBOX3, MSR_UNC_C3_PMON_CTL2, MSR_UNC_C3_PMON_CTR2, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX3C3", PMC31, CBOX3, MSR_UNC_C3_PMON_CTL3, MSR_UNC_C3_PMON_CTR3, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX4C0", PMC32, CBOX4, MSR_UNC_C4_PMON_CTL0, MSR_UNC_C4_PMON_CTR0, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX4C1", PMC33, CBOX4, MSR_UNC_C4_PMON_CTL1, MSR_UNC_C4_PMON_CTR1, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX4C2", PMC34, CBOX4, MSR_UNC_C4_PMON_CTL2, MSR_UNC_C4_PMON_CTR2, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX4C3", PMC35, CBOX4, MSR_UNC_C4_PMON_CTL3, MSR_UNC_C4_PMON_CTR3, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX5C0", PMC36, CBOX5, MSR_UNC_C5_PMON_CTL0, MSR_UNC_C5_PMON_CTR0, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX5C1", PMC37, CBOX5, MSR_UNC_C5_PMON_CTL1, MSR_UNC_C5_PMON_CTR1, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX5C2", PMC38, CBOX5, MSR_UNC_C5_PMON_CTL2, MSR_UNC_C5_PMON_CTR2, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX5C3", PMC39, CBOX5, MSR_UNC_C5_PMON_CTL3, MSR_UNC_C5_PMON_CTR3, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX6C0", PMC40, CBOX6, MSR_UNC_C6_PMON_CTL0, MSR_UNC_C6_PMON_CTR0, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX6C1", PMC41, CBOX6, MSR_UNC_C6_PMON_CTL1, MSR_UNC_C6_PMON_CTR1, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX6C2", PMC42, CBOX6, MSR_UNC_C6_PMON_CTL2, MSR_UNC_C6_PMON_CTR2, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX6C3", PMC43, CBOX6, MSR_UNC_C6_PMON_CTL3, MSR_UNC_C6_PMON_CTR3, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX7C0", PMC44, CBOX7, MSR_UNC_C7_PMON_CTL0, MSR_UNC_C7_PMON_CTR0, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX7C1", PMC45, CBOX7, MSR_UNC_C7_PMON_CTL1, MSR_UNC_C7_PMON_CTR1, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX7C2", PMC46, CBOX7, MSR_UNC_C7_PMON_CTL2, MSR_UNC_C7_PMON_CTR2, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX7C3", PMC47, CBOX7, MSR_UNC_C7_PMON_CTL3, MSR_UNC_C7_PMON_CTR3, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX8C0", PMC48, CBOX8, MSR_UNC_C8_PMON_CTL0, MSR_UNC_C8_PMON_CTR0, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX8C1", PMC49, CBOX8, MSR_UNC_C8_PMON_CTL1, MSR_UNC_C8_PMON_CTR1, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX8C2", PMC50, CBOX8, MSR_UNC_C8_PMON_CTL2, MSR_UNC_C8_PMON_CTR2, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX8C3", PMC51, CBOX8, MSR_UNC_C8_PMON_CTL3, MSR_UNC_C8_PMON_CTR3, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX9C0", PMC52, CBOX9, MSR_UNC_C9_PMON_CTL0, MSR_UNC_C9_PMON_CTR0, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX9C1", PMC53, CBOX9, MSR_UNC_C9_PMON_CTL1, MSR_UNC_C9_PMON_CTR1, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX9C2", PMC54, CBOX9, MSR_UNC_C9_PMON_CTL2, MSR_UNC_C9_PMON_CTR2, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX9C3", PMC55, CBOX9, MSR_UNC_C9_PMON_CTL3, MSR_UNC_C9_PMON_CTR3, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX10C0", PMC56, CBOX10, MSR_UNC_C10_PMON_CTL0, MSR_UNC_C10_PMON_CTR0, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX10C1", PMC57, CBOX10, MSR_UNC_C10_PMON_CTL1, MSR_UNC_C10_PMON_CTR1, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX10C2", PMC58, CBOX10, MSR_UNC_C10_PMON_CTL2, MSR_UNC_C10_PMON_CTR2, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX10C3", PMC59, CBOX10, MSR_UNC_C10_PMON_CTL3, MSR_UNC_C10_PMON_CTR3, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX11C0", PMC60, CBOX11, MSR_UNC_C11_PMON_CTL0, MSR_UNC_C11_PMON_CTR0, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX11C1", PMC61, CBOX11, MSR_UNC_C11_PMON_CTL1, MSR_UNC_C11_PMON_CTR1, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX11C2", PMC62, CBOX11, MSR_UNC_C11_PMON_CTL2, MSR_UNC_C11_PMON_CTR2, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX11C3", PMC63, CBOX11, MSR_UNC_C11_PMON_CTL3, MSR_UNC_C11_PMON_CTR3, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX12C0", PMC64, CBOX12, MSR_UNC_C12_PMON_CTL0, MSR_UNC_C12_PMON_CTR0, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX12C1", PMC65, CBOX12, MSR_UNC_C12_PMON_CTL1, MSR_UNC_C12_PMON_CTR1, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX12C2", PMC66, CBOX12, MSR_UNC_C12_PMON_CTL2, MSR_UNC_C12_PMON_CTR2, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX12C3", PMC67, CBOX12, MSR_UNC_C12_PMON_CTL3, MSR_UNC_C12_PMON_CTR3, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX13C0", PMC68, CBOX13, MSR_UNC_C13_PMON_CTL0, MSR_UNC_C13_PMON_CTR0, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX13C1", PMC69, CBOX13, MSR_UNC_C13_PMON_CTL1, MSR_UNC_C13_PMON_CTR1, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX13C2", PMC70, CBOX13, MSR_UNC_C13_PMON_CTL2, MSR_UNC_C13_PMON_CTR2, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX13C3", PMC71, CBOX13, MSR_UNC_C13_PMON_CTL3, MSR_UNC_C13_PMON_CTR3, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX14C0", PMC72, CBOX14, MSR_UNC_C14_PMON_CTL0, MSR_UNC_C14_PMON_CTR0, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX14C1", PMC73, CBOX14, MSR_UNC_C14_PMON_CTL1, MSR_UNC_C14_PMON_CTR1, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX14C2", PMC74, CBOX14, MSR_UNC_C14_PMON_CTL2, MSR_UNC_C14_PMON_CTR2, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    {"CBOX14C3", PMC75, CBOX14, MSR_UNC_C14_PMON_CTL3, MSR_UNC_C14_PMON_CTR3, 0, 0, IVBEP_VALID_OPTIONS_CBOX},
    /* Uncore management Counters: 2 48bit wide counters */
    {"UBOX0", PMC76, UBOX, MSR_UNC_U_PMON_CTL0, MSR_UNC_U_PMON_CTR0, 0, 0, IVBEP_VALID_OPTIONS_UBOX},
    {"UBOX1", PMC77, UBOX, MSR_UNC_U_PMON_CTL1, MSR_UNC_U_PMON_CTR1, 0, 0, IVBEP_VALID_OPTIONS_UBOX},
    {"UBOXFIX", PMC78, UBOXFIX, MSR_UNC_U_UCLK_FIXED_CTL, MSR_UNC_U_UCLK_FIXED_CTR, 0, 0, 0},
    /* PCU Counters: 4 48bit wide counters */
    {"WBOX0", PMC79, WBOX, MSR_UNC_PCU_PMON_CTL0, MSR_UNC_PCU_PMON_CTR0, 0, 0, IVBEP_VALID_OPTIONS_WBOX},
    {"WBOX1", PMC80, WBOX, MSR_UNC_PCU_PMON_CTL1, MSR_UNC_PCU_PMON_CTR1, 0, 0, IVBEP_VALID_OPTIONS_WBOX},
    {"WBOX2", PMC81, WBOX, MSR_UNC_PCU_PMON_CTL2, MSR_UNC_PCU_PMON_CTR2, 0, 0, IVBEP_VALID_OPTIONS_WBOX},
    {"WBOX3", PMC82, WBOX, MSR_UNC_PCU_PMON_CTL3, MSR_UNC_PCU_PMON_CTR3, 0, 0, IVBEP_VALID_OPTIONS_WBOX},
    {"WBOX0FIX", PMC83, WBOX0FIX, 0, MSR_UNC_PCU_PMON_FIXED_CTR0, 0, 0, EVENT_OPTION_NONE_MASK},
    {"WBOX1FIX", PMC84, WBOX1FIX, 0, MSR_UNC_PCU_PMON_FIXED_CTR1, 0, 0, EVENT_OPTION_NONE_MASK},
    /* IMC Counters: 4 48bit wide per memory channel, split in two reads */
    {"MBOX0C0",PMC85, MBOX0, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_0_CH_0, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX0C1",PMC86, MBOX0, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_0_CH_0, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX0C2",PMC87, MBOX0, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_0_CH_0, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX0C3",PMC88, MBOX0, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_0_CH_0, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX0FIX",PMC89, MBOX0FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_0_CH_0, EVENT_OPTION_NONE_MASK},
    {"MBOX1C0",PMC90, MBOX1, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_0_CH_1, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX1C1",PMC91, MBOX1, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_0_CH_1, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX1C2",PMC92, MBOX1, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_0_CH_1, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX1C3",PMC93, MBOX1, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_0_CH_1, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX1FIX",PMC94, MBOX1FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_0_CH_1, EVENT_OPTION_NONE_MASK},
    {"MBOX2C0",PMC95, MBOX2, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_0_CH_2, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX2C1",PMC96, MBOX2, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_0_CH_2, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX2C2",PMC97, MBOX2, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_0_CH_2, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX2C3",PMC98, MBOX2, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_0_CH_2, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX2FIX",PMC99, MBOX2FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_0_CH_2, EVENT_OPTION_NONE_MASK},
    {"MBOX3C0",PMC100, MBOX3, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_0_CH_3, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX3C1",PMC101, MBOX3, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_0_CH_3, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX3C2",PMC102, MBOX3, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_0_CH_3, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX3C3",PMC103, MBOX3, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_0_CH_3, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX3FIX",PMC104, MBOX3FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_0_CH_3, EVENT_OPTION_NONE_MASK},
    {"MBOX4C0",PMC105, MBOX4, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_1_CH_0, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX4C1",PMC106, MBOX4, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_1_CH_0, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX4C2",PMC107, MBOX4, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_1_CH_0, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX4C3",PMC108, MBOX4, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_1_CH_0, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX4FIX",PMC109, MBOX4FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_1_CH_0, EVENT_OPTION_NONE_MASK},
    {"MBOX5C0",PMC110, MBOX5, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_1_CH_1, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX5C1",PMC111, MBOX5, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_1_CH_1, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX5C2",PMC112, MBOX5, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_1_CH_1, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX5C3",PMC113, MBOX5, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_1_CH_1, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX5FIX",PMC114, MBOX5FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_1_CH_1, EVENT_OPTION_NONE_MASK},
    {"MBOX6C0",PMC115, MBOX6, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_1_CH_2, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX6C1",PMC116, MBOX6, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_1_CH_2, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX6C2",PMC117, MBOX6, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_1_CH_2, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX6C3",PMC118, MBOX6, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_1_CH_2, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX6FIX",PMC119, MBOX6FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_1_CH_2, EVENT_OPTION_NONE_MASK},
    {"MBOX7C0",PMC120, MBOX7, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_1_CH_3, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX7C1",PMC121, MBOX7, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_1_CH_3, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX7C2",PMC122, MBOX7, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_1_CH_3, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX7C3",PMC123, MBOX7, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_1_CH_3, IVBEP_VALID_OPTIONS_MBOX},
    {"MBOX7FIX",PMC124, MBOX7FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_1_CH_3, EVENT_OPTION_NONE_MASK},
    /* QPI counters four 48bit wide per port, split in two reads */
    {"SBOX0C0",PMC125, SBOX0, PCI_UNC_QPI_PMON_CTL_0, PCI_UNC_QPI_PMON_CTR_0_A, PCI_UNC_QPI_PMON_CTR_0_B, PCI_QPI_DEVICE_PORT_0, IVBEP_VALID_OPTIONS_SBOX},
    {"SBOX0C1",PMC126, SBOX0, PCI_UNC_QPI_PMON_CTL_1, PCI_UNC_QPI_PMON_CTR_1_A, PCI_UNC_QPI_PMON_CTR_1_B, PCI_QPI_DEVICE_PORT_0, IVBEP_VALID_OPTIONS_SBOX},
    {"SBOX0C2",PMC127, SBOX0, PCI_UNC_QPI_PMON_CTL_2, PCI_UNC_QPI_PMON_CTR_2_A, PCI_UNC_QPI_PMON_CTR_2_B, PCI_QPI_DEVICE_PORT_0, IVBEP_VALID_OPTIONS_SBOX},
    {"SBOX0C3",PMC128, SBOX0, PCI_UNC_QPI_PMON_CTL_3, PCI_UNC_QPI_PMON_CTR_3_A, PCI_UNC_QPI_PMON_CTR_3_B, PCI_QPI_DEVICE_PORT_0, IVBEP_VALID_OPTIONS_SBOX},
    {"SBOX1C0",PMC129, SBOX1, PCI_UNC_QPI_PMON_CTL_0, PCI_UNC_QPI_PMON_CTR_0_A, PCI_UNC_QPI_PMON_CTR_0_B, PCI_QPI_DEVICE_PORT_1, IVBEP_VALID_OPTIONS_SBOX},
    {"SBOX1C1",PMC130, SBOX1, PCI_UNC_QPI_PMON_CTL_1, PCI_UNC_QPI_PMON_CTR_1_A, PCI_UNC_QPI_PMON_CTR_1_B, PCI_QPI_DEVICE_PORT_1, IVBEP_VALID_OPTIONS_SBOX},
    {"SBOX1C2",PMC131, SBOX1, PCI_UNC_QPI_PMON_CTL_2, PCI_UNC_QPI_PMON_CTR_2_A, PCI_UNC_QPI_PMON_CTR_2_B, PCI_QPI_DEVICE_PORT_1, IVBEP_VALID_OPTIONS_SBOX},
    {"SBOX1C3",PMC132, SBOX1, PCI_UNC_QPI_PMON_CTL_3, PCI_UNC_QPI_PMON_CTR_3_A, PCI_UNC_QPI_PMON_CTR_3_B, PCI_QPI_DEVICE_PORT_1, IVBEP_VALID_OPTIONS_SBOX},
    {"SBOX2C0",PMC133, SBOX2, PCI_UNC_QPI_PMON_CTL_0, PCI_UNC_QPI_PMON_CTR_0_A, PCI_UNC_QPI_PMON_CTR_0_B, PCI_QPI_DEVICE_PORT_2, IVBEP_VALID_OPTIONS_SBOX},
    {"SBOX2C1",PMC134, SBOX2, PCI_UNC_QPI_PMON_CTL_1, PCI_UNC_QPI_PMON_CTR_1_A, PCI_UNC_QPI_PMON_CTR_1_B, PCI_QPI_DEVICE_PORT_2, IVBEP_VALID_OPTIONS_SBOX},
    {"SBOX2C2",PMC135, SBOX2, PCI_UNC_QPI_PMON_CTL_2, PCI_UNC_QPI_PMON_CTR_2_A, PCI_UNC_QPI_PMON_CTR_2_B, PCI_QPI_DEVICE_PORT_2, IVBEP_VALID_OPTIONS_SBOX},
    {"SBOX2C3",PMC136, SBOX2, PCI_UNC_QPI_PMON_CTL_3, PCI_UNC_QPI_PMON_CTR_3_A, PCI_UNC_QPI_PMON_CTR_3_B, PCI_QPI_DEVICE_PORT_2, IVBEP_VALID_OPTIONS_SBOX},
    {"SBOX0FIX",PMC137, SBOX0FIX, 0, PCI_UNC_QPI_RATE_STATUS, 0, PCI_QPI_MISC_DEVICE_PORT_0, EVENT_OPTION_NONE_MASK},
    {"SBOX1FIX",PMC138, SBOX1FIX, 0, PCI_UNC_QPI_RATE_STATUS, 0, PCI_QPI_MISC_DEVICE_PORT_0, EVENT_OPTION_NONE_MASK},
    {"SBOX2FIX",PMC139, SBOX2FIX, 0, PCI_UNC_QPI_RATE_STATUS, 0, PCI_QPI_MISC_DEVICE_PORT_2, EVENT_OPTION_NONE_MASK},
    /* HA counters four 48bit wide per counter, split in two reads */
    {"BBOX0C0", PMC140, BBOX0, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_HA_PMON_CTR_0_A, PCI_UNC_HA_PMON_CTR_0_B, PCI_HA_DEVICE_0, IVBEP_VALID_OPTIONS_BBOX},
    {"BBOX0C1", PMC141, BBOX0, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_HA_PMON_CTR_1_A, PCI_UNC_HA_PMON_CTR_1_B, PCI_HA_DEVICE_0, IVBEP_VALID_OPTIONS_BBOX},
    {"BBOX0C2", PMC142, BBOX0, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_HA_PMON_CTR_2_A, PCI_UNC_HA_PMON_CTR_2_B, PCI_HA_DEVICE_0, IVBEP_VALID_OPTIONS_BBOX},
    {"BBOX0C3", PMC143, BBOX0, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_HA_PMON_CTR_3_A, PCI_UNC_HA_PMON_CTR_3_B, PCI_HA_DEVICE_0, IVBEP_VALID_OPTIONS_BBOX},
    {"BBOX1C0", PMC144, BBOX1, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_HA_PMON_CTR_0_A, PCI_UNC_HA_PMON_CTR_0_B, PCI_HA_DEVICE_1, IVBEP_VALID_OPTIONS_BBOX},
    {"BBOX1C1", PMC145, BBOX1, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_HA_PMON_CTR_1_A, PCI_UNC_HA_PMON_CTR_1_B, PCI_HA_DEVICE_1, IVBEP_VALID_OPTIONS_BBOX},
    {"BBOX1C2", PMC146, BBOX1, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_HA_PMON_CTR_2_A, PCI_UNC_HA_PMON_CTR_2_B, PCI_HA_DEVICE_1, IVBEP_VALID_OPTIONS_BBOX},
    {"BBOX1C3", PMC147, BBOX1, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_HA_PMON_CTR_3_A, PCI_UNC_HA_PMON_CTR_3_B, PCI_HA_DEVICE_1, IVBEP_VALID_OPTIONS_BBOX},
    /* R2PCIe counters four 44bit wide per counter, split in two reads */
    {"PBOX0", PMC148, PBOX, PCI_UNC_R2PCIE_PMON_CTL_0, PCI_UNC_R2PCIE_PMON_CTR_0_A, PCI_UNC_R2PCIE_PMON_CTR_0_B, PCI_R2PCIE_DEVICE, IVBEP_VALID_OPTIONS_PBOX},
    {"PBOX1", PMC149, PBOX, PCI_UNC_R2PCIE_PMON_CTL_1, PCI_UNC_R2PCIE_PMON_CTR_1_A, PCI_UNC_R2PCIE_PMON_CTR_1_B, PCI_R2PCIE_DEVICE, IVBEP_VALID_OPTIONS_PBOX},
    {"PBOX2", PMC150, PBOX, PCI_UNC_R2PCIE_PMON_CTL_2, PCI_UNC_R2PCIE_PMON_CTR_2_A, PCI_UNC_R2PCIE_PMON_CTR_2_B, PCI_R2PCIE_DEVICE, IVBEP_VALID_OPTIONS_PBOX},
    {"PBOX3", PMC151, PBOX, PCI_UNC_R2PCIE_PMON_CTL_3, PCI_UNC_R2PCIE_PMON_CTR_3_A, PCI_UNC_R2PCIE_PMON_CTR_3_B, PCI_R2PCIE_DEVICE, IVBEP_VALID_OPTIONS_PBOX},
    /* R3QPI counters four 44bit wide per counter, split in two reads */
    {"RBOX0C0", PMC152, RBOX0, PCI_UNC_R3QPI_PMON_CTL_0, PCI_UNC_R3QPI_PMON_CTR_0_A, PCI_UNC_R3QPI_PMON_CTR_0_B, PCI_R3QPI_DEVICE_LINK_0, IVBEP_VALID_OPTIONS_RBOX},
    {"RBOX0C1", PMC153, RBOX0, PCI_UNC_R3QPI_PMON_CTL_1, PCI_UNC_R3QPI_PMON_CTR_1_A, PCI_UNC_R3QPI_PMON_CTR_1_B, PCI_R3QPI_DEVICE_LINK_0, IVBEP_VALID_OPTIONS_RBOX},
    {"RBOX0C2", PMC154, RBOX0, PCI_UNC_R3QPI_PMON_CTL_2, PCI_UNC_R3QPI_PMON_CTR_2_A, PCI_UNC_R3QPI_PMON_CTR_2_B, PCI_R3QPI_DEVICE_LINK_0, IVBEP_VALID_OPTIONS_RBOX},
    {"RBOX1C0", PMC155, RBOX1, PCI_UNC_R3QPI_PMON_CTL_0, PCI_UNC_R3QPI_PMON_CTR_0_A, PCI_UNC_R3QPI_PMON_CTR_0_B, PCI_R3QPI_DEVICE_LINK_1, IVBEP_VALID_OPTIONS_RBOX},
    {"RBOX1C1", PMC156, RBOX1, PCI_UNC_R3QPI_PMON_CTL_1, PCI_UNC_R3QPI_PMON_CTR_1_A, PCI_UNC_R3QPI_PMON_CTR_1_B, PCI_R3QPI_DEVICE_LINK_1, IVBEP_VALID_OPTIONS_RBOX},
    {"RBOX1C2", PMC157, RBOX1, PCI_UNC_R3QPI_PMON_CTL_2, PCI_UNC_R3QPI_PMON_CTR_2_A, PCI_UNC_R3QPI_PMON_CTR_2_B, PCI_R3QPI_DEVICE_LINK_1, IVBEP_VALID_OPTIONS_RBOX},
    {"RBOX2C0", PMC158, RBOX2, PCI_UNC_R3QPI_PMON_CTL_0, PCI_UNC_R3QPI_PMON_CTR_0_A, PCI_UNC_R3QPI_PMON_CTR_0_B, PCI_R3QPI_DEVICE_LINK_2, IVBEP_VALID_OPTIONS_RBOX},
    {"RBOX2C1", PMC159, RBOX2, PCI_UNC_R3QPI_PMON_CTL_1, PCI_UNC_R3QPI_PMON_CTR_1_A, PCI_UNC_R3QPI_PMON_CTR_1_B, PCI_R3QPI_DEVICE_LINK_2, IVBEP_VALID_OPTIONS_RBOX},
    {"RBOX2C2", PMC160, RBOX2, PCI_UNC_R3QPI_PMON_CTL_2, PCI_UNC_R3QPI_PMON_CTR_2_A, PCI_UNC_R3QPI_PMON_CTR_2_B, PCI_R3QPI_DEVICE_LINK_2, IVBEP_VALID_OPTIONS_RBOX},
    /* IRP counters four 44bit wide per counter */
    {"IBOX0C0", PMC161, IBOX0, PCI_UNC_IRP0_PMON_CTL_0, PCI_UNC_IRP0_PMON_CTR_0, 0, PCI_IRP_DEVICE, IVBEP_VALID_OPTIONS_IBOX},
    {"IBOX0C1", PMC162, IBOX0, PCI_UNC_IRP0_PMON_CTL_1, PCI_UNC_IRP0_PMON_CTR_1, 0, PCI_IRP_DEVICE, IVBEP_VALID_OPTIONS_IBOX},
    {"IBOX1C0", PMC163, IBOX1, PCI_UNC_IRP1_PMON_CTL_0, PCI_UNC_IRP1_PMON_CTR_0, 0, PCI_IRP_DEVICE, IVBEP_VALID_OPTIONS_IBOX},
    {"IBOX1C1", PMC164, IBOX1, PCI_UNC_IRP1_PMON_CTL_1, PCI_UNC_IRP1_PMON_CTR_1, 0, PCI_IRP_DEVICE, IVBEP_VALID_OPTIONS_IBOX},
};

static BoxMap ivybridgeEP_box_map[NUM_UNITS] = {
    [PMC] = {MSR_PERF_GLOBAL_CTRL, MSR_PERF_GLOBAL_STATUS, MSR_PERF_GLOBAL_OVF_CTRL, -1, 0, 0, 48},
    [FIXED] = {MSR_PERF_GLOBAL_CTRL, MSR_PERF_GLOBAL_STATUS, MSR_PERF_GLOBAL_OVF_CTRL, -1, 0, 0, 48},
    [THERMAL] = {0, 0, 0, 0, 0, MSR_DEV, 8},
    [POWER] = {0, 0, 0, 0, 0, MSR_DEV, 32},
    [MBOX0] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 20, 1, PCI_IMC_DEVICE_0_CH_0, 48},
    [MBOX0FIX] = {PCI_UNC_MC_PMON_BOX_CTL, 0, 0, 20, 1, PCI_IMC_DEVICE_0_CH_0, 48},
    [MBOX1] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 20, 1, PCI_IMC_DEVICE_0_CH_1, 48},
    [MBOX1FIX] = {PCI_UNC_MC_PMON_BOX_CTL, 0, 0, 20, 1, PCI_IMC_DEVICE_0_CH_1, 48},
    [MBOX2] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 20, 1, PCI_IMC_DEVICE_0_CH_2, 48},
    [MBOX2FIX] = {PCI_UNC_MC_PMON_BOX_CTL, 0, 0, 20, 1, PCI_IMC_DEVICE_0_CH_2, 48},
    [MBOX3] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 20, 1, PCI_IMC_DEVICE_0_CH_3, 48},
    [MBOX3FIX] = {PCI_UNC_MC_PMON_BOX_CTL, 0, 0, 20, 1, PCI_IMC_DEVICE_0_CH_3, 48},
    [MBOX4] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 21, 1, PCI_IMC_DEVICE_1_CH_0, 48},
    [MBOX4FIX] = {PCI_UNC_MC_PMON_BOX_CTL, 0, 0, 21, 1, PCI_IMC_DEVICE_1_CH_0, 48},
    [MBOX5] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 21, 1, PCI_IMC_DEVICE_1_CH_1, 48},
    [MBOX5FIX] = {PCI_UNC_MC_PMON_BOX_CTL, 0, 0, 21, 1, PCI_IMC_DEVICE_1_CH_1, 48},
    [MBOX6] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 21, 1, PCI_IMC_DEVICE_1_CH_2, 48},
    [MBOX6FIX] = {PCI_UNC_MC_PMON_BOX_CTL, 0, 0, 21, 1, PCI_IMC_DEVICE_1_CH_2, 48},
    [MBOX7] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 21, 1, PCI_IMC_DEVICE_1_CH_3, 48},
    [MBOX7FIX] = {PCI_UNC_MC_PMON_BOX_CTL, 0, 0, 21, 1, PCI_IMC_DEVICE_1_CH_3, 48},
    [CBOX0] = {MSR_UNC_C0_PMON_BOX_CTL, 0, 0, 3, 0, 0, 44, MSR_UNC_C0_PMON_BOX_FILTER, MSR_UNC_C0_PMON_BOX_FILTER1},
    [CBOX1] = {MSR_UNC_C1_PMON_BOX_CTL, 0, 0, 4, 0, 0, 44, MSR_UNC_C1_PMON_BOX_FILTER, MSR_UNC_C1_PMON_BOX_FILTER1},
    [CBOX2] = {MSR_UNC_C2_PMON_BOX_CTL, 0, 0, 5, 0, 0, 44, MSR_UNC_C2_PMON_BOX_FILTER, MSR_UNC_C2_PMON_BOX_FILTER1},
    [CBOX3] = {MSR_UNC_C3_PMON_BOX_CTL, 0, 0, 6, 0, 0, 44, MSR_UNC_C3_PMON_BOX_FILTER, MSR_UNC_C3_PMON_BOX_FILTER1},
    [CBOX4] = {MSR_UNC_C4_PMON_BOX_CTL, 0, 0, 7, 0, 0, 44, MSR_UNC_C4_PMON_BOX_FILTER, MSR_UNC_C4_PMON_BOX_FILTER1},
    [CBOX5] = {MSR_UNC_C5_PMON_BOX_CTL, 0, 0, 8, 0, 0, 44, MSR_UNC_C5_PMON_BOX_FILTER, MSR_UNC_C5_PMON_BOX_FILTER1},
    [CBOX6] = {MSR_UNC_C6_PMON_BOX_CTL, 0, 0, 9, 0, 0, 44, MSR_UNC_C6_PMON_BOX_FILTER, MSR_UNC_C6_PMON_BOX_FILTER1},
    [CBOX7] = {MSR_UNC_C7_PMON_BOX_CTL, 0, 0, 10, 0, 0, 44, MSR_UNC_C7_PMON_BOX_FILTER, MSR_UNC_C7_PMON_BOX_FILTER1},
    [CBOX8] = {MSR_UNC_C8_PMON_BOX_CTL, 0, 0, 11, 0, 0, 44, MSR_UNC_C8_PMON_BOX_FILTER, MSR_UNC_C8_PMON_BOX_FILTER1},
    [CBOX9] = {MSR_UNC_C9_PMON_BOX_CTL, 0, 0, 12, 0, 0, 44, MSR_UNC_C9_PMON_BOX_FILTER, MSR_UNC_C9_PMON_BOX_FILTER1},
    [CBOX10] = {MSR_UNC_C10_PMON_BOX_CTL, 0, 0, 13, 0, 0, 44, MSR_UNC_C10_PMON_BOX_FILTER, MSR_UNC_C10_PMON_BOX_FILTER1},
    [CBOX11] = {MSR_UNC_C11_PMON_BOX_CTL, 0, 0, 14, 0, 0, 44, MSR_UNC_C11_PMON_BOX_FILTER, MSR_UNC_C11_PMON_BOX_FILTER1},
    [CBOX12] = {MSR_UNC_C12_PMON_BOX_CTL, 0, 0, 15, 0, 0, 44, MSR_UNC_C12_PMON_BOX_FILTER, MSR_UNC_C12_PMON_BOX_FILTER1},
    [CBOX13] = {MSR_UNC_C13_PMON_BOX_CTL, 0, 0, 16, 0, 0, 44, MSR_UNC_C13_PMON_BOX_FILTER, MSR_UNC_C13_PMON_BOX_FILTER1},
    [CBOX14] = {MSR_UNC_C14_PMON_BOX_CTL, 0, 0, 17, 0, 0, 44, MSR_UNC_C14_PMON_BOX_FILTER, MSR_UNC_C14_PMON_BOX_FILTER1},
    [BBOX0] = {PCI_UNC_HA_PMON_BOX_CTL, PCI_UNC_HA_PMON_BOX_STATUS, PCI_UNC_HA_PMON_BOX_STATUS, 18, 1, PCI_HA_DEVICE_0, 48},
    [BBOX1] = {PCI_UNC_HA_PMON_BOX_CTL, PCI_UNC_HA_PMON_BOX_STATUS, PCI_UNC_HA_PMON_BOX_STATUS, 19, 1, PCI_HA_DEVICE_1, 48},
    [SBOX0] = {PCI_UNC_QPI_PMON_BOX_CTL, PCI_UNC_QPI_PMON_BOX_STATUS, PCI_UNC_QPI_PMON_BOX_STATUS, 22, 1, PCI_QPI_DEVICE_PORT_0, 48},
    [SBOX1] = {PCI_UNC_QPI_PMON_BOX_CTL, PCI_UNC_QPI_PMON_BOX_STATUS, PCI_UNC_QPI_PMON_BOX_STATUS, 23, 1, PCI_QPI_DEVICE_PORT_1, 48},
    [SBOX2] = {PCI_UNC_QPI_PMON_BOX_CTL, PCI_UNC_QPI_PMON_BOX_STATUS, PCI_UNC_QPI_PMON_BOX_STATUS, -1, 1, PCI_QPI_DEVICE_PORT_2, 48},
    [SBOX0FIX] = {0, 0, 0, 0, 1, PCI_QPI_MISC_DEVICE_PORT_0, 64},
    [SBOX1FIX] = {0, 0, 0, 0, 1, PCI_QPI_MISC_DEVICE_PORT_0, 64},
    [SBOX2FIX] = {0, 0, 0, 0, 1, PCI_QPI_MISC_DEVICE_PORT_2, 64},
    [WBOX] = {MSR_UNC_PCU_PMON_BOX_CTL, MSR_UNC_PCU_PMON_BOX_STATUS, MSR_UNC_PCU_PMON_BOX_STATUS, 2, 0, 0, 48,  MSR_UNC_PCU_PMON_BOX_FILTER},
    [WBOX0FIX] = {0, 0, 0, 0, 0, 0, 64},
    [WBOX1FIX] = {0, 0, 0, 0, 0, 0, 64},
    [UBOX] = {0, MSR_UNC_U_PMON_BOX_STATUS, MSR_UNC_U_PMON_BOX_STATUS, 1, 0, 0, 44},
    [UBOXFIX] = {0, MSR_UNC_U_PMON_BOX_STATUS, MSR_UNC_U_PMON_BOX_STATUS, 0, 0, 0, 44},
    [PBOX] = {PCI_UNC_R2PCIE_PMON_BOX_CTL, PCI_UNC_R2PCIE_PMON_BOX_STATUS, PCI_UNC_R2PCIE_PMON_BOX_STATUS, 26, 1,PCI_R2PCIE_DEVICE, 44},
    [RBOX0] = {PCI_UNC_R3QPI_PMON_BOX_CTL, PCI_UNC_R3QPI_PMON_BOX_STATUS, PCI_UNC_R3QPI_PMON_BOX_STATUS, 24, 1,PCI_R3QPI_DEVICE_LINK_0, 44},
    [RBOX1] = {PCI_UNC_R3QPI_PMON_BOX_CTL, PCI_UNC_R3QPI_PMON_BOX_STATUS, PCI_UNC_R3QPI_PMON_BOX_STATUS, 25, 1,PCI_R3QPI_DEVICE_LINK_1, 44},
    [RBOX2] = {PCI_UNC_R3QPI_PMON_BOX_CTL, PCI_UNC_R3QPI_PMON_BOX_STATUS, PCI_UNC_R3QPI_PMON_BOX_STATUS, -1, 1,PCI_R3QPI_DEVICE_LINK_2, 44},
    [IBOX0] = {PCI_UNC_IRP_PMON_BOX_CTL, PCI_UNC_IRP_PMON_BOX_STATUS, PCI_UNC_IRP_PMON_BOX_STATUS, -1, 1, PCI_IRP_DEVICE, 44},
    [IBOX1] = {PCI_UNC_IRP_PMON_BOX_CTL, PCI_UNC_IRP_PMON_BOX_STATUS, PCI_UNC_IRP_PMON_BOX_STATUS, -1, 1, PCI_IRP_DEVICE, 44},
};

static PciDevice ivybridgeEP_pci_devices[MAX_NUM_PCI_DEVICES] = {
 [MSR_DEV] = {NODEVTYPE, "", "", ""},
 [PCI_R3QPI_DEVICE_LINK_0] = {R3QPI, "13.5", "PCI_R3QPI_DEVICE_LINK_0", "RBOX0", 0x0e36},
 [PCI_R3QPI_DEVICE_LINK_1] = {R3QPI, "13.6", "PCI_R3QPI_DEVICE_LINK_1", "RBOX1", 0x0e37},
 [PCI_R3QPI_DEVICE_LINK_2] = {R3QPI, "12.5", "PCI_R3QPI_DEVICE_LINK_2", "RBOX2", 0x0e3e},
 [PCI_R2PCIE_DEVICE] = {R2PCIE, "13.1", "PCI_R2PCIE_DEVICE", "PBOX0", 0x0e34},
 [PCI_IMC_DEVICE_0_CH_0] = {IMC, "10.4", "PCI_IMC_DEVICE_0_CH_0", "MBOX0", 0x0eb4},
 [PCI_IMC_DEVICE_0_CH_1] = {IMC, "10.5", "PCI_IMC_DEVICE_0_CH_1", "MBOX1", 0x0eb5},
 [PCI_IMC_DEVICE_0_CH_2] = {IMC, "10.0", "PCI_IMC_DEVICE_0_CH_2", "MBOX2", 0x0eb0},
 [PCI_IMC_DEVICE_0_CH_3] = {IMC, "10.1", "PCI_IMC_DEVICE_0_CH_3", "MBOX3", 0x0eb1},
 [PCI_HA_DEVICE_0] = {HA, "0e.1", "PCI_HA_DEVICE_0", "BBOX0", 0x0e30},
 [PCI_HA_DEVICE_1] = {HA, "1c.1", "PCI_HA_DEVICE_1", "BBOX1", 0x0e38},
 [PCI_IMC_DEVICE_1_CH_0] = {IMC, "1e.4", "PCI_IMC_DEVICE_1_CH_0", "MBOX4", 0x0ef4},
 [PCI_IMC_DEVICE_1_CH_1] = {IMC, "1e.5", "PCI_IMC_DEVICE_1_CH_1", "MBOX5", 0x0ef5},
 [PCI_IMC_DEVICE_1_CH_2] = {IMC, "1e.0", "PCI_IMC_DEVICE_1_CH_2", "MBOX6", 0x0ef0},
 [PCI_IMC_DEVICE_1_CH_3] = {IMC, "1e.1", "PCI_IMC_DEVICE_1_CH_3", "MBOX7", 0x0ef1},
 [PCI_IRP_DEVICE] = {IRP, "05.6", "PCI_IRP_DEVICE", NULL, 0x0e39},
 [PCI_QPI_DEVICE_PORT_0] = {QPI, "08.2", "PCI_QPI_DEVICE_PORT_0", "SBOX0", 0x0e32},
 [PCI_QPI_DEVICE_PORT_1] = {QPI, "09.2", "PCI_QPI_DEVICE_PORT_1", "SBOX1", 0x0e33},
 [PCI_QPI_DEVICE_PORT_2] = {QPI, "0a.2", "PCI_QPI_DEVICE_PORT_2", "SBOX2", 0x0ec2},
 [PCI_QPI_MASK_DEVICE_PORT_0] = {QPI, "08.6", "PCI_QPI_MASK_DEVICE_PORT_0", NULL, 0x0e86},
 [PCI_QPI_MASK_DEVICE_PORT_1] = {QPI, "09.6", "PCI_QPI_MASK_DEVICE_PORT_1", NULL, 0x0e96},
 [PCI_QPI_MASK_DEVICE_PORT_2] = {QPI, "0a.6", "PCI_QPI_MASK_DEVICE_PORT_2", NULL, 0x0ec6},
 [PCI_QPI_MISC_DEVICE_PORT_0] = {QPI, "08.0", "PCI_QPI_MISC_DEVICE_PORT_0/1", "SBOX01FIX",0x0e80},
 [PCI_QPI_MISC_DEVICE_PORT_2] = {QPI, "0a.0", "PCI_QPI_MISC_DEVICE_PORT_2", "SBOX2FIX", 0x0ec0},
};


static char* ivybridgeEP_translate_types[NUM_UNITS] = {
    [FIXED] = "/sys/bus/event_source/devices/cpu",
    [PMC] = "/sys/bus/event_source/devices/cpu",
    [POWER] = "/sys/bus/event_source/devices/power",
    [MBOX0] = "/sys/bus/event_source/devices/uncore_imc_0",
    [MBOX1] = "/sys/bus/event_source/devices/uncore_imc_1",
    [MBOX2] = "/sys/bus/event_source/devices/uncore_imc_2",
    [MBOX3] = "/sys/bus/event_source/devices/uncore_imc_3",
    [MBOX4] = "/sys/bus/event_source/devices/uncore_imc_4",
    [MBOX5] = "/sys/bus/event_source/devices/uncore_imc_5",
    [MBOX6] = "/sys/bus/event_source/devices/uncore_imc_6",
    [MBOX7] = "/sys/bus/event_source/devices/uncore_imc_7",
    [CBOX0] = "/sys/bus/event_source/devices/uncore_cbox_0",
    [CBOX1] = "/sys/bus/event_source/devices/uncore_cbox_1",
    [CBOX2] = "/sys/bus/event_source/devices/uncore_cbox_2",
    [CBOX3] = "/sys/bus/event_source/devices/uncore_cbox_3",
    [CBOX4] = "/sys/bus/event_source/devices/uncore_cbox_4",
    [CBOX5] = "/sys/bus/event_source/devices/uncore_cbox_5",
    [CBOX6] = "/sys/bus/event_source/devices/uncore_cbox_6",
    [CBOX7] = "/sys/bus/event_source/devices/uncore_cbox_7",
    [CBOX8] = "/sys/bus/event_source/devices/uncore_cbox_8",
    [CBOX9] = "/sys/bus/event_source/devices/uncore_cbox_9",
    [CBOX10] = "/sys/bus/event_source/devices/uncore_cbox_10",
    [CBOX11] = "/sys/bus/event_source/devices/uncore_cbox_11",
    [CBOX12] = "/sys/bus/event_source/devices/uncore_cbox_12",
    [CBOX13] = "/sys/bus/event_source/devices/uncore_cbox_13",
    [CBOX14] = "/sys/bus/event_source/devices/uncore_cbox_14",
    [BBOX0] = "/sys/bus/event_source/devices/uncore_ha_0",
    [BBOX1] = "/sys/bus/event_source/devices/uncore_ha_1",
    [WBOX] = "/sys/bus/event_source/devices/uncore_pcu",
    [SBOX0] = "/sys/bus/event_source/devices/uncore_qpi_0",
    [SBOX1] = "/sys/bus/event_source/devices/uncore_qpi_1",
    [SBOX2] = "/sys/bus/event_source/devices/uncore_qpi_2",
    [PBOX] = "/sys/bus/event_source/devices/uncore_r2pcie",
    [RBOX0] = "/sys/bus/event_source/devices/uncore_r3qpi_0",
    [RBOX1] = "/sys/bus/event_source/devices/uncore_r3qpi_1",
    [UBOX] = "/sys/bus/event_source/devices/uncore_ubox",
    [IBOX0] = "/sys/bus/event_source/devices/uncore_irp",
};
