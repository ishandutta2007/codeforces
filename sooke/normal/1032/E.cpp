#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

const int maxN = 105;

int n, ans = 1, max, tot, sum, a[maxN], cnt[maxN], f[2][maxN][maxN * maxN];

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; cnt[a[i]]++; max = std::max(max, a[i]); sum += a[i]; }
    for (int i = 1; i <= max; i++) { tot += cnt[i] > 0; }
    if (tot == 2) { std::cout << n << std::endl; return 0; }
    memset(f[0], 128, sizeof(f[0])); f[0][0][0] = 0;
    for (int i = 1; i <= max; i++) {
        memcpy(f[1], f[0], sizeof(f[1]));
        for (int j = 1; j <= cnt[i]; j++) {
            for (int k = j; k <= n; k++) {
                for (int l = i * j; l <= sum; l++) { f[0][k][l] = std::max(f[0][k][l], f[1][k - j][l - i * j] + 1); }
            }
        }
    }
    for (int i = 1; i <= max; i++) {
        for (int j = 1; j <= cnt[i]; j++) {
            if (f[0][j][i * j] == 1) { ans = std::max(ans, j); }
        }
    }
    printf("%d\n", ans);
    return 0;
} //