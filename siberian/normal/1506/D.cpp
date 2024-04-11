#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define mp make_pair

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

void solve() {
    int n;
    map<int, int> a;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x]++;
    }
    set<pair<int, int>> have;
    for (auto i: a) {
        have.insert({i.second, i.first});
    }
    while (have.size() > 1) {
        auto x = *(--have.end());
        have.erase(--have.end());
        auto y = *(--have.end());
        have.erase(--have.end());
        --x.first;
        if (x.first > 0) have.insert(x);
        --y.first;
        if (y.first > 0) have.insert(y);
    }
    int ans = 0;
    for (auto i : have) {
        ans += i.first;
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}