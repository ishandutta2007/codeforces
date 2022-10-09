#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(0);
    string digits[10] = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    reverse(s.begin(), s.end());
    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1));
    dp[0][0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            if (!dp[i][j]) {
                continue;
            }
            for (int d = 0; d < 10; d++) {
                bool ok = true;
                int cnt = 0;
                for (int l = 0; l < 7; l++) {
                    if (digits[d][l] == '0' && s[i][l] == '1') {
                        ok = false;
                        break;
                    }
                    if (digits[d][l] == '1' && s[i][l] == '0') {
                        cnt++;
                    }
                }
                if (!ok || j + cnt > k) {
                    continue;
                }
                dp[i + 1][j + cnt] = true;
            }
        }
    }
    if (!dp[n][k]) {
        cout << -1;
        return 0;
    }
    vector<int> ans(n);
    int rem = k;
    for (int i = n - 1; i >= 0; i--) {
        for (int d = 9; d >= 0; d--) {
            bool ok = true;
            int cnt = 0;
            for (int l = 0; l < 7; l++) {
                if (digits[d][l] == '0' && s[i][l] == '1') {
                    ok = false;
                    break;
                }
                if (digits[d][l] == '1' && s[i][l] == '0') {
                    cnt++;
                }
            }
            if (!ok || cnt > rem || !dp[i][rem - cnt]) {
                continue;
            }
            ans[i] = d;
            rem -= cnt;
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; i++) {
        cout << ans[i];
    }
}