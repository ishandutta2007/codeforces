#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> last(26, n);
        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }
        int mn = n;
        for (int i = 0; i < 26; i++) {
            mn = min(mn, last[i]);
        }
        cout << s.substr(mn) << '\n';
    }
    return 0;
}