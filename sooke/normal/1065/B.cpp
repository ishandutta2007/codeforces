#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

long long n, m;

int main() {
    std::cin >> n >> m;
    std::cout << std::max(0ll, n - m * 2) << " ";
    for (int i = n; ~i; i--) {
        if (1ll * (n - i) * (n - i - 1) / 2 >= m) { std::cout << i << std::endl; break; }
    }
    return 0;
} ////