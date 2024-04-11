#include <bits/stdc++.h>

inline long long read() {
    char c, _c; long long x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, ans;
long long gcd;

int main() {
    n = read();
    for (int i = 0; i < n; i++) { gcd = std::__gcd(gcd, read()); }
    for (long long i = 1; i * i <= gcd; i++) {
        if (gcd % i == 0) {
            ans++;
            if (i * i != gcd) { ans++; }
        }
    } printf("%d\n", ans);
    return 0;
}