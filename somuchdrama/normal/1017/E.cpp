#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::pair;using std::set;using std::string;using std::vector;
using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;
#define ff first
#define ss second
#define pb emplace_back
template<typename T>void _dbg(const char*_s,T _h){cerr<<_s<<" = "<<_h<<"\n";}
template<typename T,typename...Ts>void _dbg(const char*_s,T _h,Ts..._t){int _b=0;while(((_b+=*_s=='(')-=*_s==')')!=0||*_s!=',')cerr<<*_s++;cerr<<" = "<<_h<<",";_dbg(_s+1,_t...);}
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 
#endif
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
cerr<<"Time elaped: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#endif
}}init;
const int N = 1e5+1;
#define sqr(x) ((x)*(x))
using myf = long long;
const myf EPS = 1e-10, PI = 3.1415926535897932384626433, MAXC = 1e9;
const bool FLOAT_GEOMETRY = std::is_floating_point<myf>::value;

inline bool less(myf a, myf b) {return a + EPS < b;}
inline bool greater(myf a, myf b) {return a > b + EPS;}
inline bool equal(myf a, myf b) {return abs(a - b) / max(myf(1), abs(a)) <= EPS;}
inline bool neq(myf a, myf b) {return abs(a - b) / max(myf(1), abs(a)) > EPS;}
inline bool leq(myf a, myf b) {return less(a, b) || equal(a, b);}
inline bool geq(myf a, myf b) {return greater(a, b) || equal(a, b);}

struct point
{
    myf x, y;
    point() {}
    point(myf _x, myf _y): x(_x), y(_y) {}
    bool operator < (const point & rhs) const {
        return x == rhs.x ? y < rhs.y : x < rhs.x; // no epsilon
    }
    bool operator == (const point & rhs) const {
        return equal(x, rhs.x) && equal(y, rhs.y);
    }
};
inline myf dist(point a, point b) {return hypotl(b.x - a.x, b.y - a.y);}
inline myf sqdist(point a, point b) {return sqr(b.x - a.x) + sqr(b.y - a.y);}

inline bool btw(myf o, myf d1, myf d2) {
    return (less(d1, o) && less(o, d2)) || (less(d2, o) && less(o, d1));
}

inline bool btw(point o, point p1, point p2) {
    return btw(o.x, p1.x, p2.x) && btw(o.y, p1.y, p2.y);
}

std::istream & operator >>(std::istream & is, point & p) {
    return is >> p.x >> p.y;
}

std::ostream & operator <<(std::ostream & os, point & p) {
    return os << p.x << ' ' << p.y;
}

