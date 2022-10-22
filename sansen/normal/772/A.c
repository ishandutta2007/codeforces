#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<math.h>

#define ALLOC(n, type) ((type*)calloc((n),sizeof(type)))

typedef uint32_t u32;
typedef uint64_t u64;

u32 read (void) {
    char c = getchar();
    while (!('0' <= c && c <= '9')) {
        c = getchar();
    }
    u32 x = 0;
    while ('0' <= c && c <= '9') {
        x = 10 * x + c - '0';
        c = getchar();
    }
    return x;
}

void run (void) {
    const u32 n = read();
    const u32 p = read();
    u32 *buf = ALLOC (2 * n, u32);
    for (u32 i = 0; i < n; ++i) {
        buf[i] = read();
        buf[i + n] = read();
    }
    const u32 *a = buf;
    const u32 *b = buf + n;
    u64 sum = 0;
    for (u32 i = 0; i < n; ++i) {
        sum += a[i];
    }
    if (sum <= p) {
        puts ("-1");
        return;
    }
    double ok = 0.000001;
    double ng = 10000000000;
    for (u32 iter = 0; iter < 60; ++iter) {
        double mid = sqrt(ok * ng);
        u64 sum_a = 0;
        u64 sum_b = 0;
        for (u32 i = 0; i < n; ++i) {
            if (a[i] * mid > b[i]) {
                sum_a += a[i];
                sum_b += b[i];
            }
        }
        if (sum_a * mid > p * mid + sum_b) {
            ng = mid;
        } else {
            ok = mid;
        }
    }
    double ans = sqrt(ok * ng);
    printf ("%.5f\n", ans);
}

int main (void) {
    run();
    return 0;
}