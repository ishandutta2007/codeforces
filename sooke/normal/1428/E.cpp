#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, k, a[N], b[N];
long long ans;
std::priority_queue<std::pair<long long, int>> que;

inline long long calc(int x, int y) {
    return 1ll * (x / y + 1) * (x / y + 1) * (x % y) + 1ll * (x / y) * (x / y) * (y - x % y);
}

int main() {
    n = read(); k = read(); k -= n;
    for (int i = 0; i < n; i++) {
        a[i] = read(); b[i] = 1;
        if (b[i] < a[i]) {
            que.push({calc(a[i], 1) - calc(a[i], 2), i});
        }
        ans += 1ll * a[i] * a[i];
    }
    for (int i = 0; i < k; i++) {
        int u = que.top().second;
        ans -= que.top().first;
        que.pop();
        b[u]++;
        if (b[u] < a[u]) {
            que.push({calc(a[u], b[u]) - calc(a[u], b[u] + 1), u});
        }
    }
    printf("%lld\n", ans);
    return 0;
}