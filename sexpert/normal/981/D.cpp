#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

ll pf[55], a[55];
int n, k;
int dp[55][55];

bool can(ll m) {
    for(int i = 0; i < 55; i++)
        for(int j = 0; j < 55; j++)
            dp[i][j] = 0;
    dp[0][0] = 1;
    for(int r = 1; r <= n; r++) {
        for(int i = 1; i <= k; i++) {
            for(int l = 1; l <= r; l++) {
                ll sum = pf[r] - pf[l - 1];
                if((sum & m) == m)
                    if(dp[l - 1][i - 1]) {
                        dp[r][i] = 1;
                    }
            }
        }
    }
    return dp[n][k] > 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pf[i] = pf[i - 1] + a[i];
    }
    ll ans = 0;
    for(ll i = 60; i >= 0; i--) {
        if(can(ans ^ (1ll << i)))
            ans |= (1ll << i);
    }
    cout << ans << '\n';
}