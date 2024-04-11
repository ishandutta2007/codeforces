#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

const int maxN = 1000005, p = 1e9 + 7;

int n, m, t, ans, f[maxN], d[maxN];

int main() {
    std::cin >> n; f[0] = 1;
    for (int i = 1; i <= n; i++) {
        std::cin >> t; m = 0;
        for (int j = 1; j * j <= t; j++) {
            if (t % j == 0) { d[++m] = j; d[++m] = t / j; }
        }
        std::sort(d + 1, d + m + 1); m = std::unique(d + 1, d + m + 1) - d - 1;
        for (int j = m; j; j--) { f[d[j]] = (f[d[j]] + f[d[j] - 1]) % p; }
    }
    for (int i = 1; i <= n; i++) { ans = (ans + f[i]) % p; }
    std::cout << ans << std::endl;
    return 0;
} //