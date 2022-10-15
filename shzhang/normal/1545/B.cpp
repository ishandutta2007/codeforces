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
        cur = mul(cur, cur);
        exponent >>= 1;
    }
    return ans;
}

int fact[100005];
int ifact[100005];

char s[100005];

void work()
{
    int n; scanf("%d", &n); scanf("%s", s + 1);
    int blank = 0, pr = 0;
    int curcnt = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            pr += curcnt / 2;
            curcnt = 0;
            blank++;
        } else {
            curcnt++;
        }
    }
    pr += curcnt / 2;
    printf("%lld\n", mul(fact[pr + blank], mul(ifact[pr], ifact[blank])));
}

int main()
{
    fact[0] = 1;
    for (int i = 1; i <= 100000; i++) fact[i] = mul(i, fact[i-1]);
    for (int i = 0; i <= 100000; i++) ifact[i] = fpow(fact[i], MOD - 2);
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}