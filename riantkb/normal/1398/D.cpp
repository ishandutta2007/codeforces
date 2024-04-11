#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
const int M = 1000000007;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int r, g, b;
    cin >> r >> g >> b;
    vector<int> rs(r), gs(g), bs(b);
    for (int i = 0; i < r; ++i) {
        cin >> rs[i];
    }
    for (int i = 0; i < g; ++i) {
        cin >> gs[i];
    }
    for (int i = 0; i < b; ++i) {
        cin >> bs[i];
    }
    sort(rs.begin(), rs.end());
    sort(gs.begin(), gs.end());
    sort(bs.begin(), bs.end());
    reverse(rs.begin(), rs.end());
    reverse(gs.begin(), gs.end());
    reverse(bs.begin(), bs.end());
    vector<vector<vector<long long>>> dp(r + 1, vector<vector<long long>>(g + 1, vector<long long>(b + 1, -(1LL << 60))));
    dp[0][0][0] = 0;
    for (int i = 0; i <= r; ++i) {
        for (int j = 0; j <= g; ++j) {
            for (int k = 0; k <= b; ++k) {
                if (i < r && j < g) {
                    dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + rs[i] * gs[j]);
                }
                if (i < r && k < b) {
                    dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + rs[i] * bs[k]);
                }
                if (j < g && k < b) {
                    dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1], dp[i][j][k] + gs[j] * bs[k]);
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < r + 1; ++i) {
        for (int j = 0; j < g + 1; ++j) {
            for (int k = 0; k < b + 1; ++k) {
                ans = max(ans, dp[i][j][k]);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}