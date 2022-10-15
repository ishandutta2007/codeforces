#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

typedef long long lol;

const int maxN = 1000006;

lol n, m, l, r, k, sqrtN, a[maxN];

void solve(lol x) {
    l = 1; r = n + 1 - x; k = (r - l) / x + 1;
    a[++m] = (l + r) * k / 2;
}

int main() {
    std::cin >> n; sqrtN = sqrt(n);
    for (int i = 1; i <= sqrtN; i++) {
        if (n % i == 0) { solve(i); solve(n / i); }
    }
    std::sort(a + 1, a + m + 1); m = std::unique(a + 1, a + m + 1) - a - 1;
    for (int i = 1; i <= m; i++) { printf("%lld ", a[i]); }
    return 0;
}