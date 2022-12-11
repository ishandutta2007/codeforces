//#pragma GCC target("avx")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#ifdef LOCAL
#include <debug.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll,ll>;
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vs = vector<string>;
template<class T> using pq = priority_queue<T,vector<T>,greater<T>>;
#define overload4(_1, _2, _3, _4, name, ...) name
#define overload3(a,b,c,name,...) name
#define rep1(n) for (ll UNUSED_NUMBER = 0; UNUSED_NUMBER < (n); ++UNUSED_NUMBER)
#define rep2(i, n) for (ll i = 0; i < (n); ++i)
#define rep3(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for (ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rrep1(n) for(ll i = (n) - 1;i >= 0;i--)
#define rrep2(i,n) for(ll i = (n) - 1;i >= 0;i--)
#define rrep3(i,a,b) for(ll i = (b) - 1;i >= (a);i--)
#define rrep4(i,a,b,c) for(ll i = (a) + ((b)-(a)-1) / (c) * (c);i >= (a);i -= c)
#define rrep(...) overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)
#define all1(i) begin(i),end(i)
#define all2(i,a) begin(i),begin(i)+a
#define all3(i,a,b) begin(i)+a,begin(i)+b
#define all(...) overload3(__VA_ARGS__, all3, all2, all1)(__VA_ARGS__)
#define sum(...) accumulate(all(__VA_ARGS__),0LL)
template<class T> bool chmin(T &a, const T &b){ if(a > b){ a = b; return 1; } else return 0; }
template<class T> bool chmax(T &a, const T &b){ if(a < b){ a = b; return 1; } else return 0; }
template<class T> auto min(const T& a){ return *min_element(all(a)); }
template<class T> auto max(const T& a){ return *max_element(all(a)); }
template<class... Ts> void in(Ts&... t);
#define INT(...) int __VA_ARGS__; in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__; in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__; in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__; in(__VA_ARGS__)
#define VEC(type, name, size) vector<type> name(size); in(name)
#define VV(type, name, h, w) vector<vector<type>> name(h, vector<type>(w)); in(name)
ll intpow(ll a, ll b){ ll ans = 1; while(b){if(b & 1) ans *= a; a *= a; b /= 2;} return ans;}
ll modpow(ll a, ll b, ll p){ ll ans = 1; a %= p;while(b){ if(b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }
ll GCD(ll a,ll b) { if(a == 0 || b == 0) return a + b; if(a % b == 0) return b; else return GCD(b,a%b);}
ll LCM(ll a,ll b) { if(a == 0) return b; if(b == 0) return a;return a / GCD(a,b) * b;}
namespace IO{
#define VOID(a) decltype(void(a))
struct setting{ setting(){cin.tie(nullptr); ios::sync_with_stdio(false);fixed(cout); cout.precision(12);}} setting;
template<int I> struct P : P<I-1>{};
template<> struct P<0>{};
template<class T> void i(T& t){ i(t, P<3>{}); }
void i(vector<bool>::reference t, P<3>){ int a; i(a); t = a; }
template<class T> auto i(T& t, P<2>) -> VOID(cin >> t){ cin >> t; }
template<class T> auto i(T& t, P<1>) -> VOID(begin(t)){ for(auto&& x : t) i(x); }
template<class T, size_t... idx> void ituple(T& t, index_sequence<idx...>){
    in(get<idx>(t)...);}
template<class T> auto i(T& t, P<0>) -> VOID(tuple_size<T>{}){
    ituple(t, make_index_sequence<tuple_size<T>::value>{});}
#undef VOID
}
#define unpack(a) (void)initializer_list<int>{(a, 0)...}
template<class... Ts> void in(Ts&... t){ unpack(IO :: i(t)); }
#undef unpack
//constexpr int mod = 1000000007;
constexpr int mod = 998244353;
static const double PI = 3.1415926535897932;
template <class F> struct REC {
    F f;
    REC(F &&f_) : f(forward<F>(f_)) {}
    template <class... Args> auto operator()(Args &&...args) const { return f(*this, forward<Args>(args)...); }};

using Real = long double;
using Point = complex<Real>;
using Points = vector<Point>;
constexpr Real EPS = 1e-7;
istream &operator>>(istream &is,Point &p) {
    Real a,b;
    is >> a >> b;
    p = Point(a,b);
    return is;
}
ostream &operator<<(ostream &os,Point &p) {
    return os << real(p) << " " << imag(p);
}
inline bool eq(Real a,Real b) {return fabsl(b - a) < EPS;}
Point operator*(const Point &p,const Real &d) {
    return Point(real(p)*d,imag(p)*d);
}
namespace std {
bool operator<(const Point &a,const Point &b) {
    return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag();
}
}
//
Real distance(Point &a,Point &b) {
    return hypotl(a.real() - b.real(),a.imag() - b.imag());
}
//(rad)
Point rotate(Real theta, const Point &p) {
  return Point(cos(theta) * p.real() - sin(theta) * p.imag(), sin(theta) * p.real() + cos(theta) * p.imag());
}
//
Real cross(const Point &a,const Point &b) {
    return real(a) * imag(b) - imag(a) * real(b);
}
//
Real dot(const Point &a,const Point &b) {
    return real(a) * real(b) + imag(a) * imag(b);
}
int ccw(const Point &a,Point b,Point c) {
    b = b - a, c = c - a;
    if(cross(b,c) > EPS) return +1;  //
    if(cross(b,c) < -EPS) return -1; //
    if(dot(b,c) < 0) return +2;      //b-a-c
    if(norm(b) < norm(c)) return -2; //a-b-c
    return 0;                        //a-c-b
}
Real get_angle(const Point &a,const Point &b,const Point &c) {
    const Point v(b - a), w(c - b);
    Real alpha = atan2(v.imag(),v.real()), beta = atan2(w.imag(),w.real());
    if(alpha > beta) swap(alpha,beta);
    Real theta = beta - alpha;
    return min(theta,2 * acosl(-1) - theta);
}
using Polygon = vector<Point>;
Polygon convex_hull(vector<Point> ps) {
    int n = (int)ps.size(),k = 0;
    if(n <= 2) return ps;
    sort(ps.begin(),ps.end());
    vector<Point> ch(2*n);
    for(int i = 0;i < n;ch[k++] = ps[i++]) {
        while(k >= 2 && cross(ch[k-1]-ch[k-2],ps[i]-ch[k-1]) < EPS) --k;
    }
    for(int i = n - 2,t = k + 1;i >= 0;ch[k++] = ps[i--]) {
        while(k >= t && cross(ch[k-1]-ch[k-2],ps[i]-ch[k-1]) < EPS) --k;
    }
    ch.resize(k-1);
    return ch;
}
Real area(const Polygon &p) {
    Real A = 0;
    for(int i = 0;i < (int)p.size();++i) {
        A += cross(p[i],p[(i+1) % p.size()]);
    }
    return A * .5;
}

struct Circle {
    Point p;
    Real r;
    Circle() = default;
    Circle(Point _p,Real _r):p(_p),r(_r){}
};
int intersect(Circle c1,Circle c2) {
    if(c1.r < c2.r) swap(c1,c2);
    Real d = abs(c1.p - c2.p);
    if(c1.r + c2.r < d) return 4;   //
    if(eq(c1.r + c2.r,d)) return 3; //
    if(c1.r - c2.r < d) return 2;   //
    if(eq(c1.r - c2.r,d)) return 1; //
    return 0;                       //
}
struct Line {
    Point a, b;
    Line() = default;
    Line(Point a, Point b) : a(a), b(b) {}
    Line(Real A, Real B, Real C) // Ax + By = C
    {
        if(eq(A, 0)) a = Point(0, C / B), b = Point(1, C / B);
        else if(eq(B, 0)) a = Point(C / A, 0), b = Point(C / A, 1);
        else a = Point(0, C / B), b = Point(C / A, 0);
    }
    friend ostream &operator<<(ostream &os, Line &p) {
        return os << p.a << " to " << p.b;
    }
    friend istream &operator>>(istream &is, Line &a) {
        return is >> a.a >> a.b;
    }
};

bool parallel(const Line &a, const Line &b) {
    return eq(cross(a.b - a.a, b.b - b.a), 0.0);
}
Point projection(const Line &l, const Point &p) {
    double t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
    return l.a + (l.a - l.b) * t;
}
Real distance(const Line &l, const Point &p) {
    return abs(p - projection(l, p));
}
bool intersect(const Circle &c, const Line &l) {
    return distance(l, c.p) <= c.r + EPS;
}
Point crosspoint(const Line &l, const Line &m) {
    Real A = cross(l.b - l.a, m.b - m.a);
    Real B = cross(l.b - l.a, l.b - m.a);
    if(eq(abs(A), 0.0) && eq(abs(B), 0.0)) return m.a;
    return m.a + (m.b - m.a) * B / A;
}
pair<Point,Point> crosspoint(const Circle &c, const Line l) {
    Point pr = projection(l, c.p);
    Point e = (l.b - l.a) / abs(l.b - l.a);
    if(eq(distance(l, c.p), c.r)) return {pr, pr};
    double base = sqrt(c.r * c.r - norm(pr - c.p));
    return {pr - e * base, pr + e * base};
}
pair<Point,Point> crosspoint(const Circle &c1,const Circle &c2) {
    Real d = abs(c1.p - c2.p);
    Real x = (c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d);
    if (abs(x) > 1) x = (x > 0 ? 1.0 : -1.0);
    Real a = acos(x);
    Real t = atan2(c2.p.imag() - c1.p.imag(), c2.p.real() - c1.p.real());
    Point p1 = c1.p + Point(cos(t + a) * c1.r, sin(t + a) * c1.r);
    Point p2 = c1.p + Point(cos(t - a) * c1.r, sin(t - a) * c1.r);
    return {p1, p2};
}
int main() {
    vi x(3),y(3),r(3);
    rep(i,3) cin >> x[i] >> y[i] >> r[i];
    Line l1,l2,l3;
    Circle c1,c2,c3;
    if(r[0] == r[1]) {
        //debug(2*(x[0]-x[1]),2*(y[0]-y[1]),-x[0]*x[0]-y[0]*y[0]+x[1]*x[1]+y[1]*y[1]);
        l1 = Line(2*(x[0]-x[1]),2*(y[0]-y[1]),-(-x[0]*x[0]-y[0]*y[0]+x[1]*x[1]+y[1]*y[1]));
    }
    else {
        Point a1,a2;
        a1 = Point{((x[0]*r[1]+x[1]*r[0])/(double)(r[0]+r[1])),((y[0]*r[1]+y[1]*r[0])/(double)(r[0]+r[1]))};
        a2 = Point{((-x[0]*r[1]+x[1]*r[0])/(double)(r[0]-r[1])),((-y[0]*r[1]+y[1]*r[0])/(double)(r[0]-r[1]))};
        c1 = Circle((a1 + a2) * 0.5,distance(a1,a2) * 0.5);
    }
    if(r[0] == r[2]) {
        l2 = Line(2*(x[0]-x[2]),2*(y[0]-y[2]),-(-x[0]*x[0]-y[0]*y[0]+x[2]*x[2]+y[2]*y[2]));
    }
    else {
        Point a1,a2;
        a1 = Point{((x[0]*r[2]+x[2]*r[0])/(double)(r[0]+r[2])),((y[0]*r[2]+y[2]*r[0])/(double)(r[0]+r[2]))};
        a2 = Point{((-x[0]*r[2]+x[2]*r[0])/(double)(r[0]-r[2])),((-y[0]*r[2]+y[2]*r[0])/(double)(r[0]-r[2]))};
        debug(a1.real(),a1.imag(),a2.real(),a2.imag());
        c2 = Circle((a1 + a2) * 0.5,distance(a1,a2) * 0.5);
    }
    if(r[2] == r[1]) {
        l3 = Line(2*(x[2]-x[1]),2*(y[2]-y[1]),-(-x[2]*x[2]-y[2]*y[2]+x[1]*x[1]+y[1]*y[1]));
    }
    else {
        Point a1,a2;
        a1 = Point{((x[2]*r[1]+x[1]*r[2])/(double)(r[2]+r[1])),((y[2]*r[1]+y[1]*r[2])/(double)(r[2]+r[1]))};
        a2 = Point{((-x[2]*r[1]+x[1]*r[2])/(double)(r[2]-r[1])),((-y[2]*r[1]+y[1]*r[2])/(double)(r[2]-r[1]))};
        c3 = Circle((a1 + a2) * 0.5,distance(a1,a2) * 0.5);
    }
    if(r[0] == r[1] && r[0] == r[2]) {
        debug(l1.a.real(),l1.a.imag(),l1.b.real(),l1.b.imag());
        debug(l2.a.real(),l2.a.imag(),l2.b.real(),l2.b.imag());
        debug(l3.a.real(),l3.a.imag(),l3.b.real(),l3.b.imag());
        if(parallel(l1,l2) || parallel(l2,l3) || parallel(l3,l1)) {
            return 0;
        }
        Point x1 = crosspoint(l1,l2);
        Point x2 = crosspoint(l2,l3);
        Point x3 = crosspoint(l2,l3);
        if(eq(x1.real(),x2.real()) && eq(x1.imag(),x2.imag()) && eq(x1.real(),x3.real()) && eq(x1.imag(),x3.imag())) {
            cout << x1 << '\n';
        }
    }
    else if(r[0] != r[1] && r[1] != r[2] && r[2] != r[0]) {
        if(intersect(c1,c2) % 4 == 0 || intersect(c2,c3) % 4 == 0 || intersect(c3,c1) % 4 == 0) {
            return 0;
        }
        auto x1 = crosspoint(c1,c2);
        auto x2 = crosspoint(c2,c3);
        auto x3 = crosspoint(c3,c1);
        Real dd = 1e18;
        Point ans;
        Point o1 = Point(x[0],y[0]);
        Point o2 = Point(x[1],y[2]);
        Point o3 = Point(x[2],y[2]);
        rep(i,2) {
            rep(j,2) {
                rep(k,2) {
                    Point y1,y2,y3;
                    if(i % 2) y1 = x1.first;
                    else y1 = x1.second;
                    if(j % 2) y2 = x2.first;
                    else y2 = x2.second;
                    if(k % 2) y3 = x3.first;
                    else y3 = x3.second;
                    if(eq(y1.real(),y2.real()) && eq(y1.imag(),y2.imag()) && eq(y1.real(),y3.real()) && eq(y1.imag(),y3.imag())) {
                        Point pp(x[0],y[0]);
                        if(distance(y1,o1) - EPS <= r[0] || distance(y1,o2) - EPS <= r[1] || distance(y1,o3) - EPS <= r[2]) continue;
                        if(chmin(dd,distance(y1,pp))) ans = y1;
                    }
                }
            }
        }
        if(dd != 1e18) {
            cout << ans << '\n';
        }
    }
    else {
        if(r[0] == r[2]) {
            swap(l1,l2);
            swap(c3,c2);
        }
        else if(r[1] == r[2]) swap(l1,l3);
        else swap(c1,c3);
        debug(c1.p.real(),c1.p.imag(),c1.r,c2.p.real(),c2.p.imag(),c2.r);
        debug(l1.a.real(),l1.a.imag(),l1.b.real(),l1.b.imag());
        if(intersect(c1,c2) % 4 == 0) return 0;
        if((!intersect(c1,l1)) || (!intersect(c2,l1))) return 0;
        auto x1 = crosspoint(c1,c2);
        auto x2 = crosspoint(c1,l1);
        auto x3 = crosspoint(c2,l1);
        Real dd = 1e18;
        Point ans;
        Point o1 = Point(x[0],y[0]);
        Point o2 = Point(x[1],y[2]);
        Point o3 = Point(x[2],y[2]);
        rep(i,2) {
            rep(j,2) {
                rep(k,2) {
                    Point y1,y2,y3;
                    if(i % 2) y1 = x1.first;
                    else y1 = x1.second;
                    if(j % 2) y2 = x2.first;
                    else y2 = x2.second;
                    if(k % 2) y3 = x3.first;
                    else y3 = x3.second;
                    debug(y1.real(),y1.imag(),y2.real(),y2.imag(),y3.real(),y3.imag());
                    if(eq(y1.real(),y2.real()) && eq(y1.imag(),y2.imag()) && eq(y1.real(),y3.real()) && eq(y1.imag(),y3.imag())) {
                        Point pp(x[0],y[0]);
                        if(distance(y1,o1) - EPS <= r[0] || distance(y1,o2) - EPS <= r[1] || distance(y1,o3) - EPS <= r[2]) continue;
                        if(chmin(dd,distance(y1,pp))) ans = y1;
                    }
                }
            }
        }
        if(dd != 1e18) {
            cout << ans << '\n';
        }
    }
}