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
    srand(time(nullptr));
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    string s;
    forn (i, m) {
        s.push_back('0');
    }
    vector<pair<int, int>> e(m);
    for (int i = 0; i < m; i++) {
        s[i] = '1';
        cout << "? " << s << endl;
        int res;
        cin >> res;
        e[i] = {res, i};
        s[i] = '0';
    }
    sort(e.begin(), e.end());
    s[e[0].second] = '1';
    int ans = e[0].first;
    for (int i = 1; i < m; i++) {
        int ind = e[i].second;
        s[ind] = '1';
        cout << "? " << s << endl;
        int res;
        cin >> res;
        if (res != ans + e[i].first) {
            s[ind] = '0';
            continue;
        }
        ans = res;
    }
    cout << "! " << ans << endl;
}