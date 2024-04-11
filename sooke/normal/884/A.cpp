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

int n, m;

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int t; std::cin >> t; m -= 86400 - t;
        if (m <= 0) { std::cout << i << std::endl; return 0; }
    }
    return 0;
} ///