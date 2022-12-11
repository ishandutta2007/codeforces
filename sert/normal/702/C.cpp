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
const int N = 1e6 + 34;
const ll INF = 1e12;

ll a[N], b[N];
ll ans = -INF;
int ps;

int main() {
    init();
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%I64d", a + i);
    for (int i = 0; i < m; i++) scanf("%I64d", b + i + 1);
    b[0] = -INF;
    b[m + 1] = INF;

    for (int i = 0; i < n; i++) {
        ps = lower_bound(b, b + m + 2, a[i]) - b;
        ans = max(ans, min(abs(a[i] - b[ps]), abs(a[i] - b[ps - 1])));
    }

    cout << ans;

    return 0;
}