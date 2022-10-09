#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool ok = false;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            int s = sqrt(x) + 0.5;
            if (s * s != x) {
                ok = true;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}