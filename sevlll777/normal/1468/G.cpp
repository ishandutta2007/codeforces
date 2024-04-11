#include <bits/stdc++.h>

#define int long long
//#define double long double
#define all(x) x.begin(), x.end()
using namespace std;

struct Pt {
    double x;
    double y;

    Pt(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}

    Pt operator+(Pt other) {
        return {x + other.x, y + other.y};
    }

    Pt operator-(Pt other) {
        return {x - other.x, y - other.y};
    }

    Pt operator*(Pt other) {
        return {x * other.x, y * other.y};
    }

    bool operator<(const Pt &other) const {
        return tie(y, x) < tie(other.y, other.x);
    }

    double dot(Pt other) {
        return x * other.x + y * other.y;
    }

    double cross(Pt other) {
        return x * other.y - y * other.x;
    }

    double dist() {
        return sqrt(x * x + y * y);
    }
};

struct Line {
    double a;
    double b;
    double c;

    Line(double a_, double b_, double c_) : a(a_), b(b_), c(c_) {
        double x = -1e7, y = 1e15;
        if (a * x + b * y + c < 0) {
            a = -a, b = -b, c = -c;
        }
    }

    Pt intersection(Line other) {
        double d = Pt(a, b).cross(Pt(other.a, other.b));
        double dx = Pt(c, b).cross(Pt(other.c, other.b));
        double dy = Pt(a, c).cross(Pt(other.a, other.c));
        if (d == 0) {
            return {-1e9, -1e9};
        }
        return {-dx / (double) d, -dy / (double) d};
    }
};

Line get_straight(Pt self, Pt other) {
    double a = self.y - other.y;
    double b = other.x - self.x;
    double c = self.cross(other);
    return {a, b, c};
}

const double e = -1e10;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    double H;
    cin >> n >> H;
    vector<Pt> pts;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pts.emplace_back(x, y);
    }
    Pt eye(pts[n - 1].x, pts[n - 1].y + H);
    reverse(all(pts));
    Line now = get_straight(eye, pts[0]);
    double ans = 0;
    for (int i = 1; i < n; i++) {
        Line kek = get_straight(pts[i], pts[i - 1]);
        Pt inter = now.intersection(kek);
        if (now.a * pts[i].x + now.b * pts[i].y + now.c < 0) {
        } else if (now.a * pts[i - 1].x + now.b * pts[i - 1].y + now.c >= 0 &&
                   now.a * pts[i].x + now.b * pts[i].y + now.c >= 0) {
            ans += (pts[i] - pts[i - 1]).dist();
        } else if (inter.x == -1e9) {
        } else {
            ans += (pts[i] - pts[i - 1]).dist() / (pts[i - 1].x - pts[i].x) * (inter.x - pts[i].x);
        }
        Line nl = get_straight(eye, pts[i]);
        if (now.b == 0) {
            now = nl;
        } else if ((-now.a * pts[i].x - now.c) / now.b < pts[i].y) {
            now = nl;
        }
    }
    cout << fixed << setprecision(20) << ans << '\n';
}