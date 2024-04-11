#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

int n;
double ans, now, sum, p;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &p);
        ans += (1.0 - p) * now;
        now = (now + sum * 2 + 1) * p, sum = (sum + 1) * p;
    }
    printf("%.6lf\n", ans + now);
    return 0;
}