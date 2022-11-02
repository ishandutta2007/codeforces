#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

int get(int x) {
    for (int bit = 30; bit >= 0; --bit) {
        if ((x >> bit) & 1) {
            return bit;
        }
    }
    assert(false);
    return -1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(40);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        x = get(x);
        ans += cnt[x];
        cnt[x]++;
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}