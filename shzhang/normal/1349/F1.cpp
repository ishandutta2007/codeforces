#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

#define MOD 998244353
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

int fpow(int base, int exponent)
{
    int ans = 1;
    int cur = base;
    while (exponent) {
        if (exponent & 1) ans = mul(ans, cur);
        cur = mul(cur, cur); exponent >>= 1;
    }
    return ans;
}

int fact[5005];
int ifact[5005];
int inv[5005];
int f[5005][5005];

int ans[5005];

int main()
{
    fact[0] = 1;
    for (int i = 1; i <= 5000; i++) fact[i] = mul(i, fact[i-1]);
    ifact[5000] = fpow(fact[5000], MOD - 2);
    for (int i = 4999; i >= 0; i--) ifact[i] = mul(ifact[i+1], i+1);
    for (int i = 1; i <= 5000; i++) inv[i] = mul(fact[i-1], ifact[i]);
    f[1][0] = 1;
    for (int i = 1; i <= 5000; i++) {
        for (int j = 0; j < i; j++) {
            f[i+1][j+1] += mul(f[i][j], i-j);
            f[i+1][j] += mul(f[i][j], j+1);
            if (f[i+1][j+1] >= MOD) f[i+1][j+1] -= MOD;
            if (f[i+1][j] >= MOD) f[i+1][j] -= MOD;
        }
    }
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ans[i] += mul(f[j][i-1], mul(fact[n], ifact[j]));
            if (ans[i] >= MOD) ans[i] -= MOD;
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
}