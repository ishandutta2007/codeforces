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

int fact[100005];
int ifact[100005];

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

int C(int x, int y)
{
    if (x < y) return 0;
    return mul(fact[x], mul(ifact[y], ifact[x - y]));
}

void work()
{
    int n, k; scanf("%d%d", &n, &k);
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        if ((ll)(k-1) * (ll)(i-1) > (ll)n) continue;
        ans += mul(mul(mul(C(n - (k - 1) * (i - 1), i), fact[i]), fact[n-i]), ifact[n]);
        if (ans >= MOD) ans -= MOD;
    }
    printf("%d\n", ans);
}

int main()
{
    fact[0] = 1;
    for (int i = 1; i <= 100000; i++) fact[i] = mul(i, fact[i-1]);
    ifact[100000] = fpow(fact[100000], MOD - 2);
    for (int i = 99999; i >= 0; i--) ifact[i] = mul(ifact[i+1], i + 1);
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}