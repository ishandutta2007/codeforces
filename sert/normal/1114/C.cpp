#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const ll INF = (ll)1e18 + 41;

ll cnt(ll x, ll p) {
    ll ans = 0;
    ll P = 1;
    while (x / P >= p) {
        P *= p;
        ans += x / P;
    }
    return ans;
}

void solve() {
    ll x, a;
    cin >> x >> a;
    ll ans = INF;    
    for (ll p = 2; p * p <= a; p++) {
        if (a % p) continue;
        int num = 0;
        while (a % p == 0) {
            a /= p;
            num++;
        }
        ans = min(ans, cnt(x, p) / num);
    }
    if (a > 1) ans = min(ans, cnt(x, a));
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
#ifdef MADE_BY_SERT
    int T = 4;
    for (int i = 1; i < T; i++) solve();    
#endif
}