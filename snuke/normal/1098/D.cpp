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

// Binary Indexed Tree
struct bit {
  int n; vector<ll> d;
  bit() {}
  bit(int mx) {
    n = 1;
    while (n < mx) n <<= 1;
    d = vl(n+1);
  }
  void add(int i, ll x) {
    for (++i;i<=n;i+=i&-i) d[i] += x;
  }
  ll sum(int i) {
    ll x = 0;
    for (++i;i;i-=i&-i) x += d[i];
    return x;
  }
  int nxt(ll x) {
    // cerr<<x<<": "<<d<<endl;
    int i = 0;
    int w = n>>1;
    while (w) {
      if (d[i+w] <= x) {
        i += w;
        x -= d[i];
      }
      w >>= 1;
    }
    return i;
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
  int qn;
  scanf("%d",&qn);
  vi q;
  X xs;
  rep(qi,qn) {
    char c; int a;
    scanf(" %c%d",&c,&a);
    xs.add(a);
    if (c == '-') a = -a;
    q.pb(a);
  }
  xs.init();
  int n = sz(xs);
  bit d(n+2);

  vi cs(n+1);

  int cnt = 0;
  rep(qi,qn) {
    int a = q[qi];
    int i = xs(abs(a));
    d.add(i,a);
    if (a < 0) --cnt; else ++cnt;
    if (a < 0) --cs[i]; else ++cs[i];
    if (!cnt) {
      puts("0");
      continue;
    }
    int now = 0;
    ll w = 0;
    // cerr<<a<<" "<<i<<endl;
    while (w < d.d.back()) {
      int j = d.nxt(w);
      if (j >= n) break;
      w = d.sum(j-1)*2;
      if (w < xs[j]) now++;
      w += (ll)xs[j]*cs[j];
    }
    int ans = cnt-now;
    printf("%d\n",ans);
  }
  return 0;
}