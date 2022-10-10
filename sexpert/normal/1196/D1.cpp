#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
int dp[MAXN][3];

void solve() {
    int n, k;
    cin >> n >> k;
    string seq = "RGB";
    string s;
    cin >> s;
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for(int i = 0; i < k; i++) {
        if(s[i] != seq[i % 3]) dp[0][0]++;
        if(s[i] != seq[(i + 1) % 3]) dp[0][1]++;
        if(s[i] != seq[(i + 2) % 3]) dp[0][2]++;
    }
    int ans = min({dp[0][0], dp[0][1], dp[0][2]});
    for(int i = 1; i + k <= n; i++) {
        dp[i][0] = dp[i - 1][2] - (s[i - 1] != 'B') + (s[i + k - 1] != seq[(k - 1) % 3]);
        dp[i][1] = dp[i - 1][0] - (s[i - 1] != 'R') + (s[i + k - 1] != seq[(k) % 3]);
        dp[i][2] = dp[i - 1][1] - (s[i - 1] != 'G') + (s[i + k - 1] != seq[(k + 1) % 3]);
        ans = min({ans, dp[i][0], dp[i][1], dp[i][2]});
        //for(int j = 0; j < 3; j++)
        //    cout << "dp(" << i << ", " << j << ") = " << dp[i][j] << '\n';
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