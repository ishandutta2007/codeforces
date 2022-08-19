#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <numeric>
#include <cctype>
#include <bitset>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define df(x) int x = in()
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

// geom
#include <cmath>
const double inf = 1e6;
const double PI = acos(-1.0);
inline double toRad(double deg){ return deg * PI / 180.0;}

struct V {
  double x, y;
  V(double x=0, double y=0):x(x),y(y){}
  V operator+(V t) { return V(x+t.x,y+t.y);}
  V operator-(V t) { return V(x-t.x,y-t.y);}
  V operator*(double t) { return V(x*t,y*t);}
  V operator/(double t) { return V(x/t,y/t);}
  double dot(V t) { return x*t.x + y*t.y;}
  double cross(V t) { return x*t.y - y*t.x;}
  double norm2() { return x*x + y*y;}
  double norm() { return sqrt(x*x + y*y);}
  V rev() { return V(-x,-y);}
  V normalize() { return V(x/norm(), y/norm());}
  V rotate90() { return V(-y,x);}
  V rotate(V a, double rad){
    return V(a.x + cos(rad)*(x-a.x) - sin(rad)*(y-a.y),
             a.y + sin(rad)*(x-a.x) + cos(rad)*(y-a.y));
  }
  bool operator<(V a)const { return abs(x - a.x) > eps ? x < a.x : y < a.y;}
  bool operator==(V a)const { return abs(x - a.x) < eps && abs(y - a.y) < eps;}
};

struct Line {
  V s, t;
  Line(V s=V(0,0), V t=V(0,0)):s(s),t(t){}
  V dir() { return t-s;}
  V normalize() { return dir().normalize();}
  double norm() { return dir().norm();}
  /* +1: s-t,s-p : ccw
   * -1: s-t,s-p : cw
   * +2: t-s-p
   * -2: s-t-p
   *  0: s-p-t */
  int ccw(V p) {
    if (dir().cross(p-s) > eps) return +1;
    if (dir().cross(p-s) < -eps) return -1;
    if (dir().dot(p-s) < -eps) return +2;
    if (dir().norm()+eps < (p-s).norm()) return -2;
    return 0;
  }
  bool touch(Line l) {
    int a = ccw(l.s)*ccw(l.t), b = l.ccw(s)*l.ccw(t);
    return !a || !b || (a == -1 && b == -1);
  }
  double distLP(V p) { return abs(dir().cross(p-s)/norm());}
  double distSP(V p) {
    if (dir().dot(p-s) < eps) return (p-s).norm();
    if (dir().rev().dot(p-t) < eps) return (p-t).norm();
    return distLP(p);
  }
  double distSS(Line l) {
    if(touch(l)) return 0;
    return min(min(distSP(l.s),distSP(l.t)),min(l.distSP(s),l.distSP(t)));
  }
  V proj(V p) {
    double a = (p-s).dot(dir())/(norm()*norm());
    return s + dir()*a;
  }
  Line mid() {
    V p = (s+t)/2, q = dir();
    return Line(p, p+V(q.y,-q.x));
  }
  V xp(Line l) {
    V a = dir(), b = l.dir();
    if (abs(b.cross(a)) < eps) return V(inf,inf);
    return s + a*(b.cross(l.s-s)/b.cross(a));
  }
};

typedef vector<V> Poly;
// geom

int n;
Poly p;
typedef pair<double, int> Q;
vector<Q> e;

int main() {
  scanf("%d",&n);
  p.resize(n);
  rep(i,n) scanf("%lf%lf",&p[i].x,&p[i].y);
  int pi = 1;
  rep(i,n) if (i) {
    if ((p[0]-p[i]).norm() < (p[0]-p[pi]).norm()) pi = i;
  }
  Line l(p[0],p[pi]);
  rep(i,n) {
    double z = l.distLP(p[i]);
    if (abs(z) < eps) continue;
    e.pb(Q(z,i+1));
  }
  sort(rng(e));
  printf("%d %d %d\n",1,pi+1,e[0].se);
  return 0;
}