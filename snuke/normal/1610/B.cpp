#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < (t); ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define newline puts("")
using namespace std;
template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
template<typename T> using PQ = priority_queue<T,vc<T>,greater<T>>;
using uint = unsigned; using ull = unsigned long long;
using vi = vc<int>; using vvi = vv<int>;
using ll = long long; using vl = vc<ll>; using vvl = vv<ll>;
using P = pair<int,int>; using vp = vc<P>;
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
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return;}
#define yes { puts("YES"); return;}
#define no { puts("NO"); return;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;

// rolling hash
// mod pair for hash
int p1 = 131231;
struct mints {
  template<int mod>
  struct mint {
    uint x;
    mint(ll x=0):x(x){}
    mint& operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
    mint& operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
    mint& operator*=(const mint& a) { x=(ull)x*a.x%mod; return *this;}
    mint& operator/=(const mint& a) { x=(ull)x*a.ex(mod-2).x%mod; return *this;}
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
  ll get() const { return (ull)x.x<<32|y.x;}
};
ostream& operator<<(ostream&o,const mints&a){o<<a.x.x*ll(1e9)+a.y.x;return o;}

// Segment tree
struct F { // min func
  mints d, e;
  F(mints d=0, mints e=1):d(d),e(e) {}
  F& operator+=(const F& f) {
    d *= f.e; d += f.d;
    e *= f.e;
    return *this;
  }
  F operator+(const F& f) const { return F(*this) += f;}
};
struct seg {
  vector<F> d; int n;
  seg(){}
  seg(int mx) {
    n = 1; while (n < mx) n <<= 1;
    d = vector<F>(n<<1);
  }
  void upd(int i) { d[i] = d[i<<1]+d[i<<1|1];}
  F& operator[](int i) { return d[n+i];}
  void init() { for(int i=n-1;i;--i) upd(i);}
  void add(int i, F f) { for (i+=n,d[i]+=f,i>>=1;i;i>>=1) upd(i);}
  void set(int i, F f) { for (i+=n,d[i]=f,i>>=1;i;i>>=1) upd(i);}
  F get(int l, int r) {
    l += n; r += n;
    F lf, rf;
    while (l < r) {
      if (l&1) lf += d[l++];
      if (r&1) rf = d[--r] + rf;
      l >>= 1; r >>= 1;
    }
    return lf += rf;
  }
};
//

struct Solver {
  void solve() {
    int n;
    scanf("%d",&n);
    vi a(n);
    cin>>a;
    rep(i,n) a[i]--;
    vvi is(n);
    rep(i,n) is[a[i]].pb(i);
    seg s(n), t(n);
    rep(i,n) s[i] = F(a[i]+1,p1);
    rep(i,n) t[n-1-i] = F(a[i]+1,p1);
    rep(i,n) is[i].pb(n);
    s.init();
    t.init();
    rep(i,n) {
      F ns, nt;
      int pre = 0;
      for (int j : is[i]) {
        ns += s.get(pre,j);
        nt = t.get(n-j,n-pre) + nt;
        pre = j+1;
      }
      if (ns.d == nt.d) yes;
    }
    no;
  }
};

int main() {
  snuke;
  p1 = rand()%1000000+101;
  int ts = 1;
  scanf("%d",&ts);
  rrep(ti,ts) {
    Solver solver;
    solver.solve();
  }
  return 0;
}