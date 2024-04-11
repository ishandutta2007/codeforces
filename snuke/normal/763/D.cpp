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

const int p1 = 33487;
struct mints {
  template<int mod>
  struct mint {
    ll x;
    mint(ll x=0):x(x){}
    mint& operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
    mint& operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
    mint& operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
    mint& operator/=(const mint& a){ (x*=a.ex(mod-2).x)%=mod; return *this;}
    mint operator+(const mint& a)const{ return mint(*this) += a;}
    mint operator-(const mint& a)const{ return mint(*this) -= a;}
    mint operator*(const mint& a)const{ return mint(*this) *= a;}
    mint operator/(const mint& a)const{ return mint(*this) /= a;}
    bool operator<(const mint& a)const{ return x < a.x;}
    bool operator==(const mint& a)const{ return x == a.x;}
    mint ex(ll t) const {
      if(!t) return 1;
      mint res = ex(t/2);
      res *= res;
      return (t&1)?res*x:res;
    }
  };
  mint<987654347> x;
  mint<1011235817> y;
  mints(ll x=0):x(x),y(x){}
  mints& operator+=(const mints& a){ x+=a.x; y+=a.y; return *this;}
  mints& operator-=(const mints& a){ x-=a.x; y-=a.y;  return *this;}
  mints& operator*=(const mints& a){ x*=a.x; y*=a.y;  return *this;}
  mints& operator/=(const mints& a){ x/=a.x; y/=a.y;  return *this;}
  mints operator+(const mints& a)const{ return mints(*this) += a;}
  mints operator-(const mints& a)const{ return mints(*this) -= a;}
  mints operator*(const mints& a)const{ return mints(*this) *= a;}
  mints operator/(const mints& a)const{ return mints(*this) /= a;}
  bool operator<(const mints& a)const{ return (x==a.x)?(y<a.y):(x<a.x);}
  bool operator==(const mints& a)const{ return x==a.x && y==a.y;}
};
ostream& operator<<(ostream&o,const mints&a){o<<'('<<a.x.x<<','<<a.y.x<<')';return o;}
typedef vector<mints> vm;

// coordinate compression
struct X {
  typedef mints T;
  vector<T> d;
  inline void add(T x) { d.pb(x);}
  void init() {
    sort(rng(d));
    d.erase(unique(rng(d)), d.end());
  }
  inline int size() { return sz(d);}
  inline int operator[](T x) { return upper_bound(rng(d),x)-d.begin()-1;}
};
//
vvi to;

vm ed[MX];
vm dp;
mints tfs(int v, int p=-1) {
  mints res = p1;
  rep(i,sz(to[v])) {
    int u = to[v][i];
    if (u == p) continue;
    mints r = tfs(u,v);
    ed[v][i] = r;
    res += r*r;
  }
  return dp[v] = res;
}
void sfs(int v, mints x, int p=-1) {
  dp[v] += x*x;
  rep(i,sz(to[v])) {
    int u = to[v][i];
    if (u == p) {
      ed[v][i] = x;
      continue;
    }
    mints y = dp[v]-dp[u]*dp[u];
    sfs(u,y,v);
  }
}

vvi e;
vi c; int now;
void add(int x) {
  if (!c[x]) ++now;
  c[x]++;
}
void del(int x) {
  c[x]--;
  if (!c[x]) --now;
}
void dfs(int v, int p=-1) {
  rep(i,sz(to[v])) {
    int u = to[v][i];
    if (u == p) {
      add(e[v][i]);
      continue;
    }
    dfs(u,v);
  }
}
P ans;
void bfs(int v, int p=-1) {
  int pi = -1;
  rep(i,sz(to[v])) {
    int u = to[v][i];
    if (u == p) pi = i;
  }
  if (pi != -1) del(e[v][pi]);
  maxs(ans, P(now+1,v));
  rep(i,sz(to[v])) {
    int u = to[v][i];
    if (u == p) continue;
    add(e[v][i]);
    bfs(u,v);
    del(e[v][i]);
  }
  if (pi != -1) add(e[v][pi]);
}

int main() {
  int n;
  scanf("%d",&n);
  to = vvi(n);
  rep(i,n-1) {
    int a,b;
    scanf("%d%d",&a,&b);
    --a; --b;
    to[a].pb(b);
    to[b].pb(a);
  }
  dp = vm(n);
  rep(i,n) ed[i] = vm(sz(to[i]));
  tfs(0);
  sfs(0,0);
  e = vvi(n);
  X xs;
  rep(i,n) {
    rep(j,sz(to[i])) {
      ed[i][j] = dp[i]-ed[i][j]*ed[i][j];
      xs.add(ed[i][j]);
    }
  }
  xs.init();
  rep(i,n)rep(j,sz(ed[i])) e[i].pb(xs[ed[i][j]]);
  c = vi(sz(xs));
  dfs(0);
  bfs(0);
  cout<<ans.se+1<<endl;
  return 0;
}