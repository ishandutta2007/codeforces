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

int t, n;
char st[200005];

void work(void)
{
    scanf("%s", st + 1);
    n = strlen(st + 1);
    int r = 0, p = 0, s = 0;
    for (int i = 1; i <= n; i++) {
        if (st[i] == 'R') r++;
        if (st[i] == 'P') p++;
        if (st[i] == 'S') s++;
    }
    int maxv = max(r, max(p, s));
    char ans;
    if (r == maxv) {
        ans = 'P';
    } else if (p == maxv) {
        ans = 'S';
    } else {
        ans = 'R';
    }
    for (int i = 1; i <= n; i++) printf("%c", ans);
    printf("\n");
}

int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}