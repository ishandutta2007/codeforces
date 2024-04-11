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

void work()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    int equalcnt = 0;
    int first = n + 1, last = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i+1]) {
            equalcnt++;
            first = min(first, i);
            last = max(last, i);
        }
    }
    if (equalcnt <= 1) {
        printf("0\n");
    } else if (last - first == 1) {
        printf("1\n");
    } else {
        printf("%d\n", last - first - 1);
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}