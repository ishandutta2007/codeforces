#include <cctype>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, q, ft[N], col[N];
long long ans[N];
std::vector<std::pair<int, int>> mdf[N];

struct List {
    int tot, fst[N], nxt[N], to[N];

    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int v) {
        nxt[tot] = fst[u]; to[tot] = v; fst[u] = tot++;
    }
    inline void link(int u, int v) {
        insert(u, v); insert(v, u);
    }
} e;

struct LinkCutTree {
    int ft[N], son[N][2], siz[N], ss[N];
    long long sf[N];

    inline bool isRight(int u) {
        return son[ft[u]][0] != u;
    }
    inline bool isRoot(int u) {
        return son[ft[u]][0] != u && son[ft[u]][1] != u;
    }
    inline void connect(int u, int fa, int d) {
        ft[u] = fa; son[fa][d] = u;
    }
    inline void pushUp(int u) {
        siz[u] = siz[son[u][0]] + siz[son[u][1]] + ss[u] + 1;
    }
    inline void rotate(int u) {
        int fa = ft[u], ud = isRight(u), v = son[u][ud ^ 1];
        int ga = ft[fa], fd = isRight(fa); ft[u] = ga;
        if (!isRoot(fa)) { son[ga][fd] = u; }
        connect(v, fa, ud); connect(fa, u, ud ^ 1);
        pushUp(fa);
    }

    void splay(int u) {
        for (int fa = ft[u]; !isRoot(u); rotate(u), fa = ft[u]) {
            if (!isRoot(fa)) { rotate(isRight(u) == isRight(fa) ? fa : u); }
        }
        pushUp(u);
    }
    void access(int u) {
        for (int v = 0; u > 0; v = u, u = ft[u]) {
            splay(u);
            ss[u] += siz[son[u][1]] - siz[v];
            sf[u] += 1ll * siz[son[u][1]] * siz[son[u][1]] - 1ll * siz[v] * siz[v];
            son[u][1] = v;
            pushUp(u);
        }
    }
    int findRoot(int u) {
        access(u); splay(u);
        for (; son[u][0] > 0; u = son[u][0]);
        return u;
    }
    void link(int u, int v) {
        access(u); splay(u);
        access(v); splay(v);
        connect(u, v, 1);
        pushUp(v);
    }
    void cut(int u) {
        access(u); splay(u);
        int v = son[u][0];
        ft[v] = son[u][0] = 0;
        pushUp(u);
    }
    long long query(int u) {
        u = findRoot(u); splay(u); u = son[u][1];
        return 1ll * siz[u] * siz[u];
    }
    long long querys(int u) {
        u = findRoot(u); splay(u);
        return 1ll * siz[son[u][0]] * siz[son[u][0]] + 1ll * siz[son[u][1]] * siz[son[u][1]] + sf[u];
    }
} lct;

void dfs(int u, int fa) {
    ft[u] = fa;
    if (fa > 0) { lct.link(u, fa); }
    for (int i = e.fst[u]; ~i; i = e.nxt[i]) {
        int v = e.to[i];
        if (v != fa) { dfs(v, u); }
    }
}

int main() {
    n = read(); q = read();
    for (int u = 1; u <= n; u++) {
        col[u] = read();
        mdf[col[u]].push_back({u, 0});
    }
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        e.link(u, v);
    }
    e.link(n + 1, 1); dfs(n + 1, 0);
    for (int i = 1; i <= q; i++) {
        int u = read();
        mdf[col[u]].push_back({u, i});
        col[u] = read();
        mdf[col[u]].push_back({u, i});
    }
    for (int u = 1; u <= n; u++) { col[u] = 0; }
    for (int x = 1; x <= n; x++) {
        for (int i = 0; i < (int) mdf[x].size(); i++) {
            int u = mdf[x][i].first, j = mdf[x][i].second, fa = ft[u];
            col[u] ^= 1;
            if (col[u] == 1) {
                ans[j] += lct.query(u);
                lct.cut(u);
                ans[j] -= lct.querys(u);
                if (col[fa] == 0) { ans[j] -= lct.query(fa); }
            } else {
                if (col[fa] == 0) { ans[j] += lct.query(fa); }
                ans[j] += lct.querys(u);
                lct.link(u, ft[u]);
                ans[j] -= lct.query(u);
            }
        }
        for (int i = (int) mdf[x].size() - 1; i >= 0; i--) {
            int u = mdf[x][i].first;
            if (col[u] == 1) {
                lct.link(u, ft[u]);
                col[u] = 0;
            }
        }
    }
    for (int i = 1; i <= q; i++) { ans[i] += ans[i - 1]; }
    for (int i = 0; i <= q; i++) { printf("%lld\n", ans[i]); }
    return 0;
}