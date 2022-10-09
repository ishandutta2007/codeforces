#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int q;
    cin >> q;
    while (q--) {
        int c, m, x;
        cin >> c >> m >> x;
        int l = 0, r = 1e8 + 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (mid <= c && mid <= m && mid <= x + c - mid + m - mid) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << l << endl;
    }
}