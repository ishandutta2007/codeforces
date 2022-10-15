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

#define lowbit(x) ((x)&(-(x)))
#define MOD 998244353
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

int ftree[200005];

void modify(int x, int val)
{
    while (x <= 200000) {
        ftree[x] += val;
        x += lowbit(x);
    }
}

int query(int x)
{
    int ans = 0;
    while (x) {
        ans += ftree[x];
        x -= lowbit(x);
    }
    return ans;
}

int pquery(int x)
{
    return query(x) - query(x-1);
}

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

int n, m;

int s[200005];
int t[200005];
int fact[200005];
int ifact[200005];

int main()
{
    fact[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        fact[i] = mul(i, fact[i-1]);
    }
    ifact[200000] = fpow(fact[200000], MOD - 2);
    for (int i = 199999; i >= 0; i--) {
        ifact[i] = mul(i+1, ifact[i+1]);
    }
    scanf("%d%d", &n, &m);
    int prod = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", s + i);
        modify(s[i], 1);
    }
    for (int i = 1; i <= 200000; i++) {
        prod = mul(prod, ifact[pquery(i)]);
    }
    prod = mul(prod, fact[n]);
    for (int i = 1; i <= m; i++) scanf("%d", t + i);
    int ans = 0;
    for (int lcp = 0; lcp <= min(n, m - 1); lcp++) {
        if (lcp < n) {
            int nxtlowcnt = query(t[lcp + 1] - 1);
            int remaining = n - lcp;
            ans += mul(prod, mul(nxtlowcnt, mul(ifact[remaining],
                fact[remaining - 1])));
        } else {
            if (m > n) {
                ans++;
            }
        }
        if (ans >= MOD) ans -= MOD;
        //printf("%d %d %d\n", lcp, ans, prod);
        if (lcp != min(n, m - 1)) {
            int oldfreq = pquery(t[lcp + 1]);
            if (!oldfreq) break;
            prod = mul(prod, mul(fact[oldfreq], ifact[oldfreq - 1]));
            prod = mul(prod, mul(ifact[n - lcp], fact[n - lcp - 1]));
            modify(t[lcp + 1], -1);
        }
    }
    printf("%d", ans);
    return 0;
}