#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    // (0, 1e9]
    int l = 0, r = 1e9;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int v = mid;
        int sum = 0;
        while (v > 0) {
            sum += v;
            v /= k;
        }
        if (sum >= n) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << endl;
}