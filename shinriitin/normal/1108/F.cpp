#include <bits/stdc++.h>

const int max_N = (int) 2e5 + 21;

int n, m, f[max_N], u[max_N], v[max_N], w[max_N], Q[max_N];

int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

int solve(int l, int r) {
    int ret = 0;
    for (int i = l; i < r; ++i) {
        int x = u[Q[i]], y = v[Q[i]];
        if (find(x) != find(y)) ++ret;
    }
    for (int i = l; i < r; ++i) {
        int x = u[Q[i]], y = v[Q[i]];
        if (find(x) != find(y)) {
            --ret;
            f[find(x)] = find(y);
        }
    }
    return ret;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", u + i, v + i, w + i);
        Q[i] = i;
    }
    std::sort(Q + 1, Q + 1 + m, [&] (int x, int y) { return w[x] < w[y]; });
    for (int i = 1; i <= n; ++i) {
        f[i] = i;
    }
    int ans = 0;
    for (int i = 1, j; i <= m; i = j) {
        for (j = i; j <= m && w[Q[i]] == w[Q[j]]; ++j);
        ans += solve(i, j);
    }
    printf("%d\n", ans);
}