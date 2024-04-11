#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e7 + 5, M = 3e5 + 5;

int n, a[M], cnt[N];
long long ans, res, f[50][2];
int tot, son[N][2];

int main() {
    n = read();
    tot = 1;
    for (int i = 0; i < n; i++) {
        int x = a[i] = read();
        int u = 1;
        for (int d = 30; d >= 0; d--) {
            int y = x >> d & 1;
            if (son[u][y] == 0) { son[u][y] = ++tot; }
            f[d][y] += cnt[son[u][y ^ 1]];
            u = son[u][y]; cnt[u]++;
        }
    }
    for (int d = 30; d >= 0; d--) {
        ans += std::min(f[d][0], f[d][1]);
        if (f[d][0] <= f[d][1]) {
            
        } else {
            res |= 1ll << d;
        }
    }
    printf("%lld %lld\n", ans, res);
    return 0;
}