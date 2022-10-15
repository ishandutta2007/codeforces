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

char a[100005];
char b[100005];

void work(void)
{
    int n; scanf("%d", &n);
    scanf("%s%s", a + 1, b + 1);
    for (int i = 1; i <= n; i++) {
        if (a[i] > b[i]) {
            printf("-1\n"); return;
        }
    }
    int ans = 0;
    for (char chr = 'a'; chr <= 'z'; chr++) {
        int cnt = 0;
        char minchr = 'z';
        for (int i = 1; i <= n; i++) {
            if (a[i] != chr) continue;
            if (a[i] == b[i]) continue;
            cnt++;
            minchr = min(minchr, b[i]);
        }
        if (cnt) {
            for (int i = 1; i <= n; i++) {
                if (a[i] != chr) continue;
                if (a[i] == b[i]) continue;
                a[i] = minchr;
            }
            ans++;
        }
        //printf("%s\n", a + 1);
    }
    printf("%d\n", ans);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}