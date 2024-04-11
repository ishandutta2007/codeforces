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

const int N = 1e5 + 10;
int n, q;
int a[N];
ll ans = 0;

void upd(int i, ll coeff) {
    ans += static_cast<ll>(i) * static_cast<ll>(n - i) * coeff;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n >> q;
    ans = static_cast<ll>(n) * static_cast<ll>(n + 1) / 2;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0) {
            if (a[i] != a[i - 1]) {
                upd(i, 1);
            } 
        }
    }
    while (q--) {
        int pos, val;
        cin >> pos >> val;
        --pos;
        if (pos > 0 && a[pos] != a[pos - 1]) {
            upd(pos, -1);
        }
        if (pos + 1 < n && a[pos + 1] != a[pos]) {
            upd(pos + 1, -1);
        }
        a[pos] = val;
        if (pos > 0 && a[pos] != a[pos - 1]) {
            upd(pos, 1);
        }
        if (pos + 1 < n && a[pos + 1] != a[pos]) {
            upd(pos + 1, 1);
        }
        cout << ans << '\n';
    }
    return 0;
}