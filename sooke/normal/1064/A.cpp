#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

int a[4];

int main() {
    std::cin >> a[1] >> a[2] >> a[3]; std::sort(a + 1, a + 4);
    std::cout << std::max(0, a[3] + 1 - a[1] - a[2]);
    return 0;
}