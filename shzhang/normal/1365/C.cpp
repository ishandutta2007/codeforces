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

int lpos[200005];
int rpos[200005];
int dfreq[200005];

void work(void)
{
    /* solve problem here */
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int a; scanf("%d", &a);
        lpos[a] = i;
    }
    for (int i = 1; i <= n; i++) {
        int a; scanf("%d", &a);
        rpos[a] = i;
    }
    for (int i = 1; i <= n; i++) {
        int slen = (rpos[i] - lpos[i] + n) % n;
        dfreq[slen]++;
    }
    int maxfreq = 0;
    for (int i = 0; i <= n; i++) {
        maxfreq = max(maxfreq, dfreq[i]);
    }
    printf("%d", maxfreq);
    /* remember to clean up any global variables if needed */
}

int main()
{
    int T = 1;
    for (int i = 1; i <= T; i++) work();
    return 0;
}