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

int fact[500005];
int ifact[500005];

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
    return mul(fact[x], mul(ifact[y], ifact[x-y]));
}

int n;
int a[500005];

int main()
{
    fact[0] = 1;
    for (int i = 1; i <= 500000; i++)
        fact[i] = mul(i, fact[i-1]);
    ifact[500000] = fpow(fact[500000], MOD - 2);
    for (int i = 499999; i >= 0; i--)
        ifact[i] = mul(ifact[i+1], i+1);
    scanf("%d", &n);
    for (int i = 1; i <= n + 1; i++) scanf("%d", a + i);
    int ans = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (a[i]) {
            ans += C(i - 1 + a[i], i);
            ans %= MOD;
        }
    }
    printf("%d", ans);
    return 0;
}