#include <bits/stdc++.h>

const int max_N = (int) 4e5 + 21;

int n, m, q, f[max_N], ans = -1;

void merge(int u, int v) {
    auto find = [&](int x) {
        int r = x, y;
        for (; r != f[r]; r = f[r]);
        for (; x != r; y = f[x], f[x] = r, x = y);
        return x;
    };
    u = find(u), v = find(v);
    f[u] = v;
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n + m; ++i) f[i] = i;
    for (int i = 1, u, v; i <= q; ++i) {
        scanf("%d%d", &u, &v);
        merge(u, n + v);
    }
    for (int i = 1; i <= n + m; ++i)
        if (f[i] == i) ++ans;
    printf("%d\n", ans);
    return 0;
}