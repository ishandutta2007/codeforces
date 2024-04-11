// Bipolar disorder is very cool

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef int64_t ll;

const ll INF = 1e9;

int main() {
    ll n, h, left, right;
    cin >> n >> h >> left >> right;
    vector<ll> dp(h, -INF);
    dp[0] = 0;
    for (ll i = 0; i < n; ++i) {
        ll y;
        cin >> y;
        vector<ll> new_dp(h, -INF);
        for (ll x = 0; x < h; ++x) {
            ll id;
            id = (x + y) % h;
            new_dp[id] = max(new_dp[id], dp[x] + (ll)(id >= left && id <= right));
            id = (x + y - 1 + h) % h;
            new_dp[id] = max(new_dp[id], dp[x] + (ll)(id >= left && id <= right));
        }
        dp = new_dp;
    }
    ll mx = 0;
    for (ll i = 0; i < h; ++i) {
        mx = max(mx, dp[i]);
    }
    cout << mx << endl;
    return 0;   
}