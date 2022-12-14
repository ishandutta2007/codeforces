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

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)
#define int long long
const int N = 105, mod = 0;

int dp[N][N], odp[N][N], cost[N][N], a[N];

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    memset(dp, 63, sizeof dp);
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> cost[i][j];
            if (a[i])
                cost[i][j] = 0;
        }
    for (int i = 0; i < n; ++i) {
        memcpy(odp, dp, sizeof dp);
        memset(dp, 63, sizeof dp);
        for (int lcol = 0; lcol <= m; ++lcol) {
            for (int ccol = 1; ccol <= m; ++ccol) if (!a[i] || ccol == a[i]) {
                for (int seg = 0; seg <= k; ++seg) {
                    if (seg - (lcol != ccol) >= 0)
                        dp[ccol][seg] = min(odp[lcol][seg - (lcol != ccol)] + cost[i][ccol], dp[ccol][seg]);
                }
            }
        }
    }
    long long res = 1e18;
    for (int i = 1; i <= m; ++i)
        res = min(res, dp[i][k]);
    cout << (res >= 1e18 - 1? -1: res) << '\n';




}