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

int n, m, k;

int main() {
    std::cin >> n >> m >> k;
    std::cout << (n <= m && n <= k ? "Yes" : "No") << std::endl;
    return 0;
}