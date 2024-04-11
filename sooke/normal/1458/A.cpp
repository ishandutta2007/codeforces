#include <bits/stdc++.h>

inline long long read() {
    char c; long long x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, m;
long long max, gcd, a[N], b[N];

int main() {
    n = read(); m = read();
    for (int i = 0; i < n; i++) {
        a[i] = read();
    }
    max = *std::max_element(a, a + n);
    for (int i = 0; i < n; i++) {
        gcd = std::__gcd(gcd, max - a[i]);
    }
    for (int i = 0; i < m; i++) {
        b[i] = read();
        printf("%lld ", std::__gcd(gcd, max + b[i]));
    }
    return 0;
}