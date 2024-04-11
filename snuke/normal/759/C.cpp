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
#include <random>
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

// Starry sky tree
struct seg {
  typedef ll TT;
  vector<TT> d, e; int x2;
  seg(){}
  seg(int mx) {
    x2 = 1; while(x2 < mx) x2 <<= 1;
    d = e = vector<TT>(x2<<1);
  }
  void f(int i) {
    int l = i<<1, r = l|1;
    d[l] += d[i]; e[l] += d[i];
    d[r] += d[i]; e[r] += d[i];
    d[i] = 0;
  }
  void add(int a, int b, ll x, int i=1, int l=0, int r=-1){
    if (r == -1) r = x2;
    if(a <= l && r <= b) {
      d[i] += x;
      e[i] += x;
      return;
    }
    f(i);
    int c = (l+r)>>1;
    if(a < c) add(a,b,x,i<<1,l,c);
    if(c < b) add(a,b,x,i<<1|1,c,r);
    e[i] = max(e[i<<1],e[i<<1|1]);
  }
  int get() {
    if (e[1] <= 0) return -1;
    int i = 1, s = 0;
    while (i < x2) {
      s += d[i];
      i <<= 1;
      if (e[i+1]+s > 0) ++i;
    }
    return i-x2;
  }
};
//

vi as;

int main() {
  int n;
  scanf("%d",&n);
  seg t(n+2);
  as = vi(n+2);
  rep(i,n) {
    int p,ty;
    scanf("%d%d",&p,&ty);
    if (ty) { // push
      int a;
      scanf("%d",&a);
      as[p] = a;
      t.add(0,p+1,1);
    } else {
      t.add(0,p+1,-1);
    }
    int j = t.get();
    // cout<<j<<endl;
    if (j == -1) puts("-1");
    else printf("%d\n",as[j]);
  }
  return 0;
}