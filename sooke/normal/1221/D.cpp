#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 3e5 + 5;

int n, a[N], b[N];
long long f[4][N];

int main() {
    for (int T = read(); T; T--) {
        n = read(); a[0] = -1e9;
        for (int i = 1; i <= n; i++) {
            a[i] = read(); b[i] = read();
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 3; j++) {
                f[j][i] = 1e18;
                for (int k = 0; k <= 3; k++) {
                    if (a[i - 1] + k != a[i] + j) {
                        f[j][i] = std::min(f[j][i], f[k][i - 1] + 1ll * j * b[i]);
                    }
                }
            }
        }
        printf("%I64d\n", std::min(std::min(f[0][n], f[1][n]), std::min(f[2][n], f[3][n])));
    }
    return 0;
} //