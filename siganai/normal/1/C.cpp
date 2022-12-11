//#pragma GCC target("avx")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

#ifdef LOCAL
#include <debug.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vs = vector<string>;
template<class T> using pq = priority_queue<T, vector<T>, greater<T>>;
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
#define all1(i) begin(i) , end(i)
#define all2(i,a) begin(i) , begin(i) + a
#define all3(i,a,b) begin(i) + a , begin(i) + b
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
ll GCD(ll a,ll b) { if(a == 0 || b == 0) return 0; if(a % b == 0) return b; else return GCD(b,a%b);}
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
constexpr Real EPS = 1e-5;
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
//a-bb-c
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
    Points xy(3);
    rep(i,3) cin >> xy[i];
    double degb = PI - get_angle(xy[0],xy[1],xy[2]);
    double dega = PI - get_angle(xy[1],xy[0],xy[2]);
    double degc = PI - get_angle(xy[1],xy[2],xy[0]);
    double ans = 1e18;
    double distab = hypotl(xy[0].real() - xy[1].real(),xy[0].imag() - xy[1].imag());
    rep(i,3,101) {
        double e = PI / i;
        int flg = 0;
        rep(j,1,i) {
            rep(k,j+1,i) {
                if(fabs(degc - e * j) < EPS && fabs(dega - e * (k - j)) < EPS) {
                    Points pos(i);
                    pos[1] = Point{1,0};
                    double rot = PI * (i - 2) / i;
                    rep(x,2,i) {
                        pos[x] = rotate(PI-rot,(pos[x-1] - pos[x-2])) + pos[x-1]; 
                    }
                    double S = area(pos);
                    double distij = hypot(pos[0].real() - pos[j].real(),pos[0].imag() - pos[j].imag());
                    chmin(ans,S * distab * distab / distij / distij);
                    flg = 1;
                    break;
                }
            }
            if(flg) break;
        }
    }
    cout << ans << '\n';
}