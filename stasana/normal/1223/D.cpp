#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef int64_t ll;

inline void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

inline void solve() {
    ll n;
    cin >> n;
    vector<ll> cnt(n + 1);
    vector<ll> a(n + 1);
    vector<ll> cord;
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
        cord.emplace_back(a[i]);
    }
    sort(cord.begin(), cord.end());
    cord.resize(unique(cord.begin(), cord.end()) - cord.begin());
    ll m = cord.size();
    for (ll i = 1; i <= n; ++i) {
        a[i] = lower_bound(cord.begin(), cord.end(), a[i]) - cord.begin() + 1;
    }
    vector<ll> first(m + 1);
    vector<ll> last(m + 1);
    for (ll i = 1; i <= n; ++i) {
        if (first[a[i]] == 0) {
            first[a[i]] = i;
        }
        last[a[i]] = i;
    }
    vector<pair<ll, ll>> events;
    for (ll i = 1; i <= m; ++i) {
        if (first[i] == 0) {
            continue;
        }
        events.emplace_back(first[i], -i);
        events.emplace_back(last[i], i);
    }
    sort(events.begin(), events.end());
    vector<ll> res1(m + 1);
    vector<ll> res2(m + 1);
    for (auto i : events) {
        if (i.second > 0) {
            res1[i.second] = res2[i.second];
        } else {
            res2[-i.second] = res1[-i.second - 1] + 1;
        }
    }
    ll mx = 0;
    for (ll i = 0; i <= m; ++i) {
        mx = max(mx, res1[i]);
    }
    cout << m - mx << "\n";
}

int main() {
    start();
    int n;
    cin >> n;
    while (n) {
        --n;
        solve();
    }
    return 0;
}