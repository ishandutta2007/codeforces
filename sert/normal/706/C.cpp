#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;
const ll INF = 1e18 + 34;

ll n, c[N];
string s[N], r[N];
ll dp[N][2];

int main() {
    init();

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++) {
        cin >> r[i];
        s[i] = r[i];
        reverse(r[i].begin(), r[i].end());
    }

    dp[0][1] = c[0];

    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i][1] = INF;
        if (s[i - 1] <= s[i]) dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        if (s[i - 1] <= r[i]) dp[i][1] = min(dp[i][1], dp[i - 1][0] + c[i]);
        if (r[i - 1] <= s[i]) dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        if (r[i - 1] <= r[i]) dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
    }

    ll ans = min(dp[n - 1][0], dp[n - 1][1]);
    cout << (ans == INF ? -1 : ans);


    return 0;
}