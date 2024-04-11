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

int n, m;

char* grid[1000005];

int cnt[1000005];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        grid[i] = new char[m + 5];
        scanf("%s", grid[i] + 1);
    }
    for (int i = 1; i < n; i++) {
        for (int j = 2; j <= m; j++) {
            if (grid[i][j] == 'X' && grid[i+1][j-1] == 'X') {
                cnt[j-1]++;
            }
        }
    }
    for (int i = 1; i <= m; i++) cnt[i] += cnt[i-1];
    int q; scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int l, r; scanf("%d%d", &l, &r);
        printf("%s\n", cnt[r-1] == cnt[l-1] ? "YES" : "NO");
    }
    return 0;
}