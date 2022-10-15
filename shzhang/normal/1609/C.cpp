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

bool comp[1000005];

int a[200005];

ll solve(vector<int> seq)
{
    /*printf("----\n");
    for (int i = 0; i < seq.size(); i++) {
        printf("%d ", seq[i]);
    }
    printf("\n");*/
    if (seq.empty()) return 0;
    int pre = 0;
    int compcnt = 0, bigcnt = 0;
    ll ans = 0;
    int pre1 = 0;
    for (int i = 0; i < seq.size(); i++) {
        compcnt += (comp[seq[i]] ? 1 : 0);
        bigcnt += (seq[i] > 1 ? 1 : 0);
        while (compcnt || bigcnt >= 2) {
            compcnt -= (comp[seq[pre]] ? 1 : 0);
            bigcnt -= (seq[pre] > 1 ? 1 : 0);
            pre++;
        }
        if (seq[i] != 1) pre1 = i + 1;
        //printf("%d %d\n", i, pre);
        ans += (ll)max(i - pre, 0);
        ans -= (ll)max(i - pre1, 0);
    }
    return ans;
}

void work()
{
    int n, e; scanf("%d%d", &n, &e);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    ll ans = 0;
    for (int i = 0; i < e; i++) {
        vector<int> seq;
        for (int j = i; j <= n; j += e) {
            if (j) seq.push_back(a[j]);
        }
        ans += solve(seq);
    }
    printf("%lld\n", ans);
}

int main()
{
    for (int i = 2; i <= 1000000; i++) {
        if (comp[i]) continue;
        for (int j = i * 2; j <= 1000000; j += i) {
            comp[j] = true;
        }
    }
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}