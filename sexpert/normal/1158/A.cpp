#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<ll> b(n);
    vector<ll> g(m);
    for(auto &x : b) cin >> x;
    for(auto &x : g) cin >> x;
    sort(b.begin(), b.end());
    sort(g.begin(), g.end());
    if(g[0] < b[n - 1]) {
        cout << "-1\n";
        return 0;
    }
    ll tot = 0;
    for(int i = 0; i < n; i++)
        tot += b[i];
    ll ans = tot * m;
    for(int i = m - 1; i >= 1; i--)
        ans += (g[i] - b[n - 1]);
    if(g[0] > b[n - 1])
        ans += (g[0] - b[n - 2]);
    cout << ans << endl;
}