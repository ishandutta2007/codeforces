#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        s = '-' + s + '-';
        int g = 1;
        vector<int> J;
        for (int i = 2; i <= n; i++) {
            if (s[i] == s[i - 1]) {
                g++;
            } else {
                J.pb(g);
                g = 1;
            }
        }
        J.pb(g);
        int B = 0, lel = 0;
        int ans = 0;
        while (B < J.size()) {
            while (lel < J.size() && J[lel] <= 1) {
                lel++;
            }
            if (lel < J.size()) {
                J[lel]--;
            } else {
                J.pop_back();
            }
            B++;
            lel = max(lel, B);
            ans++;
        }
        cout << ans << '\n';
    }
}