#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 2e6 + 5, L = 21;

int n, m, cnt, a[N], b[N], c[N], d[N], anc[N], deg[N], p[N];
std::vector<int> ans;
std::vector<std::pair<int, int>> e[N];
bool vis[N];

int find(int u) {
    return anc[u] == u ? u : anc[u] = find(anc[u]);
}

bool check() {
    for (int u = 0; u < m; u++) {
        if (deg[u] & 1) { return false; }
    }
    int rt = -1;
    for (int u = 0; u < m; u++) {
        if (deg[u] > 0) { rt = u; break; }
    }
    if (rt == -1) { return true; }
    for (int u = 0; u < m; u++) {
        if (deg[u] > 0 && find(u) != find(rt)) {
            return false;
        }
    }
    return true;
}

void dfs(int u) {
    while (true) {
        for (; p[u] < e[u].size() && vis[e[u][p[u]].second]; p[u]++);
        if (p[u] == e[u].size()) { return; }
        vis[e[u][p[u]].second] = true;
        int x, y;
        if (c[e[u][p[u]].second] == u) {
            x = e[u][p[u]].second * 2 + 1;
            y = e[u][p[u]].second * 2 + 2;
        } else {
            x = e[u][p[u]].second * 2 + 2;
            y = e[u][p[u]].second * 2 + 1;
        }
        dfs(e[u][p[u]].first);
        ans.push_back(y);
        ans.push_back(x);
    }
}

int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        a[i] = read(); b[i] = read();
    }
    for (int k = L - 1; k >= 0; k--) {
        m = 1 << k;
        for (int u = 0; u < m; u++) {
            anc[u] = u; deg[u] = 0;
            e[u].clear();
        }
        for (int i = 0; i < n; i++) {
            int u = c[i] = a[i] & (m - 1);
            int v = d[i] = b[i] & (m - 1);
            e[u].push_back({v, i}); deg[u]++;
            e[v].push_back({u, i}); deg[v]++;
            if (find(u) != find(v)) {
                anc[find(u)] = find(v);
            }
            vis[i] = false;
        }
        if (!check()) { continue; }
        for (int u = 0; u < m; u++) {
            p[u] = 0;
        }
        for (int u = 0; u < m; u++) {
            if (p[u] < e[u].size()) {
                dfs(u); break;
            }
        }
        printf("%d\n", k);
        std::reverse(ans.begin(), ans.end());
        for (auto u : ans) {
            printf("%d ", u);
        }
        break;
    }
    return 0;
}