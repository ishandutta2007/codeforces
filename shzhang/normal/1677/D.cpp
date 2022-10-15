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

#define MOD 998244353
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

int v[1000005];

void work()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", v + i);
    for (int i = n; i >= n - k + 1; i--) {
        if (v[i] > 0) {
            printf("0\n"); return;
        }
    }
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        if (i <= k || v[i - k] == -1) {
            ans = mul(ans, i);
        } else if (v[i - k] == 0) {
            ans = mul(ans, k + 1);
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