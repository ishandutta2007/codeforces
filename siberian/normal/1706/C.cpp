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

vector<ll> buildPref(vector<int> a) {
    int n = a.size();
    vector<ll> pref(n);
    for (int i = 1; i + 1 < n; i += 2) {
        if (i - 2 >= 0) { 
            pref[i] = pref[i - 2];
        }
        int add = 0;
        if (a[i] <= a[i - 1]) {
            chkmax(add, a[i - 1] - a[i] + 1);
        }
        if (a[i] <= a[i + 1]) {
            chkmax(add, a[i + 1] - a[i] + 1);
        }
        pref[i] += add;
    }
    return pref;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vin(a);
    if (n % 2 == 1) {
        ll ans = 0;
        for (int i = 1; i < n; i += 2) {
            int add = 0;
            if (a[i] <= a[i - 1]) {
                chkmax(add, a[i - 1] - a[i] + 1);
            }
            if (a[i] <= a[i + 1]) {
                chkmax(add, a[i + 1] - a[i] + 1);
            }
            ans += add;
        }
        cout << ans << '\n';
    } else {
        auto pref = buildPref(a);
        reverse(all(a));
        auto suff = buildPref(a);
        reverse(all(suff));
        // cerr << "pref = " << endl;
        // for (auto i : pref) {
        //     cerr << i << " ";
        // }
        // cerr << endl;
        // cerr << "suff = " << endl;
        // for (auto i : suff) {
        //     cerr << i << " ";
        // }
        // cerr << endl;
        ll ans = LONG_LONG_MAX;
        for (int i = 0; i < n; i += 2) {
            ll fans = 0;
            if (i - 1 >= 0) {
                fans += pref[i - 1];
            }
            if (i + 2 < n) {
                fans += suff[i + 2];
            }
            chkmin(ans, fans);
        }
        cout << ans << '\n';
    }
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