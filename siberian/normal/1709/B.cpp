#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

#define int ll

vector<int> build(vector<int> a) {
    vector<int> pref(a.size());
    for (int i = 1; i < (int)pref.size(); ++i) {
        pref[i] = pref[i - 1];
        if (a[i - 1] > a[i]) {
            pref[i] += a[i - 1] - a[i];
        } 
    }
    return pref;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vin(a);
    auto pref = build(a);
    reverse(all(a));
    auto suff = build(a);
    reverse(all(suff));
    while (q--) {
        int from, to;
        cin >> from >> to;
        --from;
        --to;
        if (from < to) {
            cout << pref[to] - pref[from] << '\n';
        } else {
            cout << suff[to] - suff[from] << '\n';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }    
    return 0;
}