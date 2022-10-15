#include <cstdio>
#include <vector>
#include <set>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>

using namespace std;

#define ll long long

int n;
int x[200005];
int h[200005];
int f[200005][20];
int xh[200005][20];
int nxt[200005][20];
ll nxtcost[200005][20];

int rmq(int rmqa[200005][20], int l, int r)
{
    int ans = 0;
    for (int i = 17; i >= 0; i--) {
        if (l + (1 << i) - 1 <= r) {
            ans = max(ans, rmqa[l][i]); l += (1 << i);
        }
    }
    return ans;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", x + i, h + i);
        xh[i][0] = x[i] + h[i];
    }
    for (int pwr = 1; pwr < 18; pwr++) {
        for (int i = 1; i <= n; i++) {
            xh[i][pwr] = max(xh[i][pwr-1], i + (1 << (pwr - 1)) > n ? 0 : xh[i + (1 << (pwr - 1))][pwr-1]);
        }
    }
    for (int i = 0; i < 18; i++) f[n][0] = n, nxt[n+1][i] = n+1;
    for (int i = n - 1; i >= 1; i--) {
        int l = i, r = n;
        while (l < r) {
            int mid = (l + r) / 2 + 1;
            if (x[mid] <= x[i] + h[i]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (l == i) {
            f[i][0] = i;
        } else {
            f[i][0] = rmq(f, i + 1, l);
        }
        for (int j = 1; j < 18; j++) {
            f[i][j] = max(f[i][j-1], i + (1 << (j - 1)) > n ? 0 : f[i + (1 << (j - 1))][j-1]);
        }
    }
    for (int i = 1; i <= n; i++) {
        nxt[i][0] = f[i][0] + 1;
        nxtcost[i][0] = x[f[i][0] + 1] - rmq(xh, i, f[i][0]);
    }
    for (int pwr = 1; pwr < 18; pwr++) {
        for (int i = 1; i <= n; i++) {
            nxt[i][pwr] = nxt[nxt[i][pwr-1]][pwr-1];
            nxtcost[i][pwr] = nxtcost[i][pwr-1] + nxtcost[nxt[i][pwr-1]][pwr-1];
        }
    }
    int q;
    scanf("%d", &q);
    for (int qry = 1; qry <= q; qry++) {
        int from, to;
        scanf("%d%d", &from, &to);
        if (f[from][0] >= to) {
            printf("0\n"); continue;
        }
        ll ans = 0;
        for (int pwr = 17; pwr >= 0; pwr--) {
            if (nxt[from][pwr] < to) {
                ans += nxtcost[from][pwr];
                from = nxt[from][pwr];
                //printf("reached %d, cost %lld\n", from, ans);
            }
        }
        if (f[from][0] < to) {
            ans += nxtcost[from][0];
        }
        printf("%lld\n", ans);
    }
    //for (int i = 1; i <= n; i++) printf("%d ", f[i][0]);
    return 0;
}