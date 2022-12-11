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

const int N = 1005;
const int INF = 1e9;
const int B = 200;

ll x1, x2, y1, y2;
ll area, mxx = -INF, mnx = INF, mny = INF, mxy = -INF;
int n;

int main() {
    init();

    cin >> n;
    while (n--) {
        cin >> x1 >> y1 >> x2 >> y2;
        area += abs((x1 - x2) * (y1 - y2));
        mxx = max(mxx, max(x1, x2));
        mnx = min(mnx, min(x1, x2));
        mny = min(mny, min(y1, y2));
        mxy = max(mxy, max(y1, y2));
    }

    //cerr << area << "\n";
    //cerr << (mxy - mny) * (mxx - mnx) << "\n";

    if (area == (mxy - mny) * (mxx - mnx) && mxy - mny == mxx - mnx)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}