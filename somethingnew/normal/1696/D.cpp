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
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<pair<int, int>>> binup(n, vector<pair<int, int>>(20)), bindown = binup;
    vector<int> lftup(n), lftdwn(n);
    for (int i = 0; i < n; ++i) {
        lftup[i] = i - 1;
        while (lftup[i] != -1 and a[lftup[i]] < a[i])
            lftup[i] = lftup[lftup[i]];
        lftdwn[i] = i - 1;
        while (lftdwn[i] != -1 and a[lftdwn[i]] > a[i])
            lftdwn[i] = lftdwn[lftdwn[i]];
    }
    vector<int> dp(n);
    dp[0] = 0;
    binup[0].assign(20, {-1, 0});
    bindown[0].assign(20, {-1, 0});

    for (int i = 1; i < n; ++i) {
        int val = 1e9;
        int lup = lftup[i], ldw = lftdwn[i];
        if (lftdwn[i] > lup) {
            int v = lftdwn[i];
            //cerr << v << ' ';
            for (int k = 19; k >= 0; --k) {
                if (bindown[v][k].first > lup) {
                    val = min(val, bindown[v][k].second);
                    v = bindown[v][k].first;
                }
            }
            //cerr << v << "Dwn" << lup << '\n';
            val = min(val, dp[v]);
        }
        if (lftup[i] > ldw) {
            int v = lftup[i];
            for (int k = 19; k >= 0; --k) {
                if (binup[v][k].first > ldw) {
                    val = min(val, binup[v][k].second);
                    v = binup[v][k].first;
                }
            }
            //cerr << v << "Up" << ldw << '\n';
            val = min(val, dp[v]);
        }
        dp[i] = val + 1;
        //cerr << dp[i] << endl;
        binup[i][0] = {lftup[i], dp[i]};
        bindown[i][0] = {lftdwn[i], dp[i]};
        for (int j = 1; j < 20; ++j) {
            if (binup[i][j-1].first == -1)
                binup[i][j] = {-1, 1e9};
            else
                binup[i][j] = {binup[binup[i][j-1].first][j-1].first, min(binup[binup[i][j-1].first][j-1].second, binup[i][j-1].second)};
            if (bindown[i][j-1].first == -1)
                bindown[i][j] = {-1, 1e9};
            else
                bindown[i][j] = {bindown[bindown[i][j-1].first][j-1].first, min(bindown[bindown[i][j-1].first][j-1].second, bindown[i][j-1].second)};
        }
    }
    cout << dp.back() << '\n';
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