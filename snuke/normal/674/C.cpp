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
#include <cassert>
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
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define df(x) int x = in()
#define dame { puts("0"); return 0;}
#define show(x) cout<<#x<<" = "<<x<<endl;
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}
template<typename T>istream& operator>>(istream&i,vector<T>&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(vector<T>&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,vector<T>&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}

const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

// Convex Hull Trick
typedef pair<double,double> LP;
struct CHT {
  deque<LP> v;
  double get(double x) {
    while (sz(v) >= 2) {
      double a = v[0].fi*x + v[0].se;
      double b = v[1].fi*x + v[1].se;
      if (a >= b) break;
      v.pop_front();
    }
    return v[0].fi*x + v[0].se;
  }
  void add(LP x) {
    while (sz(v) >= 2) {
      LP y = v[sz(v) - 1];
      LP z = v[sz(v) - 2];
      if ((x.se-y.se)*(z.fi-y.fi) >= (y.fi-x.fi)*(y.se-z.se)) break;
      v.pop_back();
    }
    v.pb(x);
  }
};
//

int main() {
  int n, m;
  scanf("%d%d",&n,&m);
  vi a(n);
  rep(i,n) scanf("%d",&a[i]);
  double sum = 0, p = 0, ans = 0;
  rep(i,n) {
    p += a[i];
    sum += p/a[i];
  }
  --m;
  vector<CHT> d(m+1);
  rep(i,m+1) d[i].add(LP(0,0));
  p = 0;
  double h = 0;
  rep(i,n) {
    p += 1.0/a[i];
    h += a[i];
    drep(j,m) {
      double x = d[j].get(p);
      d[j+1].add(LP(h,x-h*p));
    }
  }
  ans = sum-d[m].get(p);
  printf("%.10f\n",ans);
  return 0;
}