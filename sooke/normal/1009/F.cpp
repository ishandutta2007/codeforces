#include <cstdio>
#include <cstring>
#include <vector>

inline int read() {
    char c = getchar(); int x = 0;
    while (c < '0' || c > '9') { c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return x;
}

const int N = 2000005;

struct List {
    int tot, fst[N], nxt[N], to[N];

    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int v) { nxt[tot] = fst[u]; to[tot] = v; fst[u] = tot++; }
    inline void link(int u, int v) { insert(u, v); insert(v, u); }
} e;

int n, ft[N], hs[N], ans[N], dep[N], dis[N], top[N];
std::vector<int> f[N];

inline void modify(int u, int p, int x) {
    f[top[u]][p] += x;
    if (f[top[u]][ans[u]] < f[top[u]][p]) { ans[u] = p; }
    else if (f[top[u]][ans[u]] == f[top[u]][p]) { ans[u] = std::max(ans[u], p); }
}

void dfs1(int u, int fa) {
    ft[u] = fa; dep[u] = dep[fa] + 1;
    for (int i = e.fst[u], v; ~i; i = e.nxt[i]) {
        v = e.to[i];
        if (v != fa) {
            dfs1(v, u); dis[u] = std::max(dis[u], dis[v] + 1);
            if (dis[hs[u]] < dis[v]) { hs[u] = v; }
        }
    }
}
void dfs2(int u, int tp) {
    top[u] = tp;
    if (u == tp) { f[u].resize(dis[u] + 1); }
    if (hs[u]) { dfs2(hs[u], tp); ans[u] = ans[hs[u]]; }
    modify(u, dis[u], 1);
    for (int i = e.fst[u], v; ~i; i = e.nxt[i]) {
        v = e.to[i];
        if (v != ft[u] && v != hs[u]) {
            dfs2(v, v);
            for (int j = 0; j <= dis[v]; j++) { modify(u, dis[u] - (dis[v] - j) - 1, f[v][j]); }
        }
    }
}

int main() {
    n = read();
    for (int i = 2; i <= n; i++) { e.link(read(), read()); }
    dfs1(1, 0); dfs2(1, 1);
    for (int i = 1; i <= n; i++) { printf("%d\n", dis[i] - ans[i]); }
    return 0;
}