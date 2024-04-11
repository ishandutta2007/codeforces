#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;
#define int long long
int mod = 998244353;
int pw(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b /= 2;
    }
    return res;
}
int inv(int x) {
    return pw(x, mod - 2);
}
vector<int> fac;
vector<vector<int>> pwp, cnkk;
int cnk(int n, int k) {
    if (k > n)
        return 0;
    return fac[n] * inv(fac[k]) % mod * inv(fac[n - k]) % mod;
}
void solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (i == 0) {
                dp[i][j] = 1;
                continue;
            }
            if (j == 0) {
                dp[i][j] = 0;
                continue;
            }
            if (i == 1) {
                dp[i][j] = 0;
                continue;
            }
            int q = j - i + 1;
            q = max(0ll, q);
           //cout << i << ' ' << j << endl;
            for (int t = 0; t <= i; ++t) {
                dp[i][j] += dp[i - t][q] * cnkk[i][i - t] % mod *  pwp[j - q][t] % mod;
                //cout << t << ' ' << q << ' ' << dp[i - t][q] << ' ' << cnk(i, i - t) % mod << " " << pw(j - q, t) % mod << endl;
            }
            dp[i][j] %= mod;
            //cout << i << ' ' << j << ' ' << dp[i][j] << endl << endl;
        }
    }
    cout << dp[n][k];
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n = 1;
    fac.assign(600, 0);
    fac[0] = 1;
    for (int j = 1; j < 600; ++j) {
        fac[j] = fac[j - 1] * j % mod;
    }
    pwp.assign(505, vector<int>(505));
    cnkk.assign(505, vector<int>(505));
    for (int i = 0; i < 505; ++i) {
        for (int j = 0; j < 505; ++j) {
            pwp[i][j] = pw(i, j);
            cnkk[i][j] = cnk(i, j);
        }
    }
    for (int i = 0; i < n; ++i) {
        solve();
    }
}