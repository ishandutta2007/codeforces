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

int n, k;
int a[200005];
int freq[200005], psum[200005];

void work()
{
    scanf("%d%d", &n, &k);
    int mincnt = (k + n + 1) / 2;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        freq[i] = psum[i] = 0;
    }
    for (int i = 1; i <= n; i++) freq[a[i]]++;
    for (int i = 1; i <= n; i++) psum[i] = psum[i-1] + freq[i];
    int x = 1;
    int mindiff = n + 1;
    int bestx = 0, besty = 0;
    for (int y = 1; y <= n; y++) {
        while (psum[y] - psum[x] >= mincnt) x++;
        if (psum[y] - psum[x-1] >= mincnt && y - x < mindiff) {
            mindiff = y - x;
            bestx = x; besty = y;
        }
    }
    printf("%d %d\n", bestx, besty);
    for (int i = 1; i <= n; i++) {
        psum[i] = psum[i-1] + (a[i] >= bestx && a[i] <= besty ? 1 : -1);
    }
    int cur = 1;
    int last = 0;
    for (int i = 1; i <= n; i++) {
        if (psum[i] == cur) {
            printf("%d %d\n", last + 1, cur == k ? n : i);
            last = i;
            if (cur == k) {
                break;
            } else {
                cur++;
            }
        }
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}