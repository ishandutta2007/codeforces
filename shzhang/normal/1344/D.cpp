#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <utility>

using namespace std;

#define ll long long

int n; ll k;
ll a[100005];
ll ans[100005];

#define sq(x) ((x)*(x))
#define updiv(x, y) ((x) % (y) == 0 ? (x) / (y) : (x) / (y) + 1)

ll rddiv(ll val)
{
    if (val >= 0) return val / 2LL;
    return -updiv(-val, 2LL);
}

/* take everything that is at least marginal */
bool check(ll marginal)
{
    ll total_ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] - 1LL < marginal) {
            ans[i] = 0; continue;
        }
        ll l = 1; ll r = a[i];
        while (l < r) {
            ll mid = (l + r) / 2LL + 1LL;
            ll n_marginal = -3LL * sq(mid-1) - 3LL * (mid - 1) + a[i] - 1;
            if (n_marginal >= marginal) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        ans[i] = l;
        total_ans += ans[i];
    }
    return total_ans >= k;
}

int main()
{
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    ll l = -4000000000000000000LL; ll r = 10000000000LL;
    while (l < r) {
        //printf("%lld %lld\n", l, r);
        ll mid = rddiv(l + r) + 1LL;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    check(l);
    ll total = 0;
    for (int i = 1; i <= n; i++) total += ans[i];
    ll remain = total - k;
    for (int i = 1; i <= n; i++) {
        if (remain > 0 && (-3LL * sq(ans[i]-1) - 3LL * (ans[i] - 1) + a[i] - 1) == l) {
            ans[i]--; remain--;
        }
    }
    for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
    return 0;
}