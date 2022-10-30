
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpll = vector<pll>;
using vvll = vector<vll>;

ll INF = 20000000000000000;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(13);
    ll x0, y0, ax, ay, bx, by, xs, ys, t;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
    vpll locs = {{x0, y0}};
    while (locs.back().first <= INF && locs.back().second <= INF)
        locs.emplace_back(ax * locs.back().first + bx, ay * locs.back().second + by);
    ll best = 0;
    for (ll i = 0; i < locs.size(); ++i){
        ll d = abs(xs - locs[i].first) + abs(ys - locs[i].second);
        for (ll j = 0; j < locs.size(); ++j)
            if (d + abs(locs[i].first - locs[j].first) + abs(locs[i].second - locs[j].second) <= t)
                best = max(best, abs(i - j) + 1);
    }
    cout << best << endl;
    return 0;
}