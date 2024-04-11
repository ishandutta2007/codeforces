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
bool u[N];

pair <ll, ll> a[N];
ll c[N], d[N];
ll ans = 4e18;

int main() {
    init();
    ll n, m, k, x, s;
    cin >> n >> m >> k >> x >> s;

    for (int i = 0; i < m; i++) {
        cin >> a[i].second;
    }
    for (int i = 0; i < m; i++) {
        cin >> a[i].first;
    }
    a[m++] = {0, x};
    sort(a, a + m);
    for (int i = 0; i < k; i++) {
        cin >> c[i + 1];
    }
    for (int i = 0; i < k; i++) {
        cin >> d[i + 1];
    }

    c[k + 1] = d[k + 1] = s + 1;

    int cur = 0;

    for (int i = m - 1; i >= 0; i--) {
        if (a[i].first > s) continue;
        while (d[cur + 1] + a[i].first <= s)
            cur++;
        ans = min(ans, (n - c[cur]) * a[i].second);
    }

    cout << ans;

    return 0;
}