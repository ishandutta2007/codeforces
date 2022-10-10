#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 3e5 + 5;
const ll INF = 1e18;
ll dp[20][MAXN], a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i < m; i++)
        dp[i][0] = -INF;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int res = 0; res < m; res++) {
            dp[res][i] = -INF;
            if(res%m == 1%m)
                dp[res][i] = max(dp[res][i], a[i] - k);
            ll cand = a[i] + dp[(res + m - 1)%m][i - 1];
            if(res%m == 1%m)
                cand -= k;
            dp[res][i] = max(dp[res][i], cand);
            ans = max(ans, dp[res][i]);
        }
    }
    cout << ans << '\n';
}