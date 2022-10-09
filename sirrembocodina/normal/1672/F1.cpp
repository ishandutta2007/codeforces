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

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<pair<int, int>> cnt(n + 1);
        for (int i = 0; i <= n; i++) {
            cnt[i].second = i;
        }
        vector<vector<int>> where(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
            cnt[a[i]].first++;
            where[a[i]].push_back(i);
        }
        sort(cnt.rbegin(), cnt.rend());
        vector<int> p(n);
        int cur = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < cnt[i + 1].first; j++) {
                p[where[cnt[i].second][j]] = where[cnt[i + 1].second][j];
            }
            for (int j = cnt[i + 1].first; j < cnt[i].first; j++) {
                p[where[cnt[i].second][j]] = where[cnt[0].second][cur++];
            }
        }
        for (int i = 0; i < n; i++) {
            cout << a[p[i]] + 1 << ' ';
        }
        cout << '\n';
    }
}