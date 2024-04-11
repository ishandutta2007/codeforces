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

int n;
int a[200005];
int eq[200005];

void work()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    a[n+1] = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != a[i-1]) {
            eq[i] = 0;
        } else {
            eq[i] = eq[i-1] + 1;
        }
    }
    int maxv = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == a[i+1]) continue;
        int cur = i;
        int cnt = 1;
        int last = 0;
        while (true) {
            if (i >= n) break;
            if (a[n] - a[i] < 2 * last) break;
            int l = cur + 1; int r = n;
            while (l < r) {
                int mid = (l + r) / 2;
                if (a[mid] - a[i] >= 2 * last) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            cnt++;
            last = a[l] - a[i];
            cur = l;
            //printf("jump %d\n", cur);
        }
        //printf("from %d: %d\n", i, cnt);
        maxv = max(maxv, cnt + eq[i]);
    }
    printf("%d\n", n - maxv);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}