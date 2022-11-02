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

ll get_sqrt(ll x) {
    ll val = sqrt(x) - 5;
    chkmax(val, 0);
    while ((val + 1) * (val + 1) <= x) {
        ++val;
    }
    return val;
}

bool is_good(ll x) {
    ll sq = get_sqrt(x);
    // if (sq * sq == x) {
    //     return false;
    // }
    return x % sq == 0;
}

ll stupid(ll r) {
    ll ans = 0;
    for (int i = 1; i <= r; ++i) {
        if (is_good(i)) {
            ++ans;
        }
    } 
    return ans;
}

ll stupid(ll l, ll r) {
    return stupid(r) - stupid(l - 1);
}

ll smart(ll r) {
    ll sq = get_sqrt(r);
    ll ans = sq;
    while (sq * (sq + 1) > r) --sq;
    ans += sq;
    while (sq * (sq + 2) > r) --sq;
    ans += sq;
    // for (ll a = 1; a * a <= r; ++a) {
    //     if (a * a <= r) {
    //         ++ans;
    //     }
    //     if (a * (a + 1) <= r) {
    //         ++ans;
    //     }
    //     if (a * (a + 2) <= r) {
    //         ++ans;
    //     }
    // } 
    return ans;
}

ll smart(ll l, ll r) {
    // return stupid(r) - stupid(l - 1);    
    return smart(r) - smart(l - 1);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    // int last = 0;
    // for (int val = 1; val < 100000; ++val) {
    //     if (is_good(val)) {
    //         // cout << get_sqrt(val) - val / get_sqrt(val) << endl;
    //         // last = val;
    //         // cout << val << endl;
    //     } else if (abs(get_sqrt(val) - val / get_sqrt(val)) <= 2 && get_sqrt(val) * get_sqrt(val) != val) {
    //         cout << val << endl;
    //     }
    // } 
    // int t;
    // cin >> t;
    // while (t--) {

    // }
    // for (int n = 1; n <= 10000; ++n) {
    //     if (smart(n) != stupid(n)) {
    //         cout << "n = " << n << " smart = " << smart(n) << " stupid = " << stupid(n) << endl;
    //         break;
    //     }
    // }
    int t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        cout << smart(l, r) << '\n';
    }
    return 0;
}