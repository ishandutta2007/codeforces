#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5, L = 20;

int n, m, q, tms, dfn[N], low[N], vol, stc[N], bln[N];
int lgn, ft[L][N], dep[N], f[N], g[N];
std::vector<std::pair<int, int>> e[N];
std::vector<int> tr[N];

void tarjan(int u, int pre) {
    dfn[u] = low[u] = ++tms; stc[++vol] = u;
    int tmp = vol;
    for (auto i : e[u]) {
        int v = i.first, w = i.second;
        if (w == pre) { continue; }
        if (dfn[v] == 0) {
            tarjan(v, w);
            low[u] = std::min(low[u], low[v]);
        } else {
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        for (int i = tmp; i <= vol; i++) {
            bln[stc[i]] = u;
        }
        vol = tmp - 1;
    }
}

void dfs1(int u, int fa) { 
    ft[0][u] = fa; dep[u] = dep[fa] + 1;
    for (int i = 1; i <= lgn; i++) {
        ft[i][u] = ft[i - 1][ft[i - 1][u]];
    }
    for (auto v : tr[u]) {
        if (v == fa) { continue; }
        dfs1(v, u);
    }
}

int findLca(int u, int v) {
    if (dep[u] < dep[v]) {
        std::swap(u, v);
    }
    int d = dep[u] - dep[v];
    for (int i = lgn; i >= 0; i--) {
        if (d >> i & 1) {
            u = ft[i][u];
        }
    }
    if (u == v) { return u; }
    for (int i = lgn; i >= 0; i--) {
        if (ft[i][u] != ft[i][v]) {
            u = ft[i][u]; v = ft[i][v];
        }
    }
    return ft[0][u];
}

void dfs2(int u) {
    for (auto v : tr[u]) {
        if (v == ft[0][u]) { continue; }
        dfs2(v);
        f[u] += f[v];
        g[u] += g[v];
    }
    if (f[u] > 0 && g[u] > 0) {
        printf("NO\n"); exit(0);
    }
}

int main() {
    n = read(); m = read(); q = read();
    for (int i = 0; i < m; i++) {
        int u = read(), v = read();
        e[u].push_back({v, i}); e[v].push_back({u, i});
    }
    for (int u = 1; u <= n; u++) {
        if (dfn[u] == 0) { tarjan(u, -1); }
    }
    for (int u = 1; u <= n; u++) {
        for (auto i : e[u]) {
            int v = i.first;
            if (bln[u] == bln[v]) { continue; }
            tr[bln[u]].push_back(bln[v]);
        }
    }
    lgn = log(n) / log(2) + 1e-7;
    for (int u = 1; u <= n; u++) {
        if (bln[u] != u) { continue; }
        if (ft[0][u] == 0) { dfs1(u, 0); }
    }
    for (int i = 0; i < q; i++) {
        int u = read(), v = read();
        u = bln[u]; v = bln[v];
        int lca = findLca(u, v);
        if (lca == 0) { printf("No\n"); return 0; }
        f[u]++; f[lca]--;
        g[v]++; g[lca]--;
    }
    for (int u = 1; u <= n; u++) {
        if (ft[0][u] == 0) { dfs2(u); }
    }
    printf("Yes\n");
    return 0;
}