#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

long long n, m, t, x, y, ans;

int main() {
    std::cin >> n >> m >> x >> y;
    if (m == 1) { std::cout << (n - 1) * x << std::endl; return 0; }
    while (true) {
        t = n / m * m;
        if (t == 0) { ans += (n - 1) * x; break; }
        ans += std::min((n - (t / m)) * x, (n - t) * x + y); n = t / m;
    }
    std::cout << ans << std::endl;
    return 0;
} //