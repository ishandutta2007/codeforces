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
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;
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
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;

// Mod int
const int mod = 998244353;
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
  mint& operator/=(const mint& a){ (x*=a.pow(mod-2).x)%=mod; return *this;}
  mint operator+(const mint& a)const{ return mint(*this) += a;}
  mint operator-(const mint& a)const{ return mint(*this) -= a;}
  mint operator*(const mint& a)const{ return mint(*this) *= a;}
  mint operator/(const mint& a)const{ return mint(*this) /= a;}
  mint pow(ll t) const {
    if(!t) return 1;
    mint res = pow(t/2);
    res *= res;
    return (t&1)?res*x:res;
  }
  bool operator<(const mint& a)const{ return x < a.x;}
  bool operator==(const mint& a)const{ return x == a.x;}
};
mint ex(mint x, ll t) { return x.pow(t);}
istream& operator>>(istream&i,mint&a){i>>a.x;return i;}
ostream& operator<<(ostream&o,const mint&a){o<<a.x;return o;}
typedef vector<mint> vm;
typedef vector<vm> vvm;
struct comb {
  vm f, g;
  comb(){}
  comb(int mx):f(mx+1),g(mx+1) {
    f[0] = 1;
    rrep(i,mx) f[i] = f[i-1]*i;
    g[mx] = f[mx].pow(mod-2);
    for(int i=mx;i>0;i--) g[i-1] = g[i]*i;
  }
  mint c(int a, int b) {
    if (a < b) return 0;
    return f[a]*g[b]*g[a-b];
  }
} c(MX);
//


vvm f(vi d, int m) {
  int n = sz(d);
  vvm dp(n+1);
  dp[0] = vm(1,1);
  int r = n;
  rep(i,n) {
    dp[i+1] = dp[i];
    dp[i+1].pb(0);
    if (!d[i] && i && !d[i-1]) {
      rep(j,sz(dp[i-1])) dp[i+1][j+1] += dp[i-1][j];
    }
    r -= d[i];
  }
  vvm res(m+1,vm(m+1));
  rep(i,min(m+1,sz(dp[n])))rep(j,m+1) {
    res[i][j] = dp[n][i]*c.c(r-i*2,j);
  }
  return res;
}

int main() {
  int h,w,n;
  scanf("%d%d%d",&h,&w,&n);
  int a = 0, b = 0;
  vi da(h), db(w);
  rep(i,n) {
    int ai,aj,bi,bj;
    scanf("%d%d%d%d",&ai,&aj,&bi,&bj);
    --ai; --aj; --bi; --bj;
    da[ai] = da[bi] = 1;
    db[aj] = db[bj] = 1;
    if (ai == bi) ++b; else ++a;
  }
  // cerr<<da<<endl;
  // cerr<<db<<endl;
  int m = min(h-a*2-b, w-a-b*2);
  vvm sa = f(da,m);
  vvm sb = f(db,m);
  // rep(i,m+1) cerr<<sa[i]<<endl;
  // cerr<<"---"<<endl;
  // rep(i,m+1) cerr<<sb[i]<<endl;
  mint ans;
  rep(i,m+1)rep(j,m+1) {
    int na = a+i, nb = b+j;
    if (na*2+nb > h) break;
    if (na+nb*2 > w) break;
    ans += sa[i][j]*sb[j][i]*c.f[i]*c.f[j];
  }
  cout<<ans<<endl;
  return 0;
}