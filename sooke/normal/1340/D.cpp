#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 2e5 + 5;

int n, m, deg[N];
std::vector<int> e[N];
std::vector<std::pair<int, int>> ans;

void dfs(int u, int fa, int p) {
    int base = p;
    ans.push_back({u, p});
    int son = u == 1 ? deg[u] : deg[u] - 1;
    int need = 0;
    if (p == m && u > 1) {
        p = base - (son - need) - 1;
        ans.push_back({u, p});
    }
    for (auto v : e[u]) {
        if (v == fa) { continue; }
        p++; need++;
        dfs(v, u, p);
        ans.push_back({u, p});
        if (p == m && u > 1) {
            p = base - (son - need) - 1;
            ans.push_back({u, p});
        }
    }
    if (u > 1) {
        if (p != base - 1) {
            p = base - 1;
            ans.push_back({u, p});
        }
    }
}

int main() {
    n = read();
    if (n == 1) { printf("1\n1 0\n"); return 0; }
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        e[u].push_back(v); deg[u]++;
        e[v].push_back(u); deg[v]++;
    }
    m = *std::max_element(deg + 1, deg + n + 1);
    dfs(1, 0, 0);
    printf("%d\n", ans.size());
    for (auto i : ans) { printf("%d %d\n", i.first, i.second); }
    return 0;
}