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

ll b_val[200005];
ll a_val[200005];
ll cnt[200005];

int n, k; ll a, b; int q;

ll rquery(ll* arr, int v)
{
    ll ans = 0;
    while (v) {
        ans += arr[v]; v -= lowbit(v);
    }
    return ans;
}

void modify(ll* arr, int loc, ll val)
{
    //printf("%d %lld\n", loc, val);
    while (loc <= n) {
        arr[loc] += val; loc += lowbit(loc);
    }
}

ll query(ll* arr, int l, int r)
{
    return rquery(arr, r) - rquery(arr, l-1);
}


int main()
{
    scanf("%d%d%lld%lld%d", &n, &k, &a, &b, &q);
    for (int qry = 1; qry <= q; qry++) {
        int typ;
        scanf("%d", &typ);
        if (typ == 1) {
            int day; ll amt;
            scanf("%d%lld", &day, &amt);
            if (cnt[day] < a) {
                modify(a_val, day, min(amt, a - cnt[day]));
            }
            if (cnt[day] < b) {
                modify(b_val, day, min(amt, b - cnt[day]));
            }
            cnt[day] += amt;
        } else {
            /*for (int i = 1; i <= n; i++) {
                printf("%lld ", query(a_val, i, i));
            }
            printf("\n");
            for (int i = 1; i <= n; i++) {
                printf("%lld ", query(b_val, i, i));
            }
            printf("\n");*/
            int day; scanf("%d", &day);
            ll ans = query(b_val, 1, day - 1) + query(a_val, day + k, n);
            printf("%lld\n", ans);
        }
    }
    return 0;
}