#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = 5005;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
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



typedef Point<ll> P;
vector<P> convexHull(vector<P> pts) {
    if (sz(pts) <= 1) return pts;
    sort(all(pts));
    vector<P> h(sz(pts)+1);
    int s = 0, t = 0;
    for (int it = 2; it--; s = --t, reverse(all(pts)))
        trav(p, pts) {
        while (t >= s + 2 && h[t-2].cross(h[t-1], p) <= 0) t--;
        h[t++] = p;
    }
    return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

ll polygonArea2(P &p1, P &p2, P &p3) {
    return p3.cross(p1) + p1.cross(p2) + p2.cross(p3);
}

int n;
ll S;
vector<P> ps;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> S;
    rep(i, 0, n) {
        ll x, y; cin >> x >> y;
        ps.push_back(P{x, y});
    }
    auto h = convexHull(ps);
//    for(auto p : h) cout << p.x << " " << p.y << endl;
    int hsz = sz(h);
    rep(i, 0, hsz) h.push_back(h[i]);
    ll mx_area = -1;
    vector<P> mx_pts(3);
    for(int p1 = 0; p1 < hsz; p1++) {
        int p3 = -1;
        for(int p2 = p1 + 1; p2 + 1 < p1 + hsz; p2++) {
            p3 = max(p2 + 1, p3);
            while(p3 + 1 < p1 + hsz &&
                polygonArea2(h[p1], h[p2], h[p3])
                    < polygonArea2(h[p1], h[p2], h[p3 + 1]))
                p3++;
            ll curarea = polygonArea2(h[p1], h[p2], h[p3]);
            if(curarea > mx_area) {
                mx_area = curarea;
                tie(mx_pts[0], mx_pts[1], mx_pts[2]) = {h[p1], h[p2], h[p3]};
            }
        }
    }
    vector<P> res(3, P());
    rep(i, 0, 3) {
        rep(j, 0, 3) {
            res[i] = (res[i] + mx_pts[j] * (j == i ? -1 : 1));
        }
        cout << res[i].x << " " << res[i].y << '\n';
    }
}