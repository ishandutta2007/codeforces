#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll ans = 0, slp = 0;
    ll n, m;
    cin >> n >> m;
    vector<ll> gays;
    vector<pair<ll, ll>> fuck;
    for(int i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        gays.push_back(x);
        fuck.push_back({x, y});
    }
    sort(gays.rbegin(), gays.rend());
    //for(auto x : gays)
    //    cout << x << " ";
    //cout << '\n';
    vector<ll> pgays(m);
    for(int i = 0; i < m; i++)
        pgays[i] = gays[i] + (i ? pgays[i - 1] : 0);
    //for(auto x : pgays)
    //    cout << x << " ";
    //cout << '\n';
    for(int i = 0; i < m; i++) {
        ll shit = fuck[i].second;
        ll tmp = n, res = 0;
        if(gays[0] >= fuck[i].second) {
            int lo = 0, hi = m - 1;
            while(lo < hi) {
                int mi = (lo + hi + 1)/2;
                if(gays[mi] >= fuck[i].second)
                    lo = mi;
                else
                    hi = mi - 1;
            }
            //cout << i << " " << fuck[i].first << " " << shit << " " << lo << " ";
            if(lo + 1 >= tmp) {
                //cout << tmp - 1 << " " << pgays[tmp - 1] << '\n';
                ans = max(ans, pgays[tmp - 1]);
                continue;
            }
            tmp -= lo + 1;
            res += pgays[lo];
            //cout << res << " ";
        }
        if(fuck[i].first < fuck[i].second) {
            res += fuck[i].first;
            tmp--;
        }
        //cout << res + shit * tmp << '\n';
        ans = max(ans, res + shit * tmp);
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