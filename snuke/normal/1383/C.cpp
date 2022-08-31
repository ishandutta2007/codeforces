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

// union find flat
struct uff {
  vvi d;
  vi di;
  uff(int n=0):d(n),di(n) {
    rep(i,n) {
      d[i] = vi(1,i);
      di[i] = i;
    }
  }
  int operator[](int i) const { return di[i];}
  int root(int i) { return di[i];}
  bool unite(int a, int b) {
    a = di[a]; b = di[b];
    if (a == b) return false;
    if (sz(d[a]) < sz(d[b])) swap(a,b);
    for (int i : d[b]) di[i] = a;
    d[a].insert(d[a].end(),rng(d[b]));
    d[b] = vi();
    return true;
  }
  int size(int i) const { return sz(d[di[i]]);}
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

void solve() {
  scanf("%*d");
  string s, t;
  cin>>s>>t;
  int n = 20;
  vvi g(n,vi(n));
  rep(i,sz(s)) {
    if (s[i] == t[i]) continue;
    g[s[i]-'a'][t[i]-'a'] = 1;
  }
  uff d(n);
  rep(i,n)rep(j,n) if (g[i][j]) d.unite(i,j);
  int ans = 0;
  rep(di,n) {
    X xs;
    xs.d = d.d[di];
    xs.init();
    int m = sz(xs);
    if (!m) continue;
    vi o(m);
    rep(i,m)rep(j,m) {
      if (g[xs[i]][xs[j]]) o[j] |= 1<<i;
    }

    int m2 = 1<<m;
    vi dp(m2,INF);
    dp[0] = 0;
    rep(i,m2)rep(j,m) if (~i>>j&1) {
      mins(dp[i|1<<j], dp[i]+!!(o[j]&~i));
    }
    ans += dp.back()+m-1;
  }
  cout<<ans<<endl;
}

int main() {
  int ts;
  scanf("%d",&ts);
  rep(ti,ts) solve();
  return 0;
}