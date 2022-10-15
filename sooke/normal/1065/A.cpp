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

int t, s, a, b, c;

int main() {
    for (std::cin >> t; t; t--) {
        std::cin >> s >> a >> b >> c;
        std::cout << s / c + 1ll * ((s / c) / a) * b << std::endl;
    }
    return 0;
} ////