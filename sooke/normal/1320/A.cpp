#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, a[N], b[N];
long long ans;
std::map<int, long long> f;

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        b[i] = a[i] - i;
        f[b[i]] = f[b[i]] + a[i];
    }
    for (auto x : f) {
        ans = std::max(ans, x.second);
    }
    printf("%lld\n", ans);
    return 0;
}