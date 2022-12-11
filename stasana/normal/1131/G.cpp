#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef int64_t ll;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> blocks(n);
    for (ll i = 0; i < n; ++i) {
        ll k;
        cin >> k;
        blocks[i].resize(k);
        for (ll j = 0; j < k; ++j) {
            cin >> blocks[i][j].first;
        }
        for (ll j = 0; j < k; ++j) {
            cin >> blocks[i][j].second;
        }
    }
    vector<ll> height(m);
    vector<ll> cost(m);
    ll q;
    cin >> q;
    for (ll i = 0; q--;) {
        ll k, p;
        cin >> k >> p;
        --k;
        for (ll j = 0; j < blocks[k].size(); ++j, ++i) {
            height[i] = blocks[k][j].first;
            cost[i] = blocks[k][j].second * p;
        }
    }
    vector<ll> left(m);
    vector<ll> mn(m);
    vector<ll> right(m);
    for (ll i = m - 1; i >= 0; --i) {
        right[i] = i + 1;
        while (right[i] < m && right[i] - i < height[i]) {
            right[i] = right[right[i]];
        }
    }
    vector<ll> dp(m + 1, 1e17);
    for (ll i = 0; i < m; ++i) {
        left[i] = i - 1;
        mn[i] = i == 0 ? 0 : dp[i - 1];
        while (left[i] >= 0 && i - left[i] < height[i]) {
            mn[i] = min(mn[i], left[i] == -1 ? 0 : mn[left[i]]);
            left[i] = left[left[i]];
        }
        dp[i] = min(dp[i], cost[i] + (left[i] == -1 ? 0 : mn[i]));
        dp[right[i] - 1] = min(dp[right[i] - 1], (i == 0 ? 0 : dp[i - 1]) + cost[i]);
    }
    cout << dp[m - 1] << endl;
    return 0;
}