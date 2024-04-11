#include <bits/stdc++.h>

long long n, m;

int main() {
    std::cin >> n >> m;
    
    if (n > m) std::swap(n, m);
    
    if (n == 1) {
        std::cout << (m / 6 * 3 + std::max(m % 6 - 3, 0LL)) * 2 << std::endl;
    } else if (n == 2) {
        if (m <= 2) puts("0");
        else if (m == 3) puts("4");
        else if (m == 7) puts("12");
        else std::cout << m * 2 << std::endl;
    } else {
        std::cout << n * m / 2 * 2 << std::endl;
    }
    
    return 0;
}