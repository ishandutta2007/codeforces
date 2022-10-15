#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, m, a[N], cnt[N];
bool used[N];
std::vector<int> ans, e[N], p[N];

bool check() {
    for (int i = 1; i <= n; i++) {
        for (auto u : p[i]) {
            used[u] = true;
            ans.push_back(u);
            int mex = 1;
            for (auto v : e[u]) {
                if (used[v]) { cnt[a[v]]++; }
            }
            for (; cnt[mex] > 0; mex++);
            if (i != mex) { return false; }
            for (auto v : e[u]) {
                if (used[v]) { cnt[a[v]]--; }
            }
        }
    }
    return true;
}

int main() {
    n = read(); m = read();
    for (int i = 0; i < m; i++) {
        int u = read(), v = read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int u = 1; u <= n; u++) {
        a[u] = read();
        p[a[u]].push_back(u);
    }
    if (check()) {
        for (auto u : ans) {
            printf("%d ", u);
        }
    } else {
        printf("-1\n");
    }
    return 0;
}