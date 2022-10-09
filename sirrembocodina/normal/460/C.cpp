#include <bits/stdc++.h>

using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n, m, w;
    cin >> n >> m >> w;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 1, r = 2e9;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        int cnt = 0;
        vector<int> ends(n);
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur -= ends[i];
            if (a[i] + cur < mid) {
                int new_segs = mid - a[i] - cur;
                cur += new_segs;
                if (i + w < n) {
                    ends[i + w] = new_segs;
                }
                cnt += new_segs;
            }
        }
        if (cnt <= m) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
}