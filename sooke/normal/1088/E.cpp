#include <cstdio>
#include <cstring>
#include <algorithm>

inline int read() {
    char c = getchar(); int x = 0; bool sgn = false;
    while (c < '0' || c > '9') { if (c == '-') { sgn = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return sgn ? -x : x;
}

const int N = 300005, E = N << 1;

int n, cnt, val[N];
long long ans = -1e18, sum, f[N];

struct List {
    int tot, fst[N], nxt[E], to[E];

    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int v) { nxt[tot] = fst[u]; to[tot] = v; fst[u] = tot++; }
    inline void link(int u, int v) { insert(u, v); insert(v, u); }
} e;

void dfs(int u, int fa, bool flag) {
    f[u] = val[u];
    for (int i = e.fst[u], v; ~i; i = e.nxt[i]) {
        v = e.to[i];
        if (v != fa) { dfs(v, u, flag); f[u] += std::max(f[v], 0ll); }
    }
    if (flag) {
        if (f[u] == ans) { sum += ans; cnt++; f[u] = -1e18; }
    } else { ans = std::max(ans, f[u]); }
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) { val[i] = read(); }
    for (int i = 2; i <= n; i++) { e.link(read(), read()); }
    dfs(1, 0, false); dfs(1, 0, true); printf("%lld %d\n", sum, cnt);
    return 0;
}