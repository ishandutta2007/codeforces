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
        int n;
        cin >> n;
        vector<int> tp(n);
        for (int i = 0; i < n; i++) {
            cin >> tp[i];
        }
        vector<int> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        vector<int> a, b;
        for (int i = 0; i < n; i++) {
            if (tp[i]) {
                b.push_back(x[i]);
            } else {
                a.push_back(x[i]);
            }
        }
        if (a.size() == b.size()) {
            int sum = 0, mn = 2e18;
            for (int i = 0; i < n; i++) {
                sum += x[i];
                mn = min(mn, x[i]);
            }
            cout << 2 * sum - mn << '\n';
            continue;
        }
        if (a.size() > b.size()) {
            swap(a, b);
        }
        int sum = 0;
        for (int i = 0; i < a.size(); i++) {
            sum += 2 * a[i];
        }
        for (int i = 0; i < b.size(); i++) {
            sum += b[i];
        }
        sort(b.rbegin(), b.rend());
        for (int i = 0; i < a.size(); i++) {
            sum += b[i];
        }
        cout << sum << '\n';
    }
}