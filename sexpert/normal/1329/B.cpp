#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll d, m;
    cin >> d >> m;
    vector<ll> v;
    ll k = 1;
    while(d >= k) {
        v.push_back(k);
        d -= k;
        k *= 2;
    }
    if(d)
        v.push_back(d);
    ll ans = 0;
    for(auto x : v) {
        ans *= x + 1;
        ans += x;
        ans %= m;
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