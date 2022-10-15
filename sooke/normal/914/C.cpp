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

const int maxN = 1005, p = 1e9 + 7;

int n, m, k, ans, f[maxN], c[maxN][maxN];
std::string s;

int main() {
    std::cin >> s >> k; n = 1000; m = s.size(); reverse(s.begin(), s.end()); s = " " + s;
    if (k == 0) { printf("1\n"); return 0; } f[1] = 0;
    for (int i = 2; i <= n; i++) { f[i] = f[__builtin_popcount(i)] + 1; }
    for (int i = 0; i <= n; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) { c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % p; }
    }
    for (int i = 1; i <= n; i++) {
        if (f[i] == k - 1) {
            int now = 0;
            for (int j = m; j; j--) {
                if (s[j] == '1') {
                    if (i - now >= 0) { ans = (ans + c[j - 1][i - now]) % p; }
                    now++;
                }
            }
            if (i == now) { ans = (ans + 1) % p; }
        }
    }
    printf("%d\n", k == 1 ? (ans - 1 + p) % p : ans);
    return 0;
} ///