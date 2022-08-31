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
typedef pair<ll,ll> P;
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
const int MX = 31622780;
const int MD = 1000000;
typedef v(vl) vvl;

// coordinate compression
struct X {
  typedef ll T;
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

// ax+by = gcd(a,b)
ll extgcd(ll a, ll b, ll& x, ll& y) {
  for (ll u = y = 1, v = x = 0; a;) {
    ll q = b / a; swap(x -= q * u, u);
    swap(y -= q * v, v); swap(b -= q * a, a);
  }
  return b;
}
//

// linear sieve
vi ps, pf;
void sieve(int mx) {
  pf = vi(mx);
  rep(i,mx) pf[i] = i;
  for (int i = 2; i < mx; ++i) {
    if (pf[i] == i) ps.pb(i);
    for (int j = 0; j < sz(ps) && ps[j] <= pf[i]; ++j) {
      int x = ps[j]*i;
      if (x >= mx) break;
      pf[x] = ps[j];
    }
  }
}
inline bool isp(int x) { return pf[x] == x && x >= 2;}
//



int main() {
  int ts;
  scanf("%d",&ts);
  sieve(MX);

  vp qs(ts);
  cin>>qs;
  X xs;
  rep(i,ts) xs.add(qs[i].se);
  xs.init();
  int m = sz(xs);
  vvl d(m);
  vl x(m);
  rep(i,m) x[i] = xs[i];
  for (int p : ps) {
    rep(i,m) {
      if (x[i]%p) continue;
      while (x[i]%p == 0) x[i] /= p;
      d[i].pb(p);
    }
  }
  rep(i,m) if (x[i] != 1) d[i].pb(x[i]);

  vvl dp(m);
  rep(i,m) {
    if (xs[i] == 1) continue;
    if (d[i][0] > MD) continue;
    int n = d[i][0];
    dp[i] = vl(n,LINF);
    dp[i][0] = 0;
    PQ(ll) q;
    q.push(0);
    while (sz(q)) {
      ll x = q.top(); q.pop();
      int v = x%n;
      if (dp[i][v] != x) continue;
      srep(j,1,sz(d[i])) {
        ll nx = x+d[i][j];
        int u = nx%n;
        if (dp[i][u] <= nx) continue;
        dp[i][u] = nx;
        q.push(nx);
      }
    }
  }

  rep(ti,ts) {
    ll n = qs[ti].fi;
    ll k = qs[ti].se;
    int i = xs(k);
    bool ans = false;
    if (k == 1) {
      ans = false;
    } else if (d[i][0] <= MD) {
      ans = dp[i][n%d[i][0]]<=n;
    } else if (sz(d[i]) == 1) {
      ans = n%d[i][0] == 0;
    } else {
      ll a = d[i][0], b = d[i][1];
      ll x, y;
      extgcd(a,b,x,y);
      x = (x%b+b)%b;
      ll z = n%b*x%b;
      ll c = a*z;
      ans = c <= n;
    }
    puts(ans?"YES":"NO");
  }
  return 0;
}