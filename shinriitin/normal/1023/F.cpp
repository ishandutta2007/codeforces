#include <bits/stdc++.h>

inline void read(int &x) {
    char c; while (!std::isdigit(c = getchar()));
    for (x = c - '0'; std::isdigit(c = getchar()); (x *= 10) += (c - '0'));
}

const int max_N = (int) 1e6 + 21;

int n, m, k, f[max_N], u[max_N], v[max_N], w[max_N], tot;

bool vis[max_N];

std::vector<int> vec[max_N];

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

int p[max_N], dep[max_N], sz[max_N], mx[max_N];

void dfs(int u) {
    sz[u] = 1, mx[u] = 0;
    for (auto v : vec[u]) {
        if (v == p[u]) continue;
        p[v] = u, dep[v] = dep[u] + 1;
        dfs(v);
        sz[u] += sz[v];
        if (sz[mx[u]] < sz[v]) mx[u] = v;
    }
}

int head[max_N], dfn[max_N], cnt;

void dfs1(int u, int c) {
    dfn[u] = ++cnt;
    head[u] = c;
    if (mx[u]) dfs1(mx[u], c);
    for (auto v : vec[u]) {
        if (dfn[v]) continue;
        dfs1(v, v);
    }
}

const int inf = 0x3f3f3f3f;

int ret[max_N];

void modify(int l, int r, int w) {
    int x = find(r);
    while (x >= l) {
        ret[x] = w;
        f[x] = x - 1;
        x = find(x);
    }
}

void updt(int u, int v, int w) {
    while (head[u] != head[v]) {
        if (dep[head[u]] > dep[head[v]]) std::swap(u, v);
        modify(dfn[head[v]], dfn[v], w);
        v = p[head[v]];
    }
    if (dep[u] > dep[v]) std::swap(u, v);
    modify(dfn[u], dfn[v], w);
}

int main() {
    read(n), read(k), read(m);
    for (int i = 1; i <= n; ++i) f[i] = i;
    tot = n;
    for (int i = 1, a, b; i <= k; ++i) {
        read(a), read(b);
        ++tot;
        vec[a].push_back(tot), vec[tot].push_back(a);
        vec[b].push_back(tot), vec[tot].push_back(b);
        f[find(a)] = find(b);
    }
    for (int i = 1; i <= m; ++i) {
        read(u[i]), read(v[i]), read(w[i]);
        int a = find(u[i]), b = find(v[i]);
        if (a == b) continue;
        vis[i] = true;
        f[a] = b;
        vec[u[i]].push_back(v[i]);
        vec[v[i]].push_back(u[i]);
    }
    dfs(1);
    dfs1(1, 1);
    for (int i = 1; i <= tot; ++i) f[i] = i, ret[i] = inf;
    for (int i = 1; i <= m; ++i) {
        if (vis[i]) continue;
        updt(u[i], v[i], w[i]);
    }
    long long ans = 0;
    for (int i = n + 1; i <= tot; ++i) {
        if (ret[dfn[i]] == inf) return puts("-1"), 0;
        ans += ret[dfn[i]];
    }
    printf("%lld\n", ans);
    return 0;
}