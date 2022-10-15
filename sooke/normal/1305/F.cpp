#include <bits/stdc++.h>
 
inline long long read() {
    char c; long long x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}
 
const int N = 1e6 + 5;
 
int n, m;
long long ans, a[N];
 
void solve(long long x) {
    long long res = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < x) { res += x - a[i]; continue; }
        long long y = a[i] % x;
        res += std::min(y, x - y);
    }
    ans = std::min(ans, res);
}
 
void check(long long x) {
    if (x < 1) { return; }
    for (int i = 2; i <= 1000000; i++) {
        if (x % i == 0) {
            while (x % i == 0) { x /= i; }
            solve(i);
        }
    }
    if (x > 1) { solve(x); }
}
 
int main() {
    srand(23);
    n = read(); ans = n;
    for (int i = 0; i < n; i++) { a[i] = read(); }
    for (int i = 0; i < n; i++) { std::swap(a[rand() % n], a[i]); }
    for (int i = 0; i < n; i++) { std::swap(a[rand() % n], a[i]); }
    for (int i = 0; i < n; i++) { std::swap(a[rand() % n], a[i]); }
    std::random_shuffle(a, a + n);
    m = std::min(n, 25);
    std::random_shuffle(a, a + n);
    for (int i = 0; i < m; i++) { check(a[i]); }
    std::random_shuffle(a, a + n);
    for (int i = 0; i < m; i++) { check(a[i] - 1); }
    std::random_shuffle(a, a + n);
    for (int i = 0; i < m; i++) { check(a[i] + 1); }
    printf("%lld\n", ans);
    return 0;
}