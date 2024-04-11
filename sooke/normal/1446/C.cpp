#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5, V = 2e7 + 5;

int n, ans, a[N], tot = 1, son[V][2];

void dfs(int u, int x) {
    if (son[u][0] == 0 && son[u][1] == 0) {
        ans = std::max(ans, x + 1);
        return;
    }
    if (son[u][0] != 0) { dfs(son[u][0], x + (son[u][1] != 0)); }
    if (son[u][1] != 0) { dfs(son[u][1], x + (son[u][0] != 0)); }
}

int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        a[i] = read();
        int u = 1;
        for (int d = 30; d >= 0; d--) {
            int x = a[i] >> d & 1;
            if (son[u][x] == 0) { son[u][x] = ++tot; }
            u = son[u][x];
        }
    }
    dfs(1, 0);
    printf("%d\n", n - ans);
    return 0;
}