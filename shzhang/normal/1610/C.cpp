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

int a[200005], b[200005];

bool check(int cnt)
{
    int cur = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= cnt - cur && b[i] >= cur - 1) {
            cur++;
            if (cur >= cnt + 1) return true;
        }
    }
    return false;
}

void work()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", a + i, b + i);
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) / 2 + 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    printf("%d\n", l);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}