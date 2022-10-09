#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int mx = 'a';
        int l = -1, r = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] <= mx) {
                continue;
            }
            int cur = s[i] - mx;
            if (k >= cur) {
                k -= cur;
                mx = s[i];
                continue;
            }
            r = s[i];
            l = r - k;
            k = 0;
            break;
        }
        for (int i = 0; i < n; i++) {
            if (s[i] <= mx) {
                cout << 'a';
            } else if (l <= s[i] && s[i] <= r) {
                cout << char(l);
            } else {
                cout << s[i];
            }
        }
        cout << '\n';
    }
}