#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll a, b, q;
    cin >> a >> b >> q;
    ll k = a * b;
    vector<ll> ans(k), pf(k), sf(k);
    for(ll i = 0; i < k; i++)
        ans[i] = (((i % a) % b) != ((i % b) % a));
    for(int i = 0; i < k; i++)
        pf[i] = ans[i] + (i ? pf[i - 1] : 0);
    for(int i = k - 1; i >= 0; i--)
        sf[i] = ans[i] + (i == k - 1 ? 0 : sf[i + 1]);
    while(q--) {
        ll l, r;
        cin >> l >> r;
        ll big = k * (r / k);
        if(big < l) {
            cout << pf[r % k] - pf[(l - 1) % k] << " ";
            continue;
        }
        ll smol = k * ((l + k - 1) / k);
        //cout << smol << " " << big << " " << l%k << " " << r%k << endl;
        //cout << pf[k - 1] << endl;
        ll ans = pf[k - 1] * ((big - smol)/k);
        ans += pf[r % k];
        if(l % k)
            ans += sf[l % k];
        cout << ans << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}