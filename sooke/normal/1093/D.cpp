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

inline int read() {
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 300005, maxE = maxN << 1, p = 998244353;

inline int power(int x, int y) { int res = 1; for (; y; y >>= 1, x = 1ll * x * x % p) { if (y & 1) { res = 1ll * res * x % p; } } return res; }

int n, m, vis[maxN];
long long x, y;
bool flag;

struct List {
    int len, fst[maxN], nxt[maxE], v[maxE];
    
    inline void reset() { len = 0; memset(fst, -1, sizeof(int) * (n + 1)); }
    inline void insert(int u, int vv) { v[len] = vv, nxt[len] = fst[u], fst[u] = len++; }
    inline void connect(int u, int vv) { insert(u, vv), insert(vv, u); }
} ls;

void dfs(int u, int col) {
    if (vis[u] == -1) { vis[u] = col; } else {
        if (vis[u] != col) { flag = true; } return;
    }
    if (col) { x++; } else { y++; }
    for (int i = ls.fst[u]; ~i; i = ls.nxt[i]) { dfs(ls.v[i], !col); }
}

int solve() {
    long long ans = 1;
    memset(vis, -1, sizeof(int) * (n + 1));
    for (int i = 1; i <= n; i++) {
        if (vis[i] == -1) {
            flag = false; x = 0; y = 0; dfs(i, 0);
            if (flag) { return 0; }
            ans = ans * (power(2, x) + power(2, y)) % p;
        }
    }
    return ans;
}

int main() {
    for (int tn = read(); tn; tn--) {
        n = read(); m = read(); ls.reset();
        for (int i = 1; i <= m; i++) { ls.connect(read(), read()); }
        printf("%d\n", solve());
    }
    return 0;
}