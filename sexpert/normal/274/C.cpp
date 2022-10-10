#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double eps = 1e-9;
template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return fabs(x - p.x) + fabs(y - p.y) < eps; }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
    // angle to x-axis in interval [-pi, pi]
    double angle() const { return atan2(y, x); }
    P unit() const { return *this/dist(); } // makes dist()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated 'a' radians ccw around the origin
    P rotate(double a) const {
        return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")"; }
};

typedef Point<double> P;
double ccRadius(const P& A, const P& B, const P& C) {
    return (B-A).dist()*(C-B).dist()*(A-C).dist()/
            abs((B-A).cross(C-A))/2;
}
P ccCenter(const P& A, const P& B, const P& C) {
    P b = C-A, c = B-A;
    return A + (b*c.dist2()-c*b.dist2()).perp()/b.cross(c)/2;
}
int ang(const P &A, const P &B, const P &C) {
    return sgn((A - B).dot(C - B));
}
int ty(const P &A, const P &B, const P &C) {
    return ang(A, B, C) * ang(B, C, A) * ang(C, A, B);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<P> v(n);
    set<P> pts;
    for(auto &p : v) {
        cin >> p.x >> p.y;
        pts.insert(p);
    }
    double ans = -1.0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                int t = ty(v[i], v[j], v[k]);
                if(t == -1)
                    continue;
                if(t == 1) {
                    auto cc = ccCenter(v[i], v[j], v[k]);
                    double r = ccRadius(v[i], v[j], v[k]);
                    bool good = true;
                    for(int p = 0; p < n; p++) {
                        if((v[p] - cc).dist() + eps < r)
                            good = false;
                    }
                    if(good)
                        ans = max(ans, r);
                }
                if(t == 0) {
                    bool found = false;
                    P d = v[i] + v[j] - v[k];
                    found |= pts.count(d);
                    d = v[j] + v[k] - v[i];
                    found |= pts.count(d);
                    d = v[k] + v[i] - v[j];
                    found |= pts.count(d);
                    if(!found)
                        continue;
                    auto cc = ccCenter(v[i], v[j], v[k]);
                    double r = ccRadius(v[i], v[j], v[k]);
                    bool good = true;
                    for(int p = 0; p < n; p++) {
                        if((v[p] - cc).dist() + eps < r)
                            good = false;
                    }
                    if(good)
                        ans = max(ans, r);
                }
            }
        }
    }
    cout << fixed << setprecision(9) << ans << '\n';
}