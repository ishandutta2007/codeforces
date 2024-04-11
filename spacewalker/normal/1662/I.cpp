#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, m; scanf("%d %d", &n, &m);
    vector<int> pop(n);
    for (int i = 0; i < n; ++i) scanf("%d", &pop[i]);
    vector<ll> ics(m);
    for (int i = 0; i < m; ++i) scanf("%lld", &ics[i]);
    ics.push_back(-1000000000000000);
    ics.push_back(1000000000000000);
    sort(begin(ics), end(ics));
    vector<tuple<ll, ll, ll>> buyRange; // is inclusive
    for (int i = 0; i < n; ++i) {
        ll hpos = 100 * i;
        // get closest >= and closest <= 
        ll nextShopLoc = *lower_bound(begin(ics), end(ics), hpos);
        ll prevShopLoc = *prev(upper_bound(begin(ics), end(ics), hpos));
        ll mdist = min(hpos - prevShopLoc, nextShopLoc - hpos);
        // printf("hut at %lld has next prev %lld %lld mdist %lld\n", hpos, nextShopLoc, prevShopLoc, mdist);
        if (mdist == 0) continue;
        ll iwidth = mdist - 1;
        buyRange.emplace_back(hpos - iwidth, hpos + iwidth, pop[i]);
    }
    for (auto &[s, e, p] : buyRange) {
        s = 2 * s - 1;
        e = 2 * e + 1;
    }
    vector<pair<ll, ll>> evts;
    for (auto [s, e, p] : buyRange) {
        // printf("BR %lld %lld %lld\n", s, e, p);
        evts.emplace_back(s, -p);
        evts.emplace_back(e, p);
    }
    sort(begin(evts), end(evts));
    ll ans = 0, cpop = 0;
    for (auto [t, d] : evts) {
        // printf("%lld %lld ev\n", t, d);
        ans = max(cpop, ans);
        cpop -= d;
        ans = max(cpop, ans);
    }
    printf("%lld\n", ans);
}