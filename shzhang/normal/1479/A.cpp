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

int query(int pos)
{
    printf("? %d\n", pos);
    fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int main()
{
    int n; scanf("%d", &n);
    int l = 1; int r = n;
    while (true) {
        if (l == r) {
            printf("! %d\n", l); return 0;
        }
        int a = (l + r) / 2;
        int b = (l + r) / 2 + 1;
        int av = query(a);
        int bv = query(b);
        if (av < bv) {
            r = a;
        } else {
            l = b;
        }
    }
    return 0;
}