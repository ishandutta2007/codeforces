#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr int Mod = 998244353;
constexpr int mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<vector<ll>> dp(n, vector<ll>(n + 1, 1e9));
    vector<vector<int>> val(n, vector<int>(n + 1, -1));
    rep(i, n) {
        cin >> val[i][i + 1];
        dp[i][i + 1] = 1;
    }
    FOR(dif, 2, n + 1) {
        rep(l, n) {
            ll r = l + dif;
            if(r > n) break;
            FOR(i, l + 1, r) {
                if(dp[l][i] == 1 && dp[i][r] == 1 && val[l][i] == val[i][r] &&
                   val[l][i] != -1) {
                    val[l][r] = val[l][i] + 1;
                    dp[l][r] = 1;
                } else
                    chmin(dp[l][r], dp[l][i] + dp[i][r]);
            }
        }
    }
    cout << dp[0][n] << endl;

    return 0;
}