#include <bits/stdc++.h>

using namespace std;
#define TASKNAME "cactus"
void init() {
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;
const int N = (int)2e5 + 34;
const ll INF = (ll)1e9 + 34;
const ll md = (ll)1e9 + 7;

ll a[N], b[N];
int n;

ll o2e5 = 750007460;
ll f[N], o[N];

ll cnk(int n, int k) {
    ll res = (o[k] * o[n - k]) % md;
    return (res * f[n]) % md;
}

int main() {
    init();

    f[0] = 1;
    for (ll i = 1; i <= 200000; i++)
        f[i] = (f[i - 1] * i) % md;
    o[200000] = o2e5;
    for (ll i = 199999; i >= 0; i--)
        o[i] = (o[i + 1] * (i + 1)) % md;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%I64d", a + i);
    }

    bool v = false;
    while (n % 4 != 1) {
        for (int i = 1; i < n; i++) {
            b[i - 1] = (v ? (a[i - 1] - a[i] + md) % md : (a[i - 1] + a[i]) % md);
            v = !v;
        }
        for (int i = 0; i < n - 1; i++)
            a[i] = b[i];
        n--;
    }

    ll ans = 0;
    for (int i = 0; i < n; i += 2) {
        //cerr << a[i] << " " << cnk(n / 2, i / 2) << "\n";
        ans += (cnk(n / 2, i / 2) * a[i]) % md;
    }

    cout << ans % md;

    return 0;
}