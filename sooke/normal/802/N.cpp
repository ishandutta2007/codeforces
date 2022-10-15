#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, m, cnt, a[N], b[N];
long long ans, res;

void solve(int k) {
    res = cnt = 0;
    std::priority_queue<std::pair<int, int>> que;
    for (int i = 0; i < n; i++) {
        que.push({a[i] + k, 1});
        long long x = 0ll + b[i] + que.top().first;
        if (x >= 0) {
            cnt += que.top().second;
            res += x;
            que.pop();
            que.push({-b[i], 0});
        }
    }
}

int main() {
    n = read(); m = read();
    for (int i = 0; i < n; i++) { a[i] = -read(); }
    for (int i = 0; i < n; i++) { b[i] = -read(); }
    solve(0);
    for (int l = 0, r = 2e9, mid; l <= r; ) {
        mid = (0ll + l + r) / 2;
        solve(mid);
        if (cnt >= m) {
            r = mid - 1;
            ans = 1ll * m * mid - res;
        } else {
            l = mid + 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}