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
const int INF = 1e9 + 34;

int n, m, c[N];
ll a[N], ans, sum;
ll sumc, t;
bool u[N];

int main() {
    init();

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%I64d", a + i);
        sum += a[i];
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", c + i);
        c[i]--;
        sumc += a[c[i]];
        u[c[i]] = true;
        ans += (sum - a[c[i]]) * a[c[i]];
    }

    a[n] = a[0];
    u[n] = u[0];
    for (int i = 0; i < n; i++) {
        if (!u[i] && !u[i + 1]) ans += a[i] * a[i + 1];
    }

    for (int i = 0; i < m; i++)
        t += (sumc - a[c[i]]) * a[c[i]];

    cout << ans - t / 2;

    return 0;
}