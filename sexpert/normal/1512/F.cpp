#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, c;
    cin >> n >> c;
    vector<ll> a(n), b(n - 1);
    for(auto &x : a)
        cin >> x;
    for(auto &x : b)
        cin >> x;
    ll ans = 1e9 + 500, cur = 0, tot = 0;
    for(int i = 0; i < n; i++) {
        ans = min(ans, tot + (c - cur + a[i] - 1)/a[i]);
        if(i + 1 < n) {
            ll rem = b[i] - cur;
            if(rem <= 0)
                cur -= b[i];
            else {
                ll x = (rem + a[i] - 1)/a[i];
                tot += x;
                cur = cur + x * a[i] - b[i];
            }
            tot++;
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