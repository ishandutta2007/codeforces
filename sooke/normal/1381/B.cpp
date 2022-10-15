#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 2e3 + 5;

int n, a[N * 2], p[N * 2], f[2][N][N];

int main() {
    for (int T = read(); T; T--) {
        n = read();
        for (int i = 1; i <= n * 2; i++) { a[i] = read(); }
        std::reverse(a + 1, a + n * 2 + 1);
        for (int i = 1; i <= n * 2; i++) {
            for (int j = i; j <= n * 2; j++) {
                if (a[j] > a[i]) { break; }
                p[i] = j - i + 1;
            }
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 && j == 0) {
                    f[0][0][0] = 1e9;
                    f[1][0][0] = 1e9;
                    continue;
                }
                f[0][i][j] = f[1][i][j] = 0;
                if (i > 0) {
                    f[0][i][j] = std::max(f[0][i][j], f[0][i - 1][j] - 1);
                }
                if (j > 0) {
                    f[1][i][j] = std::max(f[1][i][j], f[1][i][j - 1] - 1);
                }
                if (f[0][i][j] > 0) {
                    f[1][i][j] = std::max(f[1][i][j], p[i + j]);
                }
                if (f[1][i][j] > 0) {
                    f[0][i][j] = std::max(f[0][i][j], p[i + j]);
                }
                if (f[0][i][j] > 0) {
                    f[1][i][j] = std::max(f[1][i][j], p[i + j]);
                }
                if (f[1][i][j] > 0) {
                    f[0][i][j] = std::max(f[0][i][j], p[i + j]);
                }
            }
        }
        printf("%s\n", f[0][n][n] > 0 || f[1][n][n] > 0 ? "YES" : "NO");
    }
    return 0;
}