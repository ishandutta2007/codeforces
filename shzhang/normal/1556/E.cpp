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

int n, q;
ll diff[500005];
ll psum[500005];
ll imin[500005][17], imax[500005][17];

int logval[500005];

ll rmq(int l, int r, bool ismax)
{
    int lg = logval[r-l+1];
    if (ismax) {
        return max(imax[l][lg], imax[r - (1 << lg) + 1][lg]);
    } else {
        return min(imin[l][lg], imin[r - (1 << lg) + 1][lg]);
    }
}

int main()
{
    for (int i = 1; i <= 100000; i++) {
        for (int j = 1; j <= 16; j++) {
            if ((1 << j) <= i) logval[i] = j;
        }
    }
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", diff + i);
    }
    for (int i = 1; i <= n; i++) {
        ll val;
        scanf("%lld", &val);
        diff[i] = val - diff[i];
        psum[i] = psum[i-1] + diff[i];
    }
    for (int i = 1; i <= n; i++) {
        imin[i][0] = imax[i][0] = psum[i];
    }
    for (int pwr = 1; pwr <= 16; pwr++) {
        for (int i = 1; i <= n; i++) {
            imin[i][pwr] = min(imin[i][pwr-1], imin[i + (1 << (pwr - 1))][pwr-1]);
            imax[i][pwr] = max(imax[i][pwr-1], imax[i + (1 << (pwr - 1))][pwr-1]);
        }
    }
    for (int i = 1; i <= q; i++) {
        int l, r; scanf("%d%d", &l, &r);
        if (psum[r] != psum[l-1]) {
            printf("-1\n"); continue;
        }
        ll minps = rmq(l, r, false);
        ll maxps = rmq(l, r, true);
        if (minps < psum[l-1]) {
            printf("-1\n"); continue;
        }
        printf("%lld\n", maxps - psum[l-1]);
    }
    return 0;
}