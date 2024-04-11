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
#include <map>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

int a[200005];

void work()
{
    int n, x; scanf("%d%d", &n, &x);
    map<int, int> st;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i); st[a[i]]++;
    }
    sort(a + 1, a + n + 1);
    int pairs = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] % x == 0 && st[a[i]] && st[a[i] / x]) {
            pairs++;
            st[a[i]]--;
            st[a[i] / x]--;
        }
    }
    printf("%d\n", n - 2 * pairs);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}