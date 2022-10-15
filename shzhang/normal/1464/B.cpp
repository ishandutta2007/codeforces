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

char s[100005];
int a[100005];

ll x, y; int n;

#define lowbit(x) ((x)&(-(x)))

int rquery(int* arr, int v)
{
    int ans = 0;
    while (v) {
        ans += arr[v]; v -= lowbit(v);
    }
    return ans;
}

void modify(int* arr, int loc, int val)
{
    while (loc <= n) {
        arr[loc] += val; loc += lowbit(loc);
    }
}

int query(int* arr, int l, int r)
{
    if (l > r) return 0;
    if (l < 1) l = 1;
    if (r > n) r = n;
    return rquery(arr, r) - rquery(arr, l-1);
}

int zquery(int* arr, int l, int r)
{
    return r - l + 1 - query(arr, l, r);
}

int main()
{
    scanf("%s", s + 1);
    scanf("%lld%lld", &x, &y);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            modify(a, i, 1);
        }
    }
    ll curans = 0; ll zerocnt = 0; ll onecnt = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0' || s[i] == '?') {
            //printf("%lld %lld\n", curans, y);
            curans += onecnt * y;
            zerocnt++;
        } else if (s[i] == '1') {
            //printf("%lld %lld %lld\n", curans, x);
            curans += zerocnt * x;
            onecnt++;
        }

    }
    ll ans = curans;
    if (x >= y) {
        for (int i = 1; i <= n; i++) {
            if (s[i] != '?') continue;
            curans -= (ll)query(a, 1, i - 1) * y;
            curans -= (ll)query(a, i + 1, n) * x;
            curans += (ll)zquery(a, 1, i - 1) * x;
            curans += (ll)zquery(a, i + 1, n) * y;
            modify(a, i, 1);
            ans = min(ans, curans);
        }
    } else {
        for (int i = n; i >= 1; i--) {
            //printf("%lld", ans);
            if (s[i] != '?') continue;
            curans -= (ll)query(a, 1, i - 1) * y;
            curans -= (ll)query(a, i + 1, n) * x;
            curans += (ll)zquery(a, 1, i - 1) * x;
            curans += (ll)zquery(a, i + 1, n) * y;
            modify(a, i, 1);
            ans = min(ans, curans);
        }
    }
    printf("%lld", ans);
    return 0;
}