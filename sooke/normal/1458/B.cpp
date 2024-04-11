#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 105; 

int n, sum, f[N][N * N];

int main() {
    n = read();
    memset(f, -60, sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        int x = read(), y = read();
        sum += y;
        for (int k = i; k >= 1; k--) {
            for (int j = y; j <= sum; j++) {
                f[k][j] = std::max(f[k][j], f[k - 1][j - y] + x);
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        double ans = 0;
        for (int j = 0; j <= sum; j++) {
            ans = std::max(ans, std::min(f[k][j] + 0.0, (j + sum) / 2.0));
        }
        printf("%.9f ", ans);
    }
    return 0;
}