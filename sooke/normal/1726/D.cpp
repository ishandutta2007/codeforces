#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, m, anc[N], anp[N], ans[N], deg[N];
std::vector<std::pair<int, int>> e[N];
std::vector<std::pair<std::pair<int, int>, int>> p;

int find(int u) { return anc[u] == u ? u : anc[u] = find(anc[u]); }
int finp(int u) { return anp[u] == u ? u : anp[u] = finp(anp[u]); }

bool dfs(int u, int fa, int s, int t) {
    if (u == t) { return true; }
    bool res = false;
    for (auto i : e[u]) {
        int v = i.first, id = i.second;
        if (v == fa) { continue; }
        if (dfs(v, u, s, t)) {
            res = true;
            if (u == s) { ans[id] = 1; }
        }
    }
    return res;
}

int main() {
    for (int T = read(); T; T--) {
        n = read(); m = read();
        for (int u = 1; u <= n; u++) {
            anc[u] = anp[u] = u; deg[u] = 0; e[u].clear();
        }
        p.clear();
        bool gg = false;
        for (int i = 1; i <= m; i++) {
            int u = read(), v = read();
            if (find(u) != find(v)) {
                anc[find(u)] = find(v);
                e[u].push_back({v, i});
                e[v].push_back({u, i});
                ans[i] = 0;
            } else {
                p.push_back({{u, v}, i});
                ans[i] = 1;
                if (finp(u) != finp(v)) {
                    anp[finp(u)] = finp(v); deg[u]++; deg[v]++;
                } else {
                    gg = true;
                    ans[i] = 0;
                }
            }
        }
        if (gg) {
            std::vector<int> d;
            for (int u = 1; u <= n; u++) {
                if (deg[u] == 1) { d.push_back(u); }
            }
            dfs(d[0], 0, d[0], d[1]);
        }
        for (int i = 1; i <= m; i++) {
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}