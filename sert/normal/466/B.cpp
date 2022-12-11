#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 800;
const ll md = 1e9 + 7;

ll n, a, b;
ll ans = 1e18+ 110, x, y;
ll yy;
bool sw;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> a >> b;

    n *= 6;

    if (a * b >= n) {
        cout << a * b << "\n";
        cout << a << " " << b;
        return 0;
    }

    if (a > b) {
        swap(a, b);
        sw = true;
    }
    for (ll xx = a; xx < 100000; xx++) {
        yy = (n + xx - 1) / xx;
        yy = max(yy, b);
        if (xx * yy < ans) {
            ans = xx * yy;
            x = xx;
            y = yy;
        }
    }
    if (sw) {
        swap(x, y);
    }

    cout << ans << "\n" << x << " " << y;


    return 0;
}