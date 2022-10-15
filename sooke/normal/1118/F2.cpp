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
    char c = getchar(); int x = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return f ? -x : x;
}

const int maxN = 600005, p = 998244353;

inline int add(int x, int y) { x += y; return x >= p ? x - p : x; }

int n, m, ans, col[maxN], fth[maxN], dep[maxN], siz[maxN], hson[maxN], top[maxN], lca[maxN], f[2][maxN];
std::vector<int> e[maxN];
bool flag, rt[maxN];

void dfs1(int u, int fa) {
    fth[u] = fa; dep[u] = dep[fa] + 1; siz[u] = 1;
    for (std::vector<int>::iterator it = e[u].begin(); it != e[u].end(); it++) {
        int v = *it;
        if (v != fa) {
            dfs1(v, u); siz[v] += siz[u];
            if (siz[hson[u]] < siz[v]) { hson[u] = v; }
        }
    }
}
void dfs2(int u, int tp) {
    top[u] = tp;
    if (hson[u]) { dfs2(hson[u], tp); }
    for (std::vector<int>::iterator it = e[u].begin(); it != e[u].end(); it++) {
        int v = *it;
        if (v != fth[u] && v != hson[u]) { dfs2(v, v); }
    }
}

int findLca(int u, int v) {
    if (!u) { return v; }
    if (!v) { return u; }
    while (top[u] != top[v]) {
        if (dep[top[u]] > dep[top[v]]) { u = fth[top[u]]; } else { v = fth[top[v]]; }
    }
    return dep[u] < dep[v] ? u : v;
}

void dfs3(int u, int c) {
    if (!col[u]) { col[u] = c; dfs3(fth[u], c); }
    else if (col[u] == c) { return; }
    else { flag = true; return; }
}

void dfs4(int u) {
    std::vector<int> pre, suf; int num = (int) e[u].size() - (u > 1);
    for (std::vector<int>::iterator it = e[u].begin(); it != e[u].end(); it++) {
        int v = *it;
        if (v != fth[u]) {
            dfs4(v);
            pre.push_back(add(f[0][v], f[1][v]));
            suf.push_back(add(f[0][v], f[1][v]));
        }
    }
    for (int i = 1; i < num; i++) { pre[i] = (long long) pre[i - 1] * pre[i] % p; }
    for (int i = num - 2; i >= 0; i--) { suf[i] = (long long) suf[i + 1] * suf[i] % p; }
    f[1][u] = num ? suf[0] : 1;
    for (int j = 0, i = 0; i < num; j++, i++) {
        int v = e[u][j], pr, su;
        if (v != fth[u]) {
            pr = i == 0 ? 1 : pre[i - 1];
            su = i == num - 1 ? 1 : suf[i + 1];
            f[0][u] = add(f[0][u], (long long) pr * su % p * f[0][v] % p);
        } else { i--; }
    }
    if (col[u]) { f[0][u] = f[1][u]; f[1][u] = 0; }
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) { col[i] = read(); }
    for (int i = 2; i <= n; i++) {
        int u = read(), v = read();
        e[u].push_back(v); e[v].push_back(u);
    }
    dfs1(1, 0); dfs2(1, 1);
    for (int i = 1; i <= n; i++) {
        if (col[i]) { lca[col[i]] = findLca(lca[col[i]], i); }
    }
    for (int i = 1; i <= m; i++) {
        rt[lca[i]] = true;
        if (col[lca[i]] && col[lca[i]] != i) { printf("0\n"); return 0; }
        col[lca[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (col[i] && !rt[i]) { dfs3(fth[i], col[i]); }
        if (flag) { printf("0\n"); return 0; }
    }
    dfs4(1);
    printf("%d\n", f[0][1]);
    return 0;
}