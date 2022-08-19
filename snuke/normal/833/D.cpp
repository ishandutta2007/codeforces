#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define df(x) int x = in()
#define dame { puts("-1"); return 0;}
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,vector<T>,greater<T> >
#define bn(x) ((1<<x)-1)
#define newline puts("")
#define v(T) vector<T>
#define vv(T) vector<vector<T>>
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
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}
template<typename T>istream& operator>>(istream&i,vector<T>&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const vector<T>&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const vector<T>&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;


// coordinate compression
struct X {
  typedef int T;
  vector<T> d;
  void add(T x) { d.pb(x);}
  void init() {
    sort(rng(d));
    d.erase(unique(rng(d)), d.end());
  }
  int size() const { return sz(d);}
  T operator[](int i) const { return d[i];}
  int operator()(T x) const { return upper_bound(rng(d),x)-d.begin()-1;}
};
//

// Mod int
const int mod = 1000000007;
struct mint {
  ll x;
  mint():x(0){}
  mint(ll x):x((x%mod+mod)%mod){}
  // mint(ll x):x(x){}
  mint& fix() { x = (x%mod+mod)%mod; return *this;}
  mint& operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
  mint& operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
  mint& operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
  mint& operator/=(const mint& a){ (x*=a.ex(mod-2).x)%=mod; return *this;}
  mint operator+(const mint& a)const{ return mint(*this) += a;}
  mint operator-(const mint& a)const{ return mint(*this) -= a;}
  mint operator*(const mint& a)const{ return mint(*this) *= a;}
  mint operator/(const mint& a)const{ return mint(*this) /= a;}
  mint ex(ll t) const {
    if(!t) return 1;
    mint res = ex(t/2);
    res *= res;
    return (t&1)?res*x:res;
  }
  bool operator<(const mint& a)const{ return x < a.x;}
  bool operator==(const mint& a)const{ return x == a.x;}
};
mint ex(mint x, ll t) { return x.ex(t);}
istream& operator>>(istream&i,mint&a){i>>a.x;return i;}
ostream& operator<<(ostream&o,const mint&a){o<<a.x;return o;}
typedef vector<mint> vm;
struct comb {
  vm f, g;
  comb(){}
  comb(int mx):f(mx+1),g(mx+1) {
    f[0] = 1;
    rrep(i,mx) f[i] = f[i-1]*i;
    g[mx] = f[mx].ex(mod-2);
    for(int i=mx;i>0;i--) g[i-1] = g[i]*i;
  }
  mint c(int a, int b) {
    if (a < b) return 0;
    return f[a]*g[b]*g[a-b];
  }
};
typedef pair<int,mint> MP;
//

// Binary Indexed Tree
struct bit {
  typedef mint TT;
  int n; vector<TT> d;
  bit() {}
  bit(int mx): n(mx), d(mx,mint(1)) {}
  void add(int i, TT x=1) {
    for (++i;i<n;i+=i&-i) d[i] *= x;
  }
  TT sum(int i) {
    TT x = 1;
    for (++i;i;i-=i&-i) x *= d[i];
    return x;
  }
};
//

int n;
vvi to, x, co;
int cd[2];



mint ans;
vi used, t;
int tfs(int v, int p=-1) {
  int res = 1;
  rep(i,sz(to[v])) {
    int u = to[v][i];
    if (u == p || used[u]) continue;
    res += tfs(u,v);
  }
  return t[v] = res;
}
P cfs(int v, int tot, int p=-1) {
  P res(INF,v);
  int mx = tot-t[v];
  rep(i,sz(to[v])) {
    int u = to[v][i];
    if (u == p || used[u]) continue;
    mins(res,cfs(u,tot,v));
    maxs(mx,t[u]);
  }
  return min(res,P(mx,v));
}
v(MP) nd;
void efs(int v, int sum, mint sx, int p) {
  nd.pb(MP(sum,sx));
  rep(i,sz(to[v])) {
    int u = to[v][i];
    if (u == p || used[u]) continue;
    efs(u,sum+cd[co[v][i]],sx*x[v][i],v);
  }
}
void dfs(int v) {
  int tot = tfs(v);
  v = cfs(v,tot).se;
  used[v] = 1;
  vv(MP) d(1,v(MP)(1,MP(0,1)));
  rep(i,sz(to[v])) {
    int u = to[v][i];
    if (used[u]) continue;
    nd = v(MP)();
    efs(u,cd[co[v][i]],x[v][i],v);
    d.pb(nd);
  }
  X xs;
  rep(i,sz(d))rep(j,sz(d[i])) {
    // cerr<<v<<" : "<<d[i][j]<<endl;
    xs.add(d[i][j].fi);
    xs.add(-1-d[i][j].fi);
  }
  xs.init();
  rep(ti,2) {
    bit s(sz(xs)+2);
    rep(i,sz(d)) {
      rep(j,sz(d[i])) {
        ans *= s.sum(xs(-1-d[i][j].fi));
      }
      rep(j,sz(d[i])) {
        s.add(xs(d[i][j].fi),d[i][j].se);
      }
    }
    reverse(rng(d));
  }
  for (int u : to[v]) if (!used[u]) dfs(u);
}
mint solve() {
  ans = 1;
  used = t = vi(n);
  dfs(0);
  return ans;
}

int main() {
  scanf("%d",&n);
  to = x = co = vvi(n);
  rep(i,n-1) {
    int a,b,d,c;
    scanf("%d%d%d%d",&a,&b,&d,&c);
    --a; --b;
    to[a].pb(b); x[a].pb(d); co[a].pb(c);
    to[b].pb(a); x[b].pb(d); co[b].pb(c);
  }

  cd[0] = -1; cd[1] = -1;
  mint ans = solve();
  // cerr<<ans<<endl;
  cd[0] = 2; cd[1] = -1;
  rep(ti,2) {
    ans /= solve();
    // cerr<<ans<<endl;
    swap(cd[0],cd[1]);
  }
  cout<<ans<<endl;
  return 0;
}