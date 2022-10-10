#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll m, d, w;
    cin >> m >> d >> w;
    ll req = w / __gcd(w, d - 1);
    ll sz = min(d, m);
    ll ans = 0;
    if(req <= 30000) {
        for(ll s = 0; s < req; s++) {
            ll bn = (sz - s + req - 1)/req;
            if(bn <= 0)
                continue;
            ans += (bn * (bn - 1))/2;
        }
    }
    else {
        ll s = 0;
        ll tk = sz % req;
        ll cur = (sz + req - 1)/req;
        ans += tk * (cur * (cur - 1))/2;
        s += tk;
        while(s < req) {
            cur--;
            tk = min(req, req - s);
            ans += tk * (cur * (cur - 1))/2;
            s += tk;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}