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
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define df(x) int x = in()
#define dame { puts("0"); return 0;}
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
{for(T&x:v)i>>x;return i;}
template<typename T>string join(vector<T>&v)
{stringstream s;for(T&x:v)s<<' '<<x;return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,vector<T>&v)
{if(sz(v))o<<join(v);return o;}

const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

// coordinate compression
struct X {
  typedef int T;
  vector<T> d;
  inline void add(T x) { d.pb(x);}
  void init() {
    sort(rng(d));
    d.erase(unique(rng(d)), d.end());
  }
  inline int size() { return sz(d);}
  inline T operator[](T x) { return lower_bound(rng(d),x)-d.begin();}
};
//


int n;
X xs;
vvi t;
vi dp;

// SCC
struct scc {
  int n, k;
  vvi to, ot, d, gt; // to, rev_to, groups, group_to
  vi g, used, kv, x; // group, gomi, topo_ord
  scc(int n=0):n(n),to(n),ot(n),d(n),g(n,-1){}
  void add(int a, int b) { to[a].pb(b); ot[b].pb(a);}
  void dfs(int v) {
    if (used[v]) return;
    used[v] = 1;
    rep(i,sz(to[v])) dfs(to[v][i]);
    kv[--k] = v;
  }
  void rfs(int v) {
    if (g[v] != -1) return;
    g[v] = k; d[k].pb(v);
    rep(i,sz(ot[v])) rfs(ot[v][i]);
  }
  void init() {
    k = n;
    used = kv = vi(n,0);
    rep(i,n) dfs(i);
    rep(i,n) {
      if (g[kv[i]] != -1) continue;
      d.pb(vi());
      rfs(kv[i]);
      k++;
    }
    gt = vvi(k);
    rep(i,n)rep(j,sz(ot[i])) {
      int v = g[ot[i][j]], u = g[i];
      if (v != u) gt[v].pb(u);
    }
    rep(i,k) {
      sort(rng(gt[i]));
      gt[i].erase(unique(rng(gt[i])),gt[i].end());
    }
  }
  void solve() {
    x = vi(k,1);
    drep(i,k) {
      for (int u : gt[i]) maxs(x[i],x[u]+1);
    }
  }
};
//

scc g;
void f(vvi& a, bool fl=false) {
  int h = sz(a);
  int w = sz(a[0]);
  rep(i,h) {
    vp x;
    rep(j,w) x.pb(P(a[i][j],j));
    sort(rng(x));
    if (!fl) {
      rep(j,w-1) {
        g.add(t[i][x[j+1].se], t[i][x[j].se]);
        if (x[j].fi == x[j+1].fi) g.add(t[i][x[j].se], t[i][x[j+1].se]);
      }
    } else {
      rep(j,w-1) {
        g.add(t[x[j+1].se][i], t[x[j].se][i]);
        if (x[j].fi == x[j+1].fi) g.add(t[x[j].se][i], t[x[j+1].se][i]);
      }
    }
  }
}

// int dfs(int v) {
//   if (dp[v] != -1) return dp[v];
//   dp[v] = 1;
//   for (int u : to[v]) maxs(dp[v], dfs(u)+1);
//   return dp[v];
// }

int main() {
  int h, w;
  scanf("%d%d",&h,&w);
  vvi a;
  a = vvi(h,vi(w));
  rep(i,h)rep(j,w) scanf("%d",&a[i][j]);
  vp p;
  rep(i,h)rep(j,w) p.pb(P(i,j));
  sort(rng(p),[&](P i, P j){return a[i.fi][i.se] < a[j.fi][j.se];});
  t = vvi(h,vi(w));
  rep(i,sz(p)) t[p[i].fi][p[i].se] = i;
  // rep(i,h)rep(j,w) xs.add(a[i][j]);
  // xs.init();
  // n = sz(xs);
  n = h*w;
  // to = vvi(n);
  g = scc(n);
  vvi a2(w,vi(h)), a1 = a;
  rep(i,h)rep(j,w) a2[j][i] = a[i][j];
  f(a1);
  f(a2,true);
  dp = vi(n,-1);
  g.init(); g.solve();
  rep(i,n) dp[i] = g.x[g.g[i]];
  rep(i,h)rep(j,w) a[i][j] = dp[t[i][j]];
  rep(i,h) priv(a[i]);
  return 0;
}