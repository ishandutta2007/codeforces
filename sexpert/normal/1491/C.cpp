#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, p = 0;
    cin >> n;
    vector<ll> v(n), used(n);
    for(auto &x : v)
        cin >> x;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(used[i] >= v[i] - 1 && i + 1 < n)
            used[i + 1] += used[i] - (v[i] - 1);
        ans += max(0LL, v[i] - 1 - used[i]);
        for(int j = i + 2; j <= min((ll)(n - 1), i + v[i]); j++)
            used[j]++;
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