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
    std::cout << (n * 2 - 1) / m + (n * 5 - 1) / m + (n * 8 - 1) / m + 3;
    return 0;
} //