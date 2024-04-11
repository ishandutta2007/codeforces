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
inline int getInt() { int x; scanf("%d",&x); return x;}
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

// coordinate compression
struct X {
  typedef int T;
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

vi ans;
struct seg {
  struct D {
    set<int> s;
    int l, r;
    D():l(-1),r(-1) {}
    void init() {
      if (sz(s)) {
        l = *s.rbegin();
        r = ans[l] ? -1 : l;
      } else {
        l = -1;
        r = -1;
      }
    }
  };
  v(D) d;
  int n;
  seg(int mx) {
    n = 1;
    while (n < mx) n <<= 1;
    d = v(D)(n<<1);
  }
  void calc(int i) {
    d[i].init();
    if (i >= n) return;
    int li = i<<1, ri = li|1;
    int cl = min(d[li].l, d[ri].l);
    int cr = max(d[li].r, d[ri].r);
    if (sz(d[i].s)) {
      maxs(d[i].l, cl);
      if (cr > *d[i].s.rbegin() && d[i].r < cr) d[i].r = cr;
      else if (d[i].r != -1) {
        if (d[i].r < min(d[li].l, d[ri].l)) d[i].r = -1;
      }
    } else {
      d[i].l = cl;
      d[i].r = cr;
    }
  }
  void delr(int i, int x) {
    if (d[i].r != x) return;
    if (i < n) {
      delr(i<<1, x);
      delr(i<<1|1, x);
    }
    calc(i);
  }
  void enu() {
    while (d[1].r != -1) {
      ans[d[1].r] = 1;
      delr(1, d[1].r);
    }
  }
  void add(int l, int r, int x) {
    add(1,0,n,l,r,x);
    // rep(i,n<<1) if (i) cerr<<i<<" "<<d[i].l<<" "<<d[i].r<<endl;
    enu();
    // cerr<<ans<<endl;
  }
  void add(int i, int l, int r, int a, int b, int x) {
    if (a <= l && r <= b) {
      if (x >= 0) d[i].s.insert(x);
      else d[i].s.erase(-x-1);
    } else {
      int c = (l+r)>>1;
      if (a < c) add(i<<1, l, c, a, b, x);
      if (c < b) add(i<<1|1, c, r, a, b, x);
    }
    calc(i);
  }
};

int main() {
  int n;
  scanf("%d",&n);
  X xs;
  vp xp;
  vp evs;
  rep(i,n) {
    int lx,ly,rx,ry;
    scanf("%d%d%d%d",&lx,&ly,&rx,&ry);
    xs.add(lx);
    xs.add(rx);
    xp.eb(lx,rx);
    evs.eb(ly,n-1-i);
    evs.eb(ry,n+i);
  }
  xs.init();
  sort(rng(evs));
  ans = vi(n);
  seg t(sz(xs));
  for (P ev : evs) {
    int i = ev.se;
    bool L = true;
    if (i >= n) {
      i -= n;
      L = false;
    } else {
      i = n-1-i;
    }
    int l = xs(xp[i].fi), r = xs(xp[i].se);
    // cerr<<L<<" "<<i<<" "<<l<<" "<<r<<endl;
    if (L) {
      t.add(l,r,i);
    } else {
      t.add(l,r,-i-1);
    }
  }
  // cerr<<ans<<endl;
  cout<<suma(ans)+1<<endl;
  return 0;
}