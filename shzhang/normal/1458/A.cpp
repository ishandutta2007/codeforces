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

ll Gcd(ll a, ll b)
{
    if (b == 0) return a;
    return Gcd(b, a % b);
}

ll absolute(ll x)
{
    return x < 0 ? -x : x;
}

int n, m;
ll a[200005];
ll b[200005];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    for (int i = 1; i <= m; i++) scanf("%lld", b + i);
    ll val = 0;
    for (int i = 2; i <= n; i++) {
        val = Gcd(val, absolute(a[i] - a[i-1]));
    }
    if (!val) {
        for (int i = 1; i <= m; i++) {
            printf("%lld ", a[1] + b[i]);
        }
        return 0;
    }
    ll mv = a[1] % val;
    for (int i = 1; i <= m; i++) {
        ll newv = (mv + b[i]) % val;
        printf("%lld ", Gcd(newv, val));
    }
    return 0;
}