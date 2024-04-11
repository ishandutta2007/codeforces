#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, cnt[2];
std::vector<int> e[N];

void dfs(int u, int fa, int c) {
    cnt[c]++;
    for (auto v : e[u]) {
        if (v == fa) { continue; }
        dfs(v, u, c ^ 1);
    }
}

int main() {
    n = read();
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0, 0);
    printf("%d\n", std::min(cnt[0], cnt[1]) - 1);
    return 0;
}