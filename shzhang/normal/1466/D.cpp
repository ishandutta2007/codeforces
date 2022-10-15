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

ll a[200005];
int deg[200005];

void work()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) deg[i] = 0;
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v); deg[u]++; deg[v]++;
    }
    vector<ll> vals;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= deg[i] - 1; j++) {
            vals.push_back(a[i]);
        }
    }
    sort(vals.begin(), vals.end());
    reverse(vals.begin(), vals.end());
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += a[i];
    printf("%lld ", ans);
    for (int i = 0; i < vals.size(); i++) {
        ans += vals[i];
        printf("%lld ", ans);
    }
    printf("\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}