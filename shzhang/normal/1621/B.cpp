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

int l[100005], r[100005], c[100005];

void work()
{
    int INF = 2100000000;
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d%d", l + i, r + i, c + i);
    int minl = 1000000001, lcost = 0;
    int maxr = 0, rcost = 0;
    int wholecost = INF;
    for (int i = 1; i <= n; i++) {
        if (l[i] < minl) {
            wholecost = INF;
            minl = l[i]; lcost = c[i];
        } else if (l[i] == minl) {
            lcost = min(lcost, c[i]);
        }
        if (r[i] > maxr) {
            wholecost = INF;
            maxr = r[i]; rcost = c[i];
        } else if (r[i] == maxr) {
            rcost = min(rcost, c[i]);
        }
        if (l[i] == minl && r[i] == maxr) {
            wholecost = min(wholecost, c[i]);
        }
        printf("%d\n", min(lcost + rcost, wholecost));
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}