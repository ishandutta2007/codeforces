#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

int a, b, c, ans = 1e9;

int main() {
    std::cin >> a >> b >> c;
    if (a + 1 <= b && a + 2 <= c) { ans = std::min(ans, a * 3 + 3); }
    if (b - 1 <= a && b + 1 <= c) { ans = std::min(ans, b * 3); }
    if (c - 2 <= a && c - 1 <= b) { ans = std::min(ans, c * 3 - 3); }
    std::cout << ans;
    return 0;
} //