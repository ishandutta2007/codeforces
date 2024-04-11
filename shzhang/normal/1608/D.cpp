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

int fact[100005];
int ifact[100005];

int C(int x, int y)
{
    if (x < 0) return 0;
    if (y < 0 || y > x) return 0;
    return mul(fact[x], mul(ifact[y], ifact[x-y]));
}

int main()
{
    fact[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        fact[i] = mul(i, fact[i-1]);
    }
    ifact[100000] = fpow(fact[100000], MOD - 2);
    for (int i = 99999; i >= 0; i--) {
        ifact[i] = mul(ifact[i+1], i + 1);
    }
    int n; scanf("%d", &n);
    int altways = 1;
    int lb = 0, lempty = 0, rb = 0, rempty = 0;
    for (int i = 1; i <= n; i++) {
        char s[5]; scanf("%s", s);
        if (s[0] == 'B') lb++;
        if (s[0] == '?') lempty++;
        if (s[1] == 'B') rb++;
        if (s[1] == '?') rempty++;
        if (s[0] == s[1]) {
            if (s[0] == '?') altways = mul(altways, 2);
            else altways = 0;
        }

    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += mul(C(rempty, i - rb), C(lempty, n - i - lb));
        //printf("%d\n", ans);
        if (ans >= MOD) ans -= MOD;
    }
    ans -= altways;
    if (lb + lempty == n && rb == 0) {
        ans++; ans %= MOD;
    }
    if (rb + rempty == n && lb == 0) {
        ans++; ans %= MOD;
    }
    printf("%d", ans);
    return 0;
}