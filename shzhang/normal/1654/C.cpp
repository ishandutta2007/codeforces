#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <map>
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

int n;
ll a[200005];

void work()
{
    scanf("%d", &n);
    ll tot = 0;
    map<ll, int> freq;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i); tot += a[i];
        freq[a[i]]++;
    }
    queue<ll> que; que.push(tot); freq[tot]--;
    int splitcnt = 0;
    while (!que.empty() && splitcnt < n - 1) {
        ll curv = que.front(); que.pop();
        if (freq[curv] < 0) {
            ll val1 = curv / 2;
            ll val2 = (curv + 1) / 2;
            //printf("%lld -> %lld %lld\n", curv, val1, val2);
            freq[val1]--;
            freq[val2]--;
            que.push(val1);
            que.push(val2);
            splitcnt++;
            freq[curv]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (freq[a[i]] != 0) {
            printf("NO\n"); return;
        }
    }
    printf("YES\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}