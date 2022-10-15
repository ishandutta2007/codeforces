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

int n;
int qry[105];
int nxt[105];
int ans[105];

int query()
{
    printf("? ");
    for (int i = 1; i <= n; i++) printf("%d ", qry[i]);
    printf("\n");
    fflush(stdout);
    int result; scanf("%d", &result);
    return result;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) qry[j] = 2;
        qry[i] = 1;
        int res = query();
        if (res && res < i) {
            nxt[res] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) qry[j] = 1;
        qry[i] = 2;
        int res = query();
        if (res && res < i) {
            nxt[i] = res;
        }
    }
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        bool found = false;
        for (int j = 1; j <= n; j++) {
            if (nxt[j] == i) found = true;
        }
        if (!found) cur = i;
    }
    for (int i = 1; i <= n; i++) {
        ans[cur] = i;
        cur = nxt[cur];
    }
    printf("! ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    fflush(stdout);
    return 0;
}