#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<math.h>

#define ALLOC(n, type) ((type*)calloc((n),sizeof(type)))

#define MIN(a, b) ((a) < (b) ? (a): (b))
#define MAX(a, b) ((a) > (b) ? (a): (b))

typedef uint32_t u32;
typedef uint64_t u64;
typedef int32_t i32;

i32 read (void) {
    int x;
    scanf ("%d", &x);
    return x;
}

double eval (const i32 *a, const u32 n, const double x) {
    double sum = 0;
    double min = 0;
    double max = 0;
    double ans = 0;
    for (u32 i = 0; i < n; ++i) {
        sum += a[i] - x;
        ans = MAX(ans, MAX(sum - min, max - sum));
        max = MAX(max, sum);
        min = MIN(min, sum);
    }
    return ans; 
}

void run (void) {
    const u32 n = (u32)read();
    i32 *buf = ALLOC (n, i32);
    for (u32 i = 0; i < n; ++i) {
        buf[i] = read();
    }
    const i32 *a = buf;
    double l = -10000;
    double r = 10000;
    for (u32 iter = 0; iter < 100; ++iter) {
        double ll = (2 * l + r) / 3;
        double rr = (l + 2 * r) / 3;
        if (eval(a, n, ll) >= eval(a, n, rr)) {
            l = ll;
        } else {
            r = rr;
        }
    }
    double ans = eval(a, n, (l + r) / 2);
    printf("%.7f\n", ans);
}

int main (void) {
    run();
    return 0;
}