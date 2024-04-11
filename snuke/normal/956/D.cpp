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

// 2D BIT
struct bit2 {
  typedef int TT;
  typedef int TX;
  struct bit {
    int n; vector<TT> d;
    bit() {}
    bit(int mx): n(mx), d(mx) {}
    void add(int i, TT x=1) {
      for (++i;i<n;i+=i&-i) d[i] += x;
    }
    TT sum(int i) {
      TT x = 0; for (++i;i;i-=i&-i) x += d[i];
      return x;
    }
  };
  struct X {
    vector<TX> d;
    inline void add(TX x) { d.pb(x);}
    void init() {
      sort(rng(d));
      d.erase(unique(rng(d)), d.end());
    }
    inline int size() { return sz(d);}
    inline int operator()(TX x) { // !! upper bound (1-indexed) !!
      return upper_bound(rng(d),x)-d.begin();
    }
  };

  int n; vector<bit> d;
  X xs; vector<X> ys;
  vector<pair<TX,TX> > p;
  bit2() {}
  void reg(TX x, TX y) { p.pb(make_pair(x, y));}
  void init() {
    rep(i,sz(p)) xs.add(p[i].fi);
    xs.init();
    n = sz(xs)+1;
    ys.resize(n);
    rep(j,sz(p)) {
      for (int i = xs(p[j].fi); i < n; i+=i&-i) {
        ys[i].add(p[j].se);
      }
    }
    d.resize(n);
    rep(i,n) {
      ys[i].init();
      d[i] = bit(sz(ys[i])+2);
    }
  }
  void add(TX x, TX y, TT z=1) {
    for (int i = xs(x); i < n; i+=i&-i) d[i].add(ys[i](y), z);
  }
  TT sum(TX x, TX y) {
    TT res = 0;
    for (int i = xs(x); i; i-=i&-i) res += d[i].sum(ys[i](y));
    return res;
  }
  TT sum(TX sx, TX sy, TX tx, TX ty) {
    sx--; sy--;
    TT res = sum(tx,ty);
    res -= sum(tx,sy);
    res -= sum(sx,ty);
    res += sum(sx,sy);
    return res;
  }
};
//


// Fraction
struct frac {
  ll a, b;
  frac(ll a=0, ll b=1){
    ll g = gcd(abs(a),abs(b));
    if (b < 0) g = -g;
    this->a = a/g;
    this->b = b/g;
  }
  ll gcd(ll x, ll y) { return y?gcd(y,x%y):x;}
  // frac inv() const { return frac(b,a);}
  frac operator+(const frac& x) const { return frac(a*x.b + x.a*b, b*x.b);}
  frac operator-(const frac& x) const { return frac(a*x.b - x.a*b, b*x.b);}
  frac operator*(const frac& x) const { return frac(a*x.a, b*x.b);}
  frac operator/(const frac& x) const { return frac(a*x.b, b*x.a);}
  frac& operator+=(const frac& x) { return *this = *this + x;}
  frac& operator-=(const frac& x) { return *this = *this - x;}
  frac& operator*=(const frac& x) { return *this = *this * x;}
  frac& operator/=(const frac& x) { return *this = *this / x;}
  bool operator<(const frac& x) const { return a*x.b < x.a*b;}
  bool operator==(const frac& x) const { return a*x.b == x.a*b;}
};
istream& operator>>(istream&i,frac&a){i>>a.a>>a.b;return i;}
ostream& operator<<(ostream&o,const frac&a){o<<a.a<<"/"<<a.b;return o;}
//

// coordinate compression
struct X {
  typedef frac T;
  vector<T> d;
  X() {}
  void add(const T& x) { d.pb(x);}
  void init() {
    sort(rng(d));
    d.erase(unique(rng(d)), d.end());
  }
  int size() const { return sz(d);}
  T operator[](int i) const { return d[i];}
  int operator()(const T& x) const { return upper_bound(rng(d),x)-d.begin()-1;}
};
//

int main() {
  int n,w;
  scanf("%d%d",&n,&w);
  v(frac) b(n), s(n), t(n);
  rep(i,n) {
    int x,v;
    scanf("%d%d",&x,&v);
    frac a(v,x);
    b[i] = frac(w,x);
    s[i] = a+b[i];
    t[i] = b[i]-a;
  }

  X bs; bs.d = b; bs.init();
  X ss; ss.d = s; ss.init();
  X ts; ts.d = t; ts.init();

  vt a;
  rep(i,n) {
    a.eb(bs(b[i]), ss(s[i]), ts(t[i]));
  }

  sort(rng(a));

  bit2 d;
  rep(i,n) {
    int _, x, y;
    tie(_,x,y) = a[i];
    d.reg(x,y);
  }
  d.init();

  ll ans = 0;
  rep(i,n) {
    int _, x, y;
    tie(_,x,y) = a[i];
    ans += d.sum(x,y);
    d.add(x,y);
  }

  cout<<ans<<endl;
  return 0;
}