#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

int n, p, k;
long long ans;
std::map<int, int> f;

int main() {
    n = read(); p = read(); k = read();
    for (int i = 1, x, y; i <= n; i++) {
        x = read(); y = 1ll * x * x % p * x % p * x % p;
        ans += f[(1ll * k * x + p - y) % p]; f[(1ll * k * x + p - y) % p]++;
    }
    printf("%I64d\n", ans);
    return 0;
}