#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

typedef long long lol;

inline int read() {
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 200005, maxE = maxN << 1;

int n, dep[maxN];
lol ans, siz[maxN], cnt[maxN];

struct List {
    int len, fst[maxN], nxt[maxE], v[maxE];
    
    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int vv) { v[len] = vv, nxt[len] = fst[u], fst[u] = len++; }
    inline void connect(int u, int vv) { insert(u, vv), insert(vv, u); }
} ls;

void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1, cnt[dep[u] & 1]++, siz[u] = 1;
    for (int i = ls.fst[u]; ~i; i = ls.nxt[i]) {
        int v = ls.v[i];
        if (v != fa) {
            dfs(v, u);
            siz[u] += siz[v];
        }
    }
    ans += siz[u] * (n - siz[u]);
}

int main() {
    n = read();
    for (int i = 2; i <= n; i++) { int u = read(), v = read(); ls.connect(u, v); }
    dfs(1, 0); printf("%I64d\n", (ans + cnt[0] * cnt[1]) >> 1);
    return 0;
}

// Sooke