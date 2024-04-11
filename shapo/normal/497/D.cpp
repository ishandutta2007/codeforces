#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

struct Point
{
    ll x, y;
    Point(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}
    Point &operator-=(const Point &sub)
    {
        x -= sub.x;
        y -= sub.y;
        return *this;
    }
    Point operator-(const Point &sub) const
    {
        return Point(x - sub.x, y - sub.y);
    }
    friend istream& operator>>(istream &in, Point &p)
    {
        return in >> p.x >> p.y;
    }
    ll sqdist() const
    {
        return x * x + y * y;
    }
    ll operator*(const Point &mult) const
    {
        return x * mult.x + y * mult.y;
    }
    ll operator^(const Point &mult) const
    {
        return x * mult.y - y * mult.x;
    }
};

void
input(vector< Point > &arr, Point &center)
{
    cin >> center;
    int n;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

bool
isect(Point p1, Point p2, Point cnt, ll sqd)
{   // check if circle with center at cnt and square of radius is sqd
    // intersects with segment [p1; p2] 
    ll d1 = (p1 - cnt).sqdist();
    ll d2 = (p2 - cnt).sqdist();
    if ((d1 - sqd) * (d2 - sqd) <= 0ll) {
        return true;
    }
    ll a = (cnt - p1) ^ (p2 - p1);
    ll p = a * a, q = (p2 - p1).sqdist();
    if ((p2 - p1) * (cnt - p1) < 0  || (p1 - p2) * (cnt - p2) < 0) {
        p = min((cnt - p1).sqdist(), (cnt - p2).sqdist()), q = 1ll;
    }
    return max((cnt - p1).sqdist(), (cnt - p2).sqdist()) >= sqd
        && p <= q * sqd;
}

bool
can(const Point c1, vector< Point > a1, Point c2, vector< Point > a2)
{
    for (auto &x : a1) {
        x -= c1;
    }
    for (auto &y : a2) {
        y -= c2;
    }
    c2 -= c1;
    int n = int(a1.size()), m = int(a2.size());
    for (int i = 0; i < n; ++i) {
        Point p1 = a1[i], p2 = a1[(i + 1) % n];
        for (int j = 0; j < m; ++j) {
            if (isect(p1, p2, a2[j], c2.sqdist())) {
                return true;
            }
        }
    }
    return false;
}

int
main()
{
    ios_base::sync_with_stdio(false);
    Point p, q;
    vector< Point > a, b;
    input(a, p);
    input(b, q);
    bool ok = can(p, a, q, b) || can(q, b, p, a);
    if (ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}