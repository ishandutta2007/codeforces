#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 2e5 + 5;

int n, m, k, deg[N];
std::vector<int> e[N];
bool vis[N];

bool check(std::vector<int> s) {
    if (s.size() * (s.size() - 1) / 2 > m) { return false; }
    for (auto u : s) {
        for (auto v : s) {
            if (u <= v) { continue; }
            auto it = std::lower_bound(e[u].begin(), e[u].end(), v);
            if (it == e[u].end() || *it != v) {
                return false;
            }
        }
    }
    return true;
}

bool solve() {
    std::priority_queue<std::pair<int, int>> que;
    for (int u = 1; u <= n; u++) {
        if (vis[u]) { continue; }
        que.push({-deg[u], u});
    }
    while (!que.empty()) {
        int d = -que.top().first;
        int u = que.top().second;
        que.pop();
        if (d != deg[u]) { continue; }
        if (d >= k) { break; }
        vis[u] = true;
        std::vector<int> s;
        for (auto v : e[u]) {
            if (!vis[v]) {
                deg[v]--;
                que.push({-deg[v], v});
                s.push_back(v);
            }
        }
        s.push_back(u);
        if (s.size() == k && check(s)) {
            printf("2\n");
            for (auto u : s) {
                printf("%d ", u);
            }
            printf("\n");
            return true;
        }
    }
    bool noleft = true;
    int cnt = 0;
    for (int u = 1; u <= n; u++) {
        if (!vis[u]) { noleft = false; cnt++; }
    }
    if (noleft) { return false; }
    printf("1 %d\n", cnt);
    for (int u = 1; u <= n; u++) {
        if (!vis[u]) { printf("%d ", u); }
    }
    printf("\n");
    return true;
}

int main() {
    for (int T = read(); T; T--) {
        n = read(); m = read(); k = read();
        for (int u = 1; u <= n; u++) {
            e[u].clear(); deg[u] = 0;
        }
        for (int i = 0; i < m; i++) {
            int u = read(), v = read();
            e[u].push_back(v); e[v].push_back(u);
            deg[u]++; deg[v]++;
        }
        std::priority_queue<std::pair<int, int>> que;
        for (int u = 1; u <= n; u++) {
            std::sort(e[u].begin(), e[u].end());
            que.push({-deg[u], u});
            vis[u] = false;
        }
        while (!que.empty()) {
            int d = -que.top().first;
            int u = que.top().second;
            que.pop();
            if (d != deg[u]) { continue; }
            if (d >= k - 1) { break; }
            vis[u] = true;
            for (auto v : e[u]) {
                if (!vis[v]) {
                    deg[v]--;
                    que.push({-deg[v], v});
                }
            }
        }
        bool noleft = true;
        for (int u = 1; u <= n; u++) {
            if (!vis[u]) { noleft = false; break; }
        }
        if (noleft) { printf("-1\n"); continue; }
        if (!solve()) { printf("-1\n"); }
    }
    return 0;
}