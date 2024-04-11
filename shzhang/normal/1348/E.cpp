#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

#define ll long long

int n, k;

bool f[505][505];
int a[505]; int b[505];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d%d", a + i, b + i);
    f[0][0] = true;
    ll total = 0;
    for (int i = 0; i < n; i++) {
        total += (ll)(a[i] + b[i]);
        for (int red = 0; red < k; red++) {
            if (!f[i][red]) continue;
            for (int nxtred = 0; nxtred < min(k, a[i+1] + 1); nxtred++) {
                int nxtblue = (a[i+1] + b[i+1] - nxtred) % k;
                //printf("%d %d %d\n", i, nxtred, nxtblue);
                if (nxtblue > b[i+1]) continue;
                //printf("%d %d %d\n", i, nxtred, nxtblue);
                f[i+1][(red + nxtred) % k] = true;
                //printf("%d %d\n", i + 1, (red + nxtred) % k);
            }
        }
    }
    total += (ll)(a[n] + b[n]);
    ll ans = 0;
    for (int i = 0; i < k; i++) {
        if (f[n][i]) {
            ans = max(ans, (total - (ll)i) / (ll)k);
        }
    }
    printf("%lld", ans);
    return 0;
}