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
using vi = vc<int>; using vvi = vv<int>; using vvvi = vv<vi>;
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
  bool same(int x, int y) { return root(x) == root(y);}
  int size(int x) { return -d[root(x)];}
  int operator[](int x) { return root(x);}
  int operator()(int x) { return size(x);}
};
//

struct edge {
  int a, b, id;
  edge(int a=-1, int b=-1, int id=0): a(a), b(b), id(id) {}
};
struct E {
  int to, id;
  E(int to=-1, int id=0): to(to), id(id) {}
  operator int() const { return to;}
};
using G = vv<E>;

struct Solver {
  void solve() {
    int n,m;
    scanf("%d%d",&n,&m);
    vv<edge> es(2);
    rep(i,m) {
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      --a; --b;
      es[c-1].eb(a,b,i);
    }
    vvi pa(2,vi(n,-1));
    vvvi pas(2,vvi(n));
    rep(c,2) {
      G g(n);
      uf t(n);
      vi deg(n);
      for (auto [a,b,id] : es[c]) {
        deg[a] ^= 1;
        deg[b] ^= 1;
        if (t.unite(a,b)) {
          g[a].eb(b,id);
          g[b].eb(a,m+id);
        }
      }
      auto dfs = [&](auto& dfs, int v, int p=-1) -> int {
        int res = -1;
        if (deg[v] == 1) res = v;
        for (auto [to,id] : g[v]) {
          if (to == p) continue;
          int r = dfs(dfs, to,v);
          if (r != -1) {
            pas[c][r].pb(id);
            if (res != -1) {
              reverse(rng(pas[c][r]));
              rep(i,sz(pas[c][r])) (pas[c][r][i] += m) %= m*2;
              pas[c][res].insert(pas[c][res].end(), rng(pas[c][r]));
              pas[c][r] = vi();
              pa[c][res] = r; pa[c][r] = res;

              res = -1;
            } else res = r;
          }
        }
        return res;
      };
      rep(i,n) if (t[i] == i) dfs(dfs,i);
    }

    vi ans(m,-1);
    auto con = [&](int c, int a, int b, int dir) {
      vi w = pas[c][a];
      if (w == vi()) {
        w = pas[c][b];
        rep(i,sz(w)) (w[i] += m) %= m*2;
      }
      for (int i : w) ans[i%m] = i/m ^ dir;
    };
    
    int num = 0;
    rep(i,n) if (pa[0][i] != -1) num++;
    rep(si,n) {
      rep(c,2) {
        if (pa[c][si] == -1) continue;
        int sa = pa[c][si], sb = si;
        rep(ri,2) {
          int a = sa, b = sb;
          if (ri) swap(a,b);
          int nc = c;
          while (1) {
            if (pa[nc][a] != -1) con(nc,a,b,ri);
            pa[nc][a] = pa[nc][b] = -1;
            a = b;
            nc ^= 1;
            b = pa[nc][a];
            if (b == -1) break;
          }
        }
      }
    }

    {
      rep(c,2) {
        G g(n);
        for (auto [a,b,id] : es[c]) {
          if (ans[id%m] != -1) continue;
          g[a].eb(b,id);
          g[b].eb(a,m+id);
        }
        vi gi(n);
        auto dfs = [&](auto& dfs, int v) -> void {
          while (gi[v] < sz(g[v])) {
            auto [to,id] = g[v][gi[v]];
            gi[v]++;
            if (ans[id%m] != -1) continue;
            ans[id%m] = id/m;
            dfs(dfs, to);
          }
        };
        rep(si,n) dfs(dfs, si);
      }
    }

    string anss(m,'0');
    rep(i,m) anss[i] = '1'+ans[i];
    cout<<num<<endl;
    cout<<anss<<endl;
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