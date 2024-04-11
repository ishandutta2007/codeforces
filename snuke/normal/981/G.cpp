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
typedef v(vp) vvp;

// Mod int
const int mod = 998244353;
struct mint {
  ll x;
  mint():x(0){}
  mint(ll x):x((x%mod+mod)%mod){}
  // mint(ll x):x(x){}
  mint& fix() { x = (x%mod+mod)%mod; return *this;}
  mint& operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
  mint& operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
  mint& operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
  mint operator+(const mint& a)const{ return mint(*this) += a;}
  mint operator-(const mint& a)const{ return mint(*this) -= a;}
  mint operator*(const mint& a)const{ return mint(*this) *= a;}
  bool operator<(const mint& a)const{ return x < a.x;}
  bool operator==(const mint& a)const{ return x == a.x;}
};
istream& operator>>(istream&i,mint&a){i>>a.x;return i;}
ostream& operator<<(ostream&o,const mint&a){o<<a.x;return o;}
typedef vector<mint> vm;
//

// Segment tree with lazy prop
struct F { // min func
  mint d;
  F(mint d=mint(0)):d(d) {}
  F operator+(const F& f) const {
    return F(d+f.d);
  }
};
struct G { // lazy add func
  mint d, e;
  G(mint d=1, mint e=0):d(d),e(e) {}
  void operator()(F& f, int w) const {
    f.d = f.d*d + e*w;
  }
  void operator*=(const G& g) {
    d *= g.d;
    e = e*g.d+g.e;
  }
};
struct seg {
  struct FG {
    F f; G g;
    void apply(const G& _g, int w) {
      _g(f,w);
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
    int w = width(i)>>1;
    d[i<<1].apply(d[i].g, w);
    d[i<<1|1].apply(d[i].g, w);
    d[i].g = G();
  }
  void add(int l, int r, G g) {
    add(l,r,g,1,0,n);
    // pri();
  }
  void add(int a, int b, const G& g, int i, int l, int r) {
    if (a <= l && r <= b) {
      d[i].apply(g, width(i));
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

  void pri() {
    auto sp = [&](int m) { printf("%s",string(m,' ').c_str());};
    for (int w = 1; w <= n; w <<= 1) {
      for (int i = w, s = n/w*3-3; i < w<<1; ++i) {
        printf("|"); sp(s-s/2);
        printf("%2lld",d[i].f.d.x); sp(s/2);
      }
      puts("|");
    }
    puts("");
  }
};
//


// coordinate compression
struct X {
  typedef int T;
  vector<T> d;
  X() {}
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

struct Query {
  int t, l, r, x;
};

struct UF {
  vi d;
  UF(int n) {
    d = vi(n);
    rep(i,n) d[i] = i;
  }
  int get(int i) {
    if (d[i] == i) return i;
    return d[i] = get(d[i]);
  }
  void use(int i) {
    d[i]++;
  }
};

int main() {
  int n,q;
  scanf("%d%d",&n,&q);
  v(Query) qs(q);
  X xs;
  rep(i,q) {
    int ty,l,r;
    scanf("%d%d%d",&ty,&l,&r);
    --l;
    if (ty == 1) {
      int x;
      scanf("%d",&x);
      qs[i] = (Query){ty,l,r,x};
      xs.add(x);
    } else {
      qs[i] = (Query){ty,l,r};
    }
  }
  xs.init();
  int m = sz(xs);
  vvp qas(q);
  vvp qws(q);
  vvi qis(m);
  rep(i,q) if (qs[i].t == 1) {
    int j = xs(qs[i].x);
    qis[j].pb(i);
  }
  rep(mi,m) {
    vi& qi = qis[mi];
    X is;
    for (int i : qi) {
      is.add(qs[i].l);
      is.add(qs[i].r);
    }
    is.init();
    UF d(sz(is)+1);
    for (int i : qi) {
      int l = is(qs[i].l);
      int r = is(qs[i].r);
      for (int j = l; j < r;) {
        if (d.d[j] == j) {
          qas[i].pb(P(is[j],is[j+1]));
          d.use(j);
          ++j;
        } else {
          int nj = d.get(j);
          mins(nj,r);
          qws[i].pb(P(is[j],is[nj]));
          j = nj;
        }
      }
    }
  }

  seg t(n);
  rep(i,q) {
    if (qs[i].t == 1) {
      for (P p : qas[i]) {
        // cerr<<"add"<<" "<<i<<": "<<p<<endl;
        t.add(p.fi,p.se,G(1,1));
      }
      for (P p : qws[i]) {
        // cerr<<"two"<<" "<<i<<": "<<p<<endl;
        t.add(p.fi,p.se,G(2,0));
      }
    } else {
      mint ans = t.get(qs[i].l,qs[i].r).d;
      printf("%lld\n",ans.x);
    }
  }
  return 0;
}