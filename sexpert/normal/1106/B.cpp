#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll, ll>;
 
const ll MAXN = 1e5 + 5;
ll loc[MAXN], cst[MAXN], amt[MAXN];
 
int main() {
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    ll tot = 0;
    vector<ii> dish;
    for(ll i = 0; i < n; i++) {
        cin >> amt[i];
        tot += (ll)amt[i];
    }
    for(ll i = 0; i < n; i++) {
        cin >> cst[i];
        dish.push_back({cst[i], i});
    }
    sort(dish.begin(), dish.end());
    ll lidx = 0;
    for(ll i = 0; i < m; i++) {
        ll t, d, ans = 0;
        cin >> t >> d;
        if(tot < d) {
            tot = 0;
            cout << "0\n";
            continue;
        }
        if(d <= amt[t - 1]) {
            cout << d*cst[t - 1] << endl;
            amt[t - 1] -= d;
            tot -= d;
            continue;
        }
        else {
            d -= amt[t - 1];
            ans += amt[t - 1]*cst[t - 1];
            tot -= amt[t - 1];
            amt[t - 1] = 0;
        }
        while(d > 0) {
            ll x = min((ll)amt[dish[lidx].second], d);
            amt[dish[lidx].second] -= x;
            d -= x;
            tot -= x;
            ans += (ll)x*cst[dish[lidx].second];
            if(amt[dish[lidx].second] == 0)
                lidx++;
        }
        cout << ans << endl;
    }
}