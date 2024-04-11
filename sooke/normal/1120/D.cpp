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
    char c = getchar(); int x = 0; bool sgn = false;
    while (c < '0' || c > '9') { if (c == '-') { sgn = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return sgn ? -x : x;
}

const int maxN = 200005;

int n, val[maxN], a[maxN], b[maxN], c[maxN], t[maxN];
long long f[maxN], g[maxN];
std::vector<int> ans;
bool vis[maxN][2];

struct List {
    int tot, fst[maxN], nxt[maxN << 1], to[maxN << 1];

    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int v) { nxt[tot] = fst[u]; to[tot] = v; fst[u] = tot++; }
    inline void link(int u, int v) { insert(u, v); insert(v, u); }
} e;

void dfs(int u, int fa) {
    g[u] = 1e18;
    bool isLeaf = true;
    for (int i = e.fst[u], v; ~i; i = e.nxt[i]) {
        v = e.to[i];
        if (v != fa) {
            dfs(v, u);
            f[u] += f[v];
            isLeaf = false;
        }
    }
    for (int i = e.fst[u], v; ~i; i = e.nxt[i]) {
        v = e.to[i];
        if (v != fa) {
            if (g[u] > f[u] - f[v] + g[v]) {
                g[u] = f[u] - f[v] + g[v];
                b[v] = ++c[u]; t[u] = 1;
            } else if (g[u] == f[u] - f[v] + g[v]) {
                b[v] = c[u]; t[u]++;
            }
        }
    }
    if (isLeaf) { a[u] = u; f[u] = val[u]; g[u] = 0; }
    else {
        if (f[u] > g[u] + val[u]) {
            f[u] = g[u] + val[u];
            a[u] = u;
        } else if (f[u] == g[u] + val[u]) {
            a[u] = -1;
        }
    }
}

void getAns(int u, int fa, int x) {
    if (vis[u][x]) { return; } vis[u][x] = true;
    if (x == 0) {
        if (a[u] != 0) {
            ans.push_back(u); getAns(u, fa, 1);
        }
        if (a[u] <= 0) {
            for (int i = e.fst[u], v; ~i; i = e.nxt[i]) {
                v = e.to[i];
                if (v != fa) {
                    getAns(v, u, 0);
                }
            }
        }
    } else {
        for (int i = e.fst[u], v; ~i; i = e.nxt[i]) {
            v = e.to[i];
            if (v != fa) {
                if (t[u] == 1) { getAns(v, u, b[v] == c[u]); } else {
                    if (b[v] == c[u]) { getAns(v, u, 1); }
                    getAns(v, u, 0);
                }
            }
        }
    }
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) { val[i] = read(); }
    for (int i = 2; i <= n; i++) { e.link(read(), read()); }
    dfs(1, 0); getAns(1, 1, 0); printf("%I64d %d\n", f[1], (int) ans.size());
    std::sort(ans.begin(), ans.end());
    for (std::vector<int>::iterator it = ans.begin(); it != ans.end(); it++) { printf("%d ", *it); }
    return 0;
} //