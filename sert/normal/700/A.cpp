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
const ld EPS = 1e-12;

int main() {
    init();
    ld l, v1, v2;
    int k, n;

    cin >> n >> l >> v1 >> v2 >> k;
    int r = (n + k - 1) / k;

    ld ans;
    if (r == 1)
        ans = l / v2;
    else {
        ld a = (2.0 * r * l - l) / v2;
        ld b = 2.0 * r * (1.0 - r) / v2;
        ld c = l / v2;
        ld d = (r - 1.0) / v1 + (1.0 - r) / v2;
        ans = (b * c - a * d) / (b - d);
    }

    ans = min(ans, l / v1);

    cout.precision(12);
    cout << fixed << ans;


    return 0;
}