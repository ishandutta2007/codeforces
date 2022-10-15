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

ll x[500005];

void work()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", x + i);
    ll cnt[60];
    for (int i = 0; i < 60; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++) {
        for (ll j = 0; j < 60; j++) {
            if (x[i] & (1LL << j)) cnt[j]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ll s1 = 0, s2 = 0;
        for (ll j = 0; j < 60; j++) {
            ll val = (1LL << j) % (ll)MOD;
            if (x[i] & (1LL << j)) {
                s1 += mul(val, cnt[j]);
                if (s1 >= MOD) s1 -= MOD;
                s2 += mul(val, n);
                if (s2 >= MOD) s2 -= MOD;
            } else {
                s2 += mul(val, cnt[j]);
                if (s2 >= MOD) s2 -= MOD;
            }
        }
        ans += mul(s1, s2);
        if (ans >= MOD) ans -= MOD;
    }
    printf("%d\n", ans);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}