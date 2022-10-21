#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
const int N = 105;

int mod;
ll fac[N];
ll C[N][N];
ll dp[N][N][N];

ll solve(int n, int x, int k) {
    if(x > n) return 0;

    if (n == 0) {
        return x == 0;
    }

    if(k == 1) {
        return (x == 1) * fac[n];
    }


    if (dp[n][x][k] != -1) return dp[n][x][k];

    dp[n][x][k] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = max(0, i + x - n); j <= min(i - 1, x); j++) {
            dp[n][x][k] += C[n - 1][i - 1] * solve(i - 1, j, k - 1) % mod * solve(n - i, x - j, k - 1);
            dp[n][x][k] %= mod;
        }
    }
//    cout << n << " " << x << " " << k << " " << dp[n][x][k] << endl;
    return dp[n][x][k];
}

int n, m, k;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k >> mod;

    memset(dp, -1, sizeof dp);

    rep(i, 0, N) C[i][0] = 1;
    fac[0] = 1;
    rep(i, 1, N) fac[i] = fac[i - 1] * i % mod;
//    rep(i, 0, N) fac[i][i] = 1;
//    rep(i, 0, N) rep(j, i + 1, N) fac[j][i] = (fac[j - 1][i] * j) % mod;
    rep(i, 1, N) rep(j, 1, i + 1) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;


    cout << solve(n, k, m) << '\n';


}