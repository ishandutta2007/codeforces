#include <bits/stdc++.h>

const int N = 1e5 + 5;

int n, a[N], f[N];

int main() {
    std::cin >> n;
    for (int i = 1; i < n; i++) {
        std::cout << "? " << i << " " << n << std::endl;
        std::cin >> f[i];
    }
    std::cout << "? "  << 1 << " " << n - 1 << std::endl;
    std::cin >> f[0];
    for (int i = 1; i < n - 1; i++) {
        a[i] = f[i] - f[i + 1];
    }
    a[n] = f[1] - f[0];
    a[n - 1] = f[n - 1] - a[n];
    std::cout << "!";
    for (int i = 1; i <= n; i++) {
        std::cout << " " << a[i];
    }
    std::cout << std::endl;
    return 0;
}