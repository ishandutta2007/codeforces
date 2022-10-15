#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

inline int read() {
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 200005, maxE = maxN << 1;

int n, tmp1, tmp2, root1, root2, deg[maxN], dep[maxN], f[maxN], g[maxN];

struct List {
    int len, fst[maxN], nxt[maxE], v[maxE];
    
    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int vv) { v[len] = vv, nxt[len] = fst[u], fst[u] = len++; }
    inline void connect(int u, int vv) { insert(u, vv), insert(vv, u); }
} ls;

bool dfs(int u, int fa, int &res) {
    if (res + u == 0) { return true; }
    dep[u] = dep[fa] + 1; f[u] = u; g[u] = 0;
    for (int i = ls.fst[u]; ~i; i = ls.nxt[i]) {
        int v = ls.v[i];
        if (v != fa) {
            if (dfs(v, u, res)) {
                if (!fa) { continue; } else { return true; }
            }
            if (dep[f[u]] < dep[f[v]]) { g[u] = f[u]; f[u] = f[v]; } else if (dep[g[u]] < dep[f[v]]) { g[u] = f[v]; }
        }
    }
    if (res >= 0 && deg[u] >= 3 && (dep[res] < dep[u] || (dep[res] == dep[u] && dep[f[res]] + dep[g[res]] < dep[f[u]] + dep[g[u]]))) { res = u; }
    return false;
}

int main() {
    n = read();
    for (int i = 2; i <= n; i++) { int u, v; deg[u = read()]++; deg[v = read()]++; ls.connect(u, v); }
    for (int i = 1; i <= n; i++) {
        if (deg[i] >= 3) { root1 = i; }
    }
    dfs(root1, 0, root1); dfs(root1, 0, root2); tmp1 = -root1; tmp2 = -root2;
    dfs(root1, 0, tmp2); dfs(root2, 0, tmp1);
    printf("%d %d\n%d %d\n", f[root1], f[root2], g[root1], g[root2]);
    return 0;
} // fuck codeforces