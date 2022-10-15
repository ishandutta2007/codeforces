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

const int maxN = 105;

int n, m, k, p, a[maxN], cnt[maxN];

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; cnt[a[i]]++; }
    for (int i = 1; i <= 100; i++) { p += cnt[i] > 0; k = std::max(k, (cnt[i] - 1) / m + 1); }
    printf("%d\n", p * k * m - n);
    return 0;
}