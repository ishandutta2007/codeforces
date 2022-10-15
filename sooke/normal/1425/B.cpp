#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int mod = 1e9 + 7;

inline int add(int x, int y) {
    return x + y >= mod ? x + y - mod : x + y;
}
inline int sub(int x, int y) {
    return x - y >= 0 ? x - y : x - y + mod;
}

const int N = 4e3 + 5;

int n, m, num, mid, ans, anc[N], siz[N], a[N];

int find(int u) {
    return anc[u] == u ? u : anc[u] = find(anc[u]);
}

int main() {
    n = read(); m = read();
    for (int u = 1; u <= n; u++) {
        anc[u] = u;
    }
    for (int i = 0; i < m; i++) {
        int u = read(), v = read();
        if (u == 1 || v == 1 || find(u) == find(v)) { continue; }
        anc[find(u)] = find(v);
    }
    for (int u = 1; u <= n; u++) {
        siz[find(u)]++;
    }
    num = 0;
    for (int u = 2; u <= n; u++) {
        if (find(u) == u) { a[num++] = siz[u] + 1; }
    }
    std::vector<int> f[2];
    f[0].resize(m * 2 + 2); f[1].resize(m * 2 + 2);
    mid = m + 1; f[0][mid] = 1;
    for (int i = 0; i < num; i++) {
        std::vector<int> g[2];
        g[0].resize(m * 2 + 2); g[1].resize(m * 2 + 2);
        f[0].swap(g[0]); f[1].swap(g[1]);
        for (int o = 0; o < 2; o++) {
            for (int j = -m; j <= m; j++) {
                if (std::abs(j - a[i]) <= m) {
                    f[o][mid + j] = add(f[o][mid + j], g[o][mid + j - a[i]]);
                }
                f[o][mid + j] = add(f[o][mid + j], g[o][mid + j]);
                if (std::abs(j + a[i]) <= m) {
                    f[o][mid + j] = add(f[o][mid + j], g[o][mid + j + a[i]]);
                }
            }
        }
        for (int j = 1; j < g[0].size(); j++) {
            g[0][j] = add(g[0][j], g[0][j - 1]);
        }
        for (int j = -m; j <= m; j++) {
            int l = std::max(-m, j - a[i] + 2);
            int r = std::min(m, j + a[i] - 2);
            if (l > r) { continue; }
            f[1][mid + j] = add(f[1][mid + j], sub(g[0][mid + r], g[0][mid + l - 1]));
        }
    }
    ans = add(f[1][mid], f[1][mid]);
    std::vector<int> dp(m * 2 + 2);
    dp[mid] = 1;
    for (int i = 0; i < num; i++) {
        std::vector<int> g;
        g.resize(m * 2 + 2); dp.swap(g);
        for (int j = -m; j <= m; j++) {
            if (std::abs(j - a[i]) <= m) {
                dp[mid + j] = add(dp[mid + j], g[mid + j - a[i]]);
            }
            if (std::abs(j + a[i]) <= m) {
                dp[mid + j] = add(dp[mid + j], g[mid + j + a[i]]);
            }
        }
    }
    ans = add(ans, dp[mid]);
    f[0].clear(); f[1].clear();
    f[0].resize(m * 2 + 2); f[1].resize(m * 2 + 2);
    f[0][mid] = 1;
    for (int i = 0; i < num; i++) {
        std::vector<int> g[2];
        g[0].resize(m * 2 + 2); g[1].resize(m * 2 + 2);
        f[0].swap(g[0]); f[1].swap(g[1]);
        for (int o = 0; o < 2; o++) {
            for (int j = -m; j <= m; j++) {
                if (std::abs(j - a[i]) <= m) {
                    f[o][mid + j] = add(f[o][mid + j], g[o][mid + j - a[i]]);
                }
                if (std::abs(j + a[i]) <= m) {
                    f[o][mid + j] = add(f[o][mid + j], g[o][mid + j + a[i]]);
                }
            }
        }
        for (int j = -m; j <= m; j++) {
            if (std::abs(j - a[i] + 1) <= m) {
                f[1][mid + j] = add(f[1][mid + j], g[0][mid + j - a[i] + 1]);
            }
            if (std::abs(j - a[i] + 1) <= m) {
                f[1][mid + j] = add(f[1][mid + j], g[0][mid + j + a[i] - 1]);
            }
        }
    }
    ans = add(ans, add(f[1][mid], f[1][mid]));
    printf("%d\n", ans);
    return 0;
}