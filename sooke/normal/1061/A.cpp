#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

int n, s, ans;

int main() {
    std::cin >> n >> s;
    for (int i = n; i >= 1; i--) { ans += s / i; s -= s / i * i; }
    std::cout << ans << std::endl;
    return 0;
} //