#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e2 + 5;

int n, k, ans, col[N], e[N][N], f[N][N];
std::vector<int> a[2];

int main() {
    n = read(); k = read();
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            e[u][v] = read();
        }
    }
    for (int i = 0; i < 233; i++) { rand(); }
    memset(f, 60, sizeof(f)); f[0][0] = 0; ans = 1e9 + 5;
    for (int _ = 0; _ < 5000; _++) {
        a[0].clear(); a[1].clear();
        for (int u = 0; u < n; u++) {
            col[u] = rand() & 1;
            a[col[u]].push_back(u);
        }
        for (int i = 1; i <= k; i++) {
            for (auto u : a[0]) {
                f[i][u] = 1e9 + 5;
                for (auto v : a[1]) {
                    f[i][u] = std::min(f[i][u], f[i - 1][v] + e[v][u]);
                }
            }
            for (auto u : a[1]) {
                f[i][u] = 1e9 + 5;
                for (auto v : a[0]) {
                    f[i][u] = std::min(f[i][u], f[i - 1][v] + e[v][u]);
                }
            }
        }
        ans = std::min(ans, f[k][0]);
    }
    printf("%d\n", ans);
    return 0;
}