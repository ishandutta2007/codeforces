#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef long double ld;

const ld INF = 1e18;

struct Point {
    ll x, y;

    Point() :
        x(0),
        y(0) { }

    Point(ll x, ll y) :
            x(x),
            y(y) { }
};

istream &operator>>(istream &in, Point &a) {
    in >> a.x >> a.y;
    return in;
}

struct Vector {
    ll x, y;

    Vector() :
            x(0),
            y(0) { }

    Vector(ll x, ll y) :
            x(x),
            y(y) { }

    Vector(const Point &a, const Point &b) :
            x(b.x - a.x),
            y(b.y - a.y) { }

    ll operator%(const Vector &a) const {
        return x * a.x + y * a.y;
    }

    ll operator*(const Vector &a) const {
        return x * a.y - y * a.x;
    }

    ld len() {
        return sqrtl(*this % *this);
    }
};

ld distTo(const Point &a, const Point &b, const Point &c) {
    Vector ab(a, b), ca(c, a), cb(c, b);
    ld d = ab.len();
    return (ld) (ca * cb) / d;
}

int main() {
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<Point> pts(n);
    for (int i = 0; i < n; ++i) {
        cin >> pts[i];
    }
    ld ans = INF;
    for (int i = 0; i < n; ++i) {
        int prev = (i - 1 + n) % n;
        int nt = (i + 1) % n;
        ans = min(ans, distTo(pts[prev], pts[nt], pts[i]) / 2.0);
    }
    cout << ans << "\n";
//    system("pause");
    return 0;
}