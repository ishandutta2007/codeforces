#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
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
const int MA = 10000005;
const int MX = 200005;

// Mod int
const int mod = 1000000007;
struct mint {
  ll x;
  mint():x(0){}
  mint(ll x):x((x%mod+mod)%mod){}
  // mint(ll x):x(x){}
  mint& fix() { x = (x%mod+mod)%mod; return *this;}
  mint& operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
  mint& operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
  mint& operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
  mint& operator/=(const mint& a){ (x*=a.ex(mod-2).x)%=mod; return *this;}
  mint operator+(const mint& a)const{ return mint(*this) += a;}
  mint operator-(const mint& a)const{ return mint(*this) -= a;}
  mint operator*(const mint& a)const{ return mint(*this) *= a;}
  mint operator/(const mint& a)const{ return mint(*this) /= a;}
  mint ex(ll t) const {
    if(!t) return 1;
    mint res = ex(t/2);
    res *= res;
    return (t&1)?res*x:res;
  }
  bool operator<(const mint& a)const{ return x < a.x;}
  bool operator==(const mint& a)const{ return x == a.x;}
};
mint ex(mint x, ll t) { return x.ex(t);}
istream& operator>>(istream&i,mint&a){i>>a.x;return i;}
ostream& operator<<(ostream&o,const mint&a){o<<a.x;return o;}
typedef vector<mint> vm;
struct comb {
  vm f, g;
  comb(){}
  comb(int mx):f(mx+1),g(mx+1) {
    f[0] = 1;
    rrep(i,mx) f[i] = f[i-1]*i;
    g[mx] = f[mx].ex(mod-2);
    for(int i=mx;i>0;i--) g[i-1] = g[i]*i;
  }
  mint c(int a, int b) {
    if (a < b) return 0;
    return f[a]*g[b]*g[a-b];
  }
};
//

// linear sieve
vi ps, pf;
void sieve(int mx) {
  pf = vi(mx);
  rep(i,mx) pf[i] = i;
  for (int i = 2; i < mx; ++i) {
    if (pf[i] == i) ps.pb(i);
    for (int j = 0; j < sz(ps) && ps[j] <= pf[i]; ++j) {
      int x = ps[j]*i;
      if (x >= mx) break;
      pf[x] = ps[j];
    }
  }
}
inline bool isp(int x) { return pf[x] == x && x >= 2;}
vi factor(int x) { // asc
  vi res;
  while (x != 1) {
    res.pb(pf[x]);
    x /= pf[x];
  }
  vi tmp = res;
  return res;
}
vi factor2(int x) {
  vi res = factor(x);
  int pre = -1;
  rep(i,sz(res)) {
    if (res[i] == pre) {
      res[i] = res[i-1]*pre;
    } else pre = res[i];
  }
  return res;
}
//

int q;
vi x[MX];
int cnt[MA];
vi qx[MX];
vi qs[MX];
mint ans[MX];

// HL-decomposition
struct hl {
  int n;
  vvi to, d;
  vi vd, vk, pv, dep, pa;
  int root;
  hl() {}
  hl(int mx):n(mx),to(mx),vd(mx),vk(mx),dep(mx),pa(mx,-1) {}
  void add(int a, int b) {
    to[a].pb(b);
    to[b].pb(a);
  }
  int dfs(int v, int de=0, int p=-1) {
    pa[v] = p;
    dep[v] = de;
    vector<P> rs;
    rep(i,sz(to[v])) {
      int u = to[v][i];
      if (u == p) continue;
      rs.pb(P(dfs(u,de+1,v),u));
    }
    if (sz(rs)) {
      sort(rng(rs));
      vd[v] = vd[rs[0].se]; pv[vd[v]] = p;
      d[vd[v]].pb(v); vk[v] = -sz(d[vd[v]]);
      return rs[0].fi - (sz(rs) != 1 && rs[0].fi == rs[1].fi);
    } else {
      vd[v] = sz(d); vk[v] = -1; d.pb(vi(1,v)); pv.pb(p);
      return 1;
    }
  }
  void init(int v=0) {
    dfs(root = v);
    rep(i,sz(d)) reverse(rng(d[i]));
    rep(i,sz(vk)) vk[i] += sz(d[vd[i]]);
  }
  int lca(int a, int b) {
    int p = vd[a]; vi ap(1,p);
    while (pv[p] != -1) ap.pb(p = vd[pv[p]]);
    reverse(rng(ap)); ap.pb(-2);
    p = vd[b]; vi bp(1,p);
    while (pv[p] != -1) bp.pb(p = vd[pv[p]]);
    reverse(rng(bp)); bp.pb(-3);
    int pi = 1; while (ap[pi] == bp[pi]) ++pi;
    p = ap[pi-1];
    int ai = vd[a]==p?vk[a]:vk[pv[ap[pi]]];
    int bi = vd[b]==p?vk[b]:vk[pv[bp[pi]]];
    return d[p][min(ai,bi)];
  }

  void efs(int v, int p=-1) {
    for (int a : x[v]) cnt[a]++;
    for (int qi : qs[v]) {
      int sg = 1;
      if (qi >= q) {
        qi -= q;
        sg = -1;
      }
      mint now = 1;
      for (int a : qx[qi]) now *= ex(pf[a],cnt[a]);
      if (sg == 1) ans[qi] *= now;
      else ans[qi] /= now;
    }
    for (int u : to[v]) {
      if (u == p) continue;
      efs(u,v);
    }
    for (int a : x[v]) cnt[a]--;
  }
  void solve() {
    efs(root);
  }
};
//

int main() {
  sieve(MA);
  int n;
  scanf("%d",&n);
  hl g(n);
  rep(i,n-1) {
    int a,b;
    scanf("%d%d",&a,&b);
    --a; --b;
    g.add(a,b);
  }
  g.init();
  rep(i,n) {
    int d;
    scanf("%d",&d);
    x[i] = factor2(d);
  }
  scanf("%d",&q);
  rep(i,q) {
    int a,b,d;
    scanf("%d%d%d",&a,&b,&d);
    --a; --b;
    int c = g.lca(a,b);
    qs[a].pb(i);
    qs[b].pb(i);
    qs[c].pb(q+i);
    if (c) qs[g.pa[c]].pb(q+i);
    qx[i] = factor2(d);
    ans[i] = 1;
  }
  g.solve();
  rep(i,q) {
    printf("%lld\n",ans[i].x);
  }
  return 0;
}