#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    ll k;
    cin >> n >> q >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        ll val = 0;
        if (i > 0 && i < n - 1) 
            val += a[i + 1] - a[i - 1] - 2;
        pref[i + 1] = pref[i] + val;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        if (r - l == 1) {
            cout << k - 1 << "\n";
        } else {
            ll ans = pref[r - 1] - pref[l + 1];       
            ans += a[l + 1] - 2;
            ans += k - a[r - 2] - 1;
            cout << ans << "\n";
        }

    }

    return 0;
}