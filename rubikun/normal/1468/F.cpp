#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using l_l = pair<ll, ll>;

void solve() {
    ll N;
    cin >> N;
    map<l_l, ll> mp;
    for(int i = 0; i < N; i++) {
        ll x, y, a, b;
        cin >> x >> y >> a >> b;
        ll dx = x - a;
        ll dy = y - b;
        ll g = __gcd(abs(dx), abs(dy));
        if(g != 0) {
            dx /= g;
            dy /= g;
        }
        mp[{dx, dy}]++;
    }
    ll ans = 0;
    for(auto tmp : mp) {
        ll dx = tmp.first.first;
        ll dy = tmp.first.second;
        ans += tmp.second * mp[{-dx, -dy}];
    }
    assert(ans % 2 == 0);
    ans /= 2;
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}