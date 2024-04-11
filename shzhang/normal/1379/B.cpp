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
    ll l, r; ll m; scanf("%lld%lld%lld", &l, &r, &m);
    for (ll a = l; a <= r; a++) {
        ll below = (m / a) * a;
        for (int idx = 0; idx < 2; idx++) {
            if (!below) {
                below += a; continue;
            }
            if (l - r <= m - below && m - below <= r - l) {
                ll b = l + min(m - below - (l - r), r - l);
                ll c = below + b - m;
                printf("%lld %lld %lld\n", a, b, c); goto loop_end;
            }
            below += a;
        }
    }
    loop_end:
    ;
}

int main()
{
    int T; scanf("%d", &T);
    for (int i = 1; i <= T; i++) work();
    return 0;
}