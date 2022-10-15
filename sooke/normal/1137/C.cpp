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
    char c = getchar(); int x = 0;
    while (c < '0' || c > '9') { c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return x;
}
inline bool readBool() {
    char c = getchar();
    while (c != '0' && c != '1') { c = getchar(); }
    return c & 15;
}

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

const int maxN = 100005, maxK = 55;

int n, m, k, ts, gc, vol, l = 1, r, ans, a[maxK][maxN], b[maxK][maxN], dfn[maxN], low[maxN], stack[maxN], col[maxN];
int h[maxN], dis[maxN], deg[maxN], q[maxN], f[maxK][maxN], g[maxK][maxN];
bool ins[maxN], vis[maxN];

struct List {
    int tot, fst[maxN], nxt[maxN], to[maxN], val[maxN];

    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int v, int w) { nxt[tot] = fst[u]; to[tot] = v; val[tot] = w; fst[u] = tot++; }
} e, et;

void tarjan(int u) {
    dfn[u] = low[u] = ++ts; stack[++vol] = u;
    int tmp = vol; ins[u] = true;
    for (int i = e.fst[u], v; ~i; i = e.nxt[i]) {
        v = e.to[i];
        if (!dfn[v]) {
            tarjan(v);
            low[u] = std::min(low[u], low[v]);
        } else if (ins[v]) {
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        for (int i = tmp; i <= vol; i++) {
            col[stack[i]] = u;
            ins[stack[i]] = false;
        }
        vol = tmp - 1;
    }
}

void dfs1(int u, int fa, int c, int x) {
    if (col[u] != c) { return; }
    if (dis[u] == -1) { dis[u] = x; } else { gc = gcd(gc, dis[u] - x); return; }
    for (int i = e.fst[u], v; ~i; i = e.nxt[i]) {
        v = e.to[i];
        if (u != fa) { dfs1(v, u, c, x + 1); }
    }
}
void dfs2(int u, int fa, int c) {
    if (col[u] != c || vis[u]) { return; } vis[u] = true;
    for (int i = 0; i < gc; i++) {
        for (int j = i; j <= k; j += gc) {
            if (a[j][u]) { b[((i - dis[u]) % gc + k) % gc][c]++; break; }
        }
    }
    for (int i = e.fst[u], v; ~i; i = e.nxt[i]) {
        v = e.to[i];
        if (u != fa) { dfs2(v, u, c); }
    }
}

int main() {
    n = read(); m = read(); k = read();
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read();
        e.insert(u, v, 0);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) { a[j][i] = readBool(); }
    }
    for (int i = 1; i <= n; i++) { if (!dfn[i]) { tarjan(i); } }
    memset(dis, -1, sizeof(dis));
    for (int i = 1; i <= n; i++) {
        if (col[i] == i) {
            gc = k; dfs1(i, 0, i, 0);
            h[i] = gc = std::abs(gc); dfs2(i, 0, i);
            for (int j = gc; j < k; j++) { b[j][i] = b[j - gc][i]; }
        }
    }
    for (int i = 1, u, v; i <= n; i++) {
        u = col[i];
        for (int j = e.fst[i]; ~j; j = e.nxt[j]) {
            v = col[e.to[j]];
            if (u != v) { et.insert(u, v, ((dis[i] - dis[e.to[j]] + 1) % k + k) % k); deg[v]++; }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (col[i] == i && !deg[i]) { q[++r] = i; }
    }
    memset(f, 128, sizeof(f)); memset(g, 128, sizeof(g)); f[0][col[1]] = 0;
    for (int u, v, w; l <= r; l++) {
        u = q[l];
        for (int i = 0; i < k; i++) { f[i][u] += b[i][u]; g[i % h[u]][u] = std::max(g[i % h[u]][u], f[i][u]); }
        for (int i = 0; i < k; i++) { f[i][u] = g[i % h[u]][u]; ans = std::max(ans, f[i][u]); }
        for (int i = et.fst[u]; ~i; i = et.nxt[i]) {
            v = et.to[i]; w = et.val[i]; deg[v]--;
            for (int j = 0; j < k; j++) { f[(j + w) % k][v] = std::max(f[((j + w) % k + k) % k][v], f[j][u]); }
            if (!deg[v]) { q[++r] = v; }
        }
    }
    printf("%d\n", ans);
    return 0;
} //