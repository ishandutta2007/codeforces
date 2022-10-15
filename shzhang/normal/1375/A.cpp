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

int a[105]; int n;

int absolute(int x)
{
    return x > 0 ? x : -x;
}
void work(void)
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) {
        printf("%d ", i % 2 ? absolute(a[i]) : -absolute(a[i]));
    }
    printf("\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i =  1; i <= t; i++) work();
    return 0;
}