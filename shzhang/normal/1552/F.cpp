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

#define MOD 998244353
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

int n;

int x[200005], y[200005], s[200005];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", x + i, y + i, s + i);
    }
    priority_queue<pair<int, int> > pq;
    int nsum = 0;//, dsum = 0;
    int ans = (x[n] + 1) % MOD;
    for (int i = n; i >= 1; i--) {
        while (!pq.empty() && pq.top().first > x[i]) {
            pair<int, int> pr = pq.top();
            pq.pop();
            nsum -= pr.second; if (nsum < 0) nsum += MOD;
            //dsum -= mul(x[n] - pr.first, pr.second);
            //if (dsum < 0) dsum += MOD;
        }
        int cnt = nsum;
        ans += mul(x[i] - y[i], nsum);
        if (ans >= MOD) ans -= MOD;
        if (s[i]) {
            ans += x[i] - y[i]; if (ans >= MOD) ans -= MOD;
            cnt++; if (cnt >= MOD) cnt -= MOD;
        }
        pq.push(make_pair(y[i], cnt));
        nsum += cnt; if (nsum >= MOD) nsum -= MOD;
        //dsum += mul(x[n] - y[i], cnt); if (dsum >= MOD) dsum -= MOD;
        //printf("%d\n", ans);
    }
    printf("%d", ans);
    return 0;
}