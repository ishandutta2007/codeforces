#include <bits/stdc++.h>

long long n, m, p, x;

int main() {
    std::cin >> n >> p;
    for (long long i = 1; i <= 1000000; i++) {
        m = n - i * p;
        if (m <= 0) { continue; }
        x = __builtin_popcountll(m);
        if (x <= i && i <= m) { std::cout << i; return 0; }
    }
    std::cout << -1;
    return 0;
}