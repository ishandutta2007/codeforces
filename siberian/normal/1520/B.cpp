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

int get(int x, int n) {
    ll now = 0;
    int ans = 0;
    while (now * 10 + x <= n) {
        now *= 10;
        now += x;
        ++ans;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for (int x = 1; x <= 9; ++x) {
        ans += get(x, n);
    }
    cout << ans << endl;
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