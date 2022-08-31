#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
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
const int MX = 200005;

// Mod int
const int mod = 1000000007;
struct mint {
  ll x;
  mint():x(0){}
  mint(ll x):x((x%mod+mod)%mod){}
  // mint(ll x):x(x){}
  mint& fix() { x = (x%mod+mod)%mod; return *this;}
  mint operator-() const { return mint(0) - *this;}
  mint operator~() const { return mint(1) / *this;}
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
} c(MX);
//

// Matrix
struct mat {
  typedef mint TT;
  int h, w;
  vv(TT) d;
  mat(){}
  mat(int h, int w, TT v=0):h(h),w(w),d(h,vector<TT>(w,v)){}
  v(TT)& operator[] (int i) { return d[i];}
  const v(TT)& operator[] (int i) const { return d[i];}
  void fil(TT v=0){ rep(i,h)rep(j,w) d[i][j] = v;}
  void unit(){ rep(i,h)rep(j,w) d[i][j] = (i==j);}
  mat operator*(const mat& a)const{ // w = a.h
    mat res(h,a.w);
    rep(i,h)rep(k,w)rep(j,a.w) res[i][j] += d[i][k]*a[k][j];
    return res;
  }
  mat inv() { // mint (side effect: gauss & destroy)
    mat res(h,w); res.unit();
    rep(i,w) {
      if (!d[i][i].x) {
        for (int j = i+1; j < h; ++j) {
          if (d[j][i].x) {
            swap(d[i],d[j]);
            swap(res[i],res[j]);
            break;
          }
        }
        assert(d[i][i].x);
      }
      mint x = ~d[i][i];
      rep(j,w) d[i][j] *= x;
      rep(j,w) res[i][j] *= x;
      rep(k,h) {
        if (i == k || !d[k][i].x) continue;
        mint x = d[k][i];
        for (int j = i; j < w; ++j) d[k][j] -= d[i][j]*x;
        rep(j,w) res[k][j] -= res[i][j]*x;
      }
    }
    return res;
  }
  void pri() {
    rep(i,h) {
      cout << "|";
      rep(j,w) cout << " " << d[i][j];
      cout << " |" << endl;
    }
    cout<<endl;
  }
};
//


int m;

const int K = 201;
vi to[MX];
vm co[K];
mint co2[K+1];
mint exs[K][K];

inline void fold(vm& a) {
  while (sz(a) > K) {
    mint x = a.back();
    a.pop_back();
    int j = sz(a)-K;
    rep(i,K) a[i] += co[j][i]*x;
  }
}
inline vm add(vm& a, vm& b) {
  vm res(sz(a)+sz(b)-1);
  rep(i,sz(a))rep(j,sz(b)) res[i+j] += a[i]*b[j];
  fold(res);
  return res;
}

mint ans;
vm dfs(int v, int p=-1) {
  vm dp(1,1);
  for (int u : to[v]) {
    if (u == p) continue;
    vm e = dfs(u,v);
    e.insert(e.begin(),1);
    rep(i,sz(e)) ans -= e[i]*co2[i];
    dp = add(dp,e);
  }
  rep(i,sz(dp)) dp[i] *= 2;
  dp[0] -= 1;
  rep(i,sz(dp)) ans += dp[i]*co2[i];
  return dp;
}

int main() {
  int n;
  scanf("%d",&n);
  scanf("%d",&m);
  rep(i,n-1) {
    int a,b;
    scanf("%d%d",&a,&b);
    --a; --b;
    to[a].pb(b);
    to[b].pb(a);
  }
  
  rep(i,K)rep(j,K) exs[i][j] = ex(i,j);
  mat a(K,K);
  rep(i,K)rep(j,K) a[i][j] = exs[i][j]*c.g[j];
  mat ia = mat(a).inv();

  rep(i,K+1) co2[i] = ex(i,m)*c.g[m];

  rep(i,K) {
    mat x(1,K);
    rep(j,K) x[0][j] = ex(K+i,j)*c.g[j];
    x = x*ia;
    co[i] = x[0];
  }

  dfs(0);
  ans *= c.f[m];
  cout<<ans<<endl;
  return 0;
}