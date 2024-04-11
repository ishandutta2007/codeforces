#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

typedef long long lol;

const int maxN = 1005;

int n, m;
lol ans, cnt[maxN];

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) { cnt[i * i % m] += n / m; }
    for (int i = n / m * m + 1; i <= n; i++) { cnt[1ll * i * i % m]++; }
    for (int i = 0; i < m; i++) { ans += cnt[i] * cnt[i ? m - i : 0]; }
    std::cout << ans << std::endl;
    return 0;
} ///