#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const ld eps = 1e-12;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int n, ans = 0;
    cin >> n;
    while(n--) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll D = a*(x2 - x1) + b*(y2 - y1), E = -a*x1 - b*y1 - c;
        if(D == 0) continue;
        ld t = (ld)E/(ld)D;
        if(t > eps && t < 1.0 - eps)
            ans++;
    }
    cout << ans << endl;
}