#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = (int)1e6 + 34;

int n, k, s, t;
int c[N], v[N], g[N];

int main() {
    init();

    scanf("%d%d%d%d", &n, &k, &s, &t);
    for (int i = 0; i < n; i++)
        scanf("%d%d", c + i, v + i);
    for (int i = 0; i < k; i++)
        scanf("%d", g + i + 1);
    g[k + 1] = s;
    k += 2;
    sort(g, g + k);

    ll l = 0;
    ll r = 1e10;
    ll m;
    ll d, tme, cool;

    while (r - l > 1) {
        m = (l + r) / 2;
        tme = 0;
        for (int i = 1; i < k; i++) {
            d = g[i] - g[i - 1];
            if (d > m) tme = 1e18;
            else {
                cool = min(d, m - d);
                tme += cool + 2 * (d - cool);
            }
        }
        if (tme <= t)
            r = m;
        else
            l = m;
    }

    ll ans = 1e18;
    for (int i = 0; i < n; i++)
        if (v[i] >= r)
            ans = min(c[i] + 0ll, ans);

    printf("%I64d\n", (ans > 1e17 ? -1 : ans));

    return 0;
}