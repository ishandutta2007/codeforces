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

int deadcnt[200005];
int ans;

void addedge(int u, int v)
{
    if (u > v) swap(u, v);
    if (!deadcnt[u]) ans--;
    deadcnt[u]++;
}

void removeedge(int u, int v)
{
    if (u > v) swap(u, v);
    if (deadcnt[u] == 1) ans++;
    deadcnt[u]--;
}

int main()
{
    scanf("%d%d", &n, &m);
    ans = n;
    for (int i = 1; i <= m; i++) {
        int u, v; scanf("%d%d", &u, &v);
        addedge(u, v);
    }
    int q; scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int op; scanf("%d", &op);
        if (op == 3) {
            printf("%d\n", ans);
        } else {
            int u, v; scanf("%d%d", &u, &v);
            if (op == 1) {
                addedge(u, v);
            } else {
                removeedge(u, v);
            }
        }
    }
    return 0;
}