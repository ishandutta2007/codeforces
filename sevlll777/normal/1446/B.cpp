#include <bits/stdc++.h>

#define pb push_back
// #define int long long
#define ld long double
using namespace std;
int dp[5005][5005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    a = '-' + a;
    b = '?' + b;
    vector<vector<int>> IA(26), IB(26);
    for (int i = 1; i <= n; i++) {
        IA[a[i] - 'a'].pb(i);
    }
    for (int i = 1; i <= m; i++) {
        IB[b[i] - 'a'].pb(i);
    }
    vector<int> last(26, -1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int ke = 0;
            if (a[i] == b[j]) {
                ke = max(ke, 2 + dp[i - 1][j - 1]);
            } else {
                ke = max(ke, dp[i - 1][j - 1] - 2);
            }
            int ind = (int) (upper_bound(IB[a[i] - 'a'].begin(), IB[a[i] - 'a'].end(), j) - IB[a[i] - 'a'].begin() -
                             1);
            if (0 <= ind && ind < IB[a[i] - 'a'].size()) {
                int jg = IB[a[i] - 'a'][ind];
                ke = max(ke, dp[i - 1][jg - 1] + 2 - (j - jg));
            }
            int jg = last[b[j] - 'a'];
            if (0 < jg) {
                ke = max(ke, dp[jg - 1][j - 1] + 2 - (i - jg));
            }
            dp[i][j] = ke;
        }
        last[a[i] - 'a'] = i;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
}