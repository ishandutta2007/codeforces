// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)
#define int long long
const int N = (int) 4e5 + 5, K = 2016, L = 22, mod = (int) 1e9 + 7;
int pw(int a, int b) { return b != 0? pw(a * a % mod, b >> 1) * (b & 1? a: 1) % mod: 1; }
int f[N], inv[N], dp[K][L];
map<pair<int, int>, int> has;
int comb(int n, int r) {
    if (r < 0 || n < 0 || n - r < 0) return 0;
    return f[n] * inv[r] % mod * inv[n - r] % mod;
}
int add(int x, int y) {
    x += y;
    if (x >= mod) x -= mod;
    if (x < 0) x += mod;
    return x;
}
int sadd(int &x, int y) {
    return x = add(x, y);
}
int mul(int x, int y) {
    return x * y % mod;
}
pair<int, int> sr[N];
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    f[0] = inv[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = f[i - 1] * i % mod, inv[i] = pw(f[i], mod - 2);
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    if (!k) {
        cout << s << endl;
        return 0;
    }
    for (int i = 0; i < k; ++i)
        cin >> sr[i].first >> sr[i].second, sr[i].first--, sr[i].second--;
    for (int i = 0; i < k; ++i)
        has[sr[i]] = 1;
    sr[k] = make_pair(0, 0); k++;
    sr[k] = make_pair(n - 1, m - 1); k++;
    sort(sr, sr + k);
    k = unique(sr, sr + k) - sr;
    dp[0][0] = 1;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < i; ++j) {
            int a = sr[i].first - sr[j].first, b = sr[i].second - sr[j].second;
            int ml = comb(a + b, a);
            for (int p = 1; p < L; ++p) {
                sadd(dp[i][p], mul(dp[j][p - 1], ml));
                sadd(dp[i][p], -mul(dp[j][p], ml));
            }
        }
    }
    if (n == 1 && m == 1) {
        cout << ((s + (s & 1)) >> 1) << endl;
        return 0;
    }
    long long res = 0;
    for (int i = 0; i < (has[make_pair(0, 0)] + has[make_pair(n - 1, m - 1)]); ++i) s += s & 1, s >>= 1;
 //   for (int j = 0; j < k; ++j) 
    long long cnt = 0;
    for (int i = 1; i < L; ++i) {
       // cout << " %" << ' ' <<  i << ' ' << dp[k - 1][i] << endl;
        sadd(res, dp[k - 1][i] * s % mod);
        sadd(cnt, dp[k - 1][i]);
        s += s & 1;
        s >>= 1;
    }
    sadd(res, add(comb(n + m - 2, n - 1), -cnt));
    cout << res * pw(comb(n + m - 2, n - 1), mod - 2) % mod;
}