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

void work()
{
    int x, y; scanf("%d%d", &x, &y);
    if (((x % 2) + 2) % 2 != ((y % 2) + 2) % 2) {
        printf("-1\n");
    } else if (x == 0 && y == 0) {
        printf("0\n");
    } else if (x == y || x == -y) {
        printf("1\n");
    } else {
        printf("2\n");
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}