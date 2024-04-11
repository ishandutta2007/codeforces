#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

#define EPS 1e-9

template<typename T>
struct Point {
    T x, y;
    Point(T _x = 0, T _y = 0) : x(_x), y(_y) {}
    Point operator + (const Point &other) const {return Point(x + other.x, y + other.y);}
    Point operator - (const Point &other) const {return Point(x - other.x, y - other.y);}
    Point operator * (T c) const {return Point(x * c, y * c);}
    Point operator / (T c) const {return Point(x / c, y / c);}
    void operator += (const Point &other) {*this = *this + other;}
    void operator -= (const Point &other) {*this = *this - other;}
    void operator *= (T c) {*this = *this * c;}
    void operator /= (T c) {*this = *this / c;}
    bool operator < (const Point &other) const {return tie(x, y) < tie(other.x, other.y);}
    bool operator <= (const Point &other) const {return tie(x, y) <= tie(other.x, other.y);}
    bool operator > (const Point &other) const {return tie(x, y) > tie(other.x, other.y);}
    bool operator >= (const Point &other) const {return tie(x, y) >= tie(other.x, other.y);}
    bool operator == (const Point &other) const {return tie(x, y) == tie(other.x, other.y);}
    bool operator != (const Point &other) const {return tie(x, y) != tie(other.x, other.y);}
    T mag2() const {return x * x + y * y;}
    double mag() const {return sqrt(mag2());}
    Point unit() const {return *this / mag();}
    Point perp() const {return Point(-y, x);}
    Point normal() const {return perp().unit();}
    double angle() const {return atan2(y, x);}
    Point rot(double ang) const {return Point(x * cos(ang) - y * sin(ang), x * sin(ang) + y * cos(ang));}
    friend T dot(const Point &a, const Point &b) {return a.x * b.x + a.y * b.y;}
    friend T cross(const Point<T> &a, const Point<T> &b) {return a.x * b.y - a.y * b.x;}
    friend T dist2(const Point<T> &a, const Point<T> &b) {return (a - b).mag2();}
    friend double dist(const Point<T> &a, const Point<T> &b) {return (a - b).mag();}
    friend T ccw(const Point<T> &a, const Point<T> &b, const Point<T> &o) {return cross(a - o, b - o);}
    friend double angle(const Point<T> &a, const Point<T> &b) {return atan2(cross(a, b), dot(a, b));}
    friend Point<T> rot(const Point<T> &p, const Point<T> &o, double ang) {return o + (p - o).rot(ang);}
    friend ostream& operator << (ostream &os, const Point &p) {return os << "(" << p.x << ", " << p.y << ")";}
};

int n;
Point<int> pts[100000];

bool check(double r) {
    if (2 * r < pts[0].y)
        return false;
    double sq = sqrt(2 * r * pts[0].y - (long long) pts[0].y * pts[0].y);
    double ls = pts[0].x - sq, rs = pts[0].x + sq;
    for (int i=1; i<n; i++) {
        if (2 * r < pts[i].y)
            return false;
        sq = sqrt(2 * r * pts[i].y - (long long) pts[i].y * pts[i].y);
        ls = max(ls, pts[i].x - sq);
        rs = min(rs, pts[i].x + sq);
    }
    return ls - rs < EPS;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    bool above = false, below = false;
    for (int i=0; i<n; i++) {
        cin >> pts[i].x >> pts[i].y;
        if (pts[i].y > 0) above = true;
        if (pts[i].y < 0) below = true, pts[i].y = -pts[i].y;
    }

    if (above && below) {
        cout << "-1\n";
        return 0;
    }

    double l = 0, r = 1e18;
    for (int rep=0; rep<200; rep++) {
        double m = (l + r) / 2;
        if (check(m))
            r = m;
        else
            l = m;
    }

    cout << fixed << setprecision(10) << l << "\n";

    return 0;
}