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

ll rquery(ll* arr, int v)
{
    if (v <= 0) return 0;
    ll ans = 0;
    while (v) {
        ans += arr[v]; v -= lowbit(v);
    }
    return ans;
}

void modify(ll* arr, int loc, ll val)
{
    //printf("%d %lld\n", loc, val);
    while (loc <= 300000) {
        arr[loc] += val; loc += lowbit(loc);
    }
}

ll query(ll* arr, int l, int r)
{
    return rquery(arr, r) - rquery(arr, l-1);
}

ll freq[300005];
ll mults[300005];

int n;
int a[200005];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    ll ans = 0;
    ll prevsum = 0;
    for (int i = 1; i <= n; i++) {
        ll cnt = 0;
        for (int j = 0; j <= 300000; j += a[i]) {
            cnt += (ll)(j / a[i]) * query(freq, j, min(j + a[i] - 1, 300000));
        }
        ans += prevsum - cnt * (ll)a[i];
        modify(freq, a[i], 1);
        //printf("!%lld ", ans);

        ans += ((ll)a[i] * (ll)(i-1)) - query(mults, 1, a[i]);
        for (int j = a[i]; j <= 300000; j += a[i]) {
            modify(mults, j, a[i]);
        }
        printf("%lld ", ans);
        prevsum += a[i];
    }
    return 0;
}