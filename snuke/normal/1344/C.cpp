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
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;
inline int getInt() { int x; scanf("%d",&x); return x;}
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
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;

// SCC
// upstream is smaller id
struct scc {
  int n, k;
  vvi to, ot, d, gt; // to, rev_to, groups, group_to
  vi g, used, kv; // group, gomi, topo_ord
  scc(int n=0):n(n),to(n),ot(n){}
  int inc() { to.pb(vi()); ot.pb(vi()); return n++;}
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
    used = kv = vi(n);
    g = vi(n,-1);
    rep(i,n) dfs(i);
    rep(i,n) if (g[kv[i]] == -1)  {
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
    string ans(n, 'E');
    int cnt = 0;
    vi l(n), r(n);
    rep(i,n) l[i] = r[i] = i;
    for (int v : kv) {
      for (int u : to[v]) {
        mins(l[u],l[v]);
      }
    }
    reverse(rng(kv));
    for (int v : kv) {
      for (int u : ot[v]) {
        mins(r[u],r[v]);
      }
    }
    rep(i,n) {
      if (l[i] == i && r[i] == i) {
        ans[i] = 'A';
        ++cnt;
      }
    }
    cout<<cnt<<endl;
    cout<<ans<<endl;
  }
};
//


int main() {
  int n,m;
  scanf("%d%d",&n,&m);
  scc g(n);
  rep(i,m) {
    int a,b;
    scanf("%d%d",&a,&b);
    --a; --b;
    g.add(a,b);
  }
  g.init();
  if (g.k != n) dame;
  g.solve();
  return 0;
}