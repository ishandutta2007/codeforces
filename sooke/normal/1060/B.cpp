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

typedef long long lol;

lol n, m;

inline lol solve(lol x) {
    lol sum = 0;
    while (x) { sum += x % 10, x /= 10; }
    return sum;
}

int main() {
    std::cin >> n;
    while ((m * 10 + 9) <= n) { m = m * 10 + 9; }
    std::cout << solve(m) + solve(n - m) << std::endl;
    return 0;
}

// Sooke