#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

uint64_t rdtsc(void)
{
    uint32_t ret0[2];
    __asm__ __volatile__("rdtsc" : "=a"(ret0[0]), "=d"(ret0[1]));
    return ((uint64_t)ret0[1] << 32) | ret0[0];
}

int main(int argc, const char * argv[])
{
    uint64_t startCount = rdtsc();
    sleep(1);
    uint64_t endCount = rdtsc();

    printf("Clocks per second: %llu MHz \n", (endCount - startCount)/1000000);

    return 0;
}

