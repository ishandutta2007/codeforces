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

#define updiv(a, b) ((a) % (b) == 0 ? (a) / (b) : ((a) / (b)) + 1)

int n, k;

int ans[1005][1005];
int maxc = 0;

void solve(int l, int r, int c)
{
    if (l == r) return;
    maxc = max(maxc, c);
    int blksiz = updiv(r - l + 1, k);
    for (int i = l; i <= r; i++) {
        int blk1 = (i - l) / blksiz;
        for (int j = l + 1; j <= r; j++) {
            int blk2 = (j - l) / blksiz;
            if (blk1 != blk2) {
                ans[i][j] = c;
            }
        }
    }
    for (int i = l; i <= r; i += blksiz) {
        solve(i, min(r, i + blksiz - 1), c + 1);
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    solve(1, n, 1);
    printf("%d\n", maxc);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            printf("%d ", ans[i][j]);
        }
    }
    return 0;
}