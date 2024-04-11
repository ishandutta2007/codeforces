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

char s1[100005], s2[100005];

void work()
{
    int n; scanf("%d", &n);
    scanf("%s%s", s1 + 1, s2 + 1);
    int one1 = 0, one2 = 0, dif = 0;
    for (int i = 1; i <= n; i++) {
        if (s1[i] == '1') one1++;
        if (s2[i] == '1') one2++;
        if (s1[i] != s2[i]) dif++;
    }
    int ans = n + 1;
    if (one1 == one2) {
        ans = min(ans, dif);
    }
    if (one1 == n + 1 - one2) {
        ans = min(ans, n - dif);
    }
    if (ans == n + 1) {
        printf("-1\n");
    } else {
        printf("%d\n", ans);
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}