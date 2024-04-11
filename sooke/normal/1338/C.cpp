#include <bits/stdc++.h>

inline long long read() {
    char c; long long x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

long long get(long long n, long long x, long long y, long long z) {
    long long m = 1, now = 4;
    for (; n >= now; n -= now, now *= 4, m++);
    long long ans = 0, bit = 1;
    for (int i = 0; i < m; i++, n /= 4, bit *= 4) {
        if (n % 4 == 1) { ans += bit * x; }
        if (n % 4 == 2) { ans += bit * y; }
        if (n % 4 == 3) { ans += bit * z; }
    }
    ans += bit * x;
    return ans;
}

long long solve(long long n) {
    if (n == 1) { return 1; }
    if (n == 2) { return 2; }
    if (n == 3) { return 3; }
    n -= 4;
    if (n % 3 == 0) { return get(n / 3, 1, 2, 3); } 
    if (n % 3 == 1) { return get(n / 3, 2, 3, 1); }
    if (n % 3 == 2) { return get(n / 3, 3, 1, 2); }
}

int main() {
    for (int T = read(); T; T--) {
        long long n = read();
        printf("%lld\n", solve(n));
    }
    return 0;
}