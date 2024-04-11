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
int a[100005];
int freq[100005];
int pfreq[100005];

void work(void)
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) freq[i] = pfreq[i] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i); freq[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (freq[i] > (n + 1) / 2) {
            printf("-1\n"); return;
        }
    }
    int totfreq = 2;
    int ans = 0;
    pfreq[a[1]]++;
    pfreq[a[n]]++;
    for (int i = 1; i <= n - 1; i++) {
        if (a[i] == a[i+1]) {
            pfreq[a[i]] += 2; totfreq += 2; ans++;
        }
    }
    //printf("! %d\n", pfreq[1]);
    int maxpfreq = 0; int maxpval = 0;
    for (int i = 1; i <= n; i++) {
        if (maxpfreq < pfreq[i]) {
            maxpfreq = pfreq[i];
            maxpval = i;
        }
    }
    int acnt = 0;
    for (int i = 1; i <= n - 1; i++) {
        if (a[i] != maxpval && a[i+1] != maxpval) {
            acnt++;
        }
    }
    while (maxpfreq > (totfreq + 2) / 2) {
        if (acnt) {
            totfreq += 2; acnt--; ans++;
        } else {
            totfreq += 2; maxpfreq += 1; ans++;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}