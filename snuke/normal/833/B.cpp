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

// Segment tree with lazy prop
struct F { // min func
  typedef int TF;
  TF d;
  F(TF d=0):d(d) {}
  // TF operator()() const {
  //   return d;
  // }
  F operator+(const F& f) const {
    return F(max(d,f.d));
  }
};
struct G { // lazy add func
  typedef int TG;
  TG d;
  G(TG d=0):d(d) {}
  void operator()(F& f) const {
    f.d += d;
  }
  void operator*=(const G& g) {
    d += g.d;
  }
};
struct seg {
  struct FG {
    F f; G g;
    void apply(const G& _g) {
      _g(f);
      g *= _g;
    }
  };
  vector<FG> d; int n;
  seg(){}
  seg(int mx) {
    n = 1; while (n < mx) n <<= 1;
    d = vector<FG>(n<<1);
  }
  int width(int i) { return 1<<(__builtin_clz(i)-__builtin_clz(n));}
  void upd(int i) { d[i].f = d[i<<1].f+d[i<<1|1].f;}
  FG& operator[](int i) { return d[n+i];}
  void init() { drep(i,n) upd(i);}
  void prop(int i) {
    d[i<<1].apply(d[i].g);
    d[i<<1|1].apply(d[i].g);
    d[i].g = G();
  }
  void add(int l, int r, G g) { add(l,r,g,1,0,n);}
  void add(int a, int b, const G& g, int i, int l, int r) {
    if (a <= l && r <= b) {
      d[i].apply(g);
      return;
    }
    prop(i);
    int c = (l+r)>>1;
    if (a < c) add(a,b,g,i<<1,l,c);
    if (c < b) add(a,b,g,i<<1|1,c,r);
    upd(i);
  }
  F get(int l, int r) { return get(l,r,1,0,n);}
  F get(int a, int b, int i, int l, int r) {
    if (a <= l && r <= b) return d[i].f;
    prop(i);
    int c = (l+r)>>1;
    F res;
    if (a < c) res = res + get(a,b,i<<1,l,c);
    if (c < b) res = res + get(a,b,i<<1|1,c,r);
    return res;
  }
};
//


int main() {
  int n,m;
  scanf("%d%d",&n,&m);
  vi a(n);
  X xs;
  rep(i,n) scanf("%d",&a[i]), xs.add(a[i]);
  xs.init();
  v(seg) t(m+1,seg(n+5));
  vi pre(sz(xs),-1);
  rep(i,n) {
    int x = xs(a[i]), p = pre[x];
    if (i) {
      drep(k,m) {
        t[k+1].add(i,i+1,G(t[k].get(0,i).d));
      }
    }
    rep(k,m) t[k].add(p+1,i+1,G(1));
    pre[x] = i;
  }
  int ans = t[m-1].get(0,n).d;
  cout<<ans<<endl;
  return 0;
}