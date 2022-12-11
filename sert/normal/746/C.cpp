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

const int N = 504;

bool u[N][N];
bool ez[N];

int s, x1, x2, t1, t2, p, d;
int tw, tt;

int d1, d2, dd;

int main() {
    init();

    cin >> s >> x1 >> x2;
    cin >> t1 >> t2;
    cin >> p >> d;

    if (x1 > x2) {
        x1 = s - x1;
        x2 = s - x2;
        p = s - p;
        d = -d;
    }

    tw = (x2 - x1) * t2;

    dd = -d;

    if (p < x1 && d == -1) d1 = p + x1;
    else if (p > x1 && d == 1) d1 = s - p + s - x1;
    else {
        d1 = abs(p - x1);
        dd = d;
    }

    if (dd == 1) d2 = x2 - x1;
    else d2 = x1 + x2;

    cout << min(tw, t1 * (d1 + d2));

    return 0;
}