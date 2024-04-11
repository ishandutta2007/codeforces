// Megumin top

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> b(k, -1);
    vector<ll> c(k, 1);
    ll cnt = 0;
    ll ptr = 0;
    vector<ll> used(n);
    while (cnt < n) {
        for (ll i = 0; ptr < n && i < k; ++i) {
            if (b[i] == -1) {
                b[i] = ptr;
                c[i] = 1;
                ++ptr;
            }
        }
        ll d = round(100 * (double)cnt / (double)n);
        for (ll i = 0; i < k; ++i) {
            if (b[i] == -1) {
                continue;
            }
            if (c[i] == d) {
                used[b[i]] = 1;
            }
            ++c[i];
        }
        for (ll i = 0; i < k; ++i) {
            if (c[i] == a[b[i]] + 1) {
                b[i] = -1;
                ++cnt;
            }
        }
    }

    ll result = 0;
    for (ll i : used) {
        result += i;
    }
    cout << result << endl;
}

int32_t main() {
    start();
    solve();
    return 0;
}