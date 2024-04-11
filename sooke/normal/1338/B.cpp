#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, rt, ans, deg[N], dep[N];
bool used[2], vis[N];
std::vector<int> e[N];

void dfs(int u, int fa) {
    if (deg[u] == 1) { used[dep[u] & 1] = true; vis[fa == 0 ? e[u][0] : fa] = true; }
    for (auto v : e[u]) {
        if (v == fa) { continue; }
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

int main() {
    n = read();
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        e[u].push_back(v); deg[u]++;
        e[v].push_back(u); deg[v]++;
    }
    ans = n;
    for (int u = 1; u <= n; u++) {
        if (deg[u] == 1) { rt = u; ans--; }
    }
    dfs(rt, 0);
    for (int u = 1; u <= n; u++) {
        if (vis[u]) { ans++; }
    }
    printf("%d ", used[0] && used[1] ? 3 : 1);
    printf("%d\n", ans - 1);
    return 0;
}