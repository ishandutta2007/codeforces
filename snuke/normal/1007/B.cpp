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

#define bsf __builtin_ctzll
ll gcd(ll a, ll b) {
  // a = abs(a); b = abs(b);
  if (!a || !b) return a|b;
  int t = bsf(a|b); a >>= bsf(a);
  do { b >>= bsf(b); if (a > b) swap(a, b); b -= a;} while (b);
  return a << t;
}
ll lcm(ll x, ll y) { return x/gcd(x,y)*y;}
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
vi factor(int x) { // asc
  vi res;
  while (x != 1) {
    res.pb(pf[x]);
    x /= pf[x];
  }
  return res;
}
//

int f(int x) {
  vi a = factor(x);
  int res = 1, s = 0, pre = -1;
  a.pb(INF);
  rep(i,sz(a)) {
    if (a[i] != pre) {
      res *= s+1;
      s = 1;
      pre = a[i];
    } else ++s;
  }
  return res;
}

vi states;
void solve() {
  vi a(3);
  rep(i,3) scanf("%d",&a[i]);
  vl s(8);
  rrep(i,7) {
    int g = 0;
    rep(j,3) if (i>>j&1) g = gcd(g,a[j]);
    s[i] = f(g);
  }
  drep(i,8) {
    srep(j,i+1,8) if ((i&j) == i) s[i] -= s[j];
  }
  ll ans = 0;
  for (int state : states) {
    int i = state/64, j = state/8%8, k = state%8;
    if (i == j) {
      if (j == k) {
        ans += s[i]*(s[i]+1)*(s[i]+2)/6;
      } else {
        ans += s[i]*(s[i]+1)/2*s[k];
      }
    } else if (j == k) {
      ans += s[i]*s[j]*(s[j]+1)/2;
    } else {
      ans += s[i]*s[j]*s[k];
    }
  }
  printf("%lld\n",ans);
}

int main() {
  sieve(MX);
  int ts;
  scanf("%d",&ts);

  rrep(i,7)rrep(j,7)rrep(k,7) {
    if (i > j) continue;
    if (j > k) continue;
    vi p = {0,1,2};
    bool ok = false;
    do {
      ok = true;
      if (~i>>p[0]&1) ok = false;
      if (~j>>p[1]&1) ok = false;
      if (~k>>p[2]&1) ok = false;
      if (ok) break;
    } while (next_permutation(rng(p)));
    if (!ok) continue;
    states.pb(i*64+j*8+k);
  }
  rep(ti,ts) {
    solve();
  }
  return 0;
}