#include <bits/stdc++.h>

int q;
long long n, m, sx, sy, tx, ty, gcd;

bool check() {
    long long u, v;
    if (sx == 0) {
        u = sy / (n / gcd);
    } else {
        u = sy / (m / gcd);
    }
    if (tx == 0) {
        v = ty / (n / gcd);
    } else {
        v = ty / (m / gcd);
    }
    return u == v;
}

int main() {
    std::cin >> n >> m >> q;
    gcd = std::__gcd(n, m);
    for (int i = 0; i < q; i++) {
        std::cin >> sx >> sy >> tx >> ty; sx--; sy--; tx--; ty--;
        std::cout << (check() ? "YES" : "NO") << std::endl;
    }
    return 0;
}