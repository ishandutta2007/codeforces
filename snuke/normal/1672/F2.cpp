#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < (t); ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define newline puts("")
using namespace std;
template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
template<typename T> using PQ = priority_queue<T,vc<T>,greater<T>>;
using uint = unsigned; using ull = unsigned long long;
using vi = vc<int>; using vvi = vv<int>; using vvvi = vv<vi>;
using ll = long long; using vl = vc<ll>; using vvl = vv<ll>; using vvvl = vv<vl>;
using P = pair<int,int>; using vp = vc<P>; using vvp = vv<P>;
int getInt(){int x;scanf("%d",&x);return x;}
vi pm(int n, int s=0) { vi a(n); iota(rng(a),s); return a;}
template<typename T>istream& operator>>(istream&i,vc<T>&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const T&v,const string& d=""){stringstream s;rep(i,sz(v))(i?s<<d:s)<<v[i];return s.str();}
template<typename T>ostream& operator<<(ostream&o,const vc<T>&v){if(sz(v))o<<join(v," ");return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.fi<<","<<v.se;}
template<typename T1,typename T2>bool mins(T1& x,const T2&y){if(x>y){x=y;return true;}else return false;}
template<typename T1,typename T2>bool maxs(T1& x,const T2&y){if(x<y){x=y;return true;}else return false;}
template<typename Tx, typename Ty>Tx dup(Tx x, Ty y){return (x+y-1)/y;}
template<typename T>ll suma(const vc<T>&a){ll res(0);for(auto&&x:a)res+=x;return res;}
template<typename T>ll suma(const vv<T>&a){ll res(0);for(auto&&x:a)res+=suma(x);return res;}
template<typename T>void uni(T& a){sort(rng(a));a.erase(unique(rng(a)),a.end());}
template<typename T>void prepend(vc<T>&a,const T&x){a.insert(a.begin(),x);}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return;}
#define yes { puts("AC"); return;}
#define no { puts("WA"); return;}
#define ret(x) { cout<<(x)<<endl; return;}
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
};
//

struct Solver {
  void solve() {
    int n;
    scanf("%d",&n);
    vi a(n), b(n);
    cin>>a>>b;
    rep(i,n) --a[i];
    rep(i,n) --b[i];
    P best(0,0);
    vi cnt(n);
    rep(i,n) cnt[a[i]]++;
    rep(i,n) maxs(best, P(cnt[i],i));
    int sv = best.se;
    scc g(n);
    rep(i,n) {
      if (a[i] == sv) continue;
      if (b[i] == sv) continue;
      if (a[i] == b[i]) no;
      g.add(a[i],b[i]);
    }
    g.init();
    if (g.k != n) no;
    yes;
  }
};

int main() {
  int ts = 1;
  scanf("%d",&ts);
  rep1(ti,ts) {
    Solver solver;
    solver.solve();
  }
  return 0;
}