struct vc
{
    myf x, y;
    vc() {}
    vc(myf _x, myf _y): x(_x), y(_y) {}
    vc(point a, point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
    myf length() {
        return hypotl(x, y);
    }
    myf sqlength() {
        return sqr(x) + sqr(y);
    }
};

point operator +(point a, vc v) {
    return point(a.x + v.x, a.y + v.y);
}

vc operator +(vc a, vc v) {
    return vc(a.x + v.x, a.y + v.y);
}

myf operator *(vc a, vc b) {
    return a.x * b.x + a.y * b.y;
}

myf operator %(vc a, vc b) {
    return a.x * b.y - a.y * b.x;
}

vc operator *(vc v, myf x) {
    return vc(v.x * x, v.y * x);
}

vc turn_clockwise(vc a) {
    return vc(a.y, -a.x);
}

vc turn_anticlockwise(vc a) {
    return vc(-a.y, a.x);
}

struct line
{
    myf a, b, c;
    line() {}
    line(myf _a, myf _b, myf _c): a(_a), b(_b), c(_c) {
        if (FLOAT_GEOMETRY) normalize();
    }
    line(point one, point two) {
        a = one.y - two.y;
        b = two.x - one.x;
        c = -(a * one.x + b * one.y);
        if (FLOAT_GEOMETRY) normalize();
    }
    line(vc norm, point cont) {
        a = norm.x;
        b = norm.y;
        c = -(a * cont.x + b * cont.y);
        if (FLOAT_GEOMETRY) normalize();
    }
    void normalize() {
        myf div = hypotl(a, b);
        a /= div;
        b /= div;
        c /= div;
    }
    bool operator()(point p) {
        return equal(a*p.x+b*p.y+c,0);
    }
};

struct circle {
    point center;
    myf radius;
    circle() {}
    circle(point _center, myf _radius) : center(_center), radius(_radius) {}
    circle(point _center, vc _v) : center(_center) {
        radius = _v.length();
    }
    bool inside(point p) {
        return leq(dist(p, center), radius);
    }
    bool strict_inside(point p) {
        return less(dist(p, center), radius);
    }
    bool operator()(point p) {
        return equal(dist(p, center), radius);
    }
};

myf point_segment_dist(point O, point p1, point p2) { // point O, segment [p1, p2]
    return (leq((vc(p1, O) * vc(p1, p2)) * (vc(p2, p1) * vc(p2, O)), 0)) ? 
        min(dist(O, p1), dist(O, p2)) : abs((vc(O, p1) % vc(O, p2)) / dist(p1, p2));
}

myf det(myf a, myf b, myf c, myf d) {
    return a * d - b * c;
}
// 0 if parallel; {1, point} if OK; 2 if match.
int cross(line one, line two, point & p) { 
    myf dx = det(one.c, one.b, two.c, two.b),
        dy = det(one.a, one.c, two.a, two.c),
        dd = det(one.a, one.b, two.a, two.b);
    if (equal(dx, 0) && equal(dy, 0) && equal(dd, 0))
        return 2;
    else if (equal(dd, 0))
        return 0;
    p = point(-dx / dd, -dy / dd);
    return 1;
}

// 0 if A in C; {1, point} if A on C; {2, point, point} if OK
int kasat(point A, circle C, point & p1, point & p2) { 
    vc OA(C.center, A);
    myf l = OA.length();
    if (less(l, C.radius)) 
        return 0;
    myf x = sqr(C.radius) / l;
    vc OP(OA.x * x / l, OA.y * x / l);
    point P = C.center + OP;
    myf hor = sqrtl(sqr(C.radius) - OP.sqlength());
    p1 = P + turn_clockwise(OP * (hor / x));
    p2 = P + turn_anticlockwise(OP * (hor / x));
    return equal(l, C.radius) ? 1 : 2;
}
// 0 no intersection; 1/2 = OK(1/2 points)
int cross(line l, circle c, point & p1, point & p2) { 
    if (equal(l.b, 0)) {
        p1.x = -l.c / l.a;
        if (geq(sqr(c.radius), sqr(p1.x))) {
            p2.x = p1.x;
            p1.y = c.center.y + sqrtl(max(myf(0), sqr(c.radius) - sqr(c.center.x - p1.x)));
            p2.y = c.center.y - sqrtl(max(myf(0), sqr(c.radius) - sqr(c.center.x - p1.x)));
            return equal(sqr(c.radius), sqr(c.center.x - p1.x)) ? 1 : 2;
        }
        return 0;
    }
    myf tt = (l.c + l.b * c.center.y) / l.b;
    myf ta = 1 + sqr(l.a / l.b),
        tb = 2 * (tt * l.a / l.b - c.center.x),
        tc = sqr(tt) - sqr(c.radius) + sqr(c.center.x);
    myf td = sqr(tb) - 4 * ta * tc;
    if (less(td, 0)) 
        return 0;
    p1.x = (-tb + sqrtl(max(myf(0), td))) / (2 * ta); 
    p2.x = (-tb - sqrtl(max(myf(0), td))) / (2 * ta);
    p1.y = (-l.c - l.a * p1.x) / l.b;
    p2.y = (-l.c - l.a * p2.x) / l.b;
    return equal(td, 0) ? 1 : 2;
}
// 0 no intersection; 1/2 = OK(1/2 points); 3 = match
int cross(circle one, circle two, point & p1, point & p2) { 
    if (equal(one.center.x, two.center.x) && equal(one.center.y, two.center.y)) 
        return equal(one.radius, two.radius) ? 3 : 0;
    line l(2 * (two.center.x - one.center.x), 2 * (two.center.y - one.center.y), 
        sqr(one.center.x) - sqr(two.center.x) + 
        sqr(one.center.y) - sqr(two.center.y) + 
        sqr(two.radius) - sqr(one.radius));
    return cross(l, one, p1, p2);
}
// a[0] == a.back(), points anticlockwise, O(log n)
bool inside_convex_polygon(const vector<point> & a, point p) {  
    int n = a.size() - 1, l = 1, r = a.size() - 2;
    vc cur(a[0], p);
    if (less(vc(a[0], a[1]) % cur, 0) || less(cur % vc(a[0], a[n - 1]), 0))
        return false;
    while (r - l > 1) {
        int m = l + r >> 1;
        if (geq(cur % vc(a[0], a[m]), 0))
            r = m;
        else
            l = m;
    }
    return leq(vc(a[r], p) % vc(a[r], a[r + 1]), 0) && 
        leq(vc(a[r - 1], p) % vc(a[r - 1], a[r]), 0);
}
point ch_start;
bool ch_comp(const point & p1, const point & p2) {
    vc op1(ch_start, p1), op2(ch_start, p2);
    if (op1 % op2 == 0) // and here
        return sqr(op1.x) + sqr(op1.y) < sqr(op2.x) + sqr(op2.y);
    return op1 % op2 > 0;        
}
vector<point> convex_hull(const vector<point> & p) {
    if (p.empty()) return {};
    ch_start = *std::min_element(p.begin(), p.end());

    vector<point> a;
    for (const point & i : p)
        if (i.x != ch_start.x || i.y != ch_start.y) // same here
            a.pb(i);

    sort(a.begin(), a.end(), ch_comp);

    if (a.empty()) 
        return {ch_start};

    vector<point> ans = {ch_start, a[0]};
    for (uint i = 1; i < a.size(); ++i) {
        while (ans.size() >= 2 && vc(ans[ans.size() - 2], ans.back()) % vc(ans.back(), a[i]) <= 0)
            ans.pop_back();
        ans.pb(a[i]);
    }
    return ans;
}

bool check(vector<point> a, vector<point> b) {
    int n = a.size();
    for (int i = 1; i < n; ++i) {
        if (a[i].x - a[i - 1].x != b[i].x - b[i - 1].x || a[i].y - a[i - 1].y != b[i].y - b[i - 1].y)
            return 0;
    }
    return 1;
}
vector<int> zfunc(const vector<ll> & s) {
    int n = s.size();
    vector<int> z(n, 0);
    int left = 0, right = 0;
    for (int i = 1; i < n; ++i) {
        if (i < right)
            z[i] = min(z[i - left], right - i);
        while ((i + z[i] < n) && (s[z[i]] == s[i + z[i]]))
            ++z[i];
        if (i + z[i] > right) {
            left = i;
            right = i + z[i];
        }
    }
    return z;
}

const ll INF = 1e18;

int main(){

    int n, m;
    cin >> n >> m;
    vector<point> a(n), b(m);
    for (auto & i : a)
        cin >> i;
    for (auto & i : b)
        cin >> i;
    a = convex_hull(a);
    b = convex_hull(b);

    for (auto i : a)
        dbg(i);
    for (auto j : b)
        dbg(j);

    if (a.size() != b.size()) {
        cout << "NO\n";
        return 0;
    }

    n = a.size();
    for (int i = 0; i < n; ++i)
        a.pb(a[i]);
    a.pb(a[0]);
    a.pb(a[1]);
    vector<ll> order;

    b.pb(b[0]);
    b.pb(b[1]);
    for (int i = 0; i < n; ++i) {
        order.pb(sqdist(b[i], b[i+1]));
        vc v1(b[i+1],b[i]);
        vc v2(b[i+1],b[i+2]);
        order.pb(v1 % v2);
        order.pb(v1 * v2);
    }

    order.pb(INF);

    for (int i = 0; i < n + n; ++i) {
        order.pb(sqdist(a[i], a[i+1]));
        vc v1(a[i+1],a[i]);
        vc v2(a[i+1],a[i+2]);
        order.pb(v1 % v2);
        order.pb(v1 * v2);        
    }
    dbg("okay");
    auto z = zfunc(order);
    dbg("okay");

    for (int i = n * 3; i < order.size(); ++i) {
        if (z[i] == n * 3) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}