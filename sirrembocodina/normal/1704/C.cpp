#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

struct my_hash {
    inline size_t operator()(const pair<int, int>& a) const {
        return a.first * 31 + a.second;
    }
};

//int mod = 998244353;

int32_t main() {
    srand(time(nullptr));
    ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<int> d;
        for (int i = 0; i < m; i++) {
            int j = (i + 1) % m;
            int cur = (a[j] - a[i] + n - 1) % n;
            if (cur) {
                d.push_back(cur);
                //cerr << cur << endl;
            }
        }
        sort(d.rbegin(), d.rend());
        int ans = 0;
        for (int i = 0; i < d.size(); i++) {
            if (d[i] <= 4 * i) {
                break;
            }
            if (d[i] <= 4 * i + 2) {
                ans++;
                break;
            }
            ans += d[i] - 4 * i - 1;
        }
        cout << n - ans << '\n';
    }
}