#include <cstdio>
#include <cstring>

inline int read() {
    char c = getchar(); int x = 0;
    while (c < '0' || c > '9') { c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return x;
}

const int N = 800005;

int n, m, q, ans = -1;
bool vis[N];

struct List {
    int tot, fst[N], nxt[N], to[N];

    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int v) { nxt[tot] = fst[u]; to[tot] = v; fst[u] = tot++; }
    inline void link(int u, int v) { insert(u, v); insert(v, u); }
} e;

void dfs(int u) {
    if (vis[u]) { return; } vis[u] = true;
    for (int i = e.fst[u]; ~i; i = e.nxt[i]) { dfs(e.to[i]); }
}

int main() {
    m = read(); n = m + read(); q = read();
    for (int u, v; q; q--) { u = read(); v = read(); e.link(u, m + v); }
    for (int i = 1; i <= n; i++) { if (!vis[i]) { ans++; dfs(i); } }
    printf("%d\n", ans);
    return 0;
}