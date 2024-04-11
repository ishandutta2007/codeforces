#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> l(n, -1), r(n, -1);
        int cur = 0;
        l[0] = -1;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[cur]) {
                continue;
            }
            r[cur] = i - 1;
            l[i] = i - 1;
            cur = i;
        }
        r[cur] = 2e9;
        while (q--) {
            int i, k;
            cin >> i >> k;
            i--;
            int L = max(l[i], int64_t(0));
            int R = min(r[i], k);
            if (L >= R) {
                cout << "0\n";
            } else {
                cout << R - L << '\n';
            }
        }
    }
}