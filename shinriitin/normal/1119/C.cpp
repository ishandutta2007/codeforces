#include <bits/stdc++.h>

const int max_N = 521;

int n, m, a[max_N][max_N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int x;
            scanf("%d", &x);
            a[i][j] ^= x;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int x;
            scanf("%d", &x);
            a[i][j] ^= x;
        }
    }
    for (int i = 1; i <= n; ++i) {
        int s = 0;
        for (int j = 1; j <= m; ++j) {
            s ^= a[i][j];
        }
        if (s) return puts("No"), 0;
    }
    for (int i = 1; i <= m; ++i) {
        int s = 0;
        for (int j = 1; j <= n; ++j) {
            s ^= a[j][i];
        }
        if (s) return puts("No"), 0;
    }
    puts("Yes");
}