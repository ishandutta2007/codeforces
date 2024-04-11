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

bool dec[100005];
int ans[100005];

void work()
{
    int n; ll k; scanf("%d%lld", &n, &k);
    if (n <= 63 && k > (1LL << (ll)(n - 1))) {
        printf("-1\n"); return;
    }
    k--;
    int j = 0;
    dec[n] = false;
    for (int i = n - 1; i >= 1; i--) {
        dec[i] = (j <= 62 && k & (1LL << (ll)(j)));
        j++;
    }
    int i = 1;
    while (i <= n) {
        j = i;
        while (dec[j]) j++;
        for (int c = j; c >= i; c--) {
            ans[c] = (j - c + i);
        }
        i = j + 1;
    }
    for (int x = 1; x <= n; x++) {
        printf("%d ", ans[x]);
    }
    printf("\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}