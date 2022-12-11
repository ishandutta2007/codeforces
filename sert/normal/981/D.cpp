//made by Sert
#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 34;
const int N = (int)1e6 + 34;

typedef long long ll;

bool go(int n, int k, const vector<ll> &a, ll msk) {
    vector<vector<bool>> dp(n + 1);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i].push_back(false);
        }
    }
    dp[0][0] = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            ll sum = 0;
            if (!dp[i][j]) continue;
            for (int q = i; q < n; q++) {
                sum += a[q];
                if ((sum & msk) == msk) {
                    dp[q + 1][j + 1] = true;
                }
            }
        }
    }

    return dp[n][k];
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll l = 0;
    ll r = (1ll << 60ll);
    ll m;
    while (r - l > 1) {
        m = (l + r) / 2;
        if (go(n, k, a, m)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << "\n";
}

int main() {
#ifdef MADE_BY_SERT
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    solve();
    //solve();
#endif
    solve();
    return 0;
}