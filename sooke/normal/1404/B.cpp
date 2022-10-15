#include <bits/stdc++.h>
 
inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}
 
const int N = 1e6 + 5;
 
int n, s, t, ds, dt, ft[N], hs[N], dep[N], siz[N], top[N];
std::vector<int> e[N];
 
void dfs1(int u, int fa) {
    ft[u] = fa; dep[u] = dep[fa] + 1; siz[u] = 1; hs[u] = 0;
    for (auto v : e[u]) {
        if (v != fa) {
            dfs1(v, u); siz[u] += siz[v];
            if (siz[hs[u]] < siz[v]) { hs[u] = v; }
        }
    }
}
void dfs2(int u, int tp) {
    top[u] = tp;
    if (hs[u]) { dfs2(hs[u], tp); }
    for (auto v : e[u]) {
        if (v != ft[u] && v != hs[u]) { dfs2(v, v); }
    }
}
 
int findLca(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] > dep[top[v]]) {
            u = ft[top[u]];
        } else {
            v = ft[top[v]];
        }
    }
    return dep[u] < dep[v] ? u : v;
}
 
inline int getDis(int u, int v) {
    return dep[u] + dep[v] - dep[findLca(u, v)] * 2;
}
 
bool check() {
    if (getDis(s, t) <= ds || ds * 2 >= dt) { return true; }
    int a = 1, b = 1;
    for (int u = 1; u <= n; u++) {
        if (getDis(a, b) < getDis(a, u) && getDis(b, u) < getDis(a, u)) {
            b = u;
        } else if (getDis(a, b) < getDis(b, u) && getDis(b, u) >= getDis(a, u)) {
            a = u;
        }
    }
    return getDis(a, b) <= ds * 2;
}
 
int main() {
    for (int T = read(); T; T--) {
        n = read(); s = read(); t = read(); ds = read(); dt = read();
        for (int u = 1; u <= n; u++) {
            e[u].clear();
        }
        for (int i = 1; i < n; i++) {
            int u = read(), v = read();
            e[u].push_back(v); e[v].push_back(u);
        }
        dfs1(1, 0); dfs2(1, 1);
        printf("%s\n", check() ? "Alice" : "Bob");
    }    
    return 0;
}