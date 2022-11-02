#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

#define int ll

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> cntA(n, 0);
    vector<int> cntB(m, 0);
    vector<pair<int, int>> have(k);
    for (auto& i : have) {
        cin >> i.first;
        i.first--;
        cntA[i.first]++;
    }
    for (auto& i : have) {
        cin >> i.second;
        i.second--;
        cntB[i.second]++;
    }
    ll ans = 0;
    for (auto i : have) {
        ans += k - cntA[i.first] - cntB[i.second] + 1;
    }
    assert(ans % 2 == 0);
    cout << ans / 2 << '\n';
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