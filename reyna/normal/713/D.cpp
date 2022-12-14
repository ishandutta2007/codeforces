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
const int N = (int) 1005, L = 10, mod = (int) 0;
int dp[N][N], a[N][N], width[N], rmq[L][L][N][N];


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 2; i < N; ++i) width[i] = width[i >> 1] + 1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    for (int i = n - 1; i >= 0; --i)
        for (int j = m - 1; j >= 0; --j)
            if (a[i][j])
                dp[i][j] = min(dp[i + 1][j + 1], min(dp[i][j + 1], dp[i + 1][j])) + 1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            rmq[0][0][i][j] = dp[i][j];
    for (int l = 1; l < L; ++l)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j + (1 << l) <= m; ++j)
                rmq[0][l][i][j] = max(rmq[0][l - 1][i][j], rmq[0][l - 1][i][j + (1 << l - 1)]);
    for (int l = 1; l < L; ++l)
        for (int jl = 0; jl < L; ++jl)
            for (int i = 0; i + (1 << l) <= n; ++i)
                for (int j = 0; j + (1 << jl) <= m; ++j)
                    rmq[l][jl][i][j] = max(rmq[l - 1][jl][i][j], rmq[l - 1][jl][i + (1 << l - 1)][j]);
    int q;
    cin >> q;
    while (q--) {
        int xl, yl, xr, yr;
        cin >> xl >> yl >> xr >> yr;
        if (xl > xr) swap(xl, xr);
        if (yl > yr) swap(yl, yr);
        xl--;
        yl--;
        int bl = 0, br = min(yr - yl, xr - xl) + 1;
        while (bl < br - 1) {
            int bm = bl + br >> 1;
            int nxr = xr - bm + 1;
            int nyr = yr - bm + 1;
            int wx = width[nxr - xl], wy = width[nyr - yl];
            int mx = max(max(rmq[wx][wy][xl][yl], rmq[wx][wy][nxr - (1 << wx)][yl]), max(rmq[wx][wy][xl][nyr - (1 << wy)], rmq[wx][wy][nxr - (1 << wx)][nyr - (1 << wy)]));
            if (mx >= bm)
                bl = bm;
            else
                br = bm;
        }
        cout << bl << '\n';
    }
}