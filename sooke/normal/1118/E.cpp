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
    std::cin >> m >> n;
    if ((long long) n * (n - 1) < m) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
        for (int i = 1, l = 1, r = 2; i <= m; i++, l++, r = r % n + 1) {
            if (l > n) { l = 1; r++; } printf("%d %d\n", l, r);
        }
    }
    return 0;
}