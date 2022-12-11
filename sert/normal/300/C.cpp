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
const ld EPS = 1e-12;
const ll md = (int)1e9 + 7;
const ll o_10e6 = 397802501;

const int N = (int)1e6 + 34;
ll f[N], o[N];

bool ok(int x, int a, int b) {
    if (x == 0) return false;
    while (x) {
        if (x % 10 != a && x % 10 != b) return false;
        x /= 10;
    }
    return true;
}

int main() {
    init();

    ll a, b, n;
    cin >> a >> b >> n;

    o[1000000] = o_10e6;
    for (ll i = 999999; i >= 0; i--) {
        o[i] = (o[i + 1] * (i + 1)) % md;
    }
    f[0] = 1;
    for (ll i = 1; i <= 1000000; i++) {
        f[i] = (f[i - 1] * i) % md;
    }

    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        if (ok(i * a + (n - i) * b, a, b)) {
            ans = (ans + (((f[n] * o[i]) % md) * o[n - i]) % md) % md;
        }
    }

    cout << ans;

    return 0;
}