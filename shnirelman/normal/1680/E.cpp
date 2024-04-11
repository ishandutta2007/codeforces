#include <bits/stdc++.h>

using namespace std;
using li = long long;

const int INF = 1e9 + 13;
const int N = 3013;

vector<vector<int>> get(int n, string s1, string s2) {
    vector<vector<int>> dp(n + 1, vector<int>(3, INF));\
    dp[0][0] = 0;
    for(int i = 0; i < n; i++) {
        if(s1[i] == '.' && s2[i] == '.') {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = dp[i][1] + 1;
            dp[i + 1][2] = dp[i][2] + 1;
        } else if(s1[i] == '.' && s2[i] == '*') {
            dp[i + 1][1] = min({dp[i][1] + 2, dp[i][2] + 2, dp[i][0] + 1});
            dp[i + 1][2] = min({dp[i][1] + 2, dp[i][2] + 1, dp[i][0]});
        } else if(s1[i] == '*' && s2[i] == '.') {
            dp[i + 1][1] = min({dp[i][1] + 1, dp[i][2] + 2, dp[i][0]});
            dp[i + 1][2] = min({dp[i][1] + 2, dp[i][2] + 2, dp[i][0] + 1});
        } else {
            dp[i + 1][1] = min({dp[i][1] + 2, dp[i][2] + 2, dp[i][0] + 1});
            dp[i + 1][2] = min({dp[i][1] + 2, dp[i][2] + 2, dp[i][0] + 1});
        }
//        cout << "get dp " << i + 1 << ' ' << dp[i + 1][0] << ' ' << dp[i + 1][1] << ' ' << dp[i + 1][2] << endl;
    }

    return dp;
}

void solve() {
    int n;
    cin >> n;

    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<int>> pr = get(n, s1, s2);
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    vector<vector<int>> suf = get(n, s1, s2);
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

//    for(int i = 0; i <= n; i++) {
//        cout << "pr " << i << ' ' << pr[i][0] << ' ' << pr[i][1] << ' ' << pr[i][2] << endl;
//    }
//    for(int i = 0; i <= n; i++) {
//        cout << "suf " << i << ' ' << suf[i][0] << ' ' << suf[i][1] << ' ' << suf[i][2] << endl;
//    }

    int ans = min(pr[n][1], pr[n][2]);
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 3; j++) if(pr[i][j] < INF)
            for(int k = 0; k < 3; k++) if(suf[n - i][k] < INF) {
                int res = pr[i][j] + suf[n - i][k] + (j > 0 && k > 0) + (j > 0 && k > 0 && j != k);
//                cout << i << ' ' << j << ' ' << k << ' ' << res << endl;
                ans = min(ans, res);
            }
//            ans = min(ans, pr[i][j] + suf[n - i][j]);
    }

    cout << ans << endl;
}

int main() {
    int t = 1;
    cin >> t;

    while(t--)
        solve();
}