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
#define PQ(T) priority_queue<T,vector<T>,greater<T> >
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<double> vd;
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

// Fast Hadamard Transform
void ada(vd& d) {
  int n = sz(d);
  for (int i = n; i >= 1; i >>= 1) {
    rep(j,n) if (j&i) {
      double x = d[j^i], y = d[j];
      d[j^i] = x+y;
      d[j] = x-y;
    }
  }
}
void dad(vd& d) {
  int n = sz(d);
  double i2 = 0.5;
  for (int i = 1; i <= n; i <<= 1) {
    rep(j,n) if (j&i) {
      double x = d[j^i], y = d[j];
      d[j^i] = (x+y)*i2;
      d[j] = (x-y)*i2;
    }
  }
}
//

double ex(double x, int t) {
  if (!t) return 1;
  double y = ex(x,t/2);
  y *= y;
  if (t&1) y *= x;
  return y;
}

int main() {
  int n;
  scanf("%d",&n);
  int m;
  scanf("%d",&m);
  int m2 = 1;
  while (m2 <= m) m2 <<= 1;
  vd p(m2);
  rep(i,m+1) {
    scanf("%lf",&p[i]);
  }
  ada(p);
  rep(i,m2) p[i] = ex(p[i],n);
  dad(p);
  printf("%.10f\n",1-p[0]);
  return 0;
}