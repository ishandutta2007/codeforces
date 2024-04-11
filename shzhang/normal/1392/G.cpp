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

int perm[1000005][21];
int n, m, k;
char s[25], t[25];
int a[1000005], b[1000005];
int lmask[1000005], rmask[1000005];
int minl[1100005], maxr[1100005];

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    scanf("%s%s", s + 1, t + 1);
    int s_onecnt = 0, t_onecnt = 0;
    for (int i = 1; i <= k; i++) {
        if (s[i] == '1') s_onecnt++;
        if (t[i] == '1') t_onecnt++;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", a + i, b + i);
    }
    for (int i = 1; i <= k; i++) perm[0][i] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) perm[i][j] = perm[i-1][j];
        swap(perm[i][a[i]], perm[i][b[i]]);
    }
    for (int i = 0; i <= n; i++) {
        char tmp[25];
        for (int j = 1; j <= k; j++) tmp[j] = s[j];
        for (int j = 1; j <= k; j++) {
            if (tmp[j] == '0') lmask[i] |= (1 << (perm[i][j] - 1));
        }
        for (int j = 1; j <= k; j++) tmp[j] = t[j];
        for (int j = 1; j <= k; j++) {
            if (tmp[j] == '0') rmask[i] |= (1 << (perm[i][j] - 1));
        }
    }
    for (int i = 0; i < (1 << k); i++) minl[i] = 1000000000, maxr[i] = 0;
    for (int i = 0; i <= n; i++) {
        minl[lmask[i]] = min(minl[lmask[i]], i);
        maxr[rmask[i]] = max(maxr[rmask[i]], i);
    }
    for (int bit = 0; bit < k; bit++) {
        for (int i = 0; i < (1 << k); i++) {
            if (i & (1 << bit)) {
                minl[i] = min(minl[i], minl[i ^ (1 << bit)]);
                maxr[i] = max(maxr[i], maxr[i ^ (1 << bit)]);
            }
        }
    }
    int maxans = 0;
    int l = 1, r = n;
    for (int i = 0; i < (1 << k); i++) {
        int one_match = 0;
        for (int j = 0; j < k; j++) {
            if (!(i & (1 << j))) one_match++;
        }
        int total_match = one_match * 2 + (k - s_onecnt - t_onecnt);
        if (maxr[i] - minl[i] >= m && total_match > maxans) {
            maxans = total_match;
            l = minl[i] + 1; r = maxr[i];
        }
    }
    printf("%d\n%d %d", maxans, l, r);
    return 0;
}