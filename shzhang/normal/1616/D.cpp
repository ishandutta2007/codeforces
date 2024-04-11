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

int n;
ll a[50005];
int pre[50005];
int f[50005];
ll x;

int access(int loc)
{
    if (loc < 0) return 0;
    return f[loc];
}

void work()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    for (int i = 2; i <= n; i++) a[i] += a[i-1];
    scanf("%lld", &x);
    for (int i = 1; i <= n; i++) a[i] -= x * i;
    int left = 0;
    multiset<ll> vals;
    for (int i = 1; i <= n; i++) {
        //debug("%d", i);
        if (i >= 2) vals.insert(-a[i-2]);
        while (!vals.empty() && -(*vals.begin()) > a[i]) {
            //debug("%d", i);
            vals.erase(vals.find(-a[left])); left++;
        }
        pre[i] = left;
        //printf("%d ", pre[i]);
    }
    //printf("\n");
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = max(access(pre[i] - 1), access(pre[i] - 2)) + i - pre[i];
        ans = max(ans, f[i]);
    }
    printf("%d\n", ans);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}