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
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;

const int M = 9, N = 1e6 + 6, mod = (int) 9;
int dp[M][M], odp[M][M];
int cnt[N];
int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int j = 0; j < n; ++j) {
        int x;
        cin >> x;
        ++cnt[--x];
    }
    memset(dp, -63, sizeof dp);
    dp[0][0] = 0;
    for (int j = 0; j < m; ++j) {
        memcpy(odp, dp, sizeof dp);
        memset(dp, -63, sizeof dp);
        for (int xl = 0; xl < M; ++xl)
            for (int xr = 0; xr < M; ++xr) {
               for (int cur_rem = cnt[j] % 3; cur_rem < min(cnt[j] + 1, M); cur_rem += 3) {
                    int mn = min(xl, xr);
                    mn = min(mn, cur_rem);
                    for (int pick = max(0, mn - 3); pick <= mn; ++pick) {
                        int add = (cnt[j] - cur_rem) / 3;
                        dp[xr - pick][cur_rem - pick] = max(dp[xr - pick][cur_rem - pick], add + pick + odp[xl][xr]);
                    }
               }
            }
    }
    int res = 0;
    for (int xl = 0; xl < M; ++xl)
        for (int xr = 0; xr < M; ++xr)
            res = max(res, dp[xl][xr]);
    cout << res << endl;


}