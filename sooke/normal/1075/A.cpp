#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

long long n, a, b;

int main() {
    std::cin >> n >> a >> b;
    if (std::max(std::abs(a - 1), std::abs(b - 1)) <= std::max(std::abs(n - a), std::abs(n - b))) { std::cout << "White"; } else { std::cout << "Black"; }
    return 0;
} //