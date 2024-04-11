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

ll getSum(int r) {
    if (r <= 0) return 0;
    return (ll)r * (r + 1) / 2;
}

ll getSum(int l, int r) {
    if (r < l) return 0;
    return getSum(r) - getSum(l - 1);
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = n * n;
    vector<ll> pref(n);
    vector<ll> cnt(n);

    for (int i = 0; i < n; ++i) {
        pref[i] = i * (s[i] == '*');
        if (i > 0) pref[i] += pref[i - 1];
        cnt[i] += s[i] == '*';
        if (i > 0) cnt[i] += cnt[i - 1];
    }

    // cerr << "pref = " << endl;
    // for (auto i : pref) cerr << i << " ";
    // cerr << endl;
    // cerr << "cnt = " << endl;
    // for (auto i : cnt) cerr << i << " ";
    // cerr << endl;

    for (int l = 0; l + cnt.back() <= n; ++l) {
        int L = l - 1, R = l + cnt.back();
        while (L < R - 1) {
            int M = (L + R) / 2;
            if (cnt[M] >= M - l + 1) {
                L = M;
            } else {
                R = M;
            }
        }
        // cerr << "l = " << l << " L = " << L << endl;
        int cntL = (L == l - 1 ? 0 : cnt[L]);
        // int cntR = cnt.back() - cntL;
        ll sumL = getSum(l, l + cntL - 1);
        ll sumR = getSum(l + cntL, l + cnt.back() - 1);
        // cerr << "sumL = " << sumL << " sumR = " << sumR << endl;
        ll sumPrefL = (L == l - 1 ? 0 : pref[L]);
        ll sumPrefR = pref.back() - sumPrefL;
        // cerr << "sumPrefL = " << sumPrefL << " sumPrefR = " << sumPrefR << endl;
        chkmin(ans, sumL - sumPrefL + sumPrefR - sumR);
        // exit(0);
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