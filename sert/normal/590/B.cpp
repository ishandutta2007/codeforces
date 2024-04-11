#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 7;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ld x1, y1, x2, y2, x, y;
    ld vmax, t;
    ld vx, vy, wx, wy, d;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> vmax >> t;
    cin >> vx >> vy >> wx >> wy;

    ld l = 0;
    ld r = 1e9;
    ld m;

    for (int i = 0; i < 50000; i++) {
        m = (l + r) / 2;
        if (m < t) {
            x = m * vx;
            y = m * vy;
        } else {
            x = t * vx + (m - t) * wx;
            y = t * vy + (m - t) * wy;
        }
        x = (x1 + x - x2);
        y = (y1 + y - y2);
        d = sqrtl(x * x + y * y);
        if (d / vmax > m)
            l = m;
        else
            r = m;
    }

    cout.precision(12);
    cout << fixed << l;

    return 0;
}