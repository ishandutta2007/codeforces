#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

inline int read() {
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 300005, maxE = maxN << 1;

int n, val[maxN];
long long ans, f[maxN], g[maxN];

struct List {
    int len, fst[maxN], nxt[maxE], v[maxE], w[maxE];
    
    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int vv, int ww) { v[len] = vv, w[len] = ww, nxt[len] = fst[u], fst[u] = len++; }
    inline void connect(int u, int vv, int ww) { insert(u, vv, ww), insert(vv, u, ww); }
} ls;

void dfs(int u, int fa) {
    for (int i = ls.fst[u]; ~i; i = ls.nxt[i]) {
        int v = ls.v[i], w = ls.w[i];
        if (v != fa) {
            if (g[u] >= w) { g[v] = std::max(g[v], g[u] - w + val[v]); }
            dfs(v, u);
            if (f[v] >= w) { f[u] = std::max(f[u], f[v] - w + val[u]); }
            g[u] = std::max(g[u], f[u]);
        }
    }
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) { val[i] = read(); f[i] = g[i] = val[i]; }
    for (int i = 2; i <= n; i++) { int u = read(), v = read(); ls.connect(u, v, read()); }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) { ans = std::max(ans, g[i]); }
    printf("%I64d\n", ans);
    return 0;
} //