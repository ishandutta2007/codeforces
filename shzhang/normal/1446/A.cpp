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

int n; ll W;
ll w[200005];

void work()
{
    scanf("%d%lld", &n, &W);
    ll tot = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", w + i);
        if (w[i] <= W) tot += w[i];
    }
    if (tot * 2 < W) {
        printf("-1\n"); return;
    } else {
        for (int i = 1; i <= n; i++) {
            if (w[i] * 2LL >= W && w[i] <= W) {
                printf("1\n%d\n", i); return;
            }
        }
        ll curtot = tot;
        vector<int> seq;
        for (int i = 1; i <= n; i++) {
            if (w[i] <= W) seq.push_back(i);
        }
        while (curtot > W) {
            curtot -= w[seq.back()]; seq.pop_back();
        }
        printf("%d\n", (int)seq.size());
        for (int i = 0; i < seq.size(); i++) {
            printf("%d ", seq[i]);
        }
        printf("\n");
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}