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
#define MOD 998244353
#define HALF 499122177
#define SIXTH 166374059
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

int n;
int f[1000005];
int g[1000005];
int psum[1000005];
int psum2[1000005];

int main()
{
    scanf("%d", &n);
    if (n == 1) {
        printf("5"); return 0;
    }
    f[0] = psum[0] = 1;
    g[0] = psum2[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = (f[i-1] + mul(mul(f[i-1], f[i-1] + 1), HALF)) % MOD;
        f[i] += mul(f[i-1], (i >= 2 ? psum[i-2] : 0)); f[i] %= MOD;
        psum[i] = (psum[i-1] + f[i]) % MOD;
        g[i] = (f[i] + MOD - f[i-1]) % MOD;
        psum2[i] = (psum2[i-1] + g[i]) % MOD;
        //printf("%d\n", f[i]);
    }
    int ans = f[n] - f[n-1];
    int val = 0;
    for (int i = 0; i < n - 1; i++) {
        val += mul(mul(f[i], f[i] + 1), HALF);
        if (val >= MOD) val -= MOD;
        if (i) {
            val += mul(f[i], psum[i-1]);
            if (val >= MOD) val -= MOD;
        }
    }
    ans += mul(val, f[n-1]); if (ans >= MOD) ans -= MOD;
    ans += mul(mul(mul(f[n-1], f[n-1] + 1), HALF), psum[n-2]);
    if (ans >= MOD) ans -= MOD;
    ans += mul(mul(mul(f[n-1], f[n-1] + 1), f[n-1] + 2), SIXTH);
    if (ans >= MOD) ans -= MOD;
    ans *= 2; ans %= MOD;
    for (int i = 0; i < n; i++) {
        ans += mul(g[i], psum2[n-1-i]);
        if (ans >= MOD) ans -= MOD;
    }
    printf("%d", ans);
    return 0;
}