#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e4 + 7;
const double EPS = 1e-8;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    ll n, w, b, x;
    cin >> n >> w >> b >> x;
    vector <ll> c(n), cost(n);
    for (ll i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> cost[i];
    }
    vector <vector <ll> > dp(n + 1, vector <ll> (MAXN, -1));
    dp[0][0] = w;
    ll sum = 0;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j <= sum; j++) {
            if (dp[i - 1][j] == -1) continue;
            for (ll k = 0; k <= c[i - 1]; k++) {
                dp[i][j + k] = max(dp[i][j + k], min(dp[i - 1][j] + x, w + b * j) - cost[i - 1] * k);
            }
        }
        sum += c[i - 1];
    }
    for (ll i = sum; i >= 0; i--) {
        if (dp[n][i] != -1) {
            cout << i;
            return 0;
        }
    }
    assert(false);
}