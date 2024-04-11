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
const int INF = (ll)1e9 + 34;
const ll md = (ll)1e9 + 9;
const ll p1 = 761;
const ll p2 = 2011;

pair <ll, ll> h[N];
int n, m, k, x;

int main() {
    init();

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &x);
            x--;
            h[x].first = (h[x].first * p1 + i * 7 + 1) % md;
            h[x].second = (h[x].first * p2 + i * 5 + 11) % md;
        }
    }

    sort(h, h + m);
    ll num = 1;
    ll fac = 1;
    h[m] = {-1, -1};
    ll ans = 1;

    for (int i = 1; i <= m; i++) {
        if (h[i] == h[i - 1]) {
            num++;
            fac = (fac * num) % (md - 2);
        } else {
            ans = (ans * fac) % (md - 2);
            num = 1;
            fac = 1;
        }
    }

    printf("%I64d\n", ans);

    return 0;
}