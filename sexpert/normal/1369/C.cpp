#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll ans = 0;
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    vector<int> w(k);
    for(auto &x : v)
        cin >> x;
    for(auto &x : w)
        cin >> x;
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());
    for(int i = 0; i < k; i++) {
        ll x = v.back();
        v.pop_back();
        ans += x;
        w[i]--;
        if(w[i] == 0)
            ans += x;
    }
    sort(w.rbegin(), w.rend());
    int p = 0;
    for(int i = 0; i < k; i++) {
        if(w[i] == 0)
            break;
        ans += v[p];
        p += w[i];
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