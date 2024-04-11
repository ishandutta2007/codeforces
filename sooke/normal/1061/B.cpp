#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

const int maxN = 100005;

int n, m, lst, a[maxN];
long long sum;

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; sum += a[i]; }
    std::sort(a + 1, a + n + 1); lst = a[n];
    for (int i = n; i >= 2; i--) {
        a[i] = std::max(a[i], 1); a[i - 1] = std::min(a[i - 1], a[i] - 1);
        sum -= a[i] - a[i - 1];
    }
    std::cout << sum - std::max(a[1], 1) << std::endl;
    return 0;
} //