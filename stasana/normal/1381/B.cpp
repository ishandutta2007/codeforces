// Bipolar disorder is very cool

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef int64_t ll;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n * 2);
    for (ll& i : a) {
        cin >> i;
    }
    ll last = 0;
    vector<ll> len;
    for (ll i = 1; i < (ll)a.size(); ++i) {
        if (a[last] < a[i]) {
            len.emplace_back(i - last);
            last = i;
        }
    }
    len.emplace_back(2 * n - last);
    vector<ll> dp(n + 1);
    dp[0] = 1;
    for (ll x : len) {
        for (ll i = n - x; i >= 0; --i) {
            dp[i + x] |= dp[i];
        }
    }
    if (dp[n]) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    ll t;
    cin >> t;
    while (t) {
        --t;
        solve();
    }
    return 0;
}