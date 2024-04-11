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

int T, n, s, t;

int main() {
    for (std::cin >> T; T; T--) {
        std::cin >> n >> s >> t;
        std::cout << n - std::min(s, t) + 1 << std::endl;
    }
    return 0;
}