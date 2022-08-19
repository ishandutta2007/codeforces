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
const int MX = 200005;

// coordinate compression
struct X {
  using T = ll;
  vc<T> d;
  X() {}
  /*
  X(vc<T>& a): d(a) {
    init();
    for (T& na : a) na = (*this)(na);
  }// int only */
  void add(const T& x) { d.pb(x);}
  void init() {
    sort(rng(d));
    d.erase(unique(rng(d)), d.end());
  }
  int size() const { return sz(d);}
  T operator[](int i) const { return d[i];}
  int operator()(const T& x) const { return upper_bound(rng(d),x)-d.begin()-1;}
  bool in(const T& x) const { return binary_search(rng(d),x);}
};
//

// Binary Indexed Tree
struct bit {
  using T = int;
  int n; vector<T> d;
  bit() {}
  bit(int mx): n(mx+1), d(mx+1) {}
  void add(int i, T x=1) {
    for (++i;i<n;i+=i&-i) d[i] += x;
  }
  T sum(int i) {
    T x = 0;
    for (++i;i;i-=i&-i) x += d[i];
    return x;
  }
};
//

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

struct Solver {
  void solve() {
    int n;
    scanf("%d",&n);
    vl a(n);
    cin>>a;
    if (n == 1) {
      cout<<1<<endl;
      return;
    }
    mint ans;
    ll sw = a[0]*2;
    ll tw = a.back()*2;
    vl ss(n+1), ts(n+1);
    rep(i,n) ss[i+1] = ss[i]+a[i];
    drep(i,n) ts[i] = ts[i+1]+a[i];
    rep(i,n+1) {
      if (ss[i]-ts[i] > 0) ans += 1;
    }

    vc<X> xs(2);
    ll x = 0;
    rep(i,n) {
      int ni = i%2;
      auto add = [&](ll l) {
        l = x-l;
        xs[ni].add(l);
      };
      add(-ss[i]);
      if (i) add(-ss[i]+sw);
      x = a[i]-x;
    }
    rep(i,2) xs[i].init();

    x = 0;
    vc<bit> d(2);
    rep(i,2) d[i] = bit(sz(xs[i])+1);
    rep(i,n) {
      int ni = i%2;
      auto add = [&](ll l) {
        l = x-l;
        // cerr<<i<<" "<<l<<endl;
        d[ni].add(xs[ni](l));
      };
      add(-ss[i]);
      if (i) add(-ss[i]+sw);
      
      x = a[i]-x;
      auto get = [&](ll r) {
        r += x; --r;
        // cerr<<i<<" get "<<r<<endl;
        return d[ni^1].sum(xs[ni^1](r));
      };
      ans += get(ts[i+1]);
      if (i != n-1) {
        ans += get(ts[i+1]-tw);
      }
    }
    cout<<ans<<endl;
  }
};

int main() {
  int ts = 1;
  scanf("%d",&ts);
  rrep(ti,ts) {
    Solver solver;
    solver.solve();
  }
  return 0;
}