#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, m, u1, v1, u2, v2, ft[N], _ft[N], dep[N];
std::vector<int> ans, e[N], p[N];
std::vector<std::pair<int, int>> tag[N];
bool flag, used[N];

void dfs(int u, int fa) {
    ft[u] = fa; dep[u] = dep[fa] + 1;
    for (auto v : e[u]) {
        if (ft[v] != -1) { continue; }
        if (flag && _ft[u] != v && _ft[v] != u) { continue; }
        dfs(v, u);
    }
}

void go(int u, int v) {
    if (dep[u] < dep[v]) {
        std::vector<int> res;
        for (; dep[v] >= dep[u]; v = ft[v]) {
            res.push_back(v);
        }
        std::reverse(res.begin(), res.end());
        for (auto u : res) {
            ans.push_back(u);
        }
    } else {
        for (; dep[u] >= dep[v]; u = ft[u]) {
            ans.push_back(u);
        }
    }
}
void print() {
    printf("%d", ans.size());
    for (auto u : ans) {
        printf(" %d", u);
    }
    printf("\n");
    ans.clear();
}

void solve() {
    flag = true;
    for (int u = 1; u <= n; u++) { _ft[u] = ft[u]; ft[u] = -1; }
    dfs(u1, 0);
    for (int u = v1; u != 0; u = ft[u]) { used[u] = true; }
    int s = u2, t = v2;
    for (; !used[s]; s = ft[s]);
    for (; !used[t]; t = ft[t]);
    if (dep[s] > dep[t]) { std::swap(s, t); std::swap(u2, v2); }
    printf("YES\n");
    go(s, t); print();
    go(s, u1); go(v1, t); print();
    go(s, u2); go(v2, t); print();
}

int main() {
    n = read(); m = read();
    for (int i = 0; i < m; i++) {
        int u = read(), v = read();
        e[u].push_back(v); e[v].push_back(u);
    }
    for (int u = 1; u <= n; u++) { ft[u] = -1; }
    for (int u = 1; u <= n; u++) {
        if (ft[u] == -1) { dfs(u, 0); }
    }
    for (int u = 1; u <= n; u++) {
        for (auto v : e[u]) {
            if (u > v || ft[u] == v || ft[v] == u) { continue; }
            int s = u, t = v;
            while (s != t) {
                if (dep[s] > dep[t]) {
                    tag[s].push_back({u, v});
                    if (tag[s].size() > 1) {
                        u1 = tag[s][0].first; v1 = tag[s][0].second;
                        u2 = tag[s][1].first; v2 = tag[s][1].second;
                        solve();
                        return 0;
                    }
                    s = ft[s];
                } else {
                    tag[t].push_back({u, v});
                    if (tag[t].size() > 1) {
                        u1 = tag[t][0].first; v1 = tag[t][0].second;
                        u2 = tag[t][1].first; v2 = tag[t][1].second;
                        solve();
                        return 0;
                    }
                    t = ft[t];
                }
            }
        }
    }
    printf("NO\n");
    return 0;
}