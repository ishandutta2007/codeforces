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

int a[100005], b[100005];
int seq[100005];
int pmax[100005], smin[100005];
int ans[100005];

bool cmp(int x, int y)
{
    if (a[x] != a[y]) return a[x] < a[y];
    return false;
}

void work()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) scanf("%d", b + i);
    for (int i = 1; i <= n; i++) seq[i] = i;
    sort(seq + 1, seq + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        pmax[i] = max(pmax[i-1], b[seq[i]]);
    }
    smin[n+1] = 1000000001;
    for (int i = n; i >= 1; i--) {
        smin[i] = min(smin[i+1], b[seq[i]]);
    }
    int maxbound = 0;
    for (int i = 1; i < n; i++) {
        if (pmax[i] < smin[i+1]) maxbound = i;
    }
    for (int i = 1; i <= n; i++) ans[i] = 0;
    for (int i = maxbound + 1; i <= n; i++) {
        ans[seq[i]] = 1;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d", ans[i]);
    }
    printf("\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}