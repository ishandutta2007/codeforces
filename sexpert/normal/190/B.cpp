#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    ll dx = abs(x1 - x2), dy = abs(y1 - y2);
    ll d2 = dx*dx + dy*dy;

    if(d2 <= (r1 + r2) * (r1 + r2) && d2 >= abs(r2 - r1) * abs(r2 - r1)) {
        cout << "0\n";
        return 0;
    }

    if(d2 > (r1 + r2) * (r1 + r2))
        cout << fixed << setprecision(9) << fabs((sqrtl(d2) - (r1 + r2)) / 2.0) << '\n';

    else
        cout << fixed << setprecision(9) << fabs(fabs(r2 - r1) - sqrtl(d2)) / 2.0 << '\n';
}