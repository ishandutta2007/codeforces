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

char s[1000005];
bool goodcol[1000005];
int ans[1000005];
int pre[1000005];
int subcnt[1000005];

void work()
{
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n * m; i++) {
        ans[i] = 0;
        subcnt[i] = 0;
    }
    scanf("%s", s);
    for (int i = 0; i < m; i++) goodcol[i] = false;
    int goodcolcnt = 0;
    int first_good = n * m;
    for (int i = 0; i < n * m; i++) {
        if (s[i] == '1') {
            first_good = min(first_good, i);
            if (!goodcol[i % m]) {
                goodcol[i % m] = true;
                goodcolcnt++;
            }
        }
        ans[i] = goodcolcnt;
    }
    pre[0] = (s[0] == '1' ? 0 : -1);
    for (int i = 1; i < n * m; i++) {
        if (s[i] == '1') {
            pre[i] = i;
        } else {
            pre[i] = pre[i-1];
        }
    }
    for (int i = 0; i < n * m; i++) {
        if (i - pre[i] >= m) subcnt[i]++;
        ans[i] += (i + 1) / m;
        if (first_good < (i + 1) % m) ans[i]++;
    }
    for (int i = 0; i < n * m; i++) {
        if (i >= m) subcnt[i] += subcnt[i - m];
        ans[i] -= subcnt[i];
        printf("%d ", ans[i]);
    }
    printf("\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}