#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, ft[N], dep[N];
std::vector<int> seq, ans, e[N];

void dfs1(int u) {
    dep[u] = 1;
    if (e[u].empty()) { return; }
    int w = 0;
    for (int i = 0; i < e[u].size(); i++) {
        int v = e[u][i]; dfs1(v);
        if (dep[u] < dep[v] + 1) { dep[u] = dep[v] + 1; w = i; }
    }
    std::swap(e[u][e[u].size() - 1], e[u][w]);
}

void dfs2(int u) {
    seq.push_back(u);
    for (auto v : e[u]) {
        for (int w = seq.back(); w != u; w = ft[w]) { ans.push_back(v); }
        dfs2(v);
    }
}

int main() {
    n = read();
    for (int u = 1; u < n; u++) { ft[u] = read(); e[ft[u]].push_back(u); }
    dfs1(0); dfs2(0);
    for (auto u : seq) { printf("%d ", u); }
    printf("\n%d\n", ans.size());
    for (auto u : ans) { printf("%d ", u); }
    return 0;
}