//        
//   @roadfromroi 
//        
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
int dpdp[20][300050][4];
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> nb(20);
    vector<int> a(n);
    vector<vector<int>> numa(n, vector<int>(20));
    vector<int> dp(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        int xrb = i ^ a[i];
        int msk = 0;
        for (int j = 30; j >= 0; --j) {
            if (j < 20) {
                numa[i][j] = msk;
                nb[j].push_back(msk);
            }
            msk += xrb & (1 << j);
        }
    }
    for (int j = 0; j < 20; ++j) {
        sort(all(nb[j]));
        nb[j].erase(unique(all(nb[j])), nb[j].end());
        for (int i = 0; i < nb[j].size(); ++i) {
            for (int k = 0; k < 4; ++k) {
                dpdp[j][i][k] = 0;
            }
        }
        for (int i = 0; i < n; ++i) {
            numa[i][j] = lower_bound(all(nb[j]), numa[i][j]) - nb[j].begin();
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 19; j >= 0; --j) {
            int t1 = (bool(a[i] & (1 << j))), t2 = (bool(i & (1 << j)));
            for (int y1 = 0; y1 < 2; ++y1) {
                for (int vl1 = 0; vl1 < 2; ++vl1) {
                    if ((t1 ^ y1) > (vl1 ^ t2)) {
                        dp[i] = max(dp[i], 1 + dpdp[j][numa[i][j]][y1 * 2 + vl1]);
                        //cout << i << ' ' << j << ' ' << y1 * 2 + vl1 << ' ' << numa[i][j] << ' ' << dp[i] << endl;
                    }
                }
            }
        }
        for (int j = 19; j >= 0; --j) {
            //cerr << i << ' ' << j << ' ' << numa[i][j] << ' ' << (bool(i & (1 << j))) * 2 + (bool(a[i] & (1 << j))) << ' ' << dp[i] << endl;
            dpdp[j][numa[i][j]][(bool(i & (1 << j))) * 2 + (bool(a[i] & (1 << j)))] = max(dpdp[j][numa[i][j]][(bool(i & (1 << j))) * 2 + (bool(a[i] & (1 << j)))], dp[i]);
        }
        res = max(res, dp[i]);
    }
    cout << res << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}