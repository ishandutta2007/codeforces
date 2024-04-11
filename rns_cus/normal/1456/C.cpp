#include <bits/stdc++.h>
using namespace std;

#define N 500100

int n, k, a[N];
typedef long long ll;
bool vis[N];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1, greater <int> ());
    ll D = 0, sum = 0;
    int m;
    for (m = 1; m <= n && a[m] >= 0; m ++) {
        sum += D, D += a[m], vis[m] = 1;
    }

    ll ans = -2e18, s = 0;

    for (int i = n, j = 0, c = 0; i >= m; i --) {
        s += 1ll * c * a[i];
        if (j == 0) vis[i] = 1, s += D;
        j ++;
        if (j > k) j = 0, c ++;
    }
    ans = max(ans, s);

    ll x = 0;
    for (int i = m; i <= n; i ++) {
        x += a[i];
        if (vis[i]) continue;
        s += x + D;
        ans = max(ans, s);
    }
    printf("%I64d\n", ans + sum);

    return 0;
}