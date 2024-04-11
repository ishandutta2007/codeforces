#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        int l = 0, r = n - 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                l = i;
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                r = i;
                break;
            }
        }
        cout << r - l + 1 << '\n';
    }
}