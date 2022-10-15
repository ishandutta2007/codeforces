#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

int d, a[3];

int main() {
    std::cin >> a[0] >> a[1] >> a[2] >> d;
    std::sort(a, a + 3);
    std::cout << std::max(0, a[0] - (a[1] - d)) + std::max(0, (a[1] + d) - a[2]) << std::endl;
    return 0;
}