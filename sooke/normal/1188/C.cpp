#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int p = 998244353;

inline int add(int x, int y) { return x + y >= p ? x + y - p : x + y; }
inline int sub(int x, int y) { return x - y >= 0 ? x - y : x - y + p; }

const int N = 1005;

int n, m, ans, a[N], f[N][N];

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) { a[i] = read(); }
    std::sort(a + 1, a + n + 1); a[0] = -1e9;
    for (int k = (a[n] - a[1]) / (m - 1), lst = 0; k >= 0; k--) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) { f[i][j] = 0; }
        }
        f[0][0] = 1;
        for (int i = 1, u; i <= n; i++) {
            u = std::upper_bound(a, a + i + 1, a[i] - k) - a - 1; f[i][0] = f[i - 1][0];
            for (int j = 1; j <= m; j++) { f[i][j] = add(f[i - 1][j], f[u][j - 1]); }
        }
        ans = add(ans, 1ll * k * sub(f[n][m], lst) % p); lst = f[n][m];
    }
    printf("%d\n", ans);
    return 0;
}