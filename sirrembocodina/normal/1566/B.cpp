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
        int z = 0;
        int lz = -1, rz = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                continue;
            }
            z++;
            if (lz == -1) {
                lz = i;
            }
            rz = i;
        }
        if (z == 0) {
            cout << 0 << '\n';
            continue;
        }
        if (rz - lz + 1 == z) {
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
        }
    }
    return 0;
}