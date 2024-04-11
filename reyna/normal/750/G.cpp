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
#define int long long
const int N = (int) 60;
int p[N], dp[120][2], odp[120][2];
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    p[0] = 1;
    for (int j = 1; j < N; ++j)
        p[j] = p[j - 1] << 1;
    int s, res = 0;
    cin >> s;
    for (int l = 0; l <= 52; ++l)
        for (int r = 0; r <= 52; ++r) {
            int mod = p[l + 1] + p[r + 1] - 3, mn = p[r] - 1;
            for (int choose = 0; choose <= l + r + 5; ++choose) {
                if (s - mn + choose < mod) continue;
                int len = max(l + 2, r + 2);
                int rem = (s - mn + mod) % mod;
                rem += choose;
                if (rem & 1) continue;
                memset(dp, 0, sizeof dp);
                dp[0][0] = 1;
                for (int j = 1; j <= len; ++j) {
                    for (int a = 0; a <= 1; ++a) for (int k = 0; k <= choose; ++k)
                        odp[k][a] = dp[k][a], dp[k][a] = 0;
                    for (int chose = choose; chose >= 0; --chose) for (int c = 0; c <= 1; ++c) for (int a = 0; a <= (j >= l? 0: 1); ++a)
                        for (int b = 0; b <= (j >= r? 0: 1); ++b) {
                            int nc = (a + b + c) >> 1;
                            int dig = (a + b + c) & 1;
                            if (dig == (rem >> j & 1)) {
                                dp[chose + a + b][nc] += odp[chose][c];
                            }

                        }
                }
                res += dp[choose][0];
            }
        }
    cout << res << endl;
}