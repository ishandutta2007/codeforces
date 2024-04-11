#include <bits/stdc++.h>

const int maxn = 105;

int T, n, a[maxn], d[maxn*maxn], D;
bool seen[1000*1000+5];

int main() {
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", a+i);
        }
        std::sort(a, a+n);

        D = 0;
        for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) {
            d[D++] = a[j] - a[i];
        }
        std::sort(d, d+D);

        std::fill(seen, seen+1000*1000+5, false);

        printf("YES\n");
        for (int i = 1; i <= 1000*1000; i++) {
            if (!seen[i]) {
                printf("%d ", i);
                for (int j = 0; j < D; j++) {
                    seen[i + d[j]] = true;
                }
                n--;
                if (n == 0) break;
            }
        }
        printf("\n");
    }
}