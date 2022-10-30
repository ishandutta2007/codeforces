
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpll = vector<pll>;
using vvll = vector<vll>;

ll MOD = 1000000007;

int main(){
    ll n, m;
    cin >> n >> m;
    vector<string> kaart(n);
    for (ll i = 0; i < n; ++i) cin >> kaart[i];
    if (kaart[n - 1][m - 1] == 'R'){
        cout << 0 << endl;
        return 0;
    }
    if (n == 1 && m == 1){
        cout << 1 << endl;
        return 0;
    }
    vvll right_rocks(n, vll(m)), down_rocks(n, vll(m)),
            right_dp(n, vll(m)), down_dp(n, vll(m)),
            right_prefix(n, vll(m)), down_prefix(n, vll(m));
    for (ll i = n - 1; i >= 0; --i) for (ll j = m - 1; j >= 0; --j){
        if (j + 1 < m){
            right_rocks[i][j] = right_rocks[i][j + 1];
            if (kaart[i][j + 1] == 'R') ++right_rocks[i][j];
        }
        if (i + 1 < n){
            down_rocks[i][j] = down_rocks[i + 1][j];
            if (kaart[i + 1][j] == 'R') ++down_rocks[i][j];
        }
    }
    right_dp[n - 1][m - 1] = down_dp[n - 1][m - 1] = 1;
    for (ll i = n - 1; i >= 0; --i) for (ll j = m - 1; j >= 0; --j){
        if (j + 1 < m){
            right_prefix[i][j] = (right_prefix[i][j + 1] + down_dp[i][j + 1]) % MOD;
            right_dp[i][j] = (right_prefix[i][j] - right_prefix[i][m - 1 - right_rocks[i][j]] + MOD) % MOD;
        }
        if (i + 1 < n){
            down_prefix[i][j] = (down_prefix[i + 1][j] + right_dp[i + 1][j]) % MOD;
            down_dp[i][j] = (down_prefix[i][j] - down_prefix[n - 1 - down_rocks[i][j]][j] + MOD) % MOD;
        }
    }
    cout << (right_dp[0][0] + down_dp[0][0]) % MOD << endl;
    return 0;
}