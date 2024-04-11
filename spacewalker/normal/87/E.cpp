#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
 
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
//#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
 
// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
 
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
using i64 = long long;
//using i128 = __int128;
#define MAXN 3005
#define MAXM 3005
#define M 1000000
#define K 17
#define MAXP 25
#define MAXK 55
#define MAXERR 105
#define MAXLEN 105
#define MDIR 10
#define MAXR 705
#define BASE 102240
#define MAXA 28
#define MAXT 100005
#define LIMIT 86400
#define MAXV 305
#define LEQ 1
#define EQ 0
#define OP 0
#define CLO 1
#define DIG 1
#define C1 0
#define C2 1
#define PLUS 0
#define MINUS 1
#define MUL 2
#define CLO 1
#define VERT 1
#define W 1
#define H 17
#define SPEC 1
#define MUL 2
#define CNT 3
#define ITER 1000
#define INF 1e18
#define EPS 1e-7
#define MOD 998244353
//#define MOD2 1000000007
#define FACT 100000000000000
#define SRC 0
#define PI acos(-1)
#define PUSH 0
#define POP 1
typedef long long ll;
typedef ll hash_t;
//typedef __int128_t lint;
typedef long double ld;
typedef pair<int,int> ii;
typedef pair<int,ll> ilp;
typedef pair<ll,ii> pl;
typedef pair<ll, ll> pll;
typedef pair<ll,int> ppll;
typedef pair<ll,int> li;
typedef pair<ll,ll> iv;
typedef pair<double,int> ip;
typedef tuple<int,int,int> iii;
typedef tuple<ll, ll, ll> tll;
typedef tuple<ld, int, int> iit;
typedef tuple<int,int,ll> i3;
typedef vector<vector<int>> vv;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;
typedef vector<vector<ll>> vll;
typedef complex<ld> cd;
typedef tuple<int,ll,ll> tpl;
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define ppf pop_front
#define pf push_front
#define bk back()
#define frt front()
#define ins insert
#define er erase
#define sc second
#define fr first
#define mp make_pair
#define mt make_tuple
#define repl(i,x,y) for (int i = (x); i <= (y); ++i)
#define rep(i,x,y) for (int i = (x); i < (y); ++i)
#define rev(i,x,y) for (int i = (x); i >= (y); --i)
#define repd(i,x,y,d) for (int i = (x); i < (y); i += (d))
#define LSOne(S) (S & (-S))
#define trav(i,v) for (auto &i : v)
#define foreach(it,v) for (auto it = begin(v); it != end(v); ++it)
#define bend(v) (v).begin(), (v).end()
#define rbend(v) (v).rbegin(), (v).rend()
#define sortarr(v) sort(bend(v))
#define rsortarr(v) sort(rbend(v))
#define unique(v) v.er(unique(bend(v)), end(v))
#define extend(A,B) A.insert(end(A), bend(B))
#define sz(A) (int)(A.size())
#define fill(V) iota(bend(V), (0))
#define vfill(V, st) iota(bend(V), st)
#define sum(V) accumulate(bend(V), 0LL)
#define vsum(V, st) accumulate(bend(V), (ll)(st))
template<class T> bool ckmin(T &a, T b) { return a > b ? a = b, 1 : 0; };
template<class T> bool ckmax(T &a, T b) { return a < b ? a = b, 1 : 0; };
template<class T> void amax(T &a, T b, T c) { a = max(b, c); };
template<class T> void amin(T &a, T b, T c) { a = min(b, c); };
template<class T> T getmax(vector<T> &v) { return *max_element(bend(v)); };
template<class T> T getmin(vector<T> &v) { return *min_element(bend(v)); };
template<class T> int compress(vector<T> &v, T &val) { return (int)(lower_bound(bend(v), val) - begin(v)); };
template<class T> auto vfind(vector<T> &v, T val) {
    return find(bend(v), val);
}
template<class T> auto verase(vector<T> &v, T val) {
    return v.er(vfind(v, val));
}
template<class T> void revarr(vector<T> &v) { reverse(bend(v)); };
template<class T> void print(vector<T> &v, char end) { trav(i,v) cout << i << end;
}
 
