// Megumin top

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef int64_t ll;

inline void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

const ll MOD = 1e9 + 7;

int main() {
    start();

    ll n;
    cin >> n;
    vector<ll> dp(n + 1);
    dp[0] = 1;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        vector<ll> d;
        for (ll j = 1; j * j <= x; ++j) {
            if (x % j == 0) {
                d.emplace_back(j);
                if (j * j != x) {
                    d.emplace_back(x / j);
                }
            }
        }
        sort(d.begin(), d.end());
        reverse(d.begin(), d.end());
        for (auto i : d) {
            if (i > n) {
                continue;
            }
            dp[i] += dp[i - 1];
            if (dp[i] > MOD) {
                dp[i] -= MOD;
            }
        }
    }
    ll sum = 0;
    for (auto i : dp) {
        sum += i;
    }
    --sum;
    cout << sum % MOD;
    return 0;
}