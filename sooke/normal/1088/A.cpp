#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

int n;

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i * j > n && i < n * j && i % j == 0) {
                std::cout << i << " " << j << std::endl;
                return 0;
            }
        }
    }
    std::cout << -1;
    return 0;
} //