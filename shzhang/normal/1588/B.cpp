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

ll query(int l, int r)
{
    printf("? %d %d\n", l, r);
    fflush(stdout);
    ll ans; scanf("%lld", &ans);
    if (ans == -1) exit(0);
    return ans;
}

void work()
{
    int n; scanf("%d", &n);
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) / 2 + 1;
        ll res = query(l, mid);
        if (res) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    int ansi = l;
    int ansj = ansi + (int)(query(ansi, n) - query(ansi + 1, n)) + 1;
    int ansk = ansj + (int)(query(ansj, n) - query(ansj + 1, n));
    printf("! %d %d %d\n", ansi, ansj, ansk);
    fflush(stdout);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}