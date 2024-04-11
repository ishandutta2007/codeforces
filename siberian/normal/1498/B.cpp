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

#define int ll

bool check(int h, int w, const vector<int>& a) {
    multiset<int> have;
    for (int i = 0; i < h; ++i) {
        have.insert(w);
    }
    for (auto i : a) {
        auto it = have.lower_bound(i);
        if (it == have.end()) return false;
        int x = (*it) - i;
        have.erase(it);
        if (x > 0) {
            have.insert(x);
        }
    }
    return true;
}

void solve() {
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    sort(all(a));
    reverse(all(a));
    int l = 0, r = n;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (!check(m, w, a)) {
            l = m;
        } else{
            r = m;
        }
    }
    cout << r << '\n';
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