#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, m, ft[N], deg[N];
bool vis[N], used[N], rev[N];
std::vector<std::pair<int, int>> edg, e[N];

void dfs(int u) {
    vis[u] = true;
    for (auto i : e[u]) {
        int v = i.first, w = i.second;
        if (vis[v]) { continue; }
        used[w] = true;
        if (u == edg[w].second) {
            std::swap(edg[w].first, edg[w].second);
        }
        ft[v] = u;
        dfs(v);
    }
}

void solve(int u) {
    rev[u] = deg[u] & 1;
    for (auto i : e[u]) {
        int v = i.first, w = i.second;
        if (!used[w] || v == ft[u]) { continue; }
        solve(v);
        if (rev[v]) {
            std::swap(edg[w].first, edg[w].second);
        }
        rev[u] ^= rev[v];
    }
}

int main() {
    n = read(); m = read();
    for (int i = 0; i < m; i++) {
        int u = read(), v = read();
        edg.push_back({u, v});
        deg[u]++; deg[v]++;
    }
    for (int u = 1, v = -1; u <= n; u++) {
        if (deg[u] & 1) {
            if (v == -1) {
                v = u;
            } else {
                edg.push_back({u, v});
                v = -1;
            }
        }
    }
    if (edg.size() & 1) {
        edg.push_back({1, 1});
    }
    for (int u = 1; u <= n; u++) {
        deg[u] = 0;
    }
    for (int i = 0; i < edg.size(); i++) {
        int u = edg[i].first, v = edg[i].second;
        e[u].push_back({v, i}); e[v].push_back({u, i});
    }
    for (int u = 1; u <= n; u++) {
        if (vis[u]) { continue; }
        dfs(u);
    }
    for (int i = 0; i < edg.size(); i++) {
        deg[edg[i].second]++;
    }
    for (int u = 1; u <= n; u++) {
        if (ft[u] > 0) { continue; }
        solve(u);
    }
    printf("%d\n", edg.size());
    for (int i = 0; i < edg.size(); i++) {
        int u = edg[i].first, v = edg[i].second;
        printf("%d %d\n", u, v);
    }
    return 0;
}