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

int n, m;
ll a[200005];
ll l[200005], r[200005];
int x[200005], y[200005];
ll f[200005][2];

void work()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    sort(a + 1, a + n + 1);
    vector<pair<int, int> > intvs;
    for (int i = 1; i <= m; i++) {
        int L, R; scanf("%d%d", &L, &R);
        intvs.push_back(make_pair(L, R));
    }
    sort(intvs.begin(), intvs.end());
    reverse(intvs.begin(), intvs.end());
    m = 0;
    for (int i = 0; i < intvs.size(); i++) {
        if (m == 0 || intvs[i].second < r[m]) {
            m++; l[m] = intvs[i].first; r[m] = intvs[i].second;
            //printf("%lld %lld\n", l[m], r[m]);
        }
    }
    //printf("\n");
    reverse(l + 1, l + m + 1);
    reverse(r + 1, r + m + 1);
    //for (int i = 1; i <= m; i++) printf("%lld %lld\n", l[i], r[i]);
    int p1 = 1, p2 = 1;
    for (int i = 1; i <= n; i++) {
        while (p1 <= m && r[p1] < a[i]) p1++;
        while (p2 <= m && l[p2] <= a[i]) p2++;
        x[i] = p1; y[i] = p2 - 1;
        //printf("%d %d\n", x[i], y[i]);
    }
    x[n+1] = y[n+1] = m+1;
    a[0] = -1000000000000000000LL;
    a[n+1] = 1000000000000000000LL;
    l[0] = r[0] = -1000000000000000000LL;
    l[m+1] = r[m+1] = 1000000000000000000LL;
    for (int i = 1; i <= n + 1; i++) {
        if (!(y[i-1] + 1 < x[i])) {
            f[i][0] = f[i][1] = f[i-1][0];
        } else {
            f[i][0] = f[i][1] = 1000000000000000000LL;
            for (int k = y[i-1] + 1; k <= x[i]; k++) {
                ll ldist = max(l[k-1] - a[i-1], 0LL);
                ll rdist = max(a[i] - r[k], 0LL);
                f[i][0] = min(f[i][0], f[i-1][0] + 2 * ldist + rdist);
                f[i][0] = min(f[i][0], f[i-1][1] + ldist + rdist);
                f[i][1] = min(f[i][1], f[i-1][0] + 2 * ldist + 2 * rdist);
                f[i][1] = min(f[i][1], f[i-1][1] + ldist + 2 * rdist);
            }
        }
        //printf("%lld %lld\n", f[i][0], f[i][1]);
    }
    printf("%lld\n", min(f[n+1][0], f[n+1][1]));
    //printf("\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}