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
#define dame { puts("-1"); return 0;}
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,vector<T>,greater<T> >
#define bn(x) ((1<<x)-1)
#define newline puts("")
#define v(T) vector<T>
#define vv(T) vector<vector<T>>
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
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}
template<typename T>istream& operator>>(istream&i,vector<T>&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const vector<T>&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const vector<T>&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
const int MX = 1000000007, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

int n;
vi x, y;
vi s;

int f(int l, int r) {
  --l;
  int sr = r;
  while (l+1<r) {
    int c = (l+r)/2;
    int t = n+c;
    int nx = 0, ny = 0;
    rep(i,5) {
      ll ns = s[i];
      if (x[i] == -1) ns += 0;
      else if (y[i] == -1) ns += 0;
      else if (x[i] > y[i]) ns += c;
      int ms = 3000;
      for (int j = 32; j >= 2; j>>=1) {
        if (ns*j > t) ms -= 500;
      }
      if (x[i] != -1) nx -= ms*x[i]; else nx -= ms*250;
      if (y[i] != -1) ny -= ms*y[i]; else ny -= ms*250;
    }
    if (nx > ny) r = c; else l = c;
  }
  if (sr == r) return INF;
  return r;
}

int main() {
  scanf("%d",&n);
  vvi a(n,vi(5));
  rep(i,n)rep(j,5) scanf("%d",&a[i][j]);
  x = a[0]; y = a[1];
  s = vi(5);
  rep(i,5)rep(j,n) if (a[j][i] != -1) s[i]++;
  int ans = INF;
  vi p = {0,MX+1};
  rep(i,5) {
    for (int j = 32; j >= 2; j>>=1) {
      int t = s[i]*j;
      if (t <= n) continue;
      p.pb(t-n);
    }
  }
  sort(rng(p));
  rep(i,sz(p)) {
    if (p[i] == MX+1) break;
    mins(ans,f(p[i],p[i+1]));
  }
  if (ans == INF) ans = -1;
  cout<<ans<<endl;
  return 0;
}