#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 2e5 + 5;

int n, m, k, ans, deg[N];
long long hsh[N], val[N], xm, sm, xum[10][10], sum[10][10];
std::vector<std::pair<int, int>> e[N];
std::mt19937_64 rng(time(0));

void dfs(int d, long long x, long long y) {
    if (d > k) {
        ans += x == xm && y == sm;
        return;
    }
    for (int i = 0; i < d; i++) {
        dfs(d + 1, x ^ xum[d][i], y + sum[d][i]);
    }
}

int main() {
    n = read(); m = read(); k = read();
    for (int i = 0; i < m; i++) {
        int u = read(), v = read(), w = read();
        e[u].push_back({w, v});
    }
    for (int u = 1; u <= n; u++) {
        hsh[u] = rng() / 4;
        val[u] = rng() % 998244353;
        xm ^= hsh[u];
        sm += val[u];
    }
    for (int u = 1; u <= n; u++) {
        std::sort(e[u].begin(), e[u].end());
        deg[u] = e[u].size();
        for (int i = 0; i < deg[u]; i++) {
            int v = e[u][i].second;
            xum[deg[u]][i] ^= hsh[v];
            sum[deg[u]][i] += val[v];
        }
    }
    dfs(1, 0, 0);
    printf("%d\n", ans);
    return 0;
}