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

int pref[5005][5005];

int p[5005]; int n;

void work()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", p + i);
    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pref[i][j] = 0;
        }
    }*/
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pref[i][j] = pref[i][j-1] + (p[j] <= i ? 1 : 0);
        }
    }
    ll ans = 0;
    for (int b = 2; b < n; b++) {
        for (int c = b + 1; c < n; c++) {
            ans += (ll)pref[p[c]][b-1] * (ll)(p[b] - pref[p[b]][c]);
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}