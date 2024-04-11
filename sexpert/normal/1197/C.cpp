#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<ll> v(n), d;
    for(auto &x : v) cin >> x;
    ll ans = v[n - 1] - v[0];
    for(int i = 1; i < n; i++)
        d.push_back(v[i] - v[i - 1]);
    sort(d.rbegin(), d.rend());
    for(int i = 0; i < k - 1; i++)
        ans -= d[i];
    cout << ans << '\n';
}