mt19937 gen((int)(chrono::steady_clock::now().time_since_epoch().count()));
int rng(int l,int r) {return uniform_int_distribution<int>(l,r)(gen);}
 
void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}
 
struct pt {
    ll x, y;
    public : pt() {};
    public : pt(ll _x,  ll _y) : x(_x), y(_y) {};
    pt operator +(const pt &p) {
        return {x + p.x, y + p.y};
    }
    pt operator -(const pt &p) {
        return {x - p.x, y - p.y};
    }
};
 
struct vec {
    ll x,y;
    public : vec(pt a, pt b) { x = b.x - a.x, y = b.y - a.y; };
    public : vec(ll _x, ll _y) : x(_x), y(_y) {};
};
 
vec toVec(pt &p, pt &q) {
    return vec(p, q);
}
 
ll dot (vec &p, vec &q) {
    return p.x * q.x + p.y * q.y;
}
 
ll sqrmag(vec &p) {
    return p.x * p.x + p.y * p.y;
}
 
pt translate(pt &p, vec q) {
    ll x = p.x + q.x, y = p.y + q.y;
    pt r(x,y); return r;
}
 
vec scale(ll u, vec p) {
    return vec(p.x * u, p.y * u);
}
 
ll cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}
 
bool onseg(pt &p, pt &q, pt &r) {
    return (min(p.x, r.x) <= q.x && max(r.x, p.x) >= q.x && q.y >= min(p.y, r.y)  && max(r.y, p.y) >= q.y);
}
 
int orien(pt &p, pt &q, pt &r) {
    ll res = cross(toVec(p,q), toVec(p,r));
    if (!res) return 0; //Collinear
    return (res < 0) ? 1 : 2; //1 is CW, 2 is CCW
}
 
bool intersect(pt p1, pt p2, pt q1, pt q2) {
    ll o1 = orien(p1, p2, q1), o2 = orien(p1, p2, q2), o3 = orien(q1, q2, p1), o4 = orien(q1,q2,p2);
    if (o1 != o2 && o3 != o4) return true;
    if (o1 == 0 && onseg(p1, q1, p2)) return true;
    if (o2 == 0 && onseg(p1, q2, p2)) return true;
    if (o3 == 0 && onseg(q1, p1, q2)) return true;
    if (o4 == 0 && onseg(q1, p2, q2)) return true;
    return false;
}
 
bool trypoly(vector<pt> &v, pt &p, pt &q, int n) {
    int i = 0;
    bool ac = false;
    do {
        int next = (i + 1) % n;
        if (intersect(v[i], v[next], p, q)) return true;
        i = next;
    } while (i != 0);
    return false;
}
 
bool test(vector<pt> &v, pt &p, int n) {
    int i = 0;
    bool ac = false;
    do {
        int next = (i + 1) % n;
        if ((p.y < v[i].y != p.y < v[next].y) && (double)(p.x) < (double)(v[i].x + (v[next].x - v[i].x) * ((double)(p.y - v[i].y) / (double)(v[next].y - v[i].y)))) ac = !ac;
        i = next;
    } while (i != 0);
    if (ac) return true;
    return false;
}
 
bool edg(vector<pt> &v, pt &p, int n) {
    int i = 0;
    do {
        int next = (i + 1) % n;
        if (orien(v[i], p, v[next]) == 0 && onseg(v[i], p, v[next])) return true;
        i = next;
    } while (i != 0);
    return false;
}
 
ll area(pt a, pt b, pt c) { //function to find the area of a triangle x 2
    ll res = 0;
    res += a.x * b.y - b.x * a.y;
    res += b.x * c.y - c.x * b.y;
    res += c.x * a.y - a.x * c.y;
    return abs(res);
}
 
