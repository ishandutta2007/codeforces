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
    ll m, k, n, s;
    cin >> m >> k >> n >> s;
    ll len = k + m - k * n;
    vector<ll> a(m);
    vector<ll> cnt_need(500'666);
    vector<ll> cnt(500'666);
    for (ll i = 0; i < m; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < s; ++i) {
        ll x;
        cin >> x;
        ++cnt_need[x];
    }
    ll sum = s;
    for (ll i = 0; i < len; ++i) {
        if (cnt_need[a[i]]) {
            sum -= max(0LL, cnt_need[a[i]] - cnt[a[i]]);
            ++cnt[a[i]];
            sum += max(0LL, cnt_need[a[i]] - cnt[a[i]]);
        }
    }
    if (sum == 0) {
        cout << len - k << endl;
        ll cnt = len - k;
        for (ll j = 0; j < len; ++j) {
            if (!cnt_need[a[j]]) {
                if (cnt) {
                    cout << j + 1 << " ";
                    --cnt;
                }
            }
            else {
                --cnt_need[a[j]];
            }
        }
        return;
    }
    for (ll i = 1; i + len <= m; ++i) {
        ll id = i + len - 1;
        if (cnt_need[a[id]]) {
            sum -= max(0LL, cnt_need[a[id]] - cnt[a[id]]);
            ++cnt[a[id]];
            sum += max(0LL, cnt_need[a[id]] - cnt[a[id]]);
        }
        if (cnt_need[a[i - 1]]) {
            sum -= max(0LL, cnt_need[a[i - 1]] - cnt[a[i - 1]]);
            --cnt[a[i - 1]];
            sum += max(0LL, cnt_need[a[i - 1]] - cnt[a[i - 1]]);
        }
        if (i % k == 0 && sum == 0) {
            cout << len - k << endl;
            ll cnt = len - k;
            for (ll j = i; j < i + len; ++j) {
                if (!cnt_need[a[j]]) {
                    if (cnt) {
                        cout << j + 1 << " ";
                        --cnt;
                    }
                }
                else {
                    --cnt_need[a[j]];
                }
            }
            return;
        }
    }
    cout << -1 << endl;
}

int32_t main() {
    start();
    solve();
    return 0;
}