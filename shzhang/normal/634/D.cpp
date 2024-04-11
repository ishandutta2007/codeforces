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

int n, d, m;
/* location, price */
pair<int, int> gas[200010];

int main()
{
    scanf("%d%d%d", &d, &n, &m);
    gas[1].first = 0; gas[1].second = 0;
    gas[2].first = d; gas[2].second = 0;
    for (int i = 3; i <= m + 2; i++) {
        scanf("%d%d", &(gas[i].first), &(gas[i].second));
    }
    sort(gas + 1, gas + m + 3);
    gas[m+3].second = 100000000;
    for (int i = 1; i < m + 2; i++) {
        if (gas[i+1].first - gas[i].first > n) {
            printf("-1"); return 0;
        }
    }
    /* -price, id */
    priority_queue<pair<int, int> > pq;
    int curgas = 1;
    ll oilamt = 0;
    int nxtgas = 2;
    ll ans = 0;
    pq.push(make_pair(0, 0));
    while (oilamt < d) {
        pair<int, int> cur = pq.top(); pq.pop();
        if (gas[cur.second].first < gas[curgas].first) continue;
        if (gas[cur.second].first > gas[curgas].first) curgas = cur.second;
        ll this_amt = min(n + gas[curgas].first - oilamt, gas[nxtgas].first - oilamt);
        if (this_amt != n + gas[curgas].first - oilamt) {
            pq.push(cur);
        }
        ans += (ll)gas[curgas].second * this_amt;
        oilamt += this_amt;
        //printf("buy %lld at price of %d\n", this_amt, gas[curgas].second);
        while (nxtgas <= m + 2 && gas[nxtgas].first <= oilamt) {
            pq.push(make_pair(-gas[nxtgas].second, nxtgas));
            nxtgas++;
        }
    }
    printf("%lld", ans);
    return 0;
}