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
template<typename T>string join(const vc<T>&v,const string& d=""){stringstream s;rep(i,sz(v))(i?s<<d:s)<<v[i];return s.str();}
template<typename T>ostream& operator<<(ostream&o,const vc<T>&v){if(sz(v))o<<join(v," ");return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.fi<<","<<v.se;}
vc<string> split(const string& s,char d=' '){vc<string> r(1);for(char c:s)if(c==d)r.pb("");else r.back()+=c;return r;}
string operator*(const string& s,int t){return join(vc<string>(t,s));}
template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}
template<typename T>bool maxs(T& x,const T&y){if(x<y){x=y;return true;}else return false;}
template<typename T>T dup(T x, T y){return (x+y-1)/y;}
template<typename T>ll suma(const vc<T>&a){ll res(0);for(auto&&x:a)res+=x;return res;}
template<typename T>void uni(vc<T>& a){sort(rng(a));a.erase(unique(rng(a)),a.end());}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 305;

// Mod int
// const int mod = 1000000007;
const int mod = 998244353;
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
    if(!t) return 1;
    mint res = pow(t/2);
    res *= res;
    return (t&1)?res*x:res;
  }
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
  rep(s,2)rrep(i,1000) {
    int y = ((s?-x:x)*i).x;
    if (abs(a)+b > y+i) a = s?-y:y, b = i;
  }
  o<<a; if (b != 1) o<<'/'<<b; return o;
}//*/
using vm = vector<mint>;
using vvm = vector<vm>;
struct comb {
  vm f, g;
  comb() {}
  comb(int mx): f(mx+1), g(mx+1) {
    f[0] = 1;
    rrep(i,mx) f[i] = f[i-1]*i;
    g[mx] = f[mx].pow(mod-2);
    for(int i = mx; i > 0; --i) g[i-1] = g[i]*i;
  }
  mint operator()(int a, int b) {
    if (a < b || b < 0) return 0;
    return f[a]*g[b]*g[a-b];
  }
};
//

vm dp[MX];
vm dn[MX];

struct Solver {
  int n;
  vvi to;
  int R;
  void dfs(int v, int p=-1) {
    int r = 1;
    vm sp(1), sn(1);
    sp[0] = sn[0] = 1;
    rep(ti,sz(to[v])) {
      int u = to[v][ti];
      if (u == p) continue;
      dfs(u,v);
      vm& ep = dp[u];
      vm& en = dn[u];
      maxs(r, sz(ep));
      vm pp(r), pn(r);
      swap(sp,pp);
      swap(sn,pn);
      rep(i,sz(pp))rep(j,sz(ep)) sp[min(i,j)] += pp[i]*ep[j];
      rep(i,sz(pp))rep(j,sz(en)) {
        if (i+j > R) sn[j] += pp[i]*en[j];
        else sp[i] += pp[i]*en[j];
      }
      rep(i,sz(pn))rep(j,sz(ep)) {
        if (i+j > R) sn[i] += pn[i]*ep[j];
        else sp[j] += pn[i]*ep[j];
      }
      rep(i,sz(pn))rep(j,sz(en)) sn[max(i,j)] += pn[i]*en[j];
    }

    sn.insert(sn.begin(),0);
    if (sz(sn) > R+1) sn.pop_back();

    sp.insert(sp.begin(),0);
    if (sz(sp) > R+1) {
      sn[0] = sp.back();
      sp.pop_back();
    }

    dp[v] = sp;
    dn[v] = sn;
    // cerr<<v<<endl;
    // cerr<<sp<<endl;
    // cerr<<sn<<endl;
  }
  mint f(int _r) {
    R = _r;
    dfs(0);
    mint res = dn[0][0];
    rep(i,sz(dp[0])) res += dp[0][i];
    // cerr<<res<<endl;
    return res;
  }
  void solve() {
    cin>>n;
    to = vvi(n);
    rep(i,n-1) {
      int a, b;
      scanf("%d%d",&a,&b);
      --a; --b;
      to[a].pb(b);
      to[b].pb(a);
    }
    mint ans;
    mint tot = ex(2,n);
    rep(i,n) ans += tot-f(i+1);
    ans -= 1;
    ans /= tot;
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