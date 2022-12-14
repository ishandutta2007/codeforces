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

const int N = (int) 2e5 + 5, mod = (int) 1e9 + 7, M = 3005;
int pw(int a, int b) { return b != 0? pw(a * a % mod, b >> 1) * (b & 1? a: 1) % mod: 1; }
int f[N], invf[N], pickp[N], pickn[N], sd[N], dest[N], lp[M], rp[M], olp[M], orp[M], lps[M];
int comb(int n, int r) {
    if (n < 0 || r < 0 || n - r < 0) return 0;
    return f[n] * invf[r] % mod * invf[n - r] % mod;
}
int mul(int x, int y) { return x * y % mod; }
int add(int x, int y) { return (x + y + 100 * mod) % mod; }
int sadd(int &x, int y) { return x = add(x, y); }

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    f[0] = invf[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = f[i - 1] * i % mod, invf[i] = pw(f[i], mod - 2);
    int n, m;
    cin >> n >> m;
    int pa, pb;
    cin >> pa >> pb;
    for (int i = 0; i < N; ++i)
        pickp[i] = pw(pa, i) * pw(pw(pb, mod - 2), i) % mod, pickn[i] = pw(pb - pa, i) * pw(pw(pb, mod - 2), i) % mod;
    int k;
    cin >> k;
    for (int j = 0; j < N; ++j) {
        dest[j] = comb(k, j) * pickp[j] % mod * pickn[k - j] % mod;
        sadd(sd[j], add(j == 0? 0: sd[j - 1], dest[j]));
    }
    lp[0] = 1;
    rp[m - 1] = 1;
    for (int d = 0; d < n + 1; ++d) {
        memcpy(olp, lp, sizeof lp);
        memcpy(orp, rp, sizeof rp);
        memset(lp, 0, sizeof lp);
        memset(lps, 0, sizeof lps);
        memset(rp, 0, sizeof rp);
        int sumrp = 0, all = 0, cur_val = 0;
        for (int j = 0; j < m; ++j)
            sadd(all, olp[j]);
        if (d == n) {
            cout << all;
            return 0;
        }
        for (int j = m - 1; j >= 0; --j)
            lps[j] = add(lps[j + 1], olp[j]);
        for (int j = 0; j < m; ++j) {
            sadd(rp[j], -mul(cur_val, dest[m - j - 1]));
            sadd(rp[j], -mul(lps[j + 1], mul(sd[j], dest[m - j - 1])));
            sadd(rp[j], mul(mul(all, sd[j]), dest[m - j - 1]));
//            cout << j << ' ' << all << ' ' << cnt << ' ' << sd[j] << ' ' << dest[m - j - 1] << ' ' << cur_val << ' ' << lps[j + 1] << endl;
            sadd(sumrp, orp[j]);
            sadd(cur_val, mul(sumrp, dest[j + 1]));
        }
        for (int j = 0; j < m; ++j) {
            lp[j] = rp[m - j - 1];
        }
    }





}