#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int ans = s.size();
        vector<int> cnt(10, 0);
        for (auto ch : s) cnt[ch - '0']++;
        for (auto elem : cnt) ans = min(ans, (int)s.size() - elem);
        for (int c1 = 0; c1 < 10; ++c1) {
            for (int c2 = c1 + 1; c2 < 10; ++c2) {
                int dp1 = 0, dp2 = 0;
                for (auto ch : s) {
                    int d = ch - '0';
                    if (d == c2) {
                        dp2 = max(dp2, dp1 + 1);
                    }
                    if (d == c1) {
                        dp1 = max(dp1, dp2 + 1);
                    }
                }
                int len = max(dp1, dp2);
                if (len % 2 == 1) len--;
                ans = min(ans, (int)s.size() - len);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}