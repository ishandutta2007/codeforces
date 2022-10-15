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

ll a[100005];
int cnt[100005];

int n, k;

ll cost(ll amt, ll divs)
{
    divs++;
    return ((amt / divs) + 1LL) * ((amt / divs) + 1LL) * (amt % divs)
        + (amt / divs) * (amt / divs) * (divs - (amt % divs));
}

int main()
{
    //printf("%lld %lld %lld", cost(5, 0), cost(5, 1), cost(5, 2));
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    priority_queue<pair<ll, int> > pq;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += a[i] * a[i];
        if (a[i] == 1) continue;
        pq.push(make_pair(a[i] * a[i] - cost(a[i], 1), i));
    }
    for (int i = 1; i <= k - n; i++) {
        pair<ll, int> entry = pq.top(); pq.pop();
        ans -= entry.first;
        cnt[entry.second]++;
        //printf("%lld %lld\n", entry.first, cost(a[entry.second], cnt[entry.second]));
        if (cnt[entry.second] < a[entry.second] - 1) {
            pq.push(make_pair(cost(a[entry.second], cnt[entry.second]) -
                cost(a[entry.second], cnt[entry.second] + 1), entry.second));
        }
    }
    printf("%lld", ans);
    return 0;
}