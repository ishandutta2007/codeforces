#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

const int maxN = 2005;

int n, a[maxN];

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }
    std::cout << n + 1 << std::endl;
    std::cout << 2 << " " << n << " " << 1 << std::endl;
    std::cout << 1 << " " << n << " " << 1000000 << std::endl;
    for (int i = 1; i < n; i++) { std::cout << 2 << " " << i << " " << 1000000 - i << std::endl; }
    return 0;
} //