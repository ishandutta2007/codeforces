#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sum(k);
        for (int i = 0; i < k; i++) {
            cin >> sum[i];
        }
        vector<int> dif;
        for (int i = 0; i + 1 < k; i++) {
            dif.push_back(sum[i + 1] - sum[i]);
        }
        bool ok = true;
        for (int i = 0; i + 1 < dif.size(); i++) {
            if (dif[i] > dif[i + 1]) {
                ok = false;
            }
        }
        if (!ok) {
            cout << "No\n";
            continue;
        }
        int lim = 2e9;
        if (dif.size()) {
            lim = dif[0];
        }
        cout << ((n - k + 1) * lim < sum[0] ? "No\n" : "Yes\n");
    }
}