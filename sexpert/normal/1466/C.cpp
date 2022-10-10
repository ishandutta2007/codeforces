#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10;
const int INF = 1e9 + 10;
int dp[MAXN][2][2];

void solve() {
    string s;
    cin >> s;
    int ans = 0, n = s.size();
    for(int ch = 0; ch < 26; ch++) {
        dp[0][0][0] = 0;
        for(int i = 1; i <= s.size(); i++) {
            char c = s[i - 1];
            dp[i][0][0] = dp[i][1][0] = dp[i][0][1] = dp[i][1][1] = INF;
            for(int p2 = 0; p2 <= 1; p2++) {
                for(int p1 = 0; p1 <= 1; p1++) {
                    int x = dp[i - 1][p2][p1];
                    if(p1 == 0 && p2 == 0) {
                        dp[i][p1][0] = min(dp[i][p1][0], x + ((c - 'a') == ch));
                        dp[i][p1][1] = min(dp[i][p1][1], x + ((c - 'a') != ch));
                    }
                    else
                        dp[i][p1][0] = min(dp[i][p1][0], x + ((c - 'a') == ch));
                }
            }
        }
        ans += min({dp[n][0][0], dp[n][1][0], dp[n][0][1]});
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}