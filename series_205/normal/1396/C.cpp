#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) begin(x), end(x)
using namespace std;
using ll = long long;
constexpr ll Mod = 998244353;
constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;
const double PI = acos(-1);
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) {
    return a < b && (a = b, true);
}
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {
    return a > b && (a = b, true);
}
/*-------------------------------------------*/

ll n, a, b, c, d;
ll l[1000009];

ll dp[1000009][2];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> a >> b >> c >> d;
    rep(i, n) cin >> l[i];

    rep(i, n + 1) dp[i][0] = dp[i][1] = inf;

    dp[0][0] = 0;
    rep(i, n) {
        chmin(dp[i + 1][0], dp[i][0] + l[i] * a + c + d);
        chmin(dp[i + 1][1], dp[i][0] + min((l[i] + 1) * a, b) + d);
        chmin(dp[i + 1][0], dp[i][1] + d + a + d + l[i] * a + c + d);
        chmin(dp[i + 1][0],
              dp[i][1] + min((l[i] + 1) * a, b) + d + a + d + a + d);
        // cout << dp[i][0] << " " << dp[i][1] << endl;
    }

    // cout << dp[n][0] << " " << dp[n][1] << endl;
    cout << min({dp[n][0] - d, dp[n][1] + d + a,
                 dp[n - 1][1] + l[n - 1] * a + c + d + a})
         << endl;

    return 0;
}