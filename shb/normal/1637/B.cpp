#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int>a(n + 1);
        vector<vector<int>> mex(n + 1, vector<int>(n + 1)), dp(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            set<int> s;
            for (int j = i; j <= n; j++) {
                s.insert(a[j]);
                mex[i][j] = 0;
                while(s.find(mex[i][j]) != s.end()) mex[i][j]++;
            }
        }
        /*
        for (int i = 1; i <= n; i++) {
            dp[i][i] = 1 + mex[i][i];
        }
        */
        LL ans = 0;
        for (int len = 1; len <= n; len++) {
            for (int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1;
                dp[i][j] = mex[i][j] + 1;
                for (int k = i; k < j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
                ans += dp[i][j];
            }
        }
        cout << ans << endl;
    }
}