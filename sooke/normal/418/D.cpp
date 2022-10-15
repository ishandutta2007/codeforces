#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

inline int read() {
    char c = getchar(); int x = 0;
    while (c < '0' || c > '9') { c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return x;
}

const int maxLog = 20, maxN = 200005;

int n, m, num, q, ts, bs, logN, o[maxN], fa[maxN], a[maxN], b[maxN], dep[maxN], dis[maxN], siz[maxN], hson[maxN], bl[maxN], br[maxN];
int ans, vol, stack[maxN], top[maxN], dfn[maxN], id[maxN], bfn[maxN], near[maxN];

bool cmp(int x, int y) { return dfn[x] < dfn[y]; }

struct List {
    int tot, fst[maxN], nxt[maxN << 1], to[maxN << 1];

    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int v) { nxt[tot] = fst[u]; to[tot] = v; fst[u] = tot++; }
    inline void link(int u, int v) { insert(u, v); insert(v, u); }
} e, ie;

struct Rmq {
    int f[maxLog][maxN];

    void build() {
        for (int i = 1; i <= logN; i++) {
            for (int j = 1; j + (1 << i) - 1 <= n; j++) { f[i][j] = std::max(f[i - 1][j], f[i - 1][j + (1 << i - 1)]); }
        }
    }
    inline int query(int l, int r) {
        if (l > r) { return -1e9; } int logLen = o[r - l + 1];
        return std::max(f[logLen][l], f[logLen][r - (1 << logLen) + 1]);
    }
} f, g, h;

void dfs1(int u, int fd) {
    fa[u] = fd; dep[u] = dep[fd] + 1; siz[u] = 1;
    for (int i = e.fst[u], v; ~i; i = e.nxt[i]) {
        v = e.to[i];
        if (v != fd) {
            dfs1(v, u); siz[u] += siz[v];
            if (siz[hson[u]] < siz[v]) { hson[u] = v; }
        }
    }
}
void dfs2(int u, int tp) {
    top[u] = tp; dfn[u] = ++ts; id[ts] = u;
    if (hson[u]) { dfs2(hson[u], tp); }
    for (int i = e.fst[u], v; ~i; i = e.nxt[i]) {
        v = e.to[i];
        if (v != fa[u] && v != hson[u]) { dfs2(v, v); }
    }
    if (hson[u]) { bl[u] = br[u] = bfn[hson[u]] = ++bs; h.f[0][bs] = dis[hson[u]] + 1; } else { bl[u] = 1e9; }
    for (int i = e.fst[u], v; ~i; i = e.nxt[i]) {
        v = e.to[i];
        if (v != fa[u] && v != hson[u]) { br[u] = bfn[v] = ++bs; dis[u] = std::max(dis[u], dis[v]); h.f[0][bs] = dis[v] + 1; }
    }
    f.f[0][dfn[u]] = dis[u] + dfn[u]; g.f[0][dfn[u]] = dis[u] - dfn[u];
    dis[u] = std::max(dis[u], dis[hson[u]]) + 1;
}

inline int findLca(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] > dep[top[v]]) { u = fa[top[u]]; } else { v = fa[top[v]]; } 
    }
    return dep[u] < dep[v] ? u : v;
}

void insert(int u) {
    if (vol > 1) {
        int lca = findLca(stack[vol], u);
        if (stack[vol] != lca) {
            for (; vol > 1 && dfn[lca] <= dfn[stack[vol - 1]]; vol--) { ie.insert(stack[vol - 1], stack[vol]); }
            if (stack[vol] != lca) { ie.insert(lca, stack[vol]); stack[vol] = b[++num] = lca; }
        }
    }
    stack[++vol] = b[++num] = u;
}

void dfs3(int u) {
    for (int i = ie.fst[u], v; ~i; i = ie.nxt[i]) {
        v = ie.to[i]; dfs3(v);
        near[u] = std::min(near[u], near[v] + dep[v] - dep[u]);
    }
}
void dfs4(int u) {
    if (ie.fst[u] == -1) { ans = std::max(ans, near[u] + dis[u] - 1); } ans = std::max(ans, near[u]); int r = br[u];
    for (int i = ie.fst[u], v, k, t, s; ~i; i = ie.nxt[i]) {
        v = ie.to[i]; near[v] = std::min(near[v], near[u] + dep[v] - dep[u]); dfs4(v);
        s = v; t = k = std::min(dep[v] - dep[u] - 1, near[u] - near[v] + dep[v] - dep[u] >> 1);
        while (k) {
            if (top[s] == s) {
                ans = std::max(ans, std::max(h.query(bl[fa[s]], bfn[s] - 1), h.query(bfn[s] + 1, br[fa[s]])) + near[v] + dep[v] - dep[s]);
                k--; s = fa[s];
            } else if (dfn[s] - dfn[top[s]] <= k) {
                ans = std::max(ans, g.query(dfn[top[s]], dfn[s] - 1) + dfn[s] + near[v] + dep[v] - dep[s]);
                k -= dfn[s] - dfn[top[s]]; s = top[s];
            } else {
                ans = std::max(ans, g.query(dfn[s] - k, dfn[s] - 1) + dfn[s] + near[v] + dep[v] - dep[s]);
                s = id[dfn[s] - k]; k = 0;
            }
        }
        k = dep[v] - dep[u] - 1 - t;
        while (k) {
            if (top[s] == s) {
                ans = std::max(ans, std::max(h.query(bl[fa[s]], bfn[s] - 1), h.query(bfn[s] + 1, br[fa[s]])) + near[u] + dep[s] - dep[u] - 2);
                k--; s = fa[s];
            } else if (dfn[s] - dfn[top[s]] <= k) {
                ans = std::max(ans, f.query(dfn[top[s]], dfn[s] - 1) - dfn[s] + near[u] + dep[s] - dep[u]);
                k -= dfn[s] - dfn[top[s]]; s = top[s];
            } else {
                ans = std::max(ans, f.query(dfn[s] - k, dfn[s] - 1) - dfn[s] + near[u] + dep[s] - dep[u]);
                s = id[dfn[s] - k]; k = 0;
            }
        }
        ans = std::max(ans, h.query(bfn[s] + 1, r) + near[u] - 1); r = bfn[s] - 1;
    }
    ans = std::max(ans, h.query(bl[u], r) + near[u] - 1);
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) { o[i] = log(i) / log(2) + 1e-7; } logN = o[n];
    for (int i = 2; i <= n; i++) { e.link(read(), read()); }
    dfs1(1, 0); dfs2(1, 1); f.build(); g.build(); h.build();
    for (q = read(); q; q--) {
        m = 2; ie.tot = vol = num = ans = 0;
        for (int i = 1; i <= m; i++) { a[i] = read(); }
        std::sort(a + 1, a + m + 1, cmp);
        if (a[1] != 1) { insert(1); }
        for (int i = 1; i <= m; i++) { insert(a[i]); }
        for (; vol > 1; vol--) { ie.insert(stack[vol - 1], stack[vol]); }
        for (int i = 1; i <= num; i++) { near[b[i]] = 1e9; }
        for (int i = 1; i <= m; i++) { near[a[i]] = 0; }
        dfs3(1); dfs4(1); printf("%d\n", ans);
        for (int i = 1; i <= num; i++) { ie.fst[b[i]] = -1; }
    }
    return 0;
}