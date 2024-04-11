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

using namespace std;

#define ll long long

#define lowbit(x) ((x)&(-(x)))

int n, m;

ll arr[500005];
int a[500005];
int p[500005];
int b[500005];
int bindex[500005];

ll rquery(int v)
{
    v++;
    ll ans = 0;
    while (v) {
        ans += arr[v]; v -= lowbit(v);
    }
    return ans;
}

void modify(int loc, ll val)
{
    loc++;
    while (loc <= m + 1) {
        arr[loc] += val; loc += lowbit(loc);
    }
}

ll query(int l, int r)
{
    return rquery(r) - rquery(l-1);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) scanf("%d", p + i);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) scanf("%d", b + i);
    for (int i = 1; i <= m; i++) bindex[b[i]] = i;
    modify(m, 1000000000000000000LL);
    modify(0, -1000000000000000000LL);
    //printf("%lld", query(m, m));
    for (int i = 1; i <= n; i++) {
        int l = 0; int r = m; int loc = -1; ll loc_new_val = 0;
        if (bindex[a[i]]) {
            //printf("HERE\n");
            loc = bindex[a[i]];
            loc_new_val = query(loc-1, m);
        }
        while (l < r) {
            int mid = (l + r) / 2 + 1;
            if (a[i] > b[mid]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        //printf("i = %d, l = %d\n", i, l);
        if (p[i] < 0) {
            modify(m, p[i]);
        } else {
            modify(l, p[i]);
        }
        if (loc != -1) {
            ll orig = query(loc, m);
            //printf("loc %d, orig %lld, new %lld\n", loc, orig, loc_new_val);
            if (orig <= loc_new_val) continue;
            modify(loc, loc_new_val - orig);
            modify(loc - 1, orig - loc_new_val);
        }
        /*for (int j = 0; j <= m; j++) {
            printf("f[%d][%d] = %lld\n", i, j, query(j, m));
        }*/
    }
    if (query(m, m) >= 10000000000000000LL) {
        printf("NO");
    } else {
        printf("YES\n%lld", query(m, m));
    }
    return 0;
}