#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 34;
typedef long long ll;
typedef long double ld;

struct pt {
    ll x, y;
    pt() {}
    pt(ll xx, ll yy) {
        x = xx;
        y = yy;
    }
    pt operator - (const pt &a) {
        return pt(x - a.x, y - a.y);
    }
    ll operator * (const pt &a) {
        return x * a.y - y * a.x;
    }
    ll operator % (const pt &a) {
        return x * a.x + y * a.y;
    }
    ll len() {
        return x * x + y * y;
    }
};

ld dist(pt a, pt b) {
    if ((b - a) % b < 0)
        return sqrtl(b.len());
    if ((a - b) % a < 0)
        return sqrtl(a.len());
    return 1.0 * abs(a * b) / sqrtl((a - b).len());
}

int n;
pt a[N], o;
ll mx;
ld mn = 1e18;

int main() {
    //freopen("a.in", "r", stdin);

    cin >> n >> o.x >> o.y;
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
        a[i] = a[i] - o;
        mx = max(mx, a[i].len());
    }
    a[n] = a[0];

    for (int i = 0; i < n; i++)
        mn = min(mn, dist(a[i], a[i + 1]));

    cout.precision(10);
    cout << fixed << atan2l(0, -1) * (mx - mn * mn);

    return 0;
}