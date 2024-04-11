#include <bits/stdc++.h>
 
inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}
 
const int N = 1e6 + 5;
 
int n, m, k, a[N];
long long ans, sum[N];
 
int main() {
    n = read(); m = read(); k = read();
    for (int i = 0; i < n; i++) { a[i] = read(); }
    std::sort(a, a + n);
    for (int i = n - 1; i >= 0; i--) { sum[i] = sum[i + 1] + a[i]; }
    int p = n;
    for (p = 0; p < n; p++) {
        if (a[p] > k) { break; }
    }
    for (int i = 0; i <= n; i++) {
        int q = p + i;
        if (q <= n) {
            long long res = 0;
            long long d = std::max(0ll, (i - 1ll) * m - (n - q));
            if (d > p); else {
                res = sum[n - i] - sum[n] + sum[d] - sum[p];
                ans = std::max(ans, res);
            }
        }
        if (q <= n) {
            long long res = 0;
            long long d = std::max(0ll, (i - 1ll) * m);
            if (d > n - i || d <= p); else {
                res = sum[n - i] - sum[n];
                ans = std::max(ans, res);
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}