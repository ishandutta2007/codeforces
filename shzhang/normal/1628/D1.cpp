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

#define MOD 1000000007
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

int fpow(int base, int exponent)
{
    int ans = 1;
    int cur = base;
    while (exponent) {
        if (exponent & 1) ans = mul(ans, cur);
        cur = mul(cur, cur);
        exponent >>= 1;
    }
    return ans;
}

int fact[1000005], ifact[1000005];

int C(int x, int y)
{
    return mul(fact[x], mul(ifact[y], ifact[x-y]));
}

int inv2[1000005];

void work()
{
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    if (n == m) {
        printf("%d\n", (int)mul(n, k));
        return;
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        ans += mul(m-i, mul(C(i + n - m - 1, i), inv2[n - m + i]));
        if (ans >= MOD) ans -= MOD;
    }
    ans = mul(ans, k);
    printf("%d\n", ans);
}

int main()
{
    fact[0] = 1;
    for (int i = 1; i <= 1000000; i++)
        fact[i] = mul(i, fact[i-1]);
    ifact[1000000] = fpow(fact[1000000], MOD - 2);
    for (int i = 999999; i >= 0; i--)
        ifact[i] = mul(ifact[i+1], i+1);
    inv2[0] = 1; int i2 = fpow(2, MOD - 2);
    for (int i = 1; i <= 1000000; i++)
        inv2[i] = mul(inv2[i-1], i2);
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}