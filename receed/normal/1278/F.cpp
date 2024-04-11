#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int MOD = 998244353, N = 5002;
ll dp[N][N];

ll pw(ll x, ll k) {
    ll r = 1;
    while (k) {
        if (k & 1)
            r = r * x % MOD;
        x = x * x % MOD;
        k >>= 1;
    }
    return r;
}


int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, m, k;
    cin >> n >> m >> k;
    dp[0][0] = 1;
    rep(i, k) {
        for (int j = 1; j <= k; j++)
            dp[i + 1][j] = (dp[i][j] * j + dp[i][j - 1] * (n - j + 1 + MOD) % MOD) % MOD;
    }
    ll rm = pw(m, MOD - 2), pm = 1, ans = 0;
    for (int i = 1; i <= k; i++) {
        pm = pm * rm % MOD;
        ans = (ans + dp[k][i] * pm) % MOD;
    }
    cout << ans;
}