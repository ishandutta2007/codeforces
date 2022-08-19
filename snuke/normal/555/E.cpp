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
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rrep(i,n) for(int i = 1; i <= n; ++i)
#define drep(i,n) for(int i = n-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 200005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;

// HL-decomposition
struct hl {
  vector<vi> to, d;
  vi vd, vk, pv, dep;
  // vector<bit> t;
  int root;
  hl() {}
  hl(int mx):to(mx),vd(mx),vk(mx),dep(mx) {}
  void addEdge(int a, int b) {
    to[a].pb(b);
    to[b].pb(a);
  }
  int dfs(int v, int de=0, int p=-1) {
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
    // rep(i,sz(d)) t.pb(bit(sz(d[i])+1));
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
  // int sum(int p, int v) {
  //   int res = 0;
  //   while (1) {
  //     int nd = vd[v], nk = vk[v];
  //     res += t[nd].sum(nk);
  //     if (nd == vd[p]) return res - t[nd].sum(vk[p]);
  //     v = pv[nd];
  //   }
  // }
};
//

// Lowlink
// bridge : v->u, ord[u]==low[u]
// articulation : exist ord[v]<=low[u] (root:*2)
struct Lowlink {
  int n, k;
  vector<vector<int> > to, rti, st, br, g, gr;
  vector<int> ord, low, art, vg;
  vi uc, dc;
  hl ht;
  Lowlink(int n=0):n(n),to(n),rti(n),st(n),br(n),ord(n,-1),low(n),art(n){}
  void add(int a, int b) {
    to[a].push_back(b); rti[a].pb(sz(to[b])); st[a].push_back(0);
    to[b].push_back(a); rti[b].pb(sz(to[a])-1); st[b].push_back(0);
  }
  void dfs(int v, int p=-1) {
    ord[v] = low[v] = k++;
    rep(i,to[v].size()) {
      int u = to[v][i];
      if (i == p) continue;
      if (ord[u] == -1) {
        st[v][i] = 1;
        dfs(u,rti[v][i]);
        low[v] = min(low[v],low[u]);
      } else {
        st[v][i] = -1;
        low[v] = min(low[v],ord[u]);
      }
    }
  }
  void init() {
    k = 0;
    dfs(0);
    rep(i,n)rep(j,to[i].size()) {
      int v = i, u = to[i][j];
      if (ord[v] > ord[u]) swap(v,u);
      br[i].push_back(ord[u] == low[u]);
    }
    rep(i,n) {
      int cnt = 0;
      rep(j,to[i].size()) {
        if (st[i][j] == 1 && ord[i] <= low[to[i][j]]) ++cnt;
      }
      art[i] = cnt > !i;
    }
    g.resize(1);
    gr.resize(1);
    vg = vi(n);
    gfs(0,0);
    ht = hl(sz(g));
    rep(i,sz(g)) {
      for (int u : g[i]) ht.addEdge(i,u);
    }
    ht.init();
    uc = vi(sz(g));
    dc = vi(sz(g));
  }
  void gfs(int v, int r) {
    gr[r].push_back(v);
    vg[v] = r;
    rep(i,to[v].size()) {
      if (st[v][i] != 1) continue;
      if (br[v][i]) {
        g[r].push_back(g.size());
        g.push_back(vector<int>());
        gr.push_back(vector<int>());
        gfs(to[v][i],g.size()-1);
      } else gfs(to[v][i],r);
    }
  }
  int lca(int a, int b) {
    return ht.lca(a,b);
  }
  bool cfs(int v) {
    bool res = true;
    for (int u : g[v]) {
      res &= cfs(u);
      uc[v] += uc[u];
      dc[v] += dc[u];
    }
    res &= (uc[v] == 0 || dc[v] == 0);
    return res;
  }
  bool check() {
    return cfs(0);
  }
};
//

// Union find
struct uf{
  vector<int> d;
  uf(){}
  uf(int mx):d(mx,-1){}
  int root(int x){
    if(d[x] < 0) return x;
    return d[x] = root(d[x]);
  }
  void unite(int x, int y){
    x = root(x); y = root(y);
    if(x == y) return;
    if(d[x] > d[y]) swap(x,y);
    d[x] += d[y]; d[y] = x;
  }
};
//

int n, m, q;

int main() {
  scanf("%d%d%d",&n,&m,&q);
  Lowlink t(n);
  uf ud(n);
  rep(i,m) {
    int a, b;
    scanf("%d%d",&a,&b);
    a--; b--;
    t.add(a,b);
    ud.unite(a,b);
  }
  vi roots;
  rep(i,n) if (ud.root(i) == i) roots.pb(i);
  rep(i,sz(roots)-1) t.add(roots[0],roots[i+1]);
  t.init();
  rep(qi,q) {
    int a, b;
    scanf("%d%d",&a,&b);
    --a; --b;
    if (ud.root(a) != ud.root(b)) {
      puts("No");
      return 0;
    }
    a = t.vg[a];
    b = t.vg[b];
    int c = t.lca(a,b);
    t.uc[a]++; t.uc[c]--;
    t.dc[b]++; t.dc[c]--;
  }
  if (t.check()) puts("Yes");
  else puts("No");
  return 0;
}