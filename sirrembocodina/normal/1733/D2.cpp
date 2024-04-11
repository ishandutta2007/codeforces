#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int solve(int n, int x, int y, vector<int>& pos) {
    if (pos.size() % 2) {
        return -1;
    }
    if (pos.size() == 0) {
        return 0;
    }
    vector<vector<int>> dp(pos.size() + 1, vector<int>(pos.size() / 2 + 1, 2e9));
    dp[0][0] = 0;
    dp[1][0] = 0;
    for (int i = 1; i < pos.size(); i++) {
        dp[i + 1][0] = 0;
        for (int j = 1; j < dp[i].size(); j++) {
            dp[i + 1][j] = min(dp[i][j], pos[i] - pos[i - 1] + dp[i - 1][j - 1]);
        }
    }
    int ans = 2e18;
    for (int i = 0; i < dp[pos.size()].size(); i++) {
        ans = min(ans, dp[pos.size()][i] * x + (int(pos.size()) - i * 2) / 2 * y);
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> pos;
        string a, b;
        cin >> a >> b;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                pos.push_back(i);
            }
        }
        if (x < y) {
            cout << solve(n, x, y, pos) << '\n';
            continue;
        }
        if (pos.size() % 2) {
            cout << -1 << '\n';
        } else if (pos.size() == 2 && pos[0] + 1 == pos[1]) {
            cout << min(x, 2 * y) << '\n';
        } else {
            cout << pos.size() / 2 * y << '\n';
        }
    }
}