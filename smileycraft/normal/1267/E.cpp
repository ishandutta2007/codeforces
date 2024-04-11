
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpll = vector<pll>;
using vvll = vector<vll>;

int main(){
    ll n, m;
    cin >> n >> m;
    vvll v(m, vll(n));
    for (ll i = 0; i < m; ++i) for (ll j = 0; j < n; ++j) cin >> v[i][j];
    vll best(m);
    for (ll i = 0; i < m; ++i) best[i] = i;
    for (ll j = 0; j < n - 1; ++j){
        vector<pll> ds(m);
        for (ll i = 0; i < m; ++i) ds[i] = {v[i][j] - v[i][n - 1], i};
        sort(ds.begin(), ds.end());
        ll lead = 0;
        vll retval;
        for (ll i = m - 1; i >= 0; --i){
            lead += ds[i].first;
            if (lead < 0){
                for (ll k = i; k >= 0; --k) retval.push_back(ds[k].second);
                break;
            }
        }
        if (retval.size() < best.size()) best = retval;
    }
    cout << best.size() << endl;
    if (best.size() >= 1) cout << best[0] + 1;
    for (ll i = 1; i < best.size(); ++i) cout << ' ' << best[i] + 1;
    cout << endl;
    return 0;
}