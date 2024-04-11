#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int mod = 1e9 + 7;

inline int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }

const int N = 1e6 + 5;

int n, s, t, min, ans, b[N], f[N], dis[N], deg[N];
std::pair<int, int> a[N];
std::vector<std::pair<int, int>> e[N];
std::queue<int> que;

void toposort() {
    for (int i = 0; i <= n; i++) {
        dis[i] = 2e9;
        for (auto j : e[i]) { deg[j.first]++; }
    }
    dis[s] = 0; f[s] = 1;
    for (int i = 0; i <= n; i++) {
        if (deg[i] == 0) {
            if (i != s) { dis[i] = 1e9 + 5; }
            que.push(i);
        }
    }
    for (; !que.empty(); que.pop()) {
        int u = que.front();
        for (auto i : e[u]) {
            int v = i.first, w = i.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w; f[v] = f[u];
            } else if (dis[v] == dis[u] + w) {
                f[v] = add(f[v], f[u]);
            }
            deg[v]--;
            if (deg[v] == 0) { que.push(v); }
        }
    }
    min = 2e9;
    for (int i = 1; i <= n; i++) {
        if (a[i].second > b[n]) { min = std::min(min, dis[i]); }
    }
    for (int i = 1; i <= n; i++) {
        if (dis[i] == min && a[i].second > b[n]) { ans = add(ans, f[i]); }
    }
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        a[i].second = read(); a[i].first = read();
    }
    std::sort(a + 1, a + n + 1); s = 0;
    for (int i = 1; i <= n; i++) { b[i] = a[i].first; }
    for (int i = 1; i <= n; i++) {
        e[i - 1].push_back({i, a[i].first - a[i - 1].first});
        int u = std::lower_bound(b + 1, b + n + 1, a[i].second) - b;
        if (u <= n) {
            e[i].push_back({u, a[u].first - a[i].second});
        }
    }
    toposort(); printf("%d\n", ans);
    return 0;
}