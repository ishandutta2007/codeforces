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

#define MOD 1000000007

#define lowbit(x) ((x)&(-(x)))

int n;

int rquery(int* arr, int v)
{
    int ans = 0;
    while (v) {
        ans += arr[v]; if (ans >= MOD) ans -= MOD;
        v -= lowbit(v);
    }
    return ans;
}

int query(int* arr, int l, int r)
{
    return (((rquery(arr, r) - rquery(arr, l - 1)) % MOD) + MOD) % MOD;
}

void modify(int* arr, int loc, int val)
{
    //printf("%d %lld\n", loc, val);
    while (loc <= 2 * n) {
        arr[loc] += val; if (arr[loc] >= MOD) arr[loc] -= MOD;
        loc += lowbit(loc);
    }
}

int a[400005], b[400005];
int taskid[400005];
bool isleft[400005];

bool inset[400005];

int stat_l[400005], stat_r[400005];
int reach[400005];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", a + i, b + i);
        taskid[a[i]] = taskid[b[i]] = i;
        isleft[a[i]] = true;
    }
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int s; scanf("%d", &s);
        inset[s] = true;
    }
    int oncnt = 0;
    for (int i = 2 * n; i >= 1; i--) {
        if (!isleft[i]) continue;
        int id = taskid[i];
        bool on = inset[id];
        if (!on) {
            //int num = query(stat_l, b[id] + 1, 2 * n)
            //    + query(stat_r, a[id] + 1, b[id] - 1);
            int num = query(stat_r, a[id] + 1, b[id] - 1);
            if (num < oncnt) on = true;
        }
        if (on) {
            oncnt++;
            modify(stat_l, a[id], 1);
            modify(stat_r, b[id], 1);
            inset[id] = true;
        }
    }
    /*for (int i = 1; i <= n; i++) {
        if (inset[i]) printf("%d\n", i);
    }*/
    int ans = 0;
    for (int i = 2 * n; i >= 1; i--) {
        if (!isleft[i]) continue;
        int id = taskid[i];
        //printf("! %d\n", id);
        int reachv = rquery(reach, b[id]);
        reachv++; if (reachv >= MOD) reachv -= MOD;
        modify(reach, b[id] + 1, reachv);
        if (inset[id])
            ans += reachv;
        if (ans >= MOD) ans -= MOD;
    }
    printf("%d\n", ans);
    return 0;
}