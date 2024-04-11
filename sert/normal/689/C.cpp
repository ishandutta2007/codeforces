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
const int N = 63e5 + 34;
const ll INF = 2e9 + 34;

int main() {
    init();
    ll x;
    ll l = 0;
    ll r = 3e18;
    ll m, c;
    bool ans = false;

    cin >> x;

    while (r - l > 1) {
        m = (l + r) / 2;
        c = 0;
        for (ll i = 2; i <= 1000002; i++) {
            c += m / (i * i * i);
            if (c > x)
                break;
        }

        if (c == x)
            ans = true;
        if (c < x)
            l = m;
        else
            r = m;
    }

    if (ans)
        cout << r;
    else
        cout << -1;

    return 0;
}