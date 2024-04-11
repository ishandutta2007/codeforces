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

int n, k;

int len[3005];
ll tot[3005];
int arr[3005][3005];
ll stk[3005][3005];
int stktop = 0;
ll excl[3005][3005];

void push(int x)
{
    for (int i = 0; i <= k; i++) {
        stk[stktop + 1][i] = stk[stktop][i];
    }
    for (int i = 0; i + len[x] <= k; i++) {
        stk[stktop + 1][i + len[x]] = max(stk[stktop + 1][i + len[x]],
            stk[stktop][i] + tot[x]);
    }
    stktop++;
}

void work(int l, int r)
{
    int stk_cur = stktop;
    if (l == r) {
        for (int i = 0; i <= k; i++) excl[l][i] = stk[stktop][i];
        return;
    }
    for (int i = l; i <= (l + r) / 2; i++) {
        push(i);
    }
    work((l + r) / 2 + 1, r);
    stktop = stk_cur;
    for (int i = (l + r) / 2 + 1; i <= r; i++) {
        push(i);
    }
    work(l, (l + r) / 2);
    stktop = stk_cur;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", len + i);
        for (int j = 1; j <= len[i]; j++) {
            int x; scanf("%d", &x);
            if (j <= k) {
                arr[i][j] = x;
                tot[i] += x;
            }
        }
        len[i] = min(len[i], k);
    }
    for (int i = 1; i <= k; i++) {
        stk[0][i] = -1000000000000000000LL;
        //suf[i][j] = -1000000000000000000LL;
    }
    work(1, n);
    //printf("%lld\n", excl[1][0]);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll prefsum = 0;
        for (int j = 0; j <= len[i]; j++) {
            if (j) prefsum += arr[i][j];
            ans = max(ans, excl[i][k - j] + prefsum);
        }
    }
    printf("%lld", ans);
    return 0;
}