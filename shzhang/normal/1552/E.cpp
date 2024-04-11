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
int a[10005];
int l[105], r[105];
int last[105];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n * k; i++) {
        scanf("%d", a + i);
    }
    int remain = n;
    while (remain) {
        for (int i = 1; i <= n; i++) last[i] = 0;
        for (int i = 1; i <= n * k; i++) {
            if (l[a[i]]) continue;
            if (last[a[i]]) {
                l[a[i]] = last[a[i]];
                r[a[i]] = i;
                //debug("%d %d %d", l[a[i]], r[a[i]]);
                for (int j = 1; j <= n; j++) last[j] = 0;
                remain--;
            }
            last[a[i]] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", l[i], r[i]);
    }
    return 0;
}