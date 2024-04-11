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

const int N = 2e5 + 228;
const int LOG = 20;
vector<int> pos[LOG];

void build() {
    for (int x = 1; x <= N; ++x) {
        for (int bit = 0; bit < LOG; ++bit) {
            if ((x >> bit) & 1) {
                pos[bit].push_back(x);
            }
        }
    }
}

int getCnt(int l, int r, int bit) {
    return upper_bound(all(pos[bit]), r) - lower_bound(all(pos[bit]), l);
}

void solve() {
    int l, r;
    cin >> l >> r;
    int ans = N;
    for (int bit = 0; bit < LOG; ++bit) {
        chkmin(ans, r - l + 1 - getCnt(l, r, bit));
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    build();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}