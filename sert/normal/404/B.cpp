#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 34;

ll a, d, len, pl, num;
ll n;
double aa, dd;

void prll(ll x, ll y) {
    printf("%I64d.%04I64d %I64d.%04I64d\n", x / 10000, x % 10000, y / 10000, y % 10000);
}

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    
    cin >> aa >> dd >> n;
    a = (aa * 10000 + 0.5);
    d = (dd * 10000 + 0.5);

    // cout << a << " " << d << "\n";

    for (int i = 1; i <= n; i++) {
        len = d * i;
        pl = len % (4 * a);
        num = pl / a;
        pl = pl % a;
        if (num == 0) prll(pl, 0);
        if (num == 1) prll(a, pl);
        if (num == 2) prll(a - pl, a);
        if (num == 3) prll(0, a - pl);
    }

    return 0;
}