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

const int N = 1e6 + 34;

int n, a, b, m, c;
string s[N];
bool fnd;
ld ans, d, xx, yy, x, y, v;

int main() {
    //init();

    cin >> x >> y;
    cin >> n;

    ld ans = 1e18;

    for (int i = 0; i < n; i++) {
        cin >> xx >> yy >> v;
        d = hypot(fabs(xx - x), fabs(yy - y));
        ans = min(ans, d / v);
    }

    cout.precision(10);
    cout << fixed << ans;

    return 0;
}