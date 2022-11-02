#include <bits/stdc++.h>

int a[1234567];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    double l = -1e10;
    double r = 1e10;
    double ans = 0;
    for (int it = 0; it < 100; it++) {
        double m = (l + r) * .5;
        double minimal = 0;
        double maximal = 0;
        double maxS = 0;
        double minS = 0;
        for (int i = 0; i < n; i++) {
            maxS += (a[i] - m);
            minS += (a[i] - m);
            if (maxS < 0) maxS = 0;
            if (minS > 0) minS = 0;
            minimal = std::min(minimal, minS);
            maximal = std::max(maximal, maxS);
        }
        if (-minimal > maximal) r = m; else l = m;
        ans = maximal;
    }
    printf("%.17f\n", ans);
}