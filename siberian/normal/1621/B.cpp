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

struct Segment{
    int l, r, c;
    int len() const {
        return r - l + 1;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<Segment> a(n);
    for (auto& [l, r, c] : a) {
        cin >> l >> r >> c;
    }
    int idL = 0, idR = 0, idFull = 0;
    cout << a[0].c << '\n';
    for (int i = 1; i < n; ++i) {
        if (a[i].l < a[idL].l || (a[i].l == a[idL].l && a[i].c < a[idL].c)) {
            idL = i;
        }
        if (a[i].r > a[idR].r || (a[i].r == a[idR].r && a[i].c < a[idR].c)) {
            idR = i;
        }
        if (a[i].len() > a[idFull].len() || (a[i].len() == a[idFull].len() && a[i].c < a[idFull].c)) {
            idFull = i;
        }
        int ans = a[idL].c + a[idR].c;
        if (a[idR].r - a[idL].l + 1 == a[idFull].len()) {
            chkmin(ans, a[idFull].c);
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