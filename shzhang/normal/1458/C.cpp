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

int col[3][1000005];
int colinc[3];
int ans[1005][1005];

int n, m;

char s[100005];

#define add(x, y) ((((((x) - 1 + (y)) % n) + n) % n) + 1)

void work()
{
    scanf("%d%d", &n, &m);
    int cur = 1;
    colinc[0] = colinc[1] = colinc[2] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x; scanf("%d", &x);
            col[0][cur] = i; col[1][cur] = j; col[2][cur] = x;
            cur++;
        }
    }
    int c1 = 0, c2 = 1, c3 = 2;
    scanf("%s", s + 1);
    for (int i = 1; i <= m; i++) {
        if (s[i] == 'R') {
            colinc[c2]++;
        } else if (s[i] == 'L') {
            colinc[c2]--;
        } else if (s[i] == 'U') {
            colinc[c1]--;
        } else if (s[i] == 'D') {
            colinc[c1]++;
        } else if (s[i] == 'I') {
            swap(c2, c3);
        } else {
            swap(c1, c3);
        }
    }
    for (int i = 1; i <= n * n; i++) {
        ans[add(col[c1][i], colinc[c1])][add(col[c2][i], colinc[c2])] =
            add(col[c3][i], colinc[c3]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", ans[i][j]);
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