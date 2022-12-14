// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;
const int N = (int) 1e6 + 6, mod = (int) 1e9 + 7;
int pw(int a, int b) { return b <= 0? 1: pw(a * 1ll * a % mod, b >> 1) * 1ll * (b & 1? a: 1) % mod; }
int f[N], inv[N], comb[N][25], dp[22][N], pr[N];
void sadd(int &x, int y) {
    x += y;
    while (x >= mod)
        x -= mod;
}
int32_t main() {
    for (int j = 0; j < N; ++j)
        for (int i = 0; i < 25; ++i)
            comb[j][i] = (j == i || !i)? 1: (comb[j - 1][i - 1] + comb[j - 1][i]) % mod;
    for (int j = 1; j < N; ++j)
        dp[0][j] = 1;
    for (int j = 2; j < N; ++j) {
        if (pr[j] == 0) {
            for (int i = j; i < N; i += j) {
                pr[i] = 1;
                dp[0][i] <<= 1;
            }
        }
    }
    for (int j = 1; j < 22; ++j) {
        for (int a = 1; a < N; ++a) if (dp[j - 1][a])
            for (int b = a + a; b < N; b += a) {
                sadd(dp[j][b], dp[j - 1][a]);
            }
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int r, n;
        scanf("%d%d", &r, &n);
        int res = 0;
        for (int j = 0; j < 22; ++j) {
            if (j > r) continue;
            int ways = comb[r][j];
            res = (res + ways * 1ll * dp[j][n]) % mod;
        }
        printf("%d\n", res);
    }
}