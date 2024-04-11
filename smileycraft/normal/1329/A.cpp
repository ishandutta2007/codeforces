
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(13);
    ll n, m;
    cin >> n >> m;
    vll v(m);
    for (ll i = 0; i < m; ++i) cin >> v[i];
    vll sol(m);
    ll loc = n + 1;
    for (ll i = m - 1; i >= 0; --i){
        ll maxi = min(loc - 1, n + 1 - v[i]);
        ll mini = max(i + 1, loc - v[i]);
        if (mini > maxi){
            cout << -1 << endl;
            return 0;
        }
        loc = sol[i] = mini;
    }
    if (loc > 1){
        cout << -1 << endl;
        return 0;
    }
    cout << sol[0];
    for (ll i = 1; i < m; ++i) cout << ' ' << sol[i];
    cout << endl;
    return 0;
}