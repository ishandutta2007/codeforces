// Megumin top

#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef int64_t ll;

inline void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

vector<ll> used;
vector<ll> next_;
bitset<1000006> dp;

ll dfs(ll v) {
    if (used[v]) {
        return 0;
    }
    used[v] = 1;
    return 1 + dfs(next_[v]);
}

inline void solve() {
    ll n, k;
    cin >> n >> k;
    next_.resize(n);
    used.resize(n);
    for (ll i = 0; i < n; ++i) {
        cin >> next_[i];
        --next_[i];
    }
    vector<ll> a;
    ll result = 0;
    ll m = k;
    for (ll i = 0; i < n; ++i) {
        if (used[i]) {
            continue;
        }
        a.emplace_back(dfs(i));
        result += min(2 * m, a.back() - (a.back() & 1));
        m = max((ll)0, m - a.back() / 2);
    }
    for (ll i : a) {
        if (m == 0) {
            break;
        }
        if (i & 1) {
            ++result;
            --m;
        }
    }
    sort(a.begin(), a.end());
    vector<ll> b;
    ll cnt = 1;
    a.emplace_back(-1);
    cout << endl;
    for (ll i = 1; i < a.size(); ++i) {
        if (a[i] == a[i - 1]) {
            ++cnt;
        }
        else {
            ll p = 1;
            while (cnt >= p) {
                b.emplace_back(p * a[i - 1]);
                cnt -= p;
                p <<= 1;
            }
            if (cnt > 0) {
                b.emplace_back(cnt * a[i - 1]);
            }
            cnt = 1;
        }
    }
    dp[0] = 1;
    for (auto i : b) {
        dp |= (dp << i);
    }
    cout << min(n, dp[k] ? k : k + 1) << " " << result << endl;
}

int main() {
    start();
    solve();
    return 0;
}