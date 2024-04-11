#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <numeric>
#include <cctype>
#include <bitset>
#include <cassert>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
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

// Binary Indexed Tree
struct bit {
  typedef int TT;
  int n; vector<TT> d;
  bit() {}
  bit(int mx): n(mx), d(mx) {}
  void add(int i, TT x=1) {
    for (++i;i<n;i+=i&-i) d[i] += x;
  }
  TT sum(int i) {
    TT x = 0;
    for (++i;i;i-=i&-i) x += d[i];
    return x;
  }
};
//

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
  int operator[](int i) const { return d[i];}
  int operator()(T x) const { return upper_bound(rng(d),x)-d.begin()-1;}
};
//

// Segment tree with lazy prop
struct MIN { // min func
  typedef int TF;
  TF d;
  MIN(TF d=INF):d(d) {}
  MIN operator+(const MIN& f) const {
    return MIN(min(d,f.d));
  }
  bool operator==(const MIN& f) const { return d==f.d;}
};
struct MAX { // max func
  typedef int TF;
  TF d;
  MAX(TF d=-INF):d(d) {}
  MAX operator+(const MAX& f) const {
    return MAX(max(d,f.d));
  }
  bool operator==(const MAX& f) const { return d==f.d;}
};
template<typename F>
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

template<typename F>
struct seg {
  struct FG {
    F f; G<F> g;
    void apply(const G<F>& _g) {
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
    d[i].g = G<F>();
  }
  void set(int i, int x) { set(i,i+1,x,1,0,n);}
  void set(int a, int b, int x, int i, int l, int r) {
    if (a <= l && r <= b) {
      d[i].f = F(x);
      return;
    }
    prop(i);
    int c = (l+r)>>1;
    if (a < c) set(a,b,x,i<<1,l,c);
    if (c < b) set(a,b,x,i<<1|1,c,r);
    upd(i);
  }
  void add(int l, int r, int g) { add(l,r,G<F>(g),1,0,n);}
  void add(int a, int b, const G<F>& g, int i, int l, int r) {
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
  int pos(int l, int r, int x) {
    if (l >= r) return -1;
    return pos(l,r,F(x),1,0,n);
  }
  int pos(int a, int b, F x, int i, int l, int r) {
    if (!(d[i].f+x == d[i].f)) return -1;
    if (r-l == 1) return l;
    prop(i);
    int c = (l+r)>>1;
    if (a < c) {
      int res = pos(a,b,x,i<<1,l,c);
      if (res != -1) return res;
    }
    if (c < b) {
      int res = pos(a,b,x,i<<1|1,c,r);
      return res;
    }
    return -1;
  }
};
//

vi pa;
int root(int v) {
  if (pa[v] == -1) return v;
  return pa[v] = root(pa[v]);
}

int main() {
  int n;
  scanf("%d",&n);
  vi a(n);
  rep(i,n) scanf("%d",&a[i]);
  X xs;
  rep(i,n) xs.add(a[i]);
  xs.init();
  int m = sz(xs);
  pa = vi(m,-1);
  vi used(m);
  set<int> s;
  seg<MIN> t(m);
  seg<MAX> t2(m);
  bit sm(m+5);
  rep(ai,n) {
    int tot = ai+1;
    {
      int x = xs(a[ai]);
      sm.add(x);
      if (!used[x]) {
        t.add(x,x+1, xs[x]-INF);
        t2.add(x,x+1, xs[x]+INF);
      }
      used[x]++;
      t.add(x,m,-1);
      t2.add(x,m,1);
      s.insert(x);
      int nx = x;
      while (1) {
        auto it = s.upper_bound(nx);
        if (it == s.begin()) break;
        --it;
        int p = t.pos((*it)+1,m,xs[*it]-sm.sum(*it));
        // cerr<<(*it)<<" "<<p<<endl;
        if (p == -1) {
          if (nx == x) nx--;
          else break;
          continue;
        }
        pa[*it] = p;
        s.erase(it);
      }
    }

    {
      int p = t2.pos(0,m,0);
      // cerr<<p<<endl;
      int ans = -tot;
      if (p != -1) {
        int q = t.pos(p,m,-sm.sum(p-1)*2);
        // cerr<<q<<endl;
        if (q == -1) {
          ans = tot-sm.sum(p-1)*2;
        } else {
          q = root(q);
          ans = xs[q]+(tot-sm.sum(q));
        }
      }
      printf("%d\n",ans);
    }
  }
  return 0;
}