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
// const int mod = 1000000007;
int mod;
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
//



int main() {
  int s,t;
  scanf("%d%d%d",&s,&t,&mod);
  if (s == t) {
    cout<<0<<endl;
    return 0;
  }
  map<int,int> d;
  vi qs(1,s), qt(1,t);
  d[s] = 0;
  d[t] = 1;

  auto output = [&](int x, int y, int ns) {
    // cerr<<x<<" "<<y<<" "<<ns<<endl;
    // for (auto p : d) cout<<p<<endl;
    if (ns&1) swap(x,y);
    vi ans;
    if (~ns&1) ans.pb(ns/2);
    while (1) {
      int w = d[x]/2;
      if (w == 0) break;
      ans.pb(w);
      if (w == 1) x = (x+mod-1)%mod;
      if (w == 2) x = (x+1)%mod;
      if (w == 3) x = ex(x,mod-2).x;
    }
    reverse(rng(ans));
    if (ns&1) {
      ans.pb(ns/2);
      if (ans.back() != 3) ans.back() ^= 3;
    }
    x = y;
    while (1) {
      int w = d[x]/2;
      if (w == 0) break;
      if (w != 3) w ^= 3; 
      ans.pb(w);
      if (w == 1) x = (x+1)%mod;
      if (w == 2) x = (x+mod-1)%mod;
      if (w == 3) x = ex(x,mod-2).x;
    }
    cout<<sz(ans)<<endl;
    cout<<ans<<endl;
  };

  int ti = 0;
  while (1) {
    vi q;
    swap(qs,q);
    rep(i,sz(q)) {
      int x = q[i];
      {
        int nx = (x+1)%mod;
        int ns = 2+ti;
        if (!d.count(nx)) {
          d[nx] = ns;
          qs.pb(nx);
        } else if ((d[nx]&1) != ti) {
          output(x,nx,ns);
          return 0;
        }
      }
      {
        int nx = (x+mod-1)%mod;
        int ns = 4+ti;
        if (!d.count(nx)) {
          d[nx] = ns;
          qs.pb(nx);
        } else if ((d[nx]&1) != ti) {
          output(x,nx,ns);
          return 0;
        }
      }
      {
        int nx = ex(x,mod-2).x;
        int ns = 6+ti;
        if (!d.count(nx)) {
          d[nx] = ns;
          qs.pb(nx);
        } else if ((d[nx]&1) != ti) {
          output(x,nx,ns);
          return 0;
        }
      }
    }
    swap(qs,qt);
    ti ^= 1;
  }
  return 0;
}