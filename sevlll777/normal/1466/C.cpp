#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (s.size() == 1) {
            cout << "0\n";
        } else {
            int n = (int) s.size();
            s = '0' + s;
            vector<int> dp1(n + 1), dp2(n + 1);
            dp1[1] = 1;
            dp2[1] = 0;
            dp1[2] = 1;
            dp2[2] = (s[1] == s[2]);
            for (int i = 3; i <= n; i++) {
                if (s[i] != s[i - 1] && s[i] != s[i - 2]) {
                    dp1[i] = 1 + min(dp1[i - 1], dp2[i - 1]);
                    dp2[i] = min(dp1[i - 1], dp2[i - 1]);
                } else if (s[i] != s[i - 2]) {
                    dp1[i] = 1 + min(dp1[i - 1], dp2[i - 1]);
                    dp2[i] = dp1[i - 1];
                } else if (s[i] != s[i - 1]) {
                    dp1[i] = 1 + min(dp1[i - 1], dp2[i - 1]);
                    dp2[i] = dp1[i - 2];
                    if (s[i - 1] == s[i - 3]) {
                        dp2[i] = min(dp1[i - 2] + 1, dp1[i - 3] + 1);
                    }
                } else {
                    dp1[i] = 1 + min(dp1[i - 1], dp2[i - 1]);
                    dp2[i] = dp1[i - 2] + 1;
                }
            }
            cout << min(dp1[n], dp2[n]) << '\n';
        }
    }
}