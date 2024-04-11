#include <bits/stdc++.h>
using namespace std;

void init() {
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}

typedef long long ll;
typedef long double ld;

const double EPS = 1e-9;
const int INF = (int)1e9 + 41;
const int N = (int)3e5 + 34;

ll _abs(ll x) {
    return (x < 0 ? -x : x);
}

void solve() {
    int n, k1, k2, k;
    cin >> n >> k1 >> k2;
    k = k1 + k2;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    ll ans = 0;

    while (k--) {
        int ps = 0;
        for (int i = 1; i < n; i++) {
            if (_abs(a[i] - b[i]) > _abs(a[ps] - b[ps])) ps = i;
        }
        if (a[ps] < b[ps]) a[ps]++;
        else a[ps]--;
    }

    for (int i = 0; i < n; i++) {
        ll cur = _abs(a[i] - b[i]);
        ans += cur * cur;
    }

    cout << ans << "\n";
}

int main() {
    init();
	solve();
	//solve();
	//solve();
    return 0;
}