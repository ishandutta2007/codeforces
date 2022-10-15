#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 2e5 + 5;

int n, _n, cr, gg, k, f[N], siz[N], ss[N], ft[N];
std::vector<std::pair<int, int>> e[N];
bool vis[N];

void fail() {
    puts("NO"); exit(0);
}

void findCore(int u, int fa) {
    siz[u] = 1; ss[u] = 0;
    int tmp = u != fa;
    for (auto i : e[u]) {
        int v = i.first, w = i.second;
        if (v != fa && !vis[w]) {
            findCore(v, u);
            siz[u] += siz[v];
            ss[u] = std::max(ss[u], siz[v]);
        }
    }
    ss[u] = std::max(ss[u], _n - siz[u]);
    if (cr == -1 || ss[cr] > ss[u]) { cr = u; }
}
int getCore(int u, int n) {
    _n = n; cr = -1;
    findCore(u, u);
    return cr;
}

void dfs(int u, int fa) {
    siz[u] = 1;
    for (auto i : e[u]) {
        int v = i.first, w = i.second;
        if (v != fa && !vis[w]) {
            ft[v] = w;
            dfs(v, u);
            siz[u] += siz[v];
        }
    }
}
void find(int u, int fa) {
    if (siz[u] == f[k - 1] || siz[u] == f[k - 2]) {
        gg = u;
    }
    for (auto i : e[u]) {
        int v = i.first, w = i.second;
        if (v != fa && !vis[w]) {
            find(v, u);
        }
    }
}

void solve(int u, int n) {
    if (n == 1) { return; }
    k = std::lower_bound(f, f + 28, n) - f;
    if (f[k] != n) { fail(); }
    int cr = getCore(u, n);
    for (auto i : e[cr]) {
        int v = i.first, w = i.second;
        if (vis[w]) { continue; }
        ft[v] = w;
        dfs(v, cr);
    }
    gg = -1;
    for (auto i : e[cr]) {
        int v = i.first, w = i.second;
        if (vis[w]) { continue; }
        find(v, cr);
        if (gg != -1) { break; }
    }
    if (gg == -1) { fail(); }
    int x = siz[gg], _cr = cr, _k = k;
    vis[ft[gg]] = true;
    if (x == f[_k - 1]) {
        solve(gg, f[_k - 1]);
        solve(_cr, f[_k - 2]);
    } else {
        solve(gg, f[_k - 2]);
        solve(_cr, f[_k - 1]);
    }
}

int main() {
    n = read(); f[0] = 1; f[1] = 1;
    for (int i = 2; i <= 27; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        e[u].push_back({v, i});
        e[v].push_back({u, i});
    }
    for (int u = 1; u <= n; u++) {
        if (e[u].size() > 27) { fail(); }
    }
    solve(1, n);
    puts("YES");
    return 0;
}