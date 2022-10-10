#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> fuck[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<ll> v(m);
    for(auto &x : v)
        cin >> x;
    for(int i = 0; i < m - 1; i++) {
        if(v[i] != v[i + 1])
            fuck[v[i]].push_back(v[i + 1]);
    }
    for(int i = 1; i < m; i++) {
        if(v[i] != v[i - 1])
            fuck[v[i]].push_back(v[i - 1]);
    }
    ll cost = 0;
    for(int i = 0; i < m - 1; i++)
        cost += abs(v[i] - v[i + 1]);
    ll ans = cost;

    for(int t = 1; t <= n; t++) {
        int sz = fuck[t].size();
        if(sz == 0)
            continue;
        ll delta = 0;
        for(auto f : fuck[t])
            delta -= abs(t - f);
        sort(fuck[t].begin(), fuck[t].end());
        int yay = fuck[t][sz/2];
        for(auto f : fuck[t])
            delta += abs(yay - f);
        ans = min(ans, cost + delta);
    }
    cout << ans << '\n';
}