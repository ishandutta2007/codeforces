#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for(auto &x : v) cin >> x;
    reverse(v.begin(), v.end());
    ll cap = 1e9 + 5;
    ll ans = 0;
    for(int i = 0; i < v.size(); i++) {
        ll take = min(cap, v[i]);
        ans += take;
        cap = max(0LL, take - 1);
    }
    cout << ans << endl;
}