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

const int maxN = 200005;

int n, top, a[maxN], pos[maxN];

int main() {
    std::cin >> n; top = n;
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; pos[a[i]] = n + 1 - i; }
    for (int i = 1; i <= n; i++) {
        int t; std::cin >> t;
        printf("%d ", std::max(0, top - pos[t] + 1));
        top = std::min(top, pos[t] - 1);
    }
    return 0;
} //