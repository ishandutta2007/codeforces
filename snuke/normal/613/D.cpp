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
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

// HL-decomposition
struct hl {
  int n, oi;
  vector<vi> to, d;
  vi vd, vk, pv, dep, od;
  // vector<bit> t; // bit
  int root;
  hl() {}
  hl(int mx):n(mx),to(mx),vd(mx),vk(mx),dep(mx),od(mx),oi(0) {}
  void add(int a, int b) {
    to[a].pb(b);
    to[b].pb(a);
  }
  int dfs(int v, int de=0, int p=-1) {
    od[v] = oi++;
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
    // rep(i,sz(d)) t.pb(bit(sz(d[i])+1)); // bit
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
  // int sum(int p, int v) { // bit
  //   int res = 0;
  //   while (1) {
  //     int nd = vd[v], nk = vk[v];
  //     res += t[nd].sum(nk);
  //     if (nd == vd[p]) return res - t[nd].sum(vk[p]);
  //     v = pv[nd];
  //   }
  // }
  int solve(vi& a) {
    sort(rng(a), [&](int i, int j) { return od[i] < od[j];});
    vi p = a;
    int m = sz(a);
    rep(i,m-1) {
      int c = lca(a[i],a[i+1]);
      if (c != a[i]) a.pb(c);
    }
    sort(rng(a), [&](int i, int j) { return od[i] < od[j];});
    a.erase(unique(rng(a)), a.end());
    m = sz(a);
    vvi g(m);
    // vvi co(m);
    vi s(1,0);
    rep(i,m-1) {
      int c = lca(a[i],a[i+1]);
      if (a[i] == c) s.pb(i);
      else {
        while (a[s.back()] != c) s.pop_back();
      }
      int pa = s.back();
      g[pa].pb(i+1);
      // cout<<a[pa]<<" "<<a[i+1]<<endl;
      // co[pa].pb(dep[a[i+1]]-dep[a[pa]]);
    }
    vi b(m);
    int pi = 0;
    rep(i,m) {
      if (pi < sz(p) && a[i] == p[pi]) b[i] = 1, pi++;
    }
    int res = 0;
    vi dp(m,0);
    drep(i,m) {
      int cnt = 0;
      bool ok = false;
      for (int u : g[i]) {
        // cout<<dp[u]<<endl;
        if (dp[u] == 1) {
          int len = dep[a[u]]-dep[a[i]];
          if (b[i]) {
            if (len == 1) return -1;
            res++;
          } else {
            cnt++;
            if (len > 1) ok = true;
          }
        } else if (dp[u] == 2) {
          if (b[i]) {
            res++;
          } else {
            cnt++;
            ok = true;
          }
        }
      }
      if (b[i]) dp[i] = 1;
      else if (cnt == 1) {
        dp[i] = 2;
        // else dp[i] = 1;
      } else if (cnt >= 2) {
        res++;
        // dp[i] = 0;
      }
    }
    // priv(a);
    // priv(b);
    // priv(dp);
    return res;
  }
};
//

int main() {
  int n, q;
  scanf("%d",&n);
  hl g(n);
  rep(i,n-1) {
    int a, b;
    scanf("%d%d",&a,&b);
    --a; --b;
    g.add(a,b);
  }
  g.init();
  scanf("%d",&q);
  rep(qi,q) {
    int m;
    scanf("%d",&m);
    vi a(m);
    rep(i,m) scanf("%d",&a[i]);
    rep(i,m) a[i]--;
    int ans = g.solve(a);
    printf("%d\n", ans);
  }
  return 0;
}