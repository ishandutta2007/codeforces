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

int seed[1000005];
int a[300005];
int seedfreq[1000005];

void work()
{
    vector<int> seedvals;
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    int maxfreq = 0;// int evenfreq = 0;
    for (int i = 1; i <= n; i++) {
        int val = seed[a[i]];
        seedvals.push_back(val);
        seedfreq[val]++; maxfreq = max(maxfreq, seedfreq[val]);
    }
    for (int i = 0; i < seedvals.size(); i++) {
        if (seedvals[i] == 1) continue;
        if (seedfreq[seedvals[i]] % 2 == 0) {
            seedfreq[1] += seedfreq[seedvals[i]];
            seedfreq[seedvals[i]] = 0;
        }
    }
    int q; scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        ll w; scanf("%lld", &w);
        if (w == 0) {
            printf("%d\n", maxfreq);
        } else {
            printf("%d\n", max(seedfreq[1], maxfreq));
        }
    }
    for (int i = 0; i < seedvals.size(); i++) {
        seedfreq[seedvals[i]] = 0;
    }
    seedfreq[1] = 0;
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= 1000000; i++) {
        if (seed[i]) continue;
        for (int j = 1; i * j * j <= 1000000; j++) {
            seed[i * j * j] = i;
        }
    }
    //for (int i = 1; i <= 10; i++) printf("%d ", seed[i]);
    for (int i = 1; i <= t; i++) work();
    return 0;
}