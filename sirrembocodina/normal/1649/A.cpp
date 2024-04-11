#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int f = -1, l = -1;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 0) {
                l = i;
                if (f == -1) {
                    f = i;
                }
            }
        }
        if (f == -1) {
            cout << 0 << '\n';
        } else {
            cout << l - f + 2 << '\n';
        }
    }
}