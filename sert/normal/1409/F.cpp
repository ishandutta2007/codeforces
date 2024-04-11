#include <bits/stdc++.h>
using namespace std;
bool D = false;
const int INF = (int)1e9 + 41;

inline void mxe(int &a, int b) {
    if (b > a) a = b;
}

void solve() {
    int n, k;
    string s, t;
    cin >> n >> k >> s >> t;
    if (t[0] == t[1]) {
        int num = min(n, (int)count(s.begin(), s.end(), t[0]) + k);
        cout << num * (num - 1) / 2 << "\n";
        return;
    }

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -INF)));
    int ans = 0;

    dp[0][0][0] = 0;
    for (int len = 0; len < n; len++) {
        char curC = s[len];
        for (int num0 = 0; num0 < n; num0++) {
            for (int changed = 0; changed <= k; changed++) {
                int curDp = dp[len][num0][changed];
                if (curDp == -INF) continue;

                if (changed < k || curC == t[0])
                    mxe(dp[len + 1][num0 + 1][changed + (int)(curC != t[0])], curDp);
                if (changed < k || curC == t[1])
                    mxe(dp[len + 1][num0][changed + (int)(curC != t[1])], curDp + num0);
                if (curC != t[0] && curC != t[1])
                    mxe(dp[len + 1][num0][changed], curDp);
            }
        }
    }
    for (int num0 = 0; num0 <= n; num0++)
        mxe(ans, *max_element(dp[n][num0].begin(), dp[n][num0].end()));
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
#ifdef SERT
    freopen("a.in", "r", stdin);
    D = true;
    t = 4;
#else

#endif
    while (t--) {
        solve();
    }
}