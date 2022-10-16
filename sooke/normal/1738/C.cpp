#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 105;

int n, a[N], f[2][2][N][N];

bool solve() {
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
        x += a[i] == 0;
        y += a[i] == 1;
    }
    return f[0][0][x][y];
}

int main() {
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            if (i == 0 && j == 0) {
                f[0][0][i][j] = f[1][0][i][j] = 1;
                f[0][1][i][j] = f[1][1][i][j] = 0;
                continue;
            }
            f[0][0][i][j] = 0;
            f[0][1][i][j] = 0;
            f[1][0][i][j] = 1;
            f[1][1][i][j] = 1;
            if (i > 0) {
                f[0][0][i][j] |= f[1][0][i - 1][j];
                f[0][1][i][j] |= f[1][1][i - 1][j];
                f[1][0][i][j] &= f[0][0][i - 1][j];
                f[1][1][i][j] &= f[0][1][i - 1][j];
            }
            if (j > 0) {
                f[0][0][i][j] |= f[1][1][i][j - 1];
                f[0][1][i][j] |= f[1][0][i][j - 1];
                f[1][0][i][j] &= f[0][0][i][j - 1];
                f[1][1][i][j] &= f[0][1][i][j - 1];
            }
        }
    }
    for (int T = read(); T; T--) {
        n = read();
        for (int i = 1; i <= n; i++) {
            a[i] = read();
            a[i] = (a[i] % 2 + 2) % 2;
        }
        printf("%s\n", solve() ? "Alice" : "Bob");
    }
    return 0;
}