#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
int mod = 998244353;

void pls(int &a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
}
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(8, vector<int>(8)));
    vector<int> typee = {0, 1, 2, 4, 4, 2, 1, 0};
    for (int i = 0; i < 8; ++i) {
        dp[0][typee[i]][i] = 1;
    }
    for (int i = 0; i + 1 < n; ++i) {
        int notpnum = 7;
        if (s[i + 1] == '1')
            notpnum = 0;
        int pnum = 7 - notpnum;
        for (int j = 0; j < 8; ++j) {
            for (int k = 0; k < 8; ++k) {
                if (dp[i][j][k] == 0)
                    continue;
                for (int t = 0; t < 8; ++t) {
                    if (k & t & notpnum) {
                        //cout << k << ' ' << t << '\n';
                        continue;
                    }
                    if (pnum == 7)
                        pls(dp[i + 1][j | typee[t]][k & (pnum & (7 - t))],  dp[i][j][k]);
                    else
                        pls(dp[i + 1][j | typee[t]][k],  dp[i][j][k]);
                }
            }
        }
    }
    int res = 0;
    for (int i = 0; i < 8; ++i) {
        pls(res, dp[n-1][7][i]);
    }
    cout << res;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}