#include <bits/stdc++.h>

const int m = 250;

int n, a[m];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int i = 0; i < m; i++) scanf("%d", a+i);
        double mean = 0.0;
        for (int i = 0; i < m; i++) {
            mean += a[i];
        }
        mean /= m;
        double var = 0.0;
        for (int i = 0; i < m; i++) {
            var += (a[i] - mean) * (a[i] - mean);
        }
        var /= (m-1);
        //printf("mean %lf\tvar %lf\n", mean, var);
        if (var < 2 * mean) {
            printf("poisson\n");
        } else {
            printf("uniform\n");
        }
    }
}