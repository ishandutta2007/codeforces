#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, m, c, s, a[N];
long long b[N], f[N], g[N];
int tms, vol, dfn[N], low[N], stc[N], col[N], siz[N];
bool ins[N];

struct List {
    int tot, fst[N], nxt[N], to[N];

    List() { memset(fst, -1, sizeof(fst)); }
    void insert(int u, int v) {
        nxt[tot] = fst[u]; to[tot] = v; fst[u] = tot++;
    }
    void link(int u, int v) {
        insert(u, v); insert(v, u);
    }
} e, ie;

void tarjan(int u, int fa) {
    dfn[u] = low[u] = tms++;
    int pos = vol; stc[vol++] = u; ins[u] = true;
    for (int i = e.fst[u]; ~i; i = e.nxt[i]) {
        int v = e.to[i];
        if (v != fa) {
            if (dfn[v] == -1) {
                tarjan(v, u);
                low[u] = std::min(low[u], low[v]);
            } else if (ins[v]) {
                low[u] = std::min(low[u], dfn[v]);
            }
        }
    }
    if (dfn[u] == low[u]) {
        for (c++; vol > pos; ) {
            int u = stc[--vol];
            ins[u] = false; col[u] = c; b[c] += a[u]; siz[c]++;
        }
    }
}

bool dfs(int u, int fa) {
    f[u] = g[u] = b[u];
    bool lef = true, flag = false;
    for (int i = ie.fst[u]; ~i; i = ie.nxt[i]) {
        int v = ie.to[i];
        if (v != fa) {
            lef = false;
            flag |= dfs(v, u);
            long long _f = f[u];
            f[u] = std::max(f[u], f[u] + f[v]);
            g[u] = std::max(std::max(_f, _f + g[v]), std::max(g[u], g[u] + f[v]));
        }
    } g[u] = std::max(f[u], g[u]);
    if (lef) {
        if (siz[u] == 1) {
            f[u] = -1e18; return false;
        } else {
            return true;
        }
    } else {
        if (siz[u] > 1) {
            return true;
        } else {
            if (flag == false) { f[u] = -1e18; }
            return flag;
        }
    }
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) { a[i] = read(); }
    for (int i = 1; i <= m; i++) { e.link(read(), read()); }
    s = read();
    for (int i = 1; i <= n; i++) { dfn[i] = -1; }
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == -1) { tarjan(i, 0); }
    }
    for (int i = 1; i <= n; i++) {
        int u = col[i];
        for (int j = e.fst[i]; ~j; j = e.nxt[j]) {
            int v = col[e.to[j]];
            if (u != v) { ie.insert(u, v); }
        }
    } dfs(col[s], 0);
    printf("%lld\n", std::max(f[col[s]], g[col[s]]));
    return 0;
}