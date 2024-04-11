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

int n, l = 0, r = 1e9, mid;
std::string s, t;

int main() {
    std::cin >> n;
    std::cout << "500000000" << " " << 0 << std::endl;
    std::cin >> t;
    for (int i = 1; i < n; i++) {
        mid = l + r >> 1;
        std::cout << "500000000" << " " << mid << std::endl;
        std::cin >> s;
        if (s == t) { l = mid; } else { r = mid; }
    }
    std::cout << "0 " << l << " 1000000000 " << r << std::endl;
    return 0;
}