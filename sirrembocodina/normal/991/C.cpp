#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    // (0, 1e18]
    int l = 0, r = 1e18;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int rem = n;
        int sum = 0;
        while (rem > 0) {
            sum += min(mid, rem);
            rem -= min(mid, rem);
            rem -= rem / 10;
        }
        if (2 * sum >= n) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << endl;
}