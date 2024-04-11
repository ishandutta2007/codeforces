#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 500 + 13;
const int LOGN = 10;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

/*
4
1 2 3 4
1
1 5
*/

void solve() {
    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();


    for(int k = 0; k <= t.size(); k++) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -INF));
        dp[0][0] = 0;

//        cout << k << endl;

        for(int i = 0; i < n; i++) {
//            cout << "i " << i << endl;
            for(int j = 0; j <= k; j++) if(dp[i][j] > -INF) {
                if(j < k && s[i] == t[j]) {
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
                }

                if(dp[i][j] + k < m && s[i] == t[k + dp[i][j]]) {
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + 1);
                }

                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            }
        }

//        cout << k << ' ' << dp[n][k] << endl;
//        for(int i = 0; i <= n; i++) {
//            cout << "i = " << i << "   ";
//            for(int j = 0; j <= k; j++)
//                cout << dp[i][j] << ' ';
//            cout << endl;
//        }
//        cout << endl;

        if(dp[n][k] + k == m) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}