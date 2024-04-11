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
  TT sum2(int l, int r) {
    return sum(r-1)-sum(l-1);
  }
};
//

int n;
bit d;
int f(int s, int t) {
  if (s <= t) return d.sum2(s,t);
  return d.sum2(s,n)+d.sum2(0,t);
}

int main() {
  scanf("%d",&n);
  vi a(n);
  cin>>a;
  X xs;
  xs.d = a;
  xs.init();
  rep(i,n) a[i] = xs(a[i]);
  int m = sz(xs);
  vvi b(m);
  rep(i,n) b[a[i]].pb(i);
  d = bit(n+5);
  rep(i,n) d.add(i);
  int p = 0;
  ll ans = 0;
  rep(i,m) {
    int si = 0, best = INF;
    rep(j,sz(b[i])) {
      int nx = f(p,b[i][j]);
      if (nx < best) {
        best = nx;
        si = j;
      }
    }
    rep(sj,sz(b[i])) {
      int j = (sj+si)%sz(b[i]);
      ans += f(p,b[i][j]);
      p = b[i][j];
      // cerr<<p<<" "<<ans<<endl;
      d.add(p,-1);
      ans++; p = (p+1)%n;
    }
  }
  cout<<ans<<endl;
  return 0;
}