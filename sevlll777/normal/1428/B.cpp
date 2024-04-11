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
        string s;
        cin >> n >> s;
        bool i1 = false, i2 = false;
        for (auto c : s) {
            i1 |= (c == '>');
            i2 |= (c == '<');
        }
        int ans = 0;
        s += s[0];
        for (int i = 1; i <= n; i++) {
            if (s[i] == '-' || s[i - 1] == '-') {
                ans++;
            } else if (s[i] == s[i - 1] && ((!i1) || (!i2))) {
                ans++;
            }
        }
        cout << ans;
        cout << '\n';
    }

}