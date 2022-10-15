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

#define INF 10000000000000000LL

int n, a[100005];
bool seq1[100005];
bool seq2[100005];

ll solve()
{
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) {
        if (seq1[i]) cnt1++;
        if (seq2[i]) cnt2++;
    }
    if (cnt1 != cnt2) return INF;
    int x = 0, y = 0;
    ll ans = 0;
    for (int i = 1; i <= cnt1; i++) {
        do {x++; } while (!seq1[x]);
        do {y++; } while (!seq2[y]);
        //printf("%d %d\n", x, y);
        ans += (ll)max(x - y, y - x);
    }
    return ans;
}

void work()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) {
        seq1[i] = (a[i] % 2 == 0);
        seq2[i] = (i % 2 == 0);
    }
    ll ans = solve();
    for (int i = 1; i <= n; i++) {
        seq1[i] = (a[i] % 2 == 1);
    }
    ans = min(ans, solve());
    if (ans == INF) {
        printf("-1\n");
    } else {
        printf("%lld\n", ans);
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}