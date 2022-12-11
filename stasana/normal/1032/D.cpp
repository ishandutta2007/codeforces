// Megumin

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

typedef int64_t ll;
typedef long double ld;

struct Point {
    ld x, y;

    Point(ld x = 0, ld y = 0)
        : x(x), y(y) {}

    ld dist(Point other) {
        return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }
};

istream& operator>> (istream& in, Point& point) {
    in >> point.x >> point.y;
    return in;
}

Point getByX(ld a, ld b, ld c, ld x) {
    return Point(x, -(a * x + c) / b);
}

Point getByY(ld a, ld b, ld c, ld y) {
    return Point(-(b * y + c) / a, y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    ll a, b, c;
    cin >> a >> b >> c;
    Point p1, p2;
    cin >> p1 >> p2;
    ld res = fabs(p1.x - p2.x) + fabs(p1.y - p2.y);
    if (a == 0 || b == 0) {
        cout << fixed << setprecision(12) << res;
        return 0;
    }
    Point p11 = getByX(a, b, c, p1.x);
    Point p12 = getByY(a, b, c, p1.y);
    Point p21 = getByX(a, b, c, p2.x);
    Point p22 = getByY(a, b, c, p2.y);
    res = min(res, p1.dist(p11) + p11.dist(p21) + p21.dist(p2));
    res = min(res, p1.dist(p12) + p12.dist(p21) + p21.dist(p2));
    res = min(res, p1.dist(p11) + p11.dist(p22) + p22.dist(p2));
    res = min(res, p1.dist(p12) + p12.dist(p22) + p22.dist(p2));
    cout << fixed << setprecision(12) << res;
    return 0;
}