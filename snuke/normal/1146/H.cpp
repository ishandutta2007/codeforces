#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>inline ostream& operator<<(ostream&o,const v(T)&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>inline ostream& operator<<(ostream&o,const pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
template<typename T>inline ll suma(const v(T)& a) { ll res(0); for (auto&& x : a) res += x; return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return 0;}
#define yn {puts("YES");}else{puts("NO");}
const int MX = 200005;

// geom
#include <cmath>
const double inf = 1e6;
const double PI = acos(-1.0);
inline double toRad(double deg){ return deg * PI / 180.0;}

struct V {
  double x, y;
  V(double x=0, double y=0):x(x),y(y){}
  V operator+(V t) const { return V(x+t.x,y+t.y);}
  V operator-(V t) const { return V(x-t.x,y-t.y);}
  V operator*(double t) const { return V(x*t,y*t);}
  V operator/(double t) const { return V(x/t,y/t);}
  double dot(V t) const { return x*t.x + y*t.y;}
  double cross(V t) const { return x*t.y - y*t.x;}
  double norm2() const { return x*x + y*y;}
  double norm() const { return sqrt(x*x + y*y);}
  V rev() const { return V(-x,-y);}
  V normalize() const { return V(x/norm(), y/norm());}
  V rotate90() const { return V(-y,x);}
  V rotate(V a, double rad) const {
    return V(a.x + cos(rad)*(x-a.x) - sin(rad)*(y-a.y),
             a.y + sin(rad)*(x-a.x) + cos(rad)*(y-a.y));
  }
  // bool operator<(V a) const { return abs(x - a.x) > eps ? x < a.x : y < a.y;}
  bool operator==(V a) const { return abs(x - a.x) < eps && abs(y - a.y) < eps;}
  //
  inline int side() const {
    if (abs(y) < eps) return x > 0 ? 0 : 2;
    return y > 0 ? 1 : 2;
  }
  bool operator<(V a) const {
    int s = side(), sa = a.side();
    if (s != sa) return s < sa;
    return cross(a) > 0;
  }
};
typedef vector<V> Poly;
// geom

typedef pair<V,P> E;
ll dp[305][305][5];

int main() {
  int n;
  scanf("%d",&n);
  Poly p(n);
  rep(i,n) cin>>p[i].x>>p[i].y;
  v(E) es;
  rep(i,n)rep(j,n) if (i != j) es.pb(E(p[j]-p[i], P(i,j)));
  sort(rng(es));
  for (auto e : es) {
    int a = e.se.fi, b = e.se.se;
    dp[a][b][0]++;
    rep(i,4)rep(s,n) dp[s][b][i+1] += dp[s][a][i];
  }
  ll ans = 0;
  rep(i,n) ans += dp[i][i][4];
  cout<<ans<<endl;
  return 0;
}