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

int n;

inline int query(int x) {
    if (x & 1) { return -(x / 2 + 1); } else { return x / 2; }
}

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        int l, r;
        std::cin >> l >> r;
        std::cout << query(r) - query(l - 1) << std::endl;
    }
    return 0;
} //