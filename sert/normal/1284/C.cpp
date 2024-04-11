#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> fac(n + 3, 1);
    for (int i = 1; i < (int)fac.size(); i++) {
        fac[i] = fac[i - 1] * i % m;
    }

    ll ans = 0;
    for (int k = 1; k <= n; k++) {
        ll cur = ((n - k + 1) * fac[n - k + 1] % m * fac[k] % m) % m;
        ans += cur;
    }

    cout << ans % m << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
#ifdef MADE_BY_SERT
    int T = 5;
    for (int i = 1; i < T; i++) solve();    
#endif
}