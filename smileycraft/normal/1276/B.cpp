
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpll = vector<pll>;
using vvll = vector<vll>;

vvll g;

void dfs(vll &v, ll x, ll i){
    v[x] = i;
    for (ll nb : g[x]) if (v[nb] == -1) dfs(v, nb, i);
}

int main(){
    ll T;
    cin >> T;
    while (--T >= 0){
        ll n, m, a, b;
        cin >> n >> m >> a >> b;
        --a; --b;
        g.assign(n, {});
        for (ll i = 0; i < m; ++i){
            ll u, v;
            cin >> u >> v;
            --u; --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vll v1(n, -1), v2(n, -1);
        v1[a] = 0; v2[b] = 0;
        ll i = 1;
        for (ll nb : g[a]) if (v1[nb] == -1){
            dfs(v1, nb, i);
            ++i;
        }
        vll cs1(i);
        for (ll x = 0; x < n; ++x) ++cs1[v1[x]];
        i = 1;
        for (ll nb : g[b]) if (v2[nb] == -1){
            dfs(v2, nb, i);
            ++i;
        }
        vll cs2(i);
        for (ll x = 0; x < n; ++x) ++cs2[v2[x]];
        unordered_map<ll, ll> occs;
        for (ll x = 0; x < n; ++x){
            ll y = v1[x] * n + v2[x];
            ++occs[y];
        }
        ll total = 0;
        for (ll x = 0; x < n; ++x){
            ll y = v1[x] * n + v2[x];
            //cout << x << ' ' << v1[x] << ' ' << v2[x] << ' ' << y << ' ' << cs1[v1[x]] << ' ' << cs2[v2[x]] << ' ' << occs[y] << endl;
            ll extra = n - cs1[v1[x]] - cs2[v2[x]] + occs[y];
            if (x == a || x == b) total -= extra;
            else total += extra;
        }
        cout << total / 2 + 1 << endl;
    }
    return 0;
}