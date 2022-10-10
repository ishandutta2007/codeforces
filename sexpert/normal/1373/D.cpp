#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mss(vector<ll> &v) {
    ll ans = 0, prv = 0;
    for(auto x : v) {
        prv = max(prv + x, x);
        ans = max(ans, prv);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(auto &x : a)
        cin >> x;
    ll ans = 0;
    for(int i = 0; i < n; i += 2)
        ans += a[i];
    ll add = 0;
    vector<ll> tmp;
    for(int i = 1; i < n; i += 2)
        tmp.push_back(a[i] - a[i - 1]);
    add = max(add, mss(tmp));
    tmp.clear();
    for(int i = 2; i < n; i += 2)
        tmp.push_back(a[i - 1] - a[i]);
    add = max(add, mss(tmp));
    cout << ans + add << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}