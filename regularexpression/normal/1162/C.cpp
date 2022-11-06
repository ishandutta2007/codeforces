#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector <ll> a(k);
    for (ll i = 0; i < k; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    set <ll> s;
    for (ll i = 0; i < k; i++) {
        s.insert(a[i]);
    }
    for (ll i = 1; i <= n; i++) {
        if (s.find(i) == s.end()) {
            ans++;
        }
    }
    vector <vector<ll>> c(n + 1);
    for (ll i = 0; i < k; i++) {
        c[a[i]].push_back(i);
    }
    for (ll i = 1; i <= n; i++) {
        sort(c[i].begin(), c[i].end(), less<ll>());
    }
    for (ll i = 1; i <= n; i++) {
        if (i - 1 >= 1) {
            ll r = k;
            if (((ll)c[i].size()) > 0) {
                r = c[i][0] - 1;
            }
            ll l = -1;
            if (((ll)c[i - 1].size()) > 0) {
                l = c[i - 1][((ll)c[i - 1].size()) - 1];
            }
            if (r - l >= 0) {
                ans++;
            }
        }
        if (i + 1 <= n) {
            ll r = k;
            if (((ll)c[i].size()) > 0) {
                r = c[i][0] - 1;
            }
            ll l = -1;
            if (((ll)c[i + 1].size()) > 0) {
                l = c[i + 1][((ll)c[i + 1].size()) - 1];
            }
            if (r - l >= 0) {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}