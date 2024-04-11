#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, m, ans = 1, a[N], p[N];
long long sum;
std::vector<int> b;

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read(); p[a[i]] = i;
    }
    for (int i = n; i >= n - m + 1; i--) {
        b.push_back(p[i]); sum += i;
    }
    std::sort(b.begin(), b.end());
    for (int i = 1; i < b.size(); i++) {
        ans = 1ll * ans * (b[i] - b[i - 1]) % 998244353;
    }
    printf("%lld %d\n", sum, ans);
    return 0;
}