#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 8e5 + 5;

int n, m;
char ans[N];
bool used[N];
std::vector<std::pair<int, int>> e[N];
std::vector<std::pair<int, int>>::iterator it[N];

void dfs(int u) {
    while (it[u] != e[u].end()) {
        int v = it[u]->first, i = it[u]->second; it[u]++;
        if (used[i]) { continue; }
        used[i] = true;
        ans[i] = u <= 2e5 ? 'r' : 'b';
        dfs(v);
    }
}

int main() {
    n = read(); m = n;
    for (int i = 0; i < n; i++) {
        int u = read(), v = read(); v += 2e5;
        e[u].push_back({v, i}); e[v].push_back({u, i});
    }
    for (int u = 0; u <= 4e5; u++) {
        if (e[u].size() & 1) {
            e[u].push_back({0, m}); e[0].push_back({u, m++});
        }
    }
    for (int u = 0; u <= 4e5; u++) { it[u] = e[u].begin(); }
    for (int u = 0; u <= 4e5; u++) { dfs(u); }
    for (int i = 0; i < n; i++) {
        putchar(ans[i]);
    }
    return 0;
}