#include <cstdio>
#include <cstring>
#include <iostream>

inline int read() {
    char c = getchar(); int x = 0; bool sgn = false;
    while (c < '0' || c > '9') { if (c == '-') { sgn = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return sgn ? -x : x;
}

const int N = 400005;

int n, k, ft[N], hs[N], dep[N], siz[N], top[N], bot[N];

struct List {
    int tot, fst[N], nxt[N], to[N];

    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int v) { nxt[tot] = fst[u]; to[tot] = v; fst[u] = tot++; }
    inline void link(int u, int v) { insert(u, v); insert(v, u); }
} e;

void dfs1(int u, int fa) {
    ft[u] = fa; dep[u] = dep[fa] + 1; siz[u] = 1;
    for (int i = e.fst[u]; ~i; i = e.nxt[i]) {
        int v = e.to[i];
        if (v != fa) {
            dfs1(v, u); siz[u] += siz[v];
            if (siz[hs[u]] < siz[v]) { hs[u] = v; }
        }
    }
}
void dfs2(int u, int tp) {
    top[u] = tp;
    if (hs[u]) { dfs2(hs[u], tp); bot[u] = bot[hs[u]]; } else { bot[u] = u; }
    for (int i = e.fst[u]; ~i; i = e.nxt[i]) {
        int v = e.to[i];
        if (v != ft[u] && v != hs[u]) { dfs2(v, v); }
    }
}

int get(int u) {
    std::cout << "d " << u << std::endl;
    return read();
}
int go(int u) {
    std::cout << "s " << u << std::endl;
    return read();
}
void answer(int u) {
    std::cout << "! " << u << std::endl;
}

int jump(int u, int x) {
    for (; x; x--) { u = ft[u]; } return u;
}

void solve(int u) {
    int d = get(bot[u]);
    if (d == 0) { answer(bot[u]); return; }
    d = (k + dep[bot[u]] - d) / 2; u = jump(bot[u], dep[bot[u]] - d - 1);
    if (dep[u] == k + 1) { answer(u); return; } solve(go(u));
}

int main() {
    n = read();
    for (int i = 2; i <= n; i++) { e.link(read(), read()); }
    dfs1(1, 0); dfs2(1, 1); k = get(1);
    if (k == 0) { answer(1); return 0; } solve(1);
    return 0;
} //