#include <bits/stdc++.h>

inline long long read() {
    char c; long long x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 205;

long long l, r;

long long solve(long long n) {
    long long x = std::sqrt((long double) n);
    for (; x * x > n; x--);
    for (; n > (x + 1) * (x + 1) - 1; x++);
    long long res = x * 3;
    if (x * x + x > n) { res--; }
    if (x * x + x + x > n) { res--; }
    return res;
}

int main() {
    for (int T = read(); T; T--) {
        l = read(); r = read();
        printf("%lld\n", solve(r) - solve(l - 1));
    }
    return 0;
}