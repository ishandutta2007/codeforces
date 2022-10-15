#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 2e5 + 5;

int n, ans, l[N], r[N], w[N];
std::vector<int> e[N];

void dfs(int u) {
    long long sum = 0;
    for (auto v : e[u]) {
        dfs(v);
        sum += w[v];
    }
    if (sum >= r[u]) {
        w[u] = r[u];
    } else if (sum >= l[u]) {
        w[u] = sum;
    } else {
        w[u] = r[u]; ans++;
    }
}

int main() {
    for (int T = read(); T; T--) {
        n = read();
        for (int u = 1; u <= n; u++) {
            e[u].clear();
        }
        for (int u = 2; u <= n; u++) {
            int v = read();
            e[v].push_back(u);
        }
        for (int u = 1; u <= n; u++) {
            l[u] = read(); r[u] = read();
        }
        ans = 0;
        dfs(1);
        printf("%d\n", ans);
    }
    return 0;
}