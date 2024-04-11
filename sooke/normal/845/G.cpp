#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

typedef long long lol;

inline lol read() {
    char c = getchar(); lol n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 200005, maxE = 400005;

int n, m;
lol sum[maxN], base[64];
bool vis[maxN];

struct List {
    int len, fst[maxN], nxt[maxE], v[maxE]; lol w[maxE];
    
    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int vv, lol ww) { v[len] = vv, w[len] = ww, nxt[len] = fst[u], fst[u] = len++; }
    inline void connect(int u, int vv, lol ww) { insert(u, vv, ww), insert(vv, u, ww); }
} ls;

inline void modify(lol x) { for (int i = 59; ~i; i--) { if (x & (1ll << i)) { if (base[i]) { x ^= base[i]; } else { base[i] = x; break; } } } }
inline lol query(lol x) { for (int i = 59; ~i; i--) { if (x > (x ^ base[i])) { x ^= base[i]; } } return x; }

void dfs(int u, int fa) {
    vis[u] = true;
    for (int i = ls.fst[u]; ~i; i = ls.nxt[i]) {
        int v = ls.v[i]; lol w = ls.w[i];
        if (v != fa) {
            if (vis[v]) { modify(sum[u] ^ sum[v] ^ w); } else { sum[v] = sum[u] ^ w; dfs(v, u); }
        }
    }
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= m; i++) { int u = read(), v = read(); ls.connect(u, v, read()); }
    dfs(1, 0); printf("%lld\n", query(sum[n]));
    return 0;
}