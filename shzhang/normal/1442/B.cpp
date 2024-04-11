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

int pre[200005];
int nxt[200005];
int a[200005], b[200005];
bool needed[200005];

void work()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 1; i <= n; i++) needed[i] = false;
    needed[0] = true;
    for (int i = 1; i <= k; i++) {
        scanf("%d", b + i);
        needed[b[i]] = true;
    }
    int ans = 1;
    for (int i = 1; i < n; i++) {
        nxt[a[i]] = a[i+1];
    }
    nxt[a[n]] = 0;
    for (int i = 2; i <= n; i++) {
        pre[a[i]] = a[i-1];
    }
    pre[a[1]] = 0;
    for (int i = 1; i <= k; i++) {
        int curv = b[i];
        if (needed[pre[curv]] && needed[nxt[curv]]) {
            printf("0\n"); return;
        } else if (needed[pre[curv]]) {
            nxt[curv] = nxt[nxt[curv]];
            if (nxt[curv])
                pre[nxt[curv]] = curv;
        } else {
            if (!needed[nxt[curv]]) {
                ans = ans + ans;
                if (ans >= 998244353) ans -= 998244353;
            }
            pre[curv] = pre[pre[curv]];
            if (pre[curv])
                nxt[pre[curv]] = curv;
        }
        needed[curv] = false;
    }
    printf("%d\n", ans);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}