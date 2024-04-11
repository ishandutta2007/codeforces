#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5, M = 1e3 + 5;

int n, m, ans, a[N], b[N], f[M][M];

int main() {
    n = read(); m = read();
    if (n > m) { printf("0\n"); return 0; }
    for (int i = 0; i < n; i++) {
        a[i] = read();
    }
    std::sort(a, a + n);
    ans = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            f[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        int x = a[i], y = a[i] % m;
        for (int j = 0; j < m; j++) {
            ans = ans * f[y][j] % m;
        }
        for (int j = 0; j < m; j++) {
            f[j][y] = f[j][y] * (j + m - y) % m;
        }
    }
    printf("%d\n", ans);
    return 0;
}