#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e5 + 5;

int n, m, q, k, h[N], a[N];
long long ans, f[N];

bool check(long long mid) {
    std::priority_queue<std::pair<long long, int>> que;
    for (int i = 0; i < n; i++) {
        f[i] = mid;
        if (f[i] - 1ll * a[i] * m < h[i]) {
            que.push({-(f[i] / a[i]), i});
        }
    }
    for (int s = 1; s <= m; s++) {
        for (int t = 0; t < q; t++) {
            if (que.empty()) { continue; }
            int i = que.top().second;
            que.pop();
            if (f[i] - 1ll * a[i] * s < 0) { return false; }
            f[i] += k;
            if (f[i] - 1ll * a[i] * m < h[i]) {
                que.push({-(f[i] / a[i]), i});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (f[i] - 1ll * a[i] * m < h[i]) { return false; }
    }
    return true;
}

int main() {
    n = read(); m = read(); q = read(); k = read();
    for (int i = 0; i < n; i++) {
        h[i] = read(); a[i] = read();
    }
    for (long long l = 0, r = 2e13, mid; l <= r; ) {
        mid = l + r >> 1;
        if (check(mid)) {
            r = mid - 1; ans = mid;
        } else {
            l = mid + 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}