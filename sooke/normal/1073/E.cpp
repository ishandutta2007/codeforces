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

typedef long long lol;

const int p = 998244353;

int kk, m, dig[20];
lol l, r, w = 1, s[20], f[20][10][1 << 10], g[20][10][1 << 10], h[20][1 << 10];

void init() {
    f[0][0][0] = 0; g[0][0][0] = 1;
    for (int i = 1; i <= 18; i++) {
        for (int j = 0; j < 1 << 10; j++) {
            h[i][j] = h[i - 1][j];
            for (int k = 0; k <= 9; k++) {
                for (int h = 0; h <= 9; h++) {
                    (f[i][h][j | (1 << h)] += f[i - 1][k][j] + 1ll * w * h % p * g[i - 1][k][j]) %= p;
                    (g[i][h][j | (1 << h)] += g[i - 1][k][j]) %= p;
                }
            }
            for (int k = 1; k <= 9; k++) { (h[i][j] += f[i - 1][k][j]) %= p; }
        }
        s[i] = w; w = (w * 10) % p;
    }
}
lol solve(lol n) {
    if (!n) { return 0; } m = 0;
    for (; n; n /= 10) { dig[++m] = n % 10; }
    int now = 0; lol ans = 0, tmp = 0;
    for (int i = m; i; i--) {
        for (int j = 0; j < 1 << 10; j++) {
            if (__builtin_popcount(j | now) <= kk) {
                for (int k = 0; k < dig[i]; k++) {
                    if (k) {
                        if (!(j & (1 << k))) { continue; }
                    } else {
                        if (i == m) { (ans += h[i][j]) %= p; continue; } else if (!(j & 1)) { continue; }
                    }
                    (ans += f[i][k][j] + g[i][k][j] * tmp % p) %= p;
                }
            }
        }
        now |= 1 << dig[i]; (tmp += s[i] * dig[i]) %= p;
    }
    if (__builtin_popcount(now) <= kk) { (ans += tmp) %= p; }
    return ans;
}

int main() {
    std::cin >> l >> r >> kk;
    init(); std::cout << (solve(r) - solve(l - 1) + p) % p << std::endl;
    return 0;
}