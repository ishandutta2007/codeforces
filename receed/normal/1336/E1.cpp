#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
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

const int N = 200001, M = 1 << 20, R = 1 << 16, K = 36, MOD = 998244353;
ll a[N], dp[K], cs[M], pos[K], d2[R][K];

void add(ll &x, ll y) {
    x += y;
    if (x >= MOD)
        x -= MOD;
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ll n, m, p = 0;
    cin >> n >> m;
    rep(i, n)
        cin >> a[i];
    rep(i, m) {
        for (int j = p; j < n; j++)
            if (a[j] & (1ll << i)) {
                swap(a[j], a[p]);
                break;
            }
        if (!(a[p] & (1ll << i)))
            continue;
        pos[i] = -1;
        rep(j, n)
            if (j != p && (a[j] & (1ll << i)))
                a[j] ^= a[p];
        p++;
    }
    ll d = 1;
    rep(i, n - p)
        d = d * 2 % MOD;
    vector<ll> q {0};
    if (p <= 20) {
        ll sz = 1;
        rep(i, p) {
            rep(j, sz)
                cs[sz + j] = cs[j] ^ a[i];
            sz *= 2;
        }
        rep(i, sz)
            dp[__builtin_popcountll(cs[i])]++;
    }
    else {
        int pp = 0;
        rep(i, m)
            if (pos[i] != -1)
                pos[i] = pp++;
        d2[0][0] = 1;
        rep(i, p) {
            ll cm = 0;
            rep(j, m)
                if (pos[j] != -1 && (a[i] & (1ll << j)))
                    cm |= (1ll << pos[j]);
            for (int k = m - 1; k >= 0; k--)
                rep(j, R)
                    add(d2[j ^ cm][k + 1], d2[j][k]);
        }
        rep(i, R) {
            ll cw = __builtin_popcountll(i);
            rep(j, m + 1)
                if (d2[i][j])
                    add(dp[cw + j], d2[i][j]);
        }
    }
    rep(i, m + 1) {
        dp[i] = dp[i] * d % MOD;
        cout << dp[i] << ' ';
    }
}