#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define pb push_back
// #define int long long
#define ld long double
using namespace std;
const int M = 1000000007;
char dp[505][505];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string ss;
        cin >> ss;
        ss = '-' + ss;
        for (int x = 0; x < 505; x++) dp[0][x] = ' ';
        for (int i = 1; i <= n; i++) {
            string u = "", l = "", d = "", rd = "", rl = "", ru = "";
            string hh = "";
            for (int j = 0; j < i - 1; j++) hh += dp[i-1][j];
            u = hh + (char) ('a' + ((ss[i] - 'a') + 1) % k);
            d = hh + (char) ('a' + ((ss[i] - 'a') + k - 1) % k);
            l = hh;
            if (!l.empty()) l.pop_back();
            l += ss[i];
            if (i >= 2) l += dp[i - 1][i - 2];
            if (i == 1) {
                string lol = min({u, l, d});
                for (int j = 0; j < lol.size(); j++) {
                    dp[i][j] = lol[j];
                }
            } else {
                string hh = "";
                for (int j = 0; j < i - 2; j++) hh += dp[i-2][j];
                rd = hh;
                rd += (char) ('a' + ((ss[i] - 'a') + k - 1) % k);
                rd += (char) ('a' + ((ss[i - 1] - 'a')) % k);
                ru = hh;
                ru += (char) ('a' + ((ss[i] - 'a') + 1) % k);
                ru += (char) ('a' + ((ss[i - 1] - 'a')) % k);
                rl = hh;
                if (!rl.empty()) rl.pop_back();
                rl += ss[i];
                if (i > 2) rl += dp[i - 2][i - 3];
                rl += ss[i - 1];
                string lol = min({u, l, d, rl, ru, rd});
                for (int j = 0; j < lol.size(); j++) {
                    dp[i][j] = lol[j];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << dp[n][i];
        }
        cout << '\n';
    }

}