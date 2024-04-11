// Megumin top

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef int64_t ll;

inline void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

inline void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> p(n);
    for (ll i = 0; i < n; ++i) {
        cin >> p[i];
    }
    vector<ll> a(m, -1);
    vector<ll> b(n);
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        --x;
        b[i] = x;
        if (a[x] == -1 || p[a[x]] < p[i]) {
            a[x] = i;
        }
    }
    ll result = k;
    for (ll i = 0; i < k; ++i) {
        ll x;
        cin >> x;
        --x;
        if (a[b[x]] == x) {
            --result;
        }
    }
    cout << result << endl;
}

int32_t main() {
    start();
    solve();
    return 0;
}