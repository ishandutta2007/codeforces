#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long

using namespace std;

const int N = 1000500;
const int inf = 1e9 + 50;
const int mod = 998244353;

int a[N], val[N], cnt[N];

int main() {

    int tcase;
    scanf("%d", &tcase);
    while (tcase--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        fill(val, val + n + 5, inf);
        fill(cnt, cnt + n + 5, 0);
        int d = 0;
        for (int i = 1; i <= m; i++) {
            int b;
            scanf("%d", &b);
            d = __gcd(b, d);
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += abs(a[i]);
            if (a[i] < 0) cnt[i % d]++;
            val[i % d] = min(val[i % d], abs(a[i]));
        }
        if (d > 1) {
            ll pans = 0, mans = 0;
            for (int i = 0; i < d; i++) {
                if (cnt[i] % 2) {
                    pans += 2 * val[i];
                }
            }
            for (int i = 0; i < d; i++) {
                if (cnt[i] % 2 == 0) {
                    mans += 2 * val[i];
                }
            }
            ans -= min(pans, mans);
        }
        printf("%lld\n", ans);
    }

    return 0;
}