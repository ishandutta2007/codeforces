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

int freq[105];

void work()
{
    int n; scanf("%d", &n);
    for (int i = 0; i <= 100; i++) freq[i] = 0;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        if (x < 0) x = -x;
        freq[x]++;
    }
    int ans = 0;
    for (int i = 1; i <= 100; i++) ans += min(freq[i], 2);
    if (freq[0]) ans++;
    printf("%d\n", ans);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}