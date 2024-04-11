
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpll = vector<pll>;
using vvll = vector<vll>;

ll n;
vvll g;
vpll output;

void dfs(ll from, ll to, ll t){
    ll mini = 1, maxi = g[to].size();
    if (maxi < t){
        mini += t - maxi;
        maxi = t;
    }
    ll s = t;
    for (ll toto : g[to]) if (toto != from){
        output.push_back({to, s});
        if (s == maxi){
            s = mini - 1;
            output.push_back({to, s});
        }
        dfs(to, toto, ++s);
    }
    output.push_back({to, s});
    if (s == maxi){
        s = mini - 1;
        output.push_back({to, s});
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(13);
    cin >> n;
    if (n == 1){
        cout << 1 << endl << 1 << ' ' << 0 << endl;
        return 0;
    }
    g.assign(n, {});
    for (ll i = 0; i < n - 1; ++i){
        ll u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(-1, 0, g[0].size());
    cout << output.size() - 2 << endl;
    for (ll i = 1; i < output.size() - 1; ++i) cout << output[i].first + 1 << ' ' << output[i].second << endl;
    return 0;
}