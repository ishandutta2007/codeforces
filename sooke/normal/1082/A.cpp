#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

int t, n, x, y, d;
long long ans;

int main() {
    for (std::cin >> t; t; t--) {
        std::cin >> n >> x >> y >> d; ans = 1e18;
        if (std::abs(x - y) % d == 0) { ans = std::min(ans, 0ll + std::abs(x - y) / d); }
        if (std::abs(y - 1) % d == 0 && x != 1) { ans = std::min(ans, 0ll + std::abs(y - 1) / d + (x - 2) / d + 1); }
        if (std::abs(n - y) % d == 0 && x != n) { ans = std::min(ans, 0ll + std::abs(n - y) / d + (n - x - 1) / d + 1); }
        std::cout << (ans == 1e18 ? -1 : ans) << std::endl;
    }
    return 0;
} //