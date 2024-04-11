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
#define yes { puts("Yes"); return;}
#define no { puts("No"); return;}
#define ret(x) { cout<<(x)<<endl; return;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 2000005;

// Mod int
const uint mod = 1000000007;
struct mint {
  uint x;
  mint(): x(0) {}
  mint(ll x):x((x%mod+mod)%mod) {}
  mint operator-() const { return mint(0) - *this;}
  mint operator~() const { return mint(1) / *this;}
  mint& operator+=(const mint& a) { if((x+=a.x)>=mod) x-=mod; return *this;}
  mint& operator-=(const mint& a) { if((x+=mod-a.x)>=mod) x-=mod; return *this;}
  mint& operator*=(const mint& a) { x=(ull)x*a.x%mod; return *this;}
  mint& operator/=(const mint& a) { x=(ull)x*a.pow(mod-2).x%mod; return *this;}
  mint operator+(const mint& a) const { return mint(*this) += a;}
  mint operator-(const mint& a) const { return mint(*this) -= a;}
  mint operator*(const mint& a) const { return mint(*this) *= a;}
  mint operator/(const mint& a) const { return mint(*this) /= a;}
  mint pow(ll t) const {
    mint res = 1; for (mint p=x;t;p*=p,t>>=1) if (t&1) res *= p; return res;
  }
  mint ppow(ll t) const { int p=mod-1; return pow((t%p+p)%p);}
  bool operator<(const mint& a) const { return x < a.x;}
  bool operator==(const mint& a) const { return x == a.x;}
  bool operator!=(const mint& a) const { return x != a.x;}
};
mint ex(mint x, ll t) { return x.pow(t);}
istream& operator>>(istream&i,mint&a) {i>>a.x;return i;}
//*
ostream& operator<<(ostream&o,const mint&a) {o<<a.x;return o;}
/*/
ostream& operator<<(ostream&o, const mint&x) {
  int a = x.x, b = 1;
  rep(s,2)rep1(i,1000) {
    int y = ((s?-x:x)*i).x; if (abs(a)+b > y+i) a = s?-y:y, b = i;
  }
  o<<a; if (b != 1) o<<'/'<<b; return o;
}//*/
using vm = vector<mint>;
using vvm = vector<vm>;
struct modinv {
  int n; vm d;
  modinv(): n(2), d({0,1}) {}
  mint operator()(int i) { while (n <= i) d.pb(-d[mod%n]*(mod/n)), ++n; return d[i];}
  mint operator[](int i) const { return d[i];}
} invs;
struct modfact {
  int n; vm d;
  modfact(): n(2), d({1,1}) {}
  mint operator()(int i) { while (n <= i) d.pb(d.back()*n), ++n; return d[i];}
  mint operator[](int i) const { return d[i];}
} facs;
struct modfactinv {
  int n; vm d;
  modfactinv(): n(2), d({1,1}) {}
  mint operator()(int i) { while (n <= i) d.pb(d.back()*invs(n)), ++n; return d[i];}
  mint operator[](int i) const { return d[i];}
} ifacs;
mint comb(int a, int b) {
  if (a < b || b < 0) return 0;
  return facs(a)*ifacs(b)*ifacs(a-b);
}
//


// linear sieve
vi ps, pf;
void sieve(int mx) {
  pf = vi(mx+1);
  rep(i,mx+1) pf[i] = i;
  for (int i = 2; i <= mx; ++i) {
    if (pf[i] == i) ps.pb(i);
    for (int j = 0; j < sz(ps) && ps[j] <= pf[i]; ++j) {
      int x = ps[j]*i;
      if (x > mx) break;
      pf[x] = ps[j];
    }
  }
}
inline bool isp(int x) { return pf[x] == x && x >= 2;}
vp factor(int x) { // asc
  if (x == 1) return {};
  if (x < sz(pf)) {
    vp res(1, P(pf[x], 0));
    while (x != 1) {
      if (res.back().fi == pf[x]) res.back().se++;
      else res.pb(P(pf[x],1));
      x /= pf[x];
    }
    return res;
  }
  vp res;
  for (int p : ps) {
    if (p*p > x) break;
    if (x%p) continue;
    res.eb(p,0);
    while (x%p == 0) x /= p, res.back().se++;
  }
  if (x != 1) res.eb(x,1);
  return res;
}
vi divs(int x) { // asc
  vi res(1,1);
  for (auto p : factor(x)) {
    drep(i,sz(res)) {
      int a = res[i];
      rep(j,p.se) a *= p.fi, res.pb(a);
    }
  }
  sort(rng(res));
  return res;
}
//

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
  void test() {
    int n = getInt();
    map<int,int> mp;
    rep(a,n)rep(b,n) {
      scc g(n);
      rep(i,n) {
        g.add(i,(i*a+b)%n);
      }
      g.init();
      vi s(n), l(n);
      drep(i,g.k) {
        if (sz(g.d[i]) != 1) s[i] = sz(g.d[i]);
        else {
          for (int j : g.gt[i]) {
            s[i] = s[j];
            l[i] = l[j]+1;
          }
        }
        maxs(mp[s[i]],l[i]);
      }
    }
    for (auto p : mp) cout<<p<<endl;
  }
  void solve() {
    // test(); no;

    sieve(MX);
    int n;
    scanf("%d",&n);
    map<int,int> mp;
    rep(i,n) {
      int p;
      cin>>p;
      mp[-p]++;
    }

    map<int,int> mx;

    int leg = 0;
    mint ans = 1;
    vvp ds;
    for (auto [_p,c] : mp) {
      int p = -_p;
      if (!mx.count(p)) {
        maxs(mx[p],1);
        ds.pb(vp(1,P(p,1)));
        c--;
      }
      if (c > 0) {
        if (c > 1) leg = 1;
        auto d = factor(p-1);
        for (auto q : d) maxs(mx[q.fi], q.se);
        ds.pb(d);
      }
    }
    for (auto p : mx) {
      rep(i,p.se) ans *= p.fi;
    }
    map<int,int> cnt;
    for (vp& d : ds) {
      for (auto p : d) {
        if (mx[p.fi] != p.se) continue;
        cnt[p.fi]++;
      }
    }

    for (vp& d : ds) {
      bool can = true;
      for (auto p : d) {
        if (mx[p.fi] != p.se) continue;
        if (cnt[p.fi] == 1) can = false;
      }
      if (can) leg = 1;
    }

    ans += leg;
    cout<<ans<<endl;
  }
};

int main() {
  int ts = 1;
  // scanf("%d",&ts);
  rep1(ti,ts) {
    Solver solver;
    solver.solve();
  }
  return 0;
}