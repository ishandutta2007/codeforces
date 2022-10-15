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

int t, n, k;
std::string str;

int main() {
    for (std::cin >> t; t; t--) {
        std::cin >> n >> str; k = n;
        for (int i = 0; i < n; i++) {
            if (str[i] == '8') { k = i; break; }
        }
        std::cout << (n - k >= 11 ? "YES" : "NO") << std::endl;
    }
    return 0;
}