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

#define MOD 1000000007
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

int a[200005];
int pwr2[200005];
int freq[105];

int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    pwr2[0] = 1;
    for (int i = 1; i <= n; i++) pwr2[i] = mul(pwr2[i-1], 2);
    //bool haseven = false;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        while (a[i] % 2 == 0) {
            //haseven = true;
            a[i] /= 2; cnt++;
        }
        freq[cnt]++;
    }
    int ans = pwr2[n] - 1;
    for (int i = 1; i <= 100; i++) {
        if (!freq[i]) continue;
        int sub = pwr2[freq[i] - 1];
        for (int j = i + 1; j <= 100; j++) {
            sub = mul(sub, pwr2[freq[j]]);
        }
        ans -= sub; if (ans < 0) ans += MOD;
    }
    printf("%d", ans);
    return 0;
}