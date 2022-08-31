#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < (t); ++i)
#define dsrep(i,t,s) for(int i = (t)-1; i >= (s); --i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cerr<<#x<<" = "<<x<<endl;
#define bn(x) ((1<<(x))-1)
#define newline puts("")
using namespace std;
template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
template<typename T> using PQ = priority_queue<T,vc<T>,greater<T> >;
using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
using P = pair<int,int>;
using T3 = tuple<int,int,int>;
using vi = vc<int>;
using vvi = vv<int>;
using vl = vc<ll>;
using vp = vc<P>;
using vt = vc<T3>;
int getInt(){int x;scanf("%d",&x);return x;}
vi pm(int n, int s=0) { vi a(n); iota(rng(a),s); return a;}
template<typename T>istream& operator>>(istream&i,vc<T>&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const T&v,const string& d=""){stringstream s;rep(i,sz(v))(i?s<<d:s)<<v[i];return s.str();}
template<typename T>ostream& operator<<(ostream&o,const vc<T>&v){if(sz(v))o<<join(v," ");return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.fi<<","<<v.se;}
vc<string> split(const string& s,char d=' '){vc<string> r(1);for(char c:s)if(c==d)r.pb("");else r.back()+=c;return r;}
string operator*(const string& s,int t){return join(vc<string>(t,s));}
template<typename T1,typename T2>bool mins(T1& x,const T2&y){if(x>y){x=y;return true;}else return false;}
template<typename T1,typename T2>bool maxs(T1& x,const T2&y){if(x<y){x=y;return true;}else return false;}
template<typename Tx, typename Ty>Tx dup(Tx x, Ty y){return (x+y-1)/y;}
template<typename T>ll suma(const vc<T>&a){ll res(0);for(auto&&x:a)res+=x;return res;}
template<typename T>void uni(T& a){sort(rng(a));a.erase(unique(rng(a)),a.end());}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;
using Q = pair<int,P>;
using vq = vector<Q>;

struct Solver {
  void solve() {
    int n,m;
    scanf("%d%d",&n,&m);
    map<P,int> es;
    set<Q> s;
    vc<set<Q>> ss(n);
    auto top3 = [&](int v, const Q& d) {
      int cnt = 0;
      for (auto&& nd : ss[v]) {
        if (d == nd) return true;
        ++cnt;
        if (cnt >= 3) break;
      }
      return false;
    };
    auto adds = [&](int v, bool four=false) {
      int cnt = 0;
      for (auto&& d : ss[v]) {
        ++cnt;
        if (four && cnt == 4) {
          s.erase(d);
        } else {
          int u = d.se.fi^d.se.se^v;
          if (top3(u,d)) s.insert(d);
        }
        if (cnt >= (four?4:3)) break;
      }
    };
    auto dels = [&](int v) {
      int cnt = 0;
      for (auto&& d : ss[v]) {
        s.erase(d);
        ++cnt;
        if (cnt >= 3) break;
      }
    };
    auto ad = [&](int v, const Q& d) {
      dels(v);
      ss[v].insert(d);
      adds(v, true);
    };
    auto dl = [&](int v, const Q& d) {
      dels(v);
      ss[v].erase(d);
      adds(v);
    };
    auto add = [&](int a, int b, int c) {
      --a; --b;
      if (a > b) swap(a,b);
      es[P(a,b)] = c;
      Q d(c,P(a,b));
      ad(a, d);
      ad(b, d);
    };
    auto del = [&](int a, int b) {
      --a; --b;
      if (a > b) swap(a,b);
      auto it = es.find(P(a,b));
      int c = it->se;
      es.erase(it);
      Q d(c,P(a,b));
      s.erase(d);
      dl(a, d);
      dl(b, d);
    };
    rep(i,m) {
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      add(a,b,c);
    }
    auto answer = [&] {
      int cnt = 0;
      vq ds;
      for (auto&& d : s) {
        ds.pb(d);
        ++cnt;
        if (cnt == 6) break;
      }
      // assert(sz(ds) >= 4);
      ll ans = LINF;
      rep(i,sz(ds))rep(j,i) {
        auto [a,b] = ds[i].se;
        auto [x,y] = ds[j].se;
        if (a == x || a == y || b == x || b == y) continue;
        mins(ans, (ll)ds[i].fi+ds[j].fi);
      }
      {
        auto [a,b] = ds[0].se;
        auto [x,y] = ds[1].se;
        if (a == x || a == y || b == x || b == y) {
          if (a == x) a = y;
          else if (a == y) a = x;
          else if (b == x) b = y;
          else b = x;
          if (a > b) swap(a,b);
          srep(i,2,4) {
            auto [u,v] = ds[i].se;
            if (a == u && b == v) continue;
            mins(ans, (ll)ds[0].fi+ds[1].fi+ds[i].fi);
            break;
          }
        }
      }
      printf("%lld\n",ans);
    };
    answer();
    int q;
    scanf("%d",&q);
    rep(qi,q) {
      int type,a,b;
      scanf("%d%d%d",&type,&a,&b);
      if (type == 0) {
        del(a,b);
      } else {
        int c;
        scanf("%d",&c);
        add(a,b,c);
      }
      answer();
    }
  }
};

int main() {
  int ts = 1;
  rrep(ti,ts) {
    Solver solver;
    solver.solve();
  }
  return 0;
}