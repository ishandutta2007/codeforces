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
int a[100005], b[100005];
int as[100005], bs[100005];

void work()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) scanf("%d", b + i);
    sort(a + 1, a + n + 1); reverse(a + 1, a + n + 1);
    sort(b + 1, b + n + 1); reverse(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
        as[i] = as[i-1] + a[i];
        bs[i] = bs[i-1] + b[i];
    }
    int l = 0; int r = 3 * n;
    while (l < r) {
        int mid = (l + r) / 2;
        int high_stages = (n + mid) - (n + mid) / 4;
        int your_score = mid * 100 + as[high_stages - mid];
        int ilya_score = bs[min(high_stages, n)];
        if (your_score >= ilya_score) {
            r = mid;
        } else {
            l = mid + 1;
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