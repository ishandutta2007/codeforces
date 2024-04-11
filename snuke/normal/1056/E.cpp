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

// mod pair for hash
const int p1 = 33487;
struct mints {
  template<int mod>
  struct mint {
    ll x;
    mint(ll x=0):x(x){}
    mint& operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
    mint& operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
    mint& operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
    mint& operator/=(const mint& a){ (x*=a.ex(mod-2).x)%=mod; return *this;}
    mint operator+(const mint& a)const{ return mint(*this) += a;}
    mint operator-(const mint& a)const{ return mint(*this) -= a;}
    mint operator*(const mint& a)const{ return mint(*this) *= a;}
    mint operator/(const mint& a)const{ return mint(*this) /= a;}
    bool operator<(const mint& a)const{ return x < a.x;}
    bool operator==(const mint& a)const{ return x == a.x;}
    mint ex(ll t) const {
      if(!t) return 1;
      mint res = ex(t/2);
      res *= res;
      return (t&1)?res*x:res;
    }
  };
  mint<1011235817> x;
  mint<987654347> y;
  mints(ll x=0):x(x),y(x){}
  mints& operator+=(const mints& a){ x+=a.x; y+=a.y; return *this;}
  mints& operator-=(const mints& a){ x-=a.x; y-=a.y;  return *this;}
  mints& operator*=(const mints& a){ x*=a.x; y*=a.y;  return *this;}
  mints& operator/=(const mints& a){ x/=a.x; y/=a.y;  return *this;}
  mints operator+(const mints& a)const{ return mints(*this) += a;}
  mints operator-(const mints& a)const{ return mints(*this) -= a;}
  mints operator*(const mints& a)const{ return mints(*this) *= a;}
  mints operator/(const mints& a)const{ return mints(*this) /= a;}
  bool operator<(const mints& a)const{ return (x==a.x)?(y<a.y):(x<a.x);}
  bool operator==(const mints& a)const{ return x==a.x && y==a.y;}
};
ostream& operator<<(ostream&o,const mints&a){o<<a.x.x*int(1e9)+a.y.x;return o;}
typedef vector<mints> vm;
//


int main() {
  string s, t;
  cin>>s>>t;
  int n = sz(s);
  int m = sz(t);
  vi c(2);
  vi a(n);
  rep(i,n) a[i] = s[i]-'0';
  rep(i,n) c[a[i]]++;
  if (c[0] < c[1]) {
    reverse(rng(c));
    rep(i,n) a[i] ^= 1;
  }
  int mx = (m-c[1])/c[0];

  vm d(m+1);
  d[0] = 1;
  rep(i,m) d[i+1] = d[i]*p1+t[i];
  vm x(m+1);
  x[0] = 1;
  rep(i,m) x[i+1] = x[i]*p1;

  auto get = [&](int i, int w) {
    return d[i+w] - d[i]*x[w];
  };

  int ans = 0;
  rrep(l,mx) {
    int r = m-l*c[0];
    if (r%c[1]) continue;
    r /= c[1];
    vi w = {l,r};
    vi e(2,-1);
    int p = 0;
    bool ok = true;
    rep(i,n) {
      if (e[a[i]] == -1) {
        e[a[i]] = p;
      } else {
        if (get(e[a[i]],w[a[i]]) == get(p,w[a[i]])); else {
          ok = false;
          break;
        }
      }
      p += w[a[i]];
    }
    if (ok && l == r && get(e[0],w[0]) == get(e[1],w[1])) ok = false;
    if (ok) ans++;
  }
  cout<<ans<<endl;
  return 0;
}