#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

long long n, m;

int main() {
    std::cin >> n >> m; m++;
    for (int i = 1; i <= n; i++) {
        int t; std::cin >> t; m -= t + 1;
    }
    std::cout << (m == 0 ? "YES" : "NO");
    return 0;
} ///