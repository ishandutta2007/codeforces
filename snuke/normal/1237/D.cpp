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

// Segment tree
struct F { // min func
  typedef int TT;
  TT d;
  F(TT d=INF):d(d) {}
  F& operator+=(const F& f) {
    mins(d, f.d);
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
  void set(int i, F f) {
    i+=n; d[i] += f;
    for (i>>=1;i;i>>=1) upd(i);
  }
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
// coordinate compression
struct X {
  typedef int T;
  vector<T> d;
  X() {}
  // X(vector<T>& a): d(a) {
  //   init();
  //   for (T& na : a) na = (*this)(na);
  // }
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



int main() {
  int n;
  scanf("%d",&n);
  vi a(n);
  cin>>a;
  X xs;
  rep(i,n) xs.add(a[i]);
  xs.init();
  int m = sz(xs);
  rep(i,n) a.pb(a[i]);
  rep(i,n) a.pb(a[i]);

  seg t(m+5);
  vi dp(n*3);
  drep(i,n*3) {
    int l = (a[i]-1)/2;
    int li = xs(l);
    // cerr<<a[i]<<" "<<xs(a[i])<<" "<<l<<" "<<li<<endl;
    dp[i] = t.get(0,li+1).d;
    t.set(xs(a[i]),F(i));
  }
  // cerr<<dp<<endl;
  vi ans(n);
  int now = INF;
  drep(i,n*2) {
    mins(now,dp[i]);
    if (i < n) ans[i] = now-i;
  }
  if (now == INF) ans = vi(n,-1);
  cout<<ans<<endl;
  return 0;
}