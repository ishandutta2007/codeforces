#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int l = 1, r = 2e9 + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int cnt = 0;
        for (int i = n / 2; i < n; i++) {
            if (a[i] < mid) {
                cnt += mid - a[i];
            }
        }
        if (cnt <= k) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
}