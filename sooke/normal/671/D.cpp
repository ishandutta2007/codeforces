#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const long long inf = 1e18;
const int N = 1e6 + 5;

int n, m, dep[N];
long long f[N], g[N];
std::vector<int> e[N];
std::vector<std::pair<int, int>> p[N];

struct LeftistTree {
    int tot, rt[N], ls[N], rs[N], dis[N];
    long long tag[N];
    std::pair<long long, int> a[N];

    LeftistTree() { dis[0] = -1; a[0] = {inf, 0}; }

    inline void pushUp(int u) {
        if (dis[ls[u]] < dis[rs[u]]) {
            std::swap(ls[u], rs[u]);
        }
        dis[u] = dis[ls[u]] + 1;
    }
    inline void pushTag(int u, long long x) {
        if (u == 0) { return; }
        tag[u] += x; a[u].first += x;
    }
    inline void pushDown(int u) {
        if (tag[u] == 0) { return; }
        pushTag(ls[u], tag[u]);
        pushTag(rs[u], tag[u]);
        tag[u] = 0;
    }

    int merge(int u, int v) {
        if (u == 0 || v == 0) { return u + v; }
        pushDown(u); pushDown(v);
        if (a[u].first > a[v].first) {
            std::swap(u, v);
        }
        rs[u] = merge(rs[u], v);
        pushUp(u);
        return u;
    }

    inline std::pair<long long, int> top(int i) {
        return a[rt[i]];
    }
    inline void push(int i, std::pair<long long, int> p) {
        int u = ++tot; a[u] = p;
        rt[i] = merge(rt[i], u);
    }
    inline void pop(int i) {
        rt[i] = merge(ls[rt[i]], rs[rt[i]]);
    }
    inline void modify(int i, long long x) {
        pushTag(rt[i], x);
    }
    inline void join(int i, int j) {
        rt[i] = merge(rt[i], rt[j]);
    }
} tr;

void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1;
    for (auto v : e[u]) {
        if (v == fa) { continue; }
        dfs(v, u);
        for (; tr.top(v).second > dep[u]; tr.pop(v));
        g[v] = std::min(inf, tr.top(v).first);
        f[u] = std::min(inf + inf, f[u] + g[v]);
    }
    for (auto i : p[u]) {
        tr.push(u, {f[u] + i.second, dep[i.first]});
    }
    for (auto v : e[u]) {
        if (v == fa) { continue; }
        tr.modify(v, f[u] - g[v]);
        tr.join(u, v);
    }
}

int main() {
    n = read(); m = read();
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        e[u].push_back(v); e[v].push_back(u);
    }
    for (int i = 0; i < m; i++) {
        int u = read(), v = read(), w = read();
        p[u].push_back({v, w});
    }  
    dfs(1, 0);
    printf("%lld\n", f[1] >= inf ? -1 : f[1]);
    return 0;
}