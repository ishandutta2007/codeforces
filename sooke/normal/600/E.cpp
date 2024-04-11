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

typedef long long lol;

const int maxN = 100005, maxE = maxN << 1;

int n, col[maxN];
lol ans[maxN];

struct List {
    int len, fst[maxN], nxt[maxE], v[maxE];
    
    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int vv) { v[len] = vv, nxt[len] = fst[u], fst[u] = len++; }
    inline void connect(int u, int vv) { insert(u, vv), insert(vv, u); }
} ls;

struct SegmentTree {
    int cnt, root[maxN], sonL[maxN << 6], sonR[maxN << 6], max[maxN << 6]; lol sum[maxN << 6];

    inline void pushUp(int u) {
        if (max[sonL[u]] > max[sonR[u]]) { max[u] = max[sonL[u]]; sum[u] = sum[sonL[u]]; }
        else if (max[sonR[u]] > max[sonL[u]]) { max[u] = max[sonR[u]]; sum[u] = sum[sonR[u]]; }
        else { max[u] = max[sonL[u]]; sum[u] = sum[sonL[u]] + sum[sonR[u]]; }
    }
    void modify(int &u, int l, int r, int p) {
        if (!u) { u = ++cnt; }
        if (l == r) { max[u]++; sum[u] = l; return; }
        int mid = l + r >> 1;
        if (p <= mid) { modify(sonL[u], l, mid, p); } else { modify(sonR[u], mid + 1, r, p); }
        pushUp(u);
    }
    void merge(int &u, int v, int l, int r) {
        if (!u || !v) { u |= v; return; }
        if (l == r) { max[u] += max[v]; return; }
        int mid = l + r >> 1;
        merge(sonL[u], sonL[v], l, mid); merge(sonR[u], sonR[v], mid + 1, r); pushUp(u);
    }
} tr;

void dfs(int u, int fa) {
    tr.modify(tr.root[u], 1, n, col[u]);
    for (int i = ls.fst[u]; ~i; i = ls.nxt[i]) {
        int v = ls.v[i];
        if (v != fa) { dfs(v, u); tr.merge(tr.root[u], tr.root[v], 1, n); }
    }
    ans[u] = tr.sum[tr.root[u]];
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) { col[i] = read(); }
    for (int i = 2; i <= n; i++) { ls.connect(read(), read()); }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) { printf("%I64d ", ans[i]); }
    return 0;
}