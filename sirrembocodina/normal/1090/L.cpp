#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t, n, a, b, k;
    cin >> t >> n >> a >> b >> k;
    int l = 0, r = t + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (min(a, mid) * ((n + 1) / 2) + min(b, mid) * (n / 2) >= mid * k) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
}