#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int inf = 1e8;
const int N = 1e6 + 5;

int n, rt, a[N], f[N], d[N];
std::vector<int> e[N];

void dfs1(int u, int fa, int c) {
    d[u] = d[fa] + (a[u] != 0 && c != a[u]);
    if (a[u] != 0 && d[rt] <= d[u]) { rt = u; }
    for (auto v : e[u]) {
        if (v == fa) { continue; }
        dfs1(v, u, a[u] != 0 ? a[u] : c);
    }
}
void dfs2(int u, int fa) {
    if (a[u] == 0) { a[u] = a[fa]; }
    f[u] = 1;
    for (auto v : e[u]) {
        if (v == fa) { continue; }
        dfs2(v, u);
        f[u] = std::max(f[u], f[v] + (a[u] != a[v]));
    }
}

int main() {
    for (int T = read(); T; T--) {
        n = read();
        for (int u = 1; u <= n; u++) {
            a[u] = read(); e[u].clear();
        }
        for (int i = 1; i < n; i++) {
            int u = read(), v = read();
            e[u].push_back(v); e[v].push_back(u);
        }
        rt = 0;
        for (int u = 1; u <= n; u++) {
            if (a[u] != 0) { dfs1(u, 0, a[u]); break; }
        }
        if (rt == 0) { printf("1\n"); continue; }
        dfs2(rt, 0); printf("%d\n", f[rt] / 2 + 1);
    }
    return 0;
}