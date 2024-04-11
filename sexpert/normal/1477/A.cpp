#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> v(n);
    for(auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    ll off = v[0];
    k -= off;
    for(auto &x : v) {
        x -= off;
        //cout << x << " ";
    }
    //cout << '\n';
    ll g = 0;
    for(auto &x : v) {
        if(x > 0)
            g = __gcd(x, g);
    }
    cout << ((k % g == 0) ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}