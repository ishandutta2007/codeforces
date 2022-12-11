#include <bits/stdc++.h>

using namespace std;
using ll = long long;


ll solve(vector<int> &type, vector<ll> &dmg) {
    int n = type.size();
    vector<int> fire, frost;
    for (int i = 0; i < n; ++i) (type[i] == 0 ? fire : frost).push_back(dmg[i]);
    sort(begin(fire), end(fire), greater<int>());
    sort(begin(frost), end(frost), greater<ll>());
    if (fire.size() == frost.size()) {
        return 2 * accumulate(begin(dmg), end(dmg), 0LL) - *min_element(begin(dmg), end(dmg));
    } else if (fire.size() < frost.size()) {
        swap(fire, frost);
    }
    // WLOG |fire| >= |frost|
    ll ans = accumulate(begin(dmg), end(dmg), 0LL);
    int f = frost.size();
    for (int i = 0; i < frost.size(); ++i) {
        ans += frost[i] + fire[i];
    }
    return ans;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        vector<int> type(n);
        vector<ll> dmg(n);
        for (int i = 0; i < n; ++i) scanf("%d", &type[i]);
        for (int i = 0; i < n; ++i) scanf("%d", &dmg[i]);
        printf("%lld\n", solve(type, dmg));
    }
}