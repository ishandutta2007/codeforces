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

long long a, b, c, d;

int main() {
    std::cin >> a >> b >> c >> d;
    std::cout << (std::max(a, c) + b + d) * 2 + 4 << std::endl;
    return 0;
} //