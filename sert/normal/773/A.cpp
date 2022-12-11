#include <bits/stdc++.h>
using namespace std;
#define TASKNAME "sum"
void init() {
#ifdef MOI_KOD_IDEALEN
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = (int)1e6 + 34;
const ll md = (int)1e9 + 7;

void solve() {
    ll x, y, p, q;

    cin >> x >> y >> p >> q;
    if (p >= q && x < y) {
        cout << -1 << "\n";
        return;
    }

    if (p == q && x == y) {
        cout << "0\n";
        return;
    }

    if (p == 0 && x == 0) {
        cout << "0\n";
        return;
    }

    if (p == 0 && x > 0) {
        cout << "-1\n";
        return;
    }

    ll ost = p - x % p;
    if (ost == p) ost = 0;

    ll r = ost;
    ll l = q * (x + ost) / p - y;

    ll z = q - p;
    ll tm = max(0ll, (r - l + z - 1) / z);

    cout << l + tm * q << "\n";
}
int main() {
    init();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}