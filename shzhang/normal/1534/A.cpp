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
char grid[55][55];
char s[55];

void work()
{
    scanf("%d%d", &n, &m);
    bool hasodd = false, haseven = false;
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= m; j++) {
            grid[i][j] = s[j];
            if (grid[i][j] == '.') continue;
            if ((i + j + (grid[i][j] == 'R' ? 0 : 1)) % 2 == 0) {
                haseven = true;
            } else {
                hasodd = true;
            }
        }
    }
    if (haseven && hasodd) {
        printf("NO\n"); return;
    }
    printf("YES\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%c", (i + j + (haseven ? 0 : 1)) % 2 ? 'W' : 'R');
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