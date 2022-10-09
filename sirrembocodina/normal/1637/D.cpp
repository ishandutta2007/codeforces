#include <bits/stdc++.h>
#define int long long

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - a.second) > abs(b.first - b.second);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i].second;
        }
        sort(a.begin(), a.end(), cmp);

        vector<vector<bool>> dp(n + 1, vector<bool>(200 * n));
        dp[0][0] = true;
        for (int i = 0; i < n; i++) {
            int w = 100 + a[i].first - a[i].second;
            for (int j = 0; j + w < 200 * n; j++) {
                if (dp[i][j]) {
                    dp[i + 1][j + w] = true;
                }
            }
            w = 100 - a[i].first + a[i].second;
            for (int j = 0; j + w < 200 * n; j++) {
                if (dp[i][j]) {
                    dp[i + 1][j + w] = true;
                }
            }
        }

        int s = 0;
        for (int i = 0; i < 200 * n; i++) {
            if (dp[n][i] && abs(s - 100 * n) > abs(i - 100 * n)) {
                s = i;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            int w = 100 + a[i].first - a[i].second;
            if (s >= w && dp[i][s - w]) {
                s -= w;
                continue;
            }
            swap(a[i].first, a[i].second);
            w = 100 + a[i].first - a[i].second;
            s -= w;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                ans += (a[i].first + a[j].first) * (a[i].first + a[j].first);
                ans += (a[i].second + a[j].second) * (a[i].second + a[j].second);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}