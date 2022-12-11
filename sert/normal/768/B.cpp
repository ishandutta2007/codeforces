#include <bits/stdc++.h>
using namespace std;
#define TASKNAME "sum"
void init() {
#ifdef MOI_KOD_IDEALEN
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;

ll n, L, R, ans = 0;

void go(ll x, ll l, ll r) {
    if (l > R || L > r) return;
    //cout << l << " " << r << "\n";
    ll m = (l + r) / 2;
    if (x % 2 == 1 && L <= m && m <= R) ans++;
    if (l == r) return;
    go(x / 2, l, m - 1);
    go(x / 2, m + 1, r);
}


int main() {
    //init();

    cin >> n >> L >> R;
    L--;
    R--;

    ll q = 1;
    ll deg = 0;
    while (q <= n) {
        q *= 2;
        deg++;
    }
    //cout << deg;
    go(n, 0, (1ll << deg) - 2);
    cout << ans;

    return 0;
}