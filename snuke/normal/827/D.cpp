#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
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
const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

// Segment tree
struct F { // min func
  typedef int TT;
  TT d;
  F(TT d=-INF):d(d) {}
  // TT operator()() const {
  //   return d;
  // }
  F operator+(const F& f) const {
    return F(max(d,f.d));
  }
};
struct seg {
  vector<F> d; int n;
  vi e;
  seg(){}
  seg(int mx) {
    n = 1; while (n < mx) n <<= 1;
    d = vector<F>(n<<1);
    e = vi(n<<1,INF);
  }
  void upd(int i) { d[i] = d[i<<1]+d[i<<1|1];}
  F& operator[](int i) { return d[n+i];}
  void init() { for(int i=n-1;i;--i) upd(i);}
  void set(int i, F f) {
    i+=n; d[i] = f;
    for (i>>=1;i;i>>=1) upd(i);
  }
  F ga(int l, int r) {
    l += n; r += n;
    F lf, rf;
    while (l < r) {
      if (l&1) {
        lf = lf + d[l++];
      }
      if (r&1) {
        rf = d[--r] + rf;
      }
      l >>= 1; r >>= 1;
    }
    return lf + rf;
  }
  void app(int l, int r, int x) {
    l += n; r += n;
    while (l < r) {
      if (l&1) {
        mins(e[l],x);
        ++l;
      }
      if (r&1) {
        --r;
        mins(e[r],x);
      }
      l >>= 1; r >>= 1;
    }
  }
  int get(int i) {
    i += n;
    int res = INF;
    while (i) {
      mins(res, e[i]);
      i >>= 1;
    }
    return res;
  }
};
//
// Union find
struct uf {
  vi d;
  uf(){}
  uf(int mx):d(mx,-1){}
  int root(int x) {
    if(d[x] < 0) return x;
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    if(x == y) return false;
    if(d[x] > d[y]) swap(x,y);
    d[x] += d[y]; d[y] = x;
    return true;
  }
  int size(int x) { return -d[root(x)];}
};
//

// HL-decomposition
struct hl {
  int n;
  vvi to, co, d;
  vi vco, vd, vk, pv, dep;
  vector<seg> t;
  int root;
  hl() {}
  hl(int mx):n(mx),to(mx),co(mx),vco(mx),vd(mx),vk(mx),dep(mx) {}
  void add(int a, int b, int c) {
    to[a].pb(b); co[a].pb(c);
    to[b].pb(a); co[b].pb(c);
  }
  int dfs(int v, int de=0, int p=-1) {
    dep[v] = de;
    vector<P> rs;
    rep(i,sz(to[v])) {
      int u = to[v][i];
      if (u == p) continue;
      vco[u] = co[v][i];
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
    rep(i,sz(d)) {
      t.pb(seg(sz(d[i])+1));
      rep(j,sz(d[i])) t[i][j] = F(vco[d[i][j]]);
      t[i].init();
    }
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
  F ga(int p, int v) {
    F res;
    while (1) {
      int nd = vd[v], nk = vk[v];
      if (nd == vd[p]) {
        return res + t[nd].ga(vk[p]+1,nk+1);
      } else {
        res = res + t[nd].ga(0,nk+1);
      }
      v = pv[nd];
    }
  }
  void app(int p, int v, int x) {
    while (1) {
      int nd = vd[v], nk = vk[v];
      if (nd == vd[p]) {
        t[nd].app(vk[p]+1,nk+1,x);
        return;
      } else {
        t[nd].app(0,nk+1,x);
      }
      v = pv[nd];
    }
  }
  int query(int a, int b, int x) {
    int c = lca(a,b);
    F res = ga(c,a);
    res = res + ga(c,b);
    assert(x >= res.d);
    app(c,a,max(res.d,x));
    app(c,b,max(res.d,x));
    return res.d;
  }
  int get(int a, int b) {
    if (dep[a] < dep[b]) a = b;
    return t[vd[a]].get(vk[a]);
  }
};
//

struct E {
  int a, b, c, i;
  bool operator<(const E& e)const{ return c < e.c;}
};

int main() {
  int n,m;
  scanf("%d%d",&n,&m);
  v(E) es;
  rep(i,m) {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    --a; --b;
    es.pb((E){a,b,c,i});
  }
  uf t(n);
  sort(rng(es));
  vi ans(m);
  hl g(n);
  for (auto&& e : es) {
    if (t.unite(e.a,e.b)) {
      ans[e.i] = -1;
      g.add(e.a,e.b,e.c);
    }
  }
  g.init();
  for (auto&& e : es) {
    int a = e.a, b = e.b, x = e.c, i = e.i;
    if (ans[i] == -1) continue;
    ans[i] = g.query(a,b,x);
  }
  for (auto&& e : es) {
    int a = e.a, b = e.b, i = e.i;
    if (ans[i] != -1) continue;
    ans[i] = g.get(a,b);
  }
  for (int& x : ans) if (x == INF) x = -1; else x--;
  cout<<ans<<endl;
  return 0;
}