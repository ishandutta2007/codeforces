#include <bits/stdc++.h>
using namespace std;

#define ll long long

int dp[202][202][202];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, kk;
    string s, t;
    cin >> n >> kk >> s >> t;
    for (int i = 0; i < 202; i++) for (int j = 0; j < 202; j++) for (int k = 0; k < 202; k++) dp[i][j][k] = -1e9;
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= i; k++) {
                if (dp[i][j][k] == -1e9) continue;
                set<char> st;
                st.insert(s[i]);
                st.insert(t[0]);
                st.insert(t[1]);
                for (auto c : st) {
                    int jj = j;
                    if (c == t[0]) jj++;
                    int dpp = dp[i][j][k];
                    if (c == t[1]) dpp += j;
                    int kkk = k;
                    if (c != s[i]) kkk++;
                    dp[i + 1][jj][kkk] = max(dp[i + 1][jj][kkk], dpp);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= kk; j++) ans = max(ans, dp[n][i][j]);
    }
    cout << ans;
    return 0;
}