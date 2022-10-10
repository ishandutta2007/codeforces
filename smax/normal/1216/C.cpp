#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef tuple<ll, ll, ll, ll> tll;

tll intersect(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
    ll i = min(x2, x4), j = max(x1, x3), k = min(y2, y4), l = max(y1, y3);
    if (i > j && k > l)
        return make_tuple(j, l, i, k);
    return make_tuple(0, 0, 0, 0);
}

ll area(tll rect) {
    ll x1, y1, x2, y2;
    tie(x1, y1, x2, y2) = rect;
    return (x2 - x1) * (y2 - y1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;

    tll a1 = intersect(x1, y1, x2, y2, x3, y3, x4, y4), a2 = intersect(x1, y1, x2, y2, x5, y5, x6, y6);
    ll xi, yi, xj, yj;
    tie(xi, yi, xj, yj) = intersect(x3, y3, x4, y4, x5, y5, x6, y6);
    tll a3 = intersect(x1, y1, x2, y2, xi, yi, xj, yj);

    if ((x2 - x1) * (y2 - y1) - area(a1) - area(a2) + area(a3))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}