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
#include <ext/pb_ds/assoc_container.hpp>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int K = 30, N = 500001, MOD = 998244353;
int ps[K][N], mx[K][N];
ll dp[N];

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k, m, l, r, x;
    cin >> n >> k >> m;
    rep(i, k)
        rep(j, n)
            mx[i][j] = -1;
    rep(i, m) {
        cin >> l >> r >> x;
        l--; r--;
        rep(j, k) {
            if (x & (1 << j)) {
                ps[j][l]++;
                ps[j][r + 1]--;
            }
            else
                mx[j][r] = max(mx[j][r], l);
        }
    }
    ll ans = 1;
    rep(i, k) {
        memset(dp, 0, N * sizeof(ll));
        dp[0] = 1;
        ll sm = 1, pos = 0;
        rep(j, n) {
            ps[i][j + 1] += ps[i][j];
            if (ps[i][j] == 0) {
                dp[j + 1] = sm;
                sm = sm * 2 % MOD;
            }
            while (pos <= mx[i][j]) {
                sm = (sm + MOD - dp[pos]) % MOD;
                pos++;
            }
        }
        ans = ans * sm % MOD;
    }
    cout << ans;
}