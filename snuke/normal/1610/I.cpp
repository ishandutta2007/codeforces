#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < (t); ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define newline puts("")
using namespace std;
template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
template<typename T> using PQ = priority_queue<T,vc<T>,greater<T>>;
using uint = unsigned; using ull = unsigned long long;
using vi = vc<int>; using vvi = vv<int>;
using ll = long long; using vl = vc<ll>; using vvl = vv<ll>;
using P = pair<int,int>; using vp = vc<P>;
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
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return;}
#define yes { puts("Yes"); return;}
#define no { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;

// template<typename T>
// struct edge {
//   int to; T co;
//   edge(int to=-1, T co=T()): to(to), co(co) {}
//   operator int() const { return to;}
// };
// template<typename T=ll> using Gw = vv<edge<T>>;
// Gw<int> togw(const vvi& to){Gw<int> g(sz(to));rep(i,sz(to))for(int j:to[i])g[i].eb(j);return g;}

// template<typename T=ll>
// Gw<T> ingw(int n, int m=-1, bool bi=true) {
//   if (m == -1) m = n-1;
//   Gw<T> g(n);
//   rep(i,m) {
//     int a, b; T c;
//     cin >> a >> b >> c;
//     --a; --b;
//     g[a].eb(b,c);
//     if (bi) g[b].eb(a,c);
//   }
//   return g;
// }

// template<typename Te, typename Ts>
// struct Rerooting {
//   const Gw<Te>& g;
//   using Fm = function<void(Ts&,Ts)>;
//   using Fa = function<void(Ts&,edge<Te>)>;
//   const Fm merge; const Fa add;
//   vc<Ts> d;
//   Rerooting(const Gw<Te>& g, Fm merge, Fa add): g(g), merge(merge), add(add), d(sz(g)) { dfs(0);  bfs(0);}
//   void dfs(int v, int p=-1) {
//     for (auto&& e : g[v]) if (e != p) {
//       dfs(e,v);
//       add(d[e], e); merge(d[v], d[e]);
//     }
//   }
//   void bfs(int v, Ts ps=Ts(), int p=-1) {
//     int m = sz(g[v]);
//     vc<Ts> ds(m);
//     Ts ns = Ts();
//     drep(i,m) {
//       auto&& e = g[v][i];
//       ds[i] = ns;
//       merge(ns, (e==p)?(add(ps,e),ps):d[e]);
//     }
//     ns = Ts();
//     rep(i,m) {
//       auto&& e = g[v][i];
//       merge(ds[i], ns);
//       merge(ns, (e==p)?ps:d[e]);
//       if (e != p) bfs(e, ds[i], v);
//     }
//     d[v] = ns;
//   }
// };
// /*
// auto fm = [&](ll& a, ll& b) {};
// auto fa = [&](ll& a, const edge<ll>& e) {};
// Rerooting<ll> r(g,fm,fa);
// */

vvi ing(int n, int m=-1, bool bi=true) {
  if (m == -1) m = n-1;
  vvi to(n);
  rep(i,m) {
    int a, b;
    scanf("%d%d",&a,&b);
    --a; --b;
    to[a].pb(b);
    if (bi) to[b].pb(a);
  }
  return to;
}

vvi to;
vi d;
vi pa;
int dfs(int v, int p=-1) {
  pa[v] = p;
  int res = 0;
  for (int u : to[v]) {
    if (u == p) continue;
    int r = dfs(u,v);
    ++r;
    res ^= r;
  }
  d[v] = res;
  return res;
}

struct Solver {
  void solve() {
    int n;
    scanf("%d",&n);
    // auto g = togw(ing(n));
    // auto f = [&](int& x, int y) { x ^= y;};
    // auto f2 = [&](int& x, edge<int> e) { x++;};
    // Rerooting<int,int> r(g, f, f2);
    // string ans;
    // rep(i,n) ans += "12"[r.d[i]==0];
    // cout<<ans<<endl;
    to = ing(n);
    d = pa = vi(n,-1);
    
    dfs(0);
    string ans;
    int now = d[0];
    ans += "12"[now==0];

    vi fix(n);
    fix[0] = 1;

    rep(v,n) if (v) {
      int u = v;
      int pre = -1;
      while (!fix[u]) {
        fix[u] = 1;
        for (int c : to[u]) {
          if (c == pa[u]) continue;
          if (fix[c]) continue;
          now ^= d[c]+1;
        }
        pre = u;
        u = pa[u];
        now ^= 1;
      }
      if (pre != -1) now ^= d[pre]+1;
      // cerr<<now<<endl;
      ans += "12"[now==0];
    }

    cout<<ans<<endl;
  }
};

int main() {
  int ts = 1;
  // scanf("%d",&ts);
  rrep(ti,ts) {
    Solver solver;
    solver.solve();
  }
  return 0;
}