vector<pt> chull(vector<pt> &points, int n) { //function prunes collinear points, modify it if you want collinear points to be included
     if (points.size() <= 3) return points;
      vector<pt> res(2 * n);
      int m = 0;
      sort(points.begin(), points.end(), [](pt &p, pt &q) {
          if (p.x < q.x) return true;
          if (p.x == q.x && p.y < q.y) return true;
          return false;
      });
      for (int i = 0; i < n; i++) {
          while (m >= 2 && orien(res[m - 2], res[m - 1], points[i]) < 2) m--;
          res[m++] = points[i];
      }
      for (int i = n - 2, t = m + 1; i >= 0; i--) {
          while (m >= t && orien(res[m - 2], res[m - 1], points[i]) < 2) m--;
          res[m++] = points[i];
      }
      res.resize(m - 1);
      return res;
}
 
namespace KACTL {
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
    
    void reorder(vector<Point<ll>> &v) { //reorder in order for the bottom most point to be the one with the smallest x and y coordinates
        int pos = 0;
        rep(i,1,(int)(v.size())) {
            if (v[i].y < v[pos].y || (v[i].y == v[pos].y && v[i].x < v[pos].x)) pos = i;
        }
        //cyclic shift leftwards all vertices before the bottomost point
        rotate(begin(v), begin(v) + pos, end(v));
    }
    

    vector<Point<ll>> minkowski(vector<Point<ll>> &a, vector<Point<ll>> &b) {
        reorder(a); reorder(b);
        a.pb(a[0]); a.pb(a[1]); b.pb(b[0]); b.pb(b[1]);
        vector<Point<ll>> result;
        int i = 0, j = 0;
        while (i < (int)(a.size()) - 2 || j < (int)(b.size()) - 2) {
            result.pb(a[i] + b[j]);
            // ll mag = cross(toVec(a[i], a[i + 1]), toVec(b[j], b[j + 1]));
            ll mag = (a[i+1] - a[i]).cross(b[j+1] - b[j]);
            //polar angle from ai to ai+1 is smaller than or equal to polar angle from bj to bj+1
            if (mag >= 0) i++;
            //polar angle from ai to ai+1 is larger than or equal to polar angle from bj to bj+1
            if (mag <= 0) j++;
        }
        return result;
    }
};

vector<pt> minkowski(vector<pt> &a, vector<pt> &b) {
    vector<KACTL::Point<ll>> pa, pb;
    for (pt p : a) pa.emplace_back(p.x, p.y);
    for (pt p : b) pb.emplace_back(p.x, p.y);
    vector<KACTL::Point<ll>> mks = KACTL::minkowski(pa, pb);
    vector<pt> res;
    for (KACTL::Point p : mks) res.emplace_back(p.x, p.y);
    return res;
}
 
//we want to find points such that there exists OA + OB + OC = 3 * OQ
//by the definition of the centroid of triangle (center of mass)
 
//OA,OB and OC can by any point inside A,B and C. We want to combine all points together into a convex polygon, hence we use minkowski sum
int main() {
    fast_io();
    //int t; cin >> t;
    //while (t--) solve();
    vector<vector<pt>> v(3);
    rep(i,0,3) {
        int n; cin >> n;
        rep(j,0,n) {
            int a,b; cin >> a >> b;
            v[i].pb({a,b});
        }
    }
    vector<pt> temp = minkowski(v[0], v[1]);
    vector<pt> points = minkowski(temp, v[2]);
    points = chull(points, sz(points));
    int m; cin >> m;
    //binary search the enclosing triangle using counter clockwise turns
    //check if the points does indeed lie inside the triangle based on the ccw turns
    rep(i,0,m) {
        ll x,y; cin >> x >> y;
        x *= 3, y *= 3;
        pt p(x,y);
        int lo = 1, hi = sz(points) - 1;
        while (hi - lo > 1) {
            int mid = (hi + lo) >> 1;
            int ccw = orien(points[0], points[mid], p);
            if (ccw == 2) lo = mid;
            else hi = mid;
        }
        bool ok = true;
        if (orien(points[lo], points[hi], p) == 1) ok = false;
        if (orien(points[hi], points[0], p) == 1) ok = false;
        if (orien(points[0], points[lo], p) == 1) ok = false;
        if (ok) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
}