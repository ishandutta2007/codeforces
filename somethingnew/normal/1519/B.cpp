#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#include "queue"
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;
void upd(pair<int, int> &a, pair<int, int> b, int c) {
    if (a.first == -1)
        a.first = b.first + c;
    a.first = min(a.first, b.first + c);
    a.second = max(a.second, b.second + c);
}
void solve(){
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(m, {-1, 0}));
    dp[0][0].first = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i + 1 != n) {
                upd(dp[i+1][j], dp[i][j], j + 1);
            }
            if (j + 1 != m) {
                upd(dp[i][j + 1], dp[i][j], i + 1);
            }
        }
    }
    if (dp[n-1][m-1].first <= x and x <= dp[n-1][m-1].second){
        cout << "Yes\n";
    }else {
        cout << "No\n";
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}