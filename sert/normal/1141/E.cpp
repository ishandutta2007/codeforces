#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
    ll h, n;
    cin >> h >> n;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    ll sum = -accumulate(all(a), (ll)0);
    ll pref = h;
    ll ans = -1;

    for (int i = 0; i < n; i++) {
        pref += a[i];
        if (pref <= 0) {
            cout << i + 1 << "\n";
            return;
        }
        if (sum <= 0) continue;
        ll kk = (pref + sum - 1) / sum * n + i + 1;
        if (ans == -1 || kk < ans) ans = kk;
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
#ifdef MADE_BY_SERT
    int T = 3;
    for (int i = 1; i < T; i++) solve();    
#endif
}