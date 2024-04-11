#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> v(n);
    ll ans = 0;
    for(auto &x : v) cin >> x;
    ans = v[0] * (n - v[0] + 1);
    for(int i = 1; i < v.size(); i++) {
        if(v[i] == v[i - 1])
            continue;
        if(v[i] < v[i - 1])
            ans += v[i] * (v[i - 1] - v[i]);
        if(v[i] > v[i - 1])
            ans += (v[i] - v[i - 1]) * (n - v[i] + 1);
    }
    cout << ans << '\n';
}