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
int a[100005];

void work()
{
    scanf("%d", &n);
    int ones = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        if (a[i]) ones++;
    }
    int ans = 0;
    for (int i = n - ones + 1; i <= n; i++) {
        if (!a[i]) ans++;
    }
    printf("%d\n", ans);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}