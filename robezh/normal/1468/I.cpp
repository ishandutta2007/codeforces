#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
#define double long double

int n;
int dx1, dy1, dx2, dy2;
const int INF = (int)1e9;
const double EPS = 1e-9;

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

typedef Point<double> Pt;

void printout(int n, int xn, int yn) {
    if(n < 1LL * xn * yn) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        rep(i, 0, n) cout << i % xn << " " << i / xn << '\n';
    }
    exit(0);
}

pair<int, double> seginter(int x, Pt p1, Pt p2) {
    if(p1.x > p2.x) swap(p1, p2);
    if(x < p1.x - EPS || x > p2.x + EPS) return {-1, -1};
    return {1, p1.y + (x - p1.x) * (p2.y - p1.y) / (p2.x - p1.x)};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> dx1 >> dy1 >> dx2 >> dy2;
    if((dx1 == 0 && dx2 == 0) || (dy1 == 0 && dy2 == 0) || (dx1 == 0 && dy1 == 0) || (dx2 == 0 && dy2 == 0) ) {
        return cout << "NO\n", 0;
    }
    if(1LL * dx1 * dy2 == 1LL * dx2 * dy1) {
        return cout << "NO\n", 0;
    }
    if(dx1 == 0 || dy2 == 0) printout(n, dx2, dy1);
    if(dx2 == 0 || dy1 == 0) printout(n, dx1, dy2);

    Pt p[4] = {Pt(0, 0), Pt(dx1, dy1), Pt(dx1 + dx2, dy1 + dy2), Pt(dx2, dy2)};
    int mnx = min({0, dx1, dx1 + dx2, dx2});
    int mxx = max({0, dx1, dx1 + dx2, dx2});
//    cout << "rect: \n";
//    rep(d, 0, 4) cout << p[d] << endl;
    vector<pii> res;
    for(int i = mnx; i <= mxx; i++) {
        double mxy = -INF, mny = INF;
        for(int d = 0; d < 4; d++) {
            auto r = seginter(i, p[d], p[(d + 1) % 4]);
//            cout << d << " " << r.first << " " << r.second << endl;
            if(r.first == 1) {
                mxy = max(mxy, r.second);
                mny = min(mny, r.second);
            }
        }
//        cout << mny << endl;
        int l = int(ceil(mny + EPS)), r = int(floor(mxy + EPS));
//        cout << i << ": " << l << " " << r << endl;
        for(int j = l; j <= r; j++) {
            bool is_ver = false;
            rep(d, 0, 4) is_ver |= (int(floor(p[d].x + 0.5)) == i && int(floor(p[d].y + 0.5)) == j);
            if(is_ver) continue;
            if(sz(res) <= n) res.push_back({i, j});
            else {
                cout << "NO\n";
                return 0;
            }
        }
    }
    res.push_back({0, 0});
    if(sz(res) == n) {
        cout << "YES\n";
        for(auto &p : res) cout << p.first << " " << p.second << '\n';
    } else cout << "NO\n";


}