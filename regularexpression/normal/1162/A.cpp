#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, h, m;
    cin >> n >> h >> m;
    vector <ll> a(n, h);
    for (ll i = 0; i < m; i++) {
        ll l, r, x;
        cin >> l >> r >> x;
        l--;
        r--;
        for (ll j = l; j <= r; j++) {
            a[j] = min(a[j], x);
        }
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ans += a[i] * a[i];
    }
    cout << ans;
    return 0;
}