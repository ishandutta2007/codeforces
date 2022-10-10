#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    vector<ll> v[3];
    v[0].resize(a);
    v[1].resize(b);
    v[2].resize(c);
    for(auto &x : v[0])
        cin >> x;
    for(auto &x : v[1])
        cin >> x;
    for(auto &x : v[2])
        cin >> x;
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    sort(v[2].begin(), v[2].end());
    vector<int> p = {0, 1, 2};
    ll ans = LLONG_MAX;
    do {
        for(auto mi : v[p[0]]) {
            if(v[p[1]][0] > mi)
                continue;
            if(v[p[2]].back() < mi)
                continue;
            ll x, y;
            int lo = 0, hi = v[p[1]].size() - 1;
            while(lo < hi) {
                int m = (lo + hi + 1)/2;
                if(v[p[1]][m] <= mi)
                    lo = m;
                else
                    hi = m - 1;
            }
            x = v[p[1]][lo];
            lo = 0;
            hi = v[p[2]].size() - 1;
            while(lo < hi) {
                int m = (lo + hi)/2;
                if(v[p[2]][m] >= mi)
                    hi = m;
                else
                    lo = m + 1;
            }
            y = v[p[2]][lo];
            ans = min(ans, (mi - x)*(mi - x) + (mi - y)*(mi - y) + (x - y)*(x - y));
        }
    } while(next_permutation(p.begin(), p.end()));
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