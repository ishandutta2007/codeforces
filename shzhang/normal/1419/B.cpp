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

void work(void)
{
    ll x; scanf("%lld", &x);
    int ans = 0;
    for (ll i = 1; i <= 2500000000LL; i *= 2, i++) {
        if (((1LL + i) * i) / 2LL <= x) ans++, x -= ((1LL + i) * i) / 2LL;
    }
    printf("%d\n", ans);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}