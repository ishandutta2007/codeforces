#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

const int maxN = 200005, maxE = maxN << 1;

int n, m, siz[maxN], dep[maxN], w[maxN];
long long ans;

bool cmp(const int &x, const int &y) { return x > y; }

struct List {
    int len, fst[maxN], nxt[maxE], v[maxE];
    
    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int vv) { v[len] = vv, nxt[len] = fst[u], fst[u] = len++; }
    inline void connect(int u, int vv) { insert(u, vv), insert(vv, u); }
} ls;

void dfs(int u, int fa) {
    siz[u] = 1; dep[u] = dep[fa] + 1;
    for (int i = ls.fst[u]; ~i; i = ls.nxt[i]) {
        int v = ls.v[i];
        if (v != fa) { dfs(v, u); siz[u] += siz[v]; }
    }
    w[u] = siz[u] - dep[u];
}

int main() {
    scanf("%d%d", &n, &m); m=n-m;
    for (int i = 2; i <= n; i++) { int u, v; scanf("%d%d", &u, &v); ls.connect(u, v); }
    dfs(1, 0); std::sort(w + 1, w + n + 1, cmp);
    for (int i = 1; i <= m; i++) { ans += w[i]; }
    printf("%lld\n", ans);
    return 0;
}