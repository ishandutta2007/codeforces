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

char a[200005], b[200005], c[200005];

int n;

void work()
{
    scanf("%d", &n);
    scanf("%s%s%s", a + 1, b + 1, c + 1);
    int x = 1, y = 1, z = 1;
    int pcnt = 0;
    while (x <= 2 * n && y <= 2 * n && z <= 2 * n) {
        int zcnt = 0;
        if (a[x] == '0') zcnt++;
        if (b[y] == '0') zcnt++;
        if (c[z] == '0') zcnt++;
        char use = (zcnt < 2 ? '1' : '0');
        printf("%c", use);
        if (a[x] == use) x++;
        if (b[y] == use) y++;
        if (c[z] == use) z++;
        pcnt++;
    }
    int remain = 3 * n - pcnt;
    if (x <= 2 * n && 2 * n - x + 1 <= remain) {
        printf("%s\n", a + x);
    } else if (y <= 2 * n && 2 * n - y + 1 <= remain) {
        printf("%s\n", b + y);
    } else if (z <= 2 * n && 2 * n - z + 1 <= remain) {
        printf("%s\n", c + z);
    } else {
        printf("\n");
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}