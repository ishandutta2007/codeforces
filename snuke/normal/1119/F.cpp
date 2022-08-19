#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
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
const int MX = 250005;

struct DivideSet {
  typedef ll TT;
  multiset<TT> ls, rs;
  int k;
  ll l, r;
  DivideSet():k(0),l(0),r(0) {}
  void ladd(TT x) { ls.insert(x); l += x;}
  void radd(TT x) { rs.insert(x); r += x;}
  void ldel(TT x) { ls.erase(ls.find(x)); l -= x;}
  void rdel(TT x) { rs.erase(rs.find(x)); r -= x;}
  void fix() {
    if (sz(ls) && sz(rs)) {
      while (1) {
        auto lt = ls.end(); --lt;
        auto rt = rs.begin();
        TT ltx = *lt, rtx = *rt;
        if (ltx <= rtx) break;
        ls.erase(lt); l -= ltx; ladd(rtx);
        rs.erase(rt); r -= rtx; radd(ltx);
      }
    }
    while (sz(rs)) {
      auto it = rs.begin();
      if (*it > 0 && sz(ls) >= k) break;
      ladd(*it);
      r -= *it; rs.erase(it);
    }
    while (sz(ls) > k) {
      auto it = ls.end(); --it;
      if (*it <= 0) break; 
      radd(*it);
      l -= *it; ls.erase(it);
    }
  }

  TT lx() { return sz(ls) ? *(ls.rbegin()) : -LINF;} // INF
  TT rx() { return sz(rs) ? *(rs.begin()) : LINF;}   // INF
  int size() { return sz(ls)+sz(rs);}
  int lsz() { return sz(ls);}
  int rsz() { return sz(rs);}
  void add(TT x) {
    radd(x);
    fix();
  }
  void del(TT x) {
    if (lx() < x) rdel(x);
    else ldel(x);
    fix();
  }
  void inc() {
    ++k;
    fix();
  }
  void dec() {
    --k;
    fix();
  }
};


DivideSet ds[MX];
vi to[MX], co[MX];
int pa[MX], pc[MX];
ll val[MX];
void pfs(int v, int p=-1) {
  pa[v] = p;
  rep(i,sz(to[v])) {
    int u = to[v][i], c = co[v][i];
    if (u == p) continue;
    pfs(u,v);
    val[u] = pc[u] = c;
    ds[v].add(c);
  }
}
int deg[MX], act[MX];

vl dp[MX];
ll now;
void dfs(int v) {
  rep(i,sz(to[v])) {
    int u = to[v][i], c = co[v][i];
    ds[v].del(val[u]);
    dfs(u);
    val[u] = (dp[u][1]+c) - dp[u][0];
    ds[v].add(val[u]);
  }
  dp[v] = vl(2,ds[v].l);
  dp[v][1] -= max(ds[v].lx(),0ll);
  now += dp[v][0];
  // cerr<<v<<" "<<dp[v]<<endl;
}

int main() {
  int n;
  scanf("%d",&n);
  ll tot = 0;
  rep(i,n-1) {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    --a; --b;
    to[a].pb(b); co[a].pb(c);
    to[b].pb(a); co[b].pb(c);
    tot += c;
  }
  pfs(0);
  vvi dvs(n);
  rep(v,n) {
    deg[v] = sz(to[v]);
    dvs[deg[v]].pb(v);
    to[v] = co[v] = vi();
  }
  vl ans(n,tot);
  vi vs;
  drep(i,n) if (i) {
    for (int v : vs) ds[v].inc();
    for (int v : dvs[i]) {
      vs.pb(v);
      act[v] = 1;
      if (pa[v] != -1) {
        to[pa[v]].pb(v);
        co[pa[v]].pb(pc[v]);
      }
    }
    now = 0;
    for (int v : vs) {
      if (pa[v] != -1 && act[pa[v]]) continue;
      dfs(v);
      if (pa[v] != -1) {
        now += min(0ll, (dp[v][1]+pc[v])-dp[v][0]);
      }
    }
    ans[i] = now;
  }
  cout<<ans<<endl;
  return 0;
}