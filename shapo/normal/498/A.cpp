#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int
sign(ll val)
{
    return val / abs(val);
}

int
main()
{
    ios_base::sync_with_stdio(false);
    ll x1, y1, x2, y2;
    int n;
    int res = 0;
    cin >> x1 >> y1 >> x2 >> y2 >> n;
    for (int i = 0; i < n; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        int p1 = sign(a * x1 + b * y1 + c),
            p2 = sign(a * x2 + b * y2 + c);
        if (p1 * p2 < 0) {
            res++;
        }
    }
    cout << res << '\n';
    return 0;
}