#include <bits/stdc++.h>

const int m = 250;

int n, a[m];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int i = 0; i < m; i++) scanf("%d", a+i);
        double var = 0.0;
        for (int i = 0; i < m; i++) {
            var += a[i] * a[i];
        }
        var /= (m-1);
        double abs = 0.0;
        for (int i = 0; i < m; i++) {
            abs += std::abs(a[i]);
        }
        abs /= m-1;
        int outside = 0;
        int k = (std::abs(*std::min_element(a, a+m)) + *std::max_element(a, a+m)) / 4;
        for (int i = 0; i < m; i++) {
            if (std::abs(a[i]) > k) {
                outside++;
            }
        }
        int min = *std::min_element(a, a+m);
        int max = *std::max_element(a, a+m);
        bool pois;
        if (min >= -2) {
            pois = (-min != max);
        } else {
            pois = outside < 90;
        }
        printf("%s\n", pois ? "poisson" : "uniform");

        //printf("mean %lf\tvar %lf\n", mean, var);
        //printf("%d %d %lf %lf %lf %d\n", *std::min_element(a, a+m), *std::max_element(a, a+m), var, abs, var/abs, outside);
        /*if (true) {
            //printf("poisson\n");
            //printf("%d\n", (int)std::round(mean));
        } else {
            //printf("uniform %d\n", *std::max_element(a, a+m));
            //printf("%d\n", *std::max_element(a, a+m) / 2);
        }*/
    }
}