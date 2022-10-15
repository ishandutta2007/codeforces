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

int cnt[200005][20];

int main()
{
    for (int i = 1; i <= 200000; i++) {
        for (int j = 0; j < 20; j++) {
            cnt[i][j] = cnt[i-1][j] + ((i & (1 << j)) ? 1 : 0);
        }
    }
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int l, r; scanf("%d%d", &l, &r);
        int ans = 0;
        for (int j = 0; j < 20; j++) {
            ans = max(ans, cnt[r][j] - cnt[l-1][j]);
        }
        printf("%d\n", r - l + 1 - ans);
    }
    return 0;
}