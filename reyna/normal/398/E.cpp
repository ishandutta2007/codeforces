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

const int N = (int) 3e5 + 5, mod = (int) 1e9 + 7;
int pw(int a, int b) { return b != 0? pw(a * 1ll * a % mod, b >> 1) * 1ll * (b & 1? a: 1) % mod: 1; }
int n, k;
int dpinv[N], sz[N], pt, f[N], inv[N], cnt[N], p[N], pl[N], mark[N];
int dp[N][20], ans = 1;

int comb(int n, int r) {
    if (n < 0 || r < 0 || n - r < 0)
        return 0;
    return f[n] * 1ll * inv[r] % mod * inv[n - r] % mod;
}
void sadd(int &x, int y) { x += y; while (x >= mod) x -= mod; }
int dfs(int v) {
    if (v < 0 || p[v] < 0) return 0;
    mark[v] = 1;
    int res = 1;
    if (pl[v] >= 0 && !mark[pl[v]])
        res += dfs(pl[v]);
    return res;
}
int q[N], csz[N], to_add[N], t = 0, g[N];
int go(int m = 0, int d = 0, int to_mul = 1) {
    if (m == k) {
        for (int j = 0; j < d; ++j)
            csz[j] = 0;
        for (int j = 0; j < k; ++j)
            csz[q[j]] += sz[j];
#define size size_vector
        vector<int> size;
        for (int j = 0; j < d; ++j)
            if (!mark[csz[j]]++)
                size.push_back(csz[j]);
        for (int j = 0; j < d; ++j)
            mark[csz[j]] = 0;
        for (int j = 0; j < d; ++j)
            to_add[csz[j]]++;
        int res = to_mul;
        if (cnt[1] + to_add[1] + cnt[2] + cnt[2] + to_add[2] + to_add[2] < n) {
            res = (long long) ans * to_mul % mod;
            for (int x : size)
                res = (long long) res * dp[x][to_add[x]] % mod;
        }
        for (int j = 0; j < d; ++j)
            to_add[csz[j]] = 0;
#undef size
        return res;
    }
    int res = 0;
    for (int j = 0; j <= d; ++j) {
        q[m] = j; 
        g[q[m]]++;
        sadd(res, go(m + 1, max(j + 1, d), to_mul * 1ll * max(1, g[q[m]] - 1) % mod));
        g[q[m]]--;
    }
    return res;
}

int32_t main() {
    memset(pl, -1, sizeof pl);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    inv[0] = f[0] = 1;
    for (int j = 1; j < N; ++j) {
        f[j] = f[j - 1] * 1ll * j % mod;
        inv[j] = pw(f[j], mod - 2);
    }
    cin >> n >> k;
    for (int j = 0; j < n; ++j) {
        cin >> p[j];
        p[j]--;
        if (p[j] >= 0)
            pl[p[j]] = j;
    }
    for (int j = 0; j < n; ++j)
        if (p[j] < 0)
            sz[pt++] = 1 + dfs(pl[j]);
    for (int j = 0; j < n; ++j)
        if (p[j] >= 0 && !mark[j]) {
            int x = dfs(j);
            cnt[x]++;
        }
    memset(mark, 0, sizeof mark);
    for (int mask = 0; mask < (1 << k); ++mask) {
        int s = 0;
        for (int j = 0; j < k; ++j)
            if (mask >> j & 1)
                s += sz[j];
        mark[s] = 1;
    }
    for (int j = 1; j <= n; ++j) if (mark[j] || cnt[j]) {
        for (int add = 0; add <= 12; ++add) {
            int c = cnt[j] + add;
            if (add <= 1) {
                if (c * j > n) continue;
                int z = pw(j * 2, mod - 2), cur = pw(j, c) * 1ll * f[c] % mod;
                for (int match = 0; match * 2 <= c; ++match) {
                    sadd(dp[j][add], (long long) cur * inv[c - match - match] % mod * inv[match] % mod);
                    cur = (long long) cur * z % mod;
                }
            } else {
                dp[j][add] = (dp[j][add - 1] * 1ll * j  + dp[j][add - 2] * 1ll * (c - 1) % mod * j) % mod;
            }
        }
        dpinv[j] = pw(dp[j][0], mod - 2);
        for (int add = 1; add <= 12; ++add)
            dp[j][add] = dp[j][add] * 1ll * dpinv[j] % mod;
        ans = ans * 1ll * dp[j][0] % mod;
    }
    memset(mark, 0, sizeof mark);
    cout << go() << endl;
}