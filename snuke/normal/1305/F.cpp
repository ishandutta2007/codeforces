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
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;
const int MA = 1000005;
random_device _rd;
struct xrand {
  static const uint64_t _x = 88172645463325252ull;
  uint64_t x;
  xrand(): x(_x ^ (_rd()+time(0))) {}
  xrand(uint64_t seed): x(_x ^ seed) {}
  uint64_t get() {
    x = x ^ (x << 7);
    return x = x ^ (x >> 9);
  }
  int operator()(int n) { return get()%n;}
  int operator()(int l, int r) { return get()%(r-l+1) + l;}
} rnd;

// linear sieve
vi ps, pf;
void sieve(int mx) {
  pf = vi(mx+1);
  rep(i,mx+1) pf[i] = i;
  for (int i = 2; i <= mx; ++i) {
    if (pf[i] == i) ps.pb(i);
    for (int j = 0; j < sz(ps) && ps[j] <= pf[i]; ++j) {
      int x = ps[j]*i;
      if (x > mx) break;
      pf[x] = ps[j];
    }
  }
}
inline bool isp(int x) { return pf[x] == x && x >= 2;}
vp factor(int x) { // asc
  if (x == 1) return {};
  vp res(1, P(pf[x], 0));
  while (x != 1) {
    if (res.back().fi == pf[x]) res.back().se++;
    else res.pb(P(pf[x],1));
    x /= pf[x];
  }
  return res;
}
//

ll x;
ll f[MX*2];

int main() {
  sieve(MA);
  int n;
  scanf("%d",&n);
  vl a(n);
  cin>>a;
  sort(rrng(a));
  ll ans = 0;
  rep(i,n) ans += a[i]%2;
  x = a[rnd(n)];
  ll l = max(2ll,x-ans);
  ll r = x+ans;
  rep(i,r-l+1) f[i] = l+i;
  set<ll> fs;
  for (int p : ps) {
    ll lx = (l+p-1)/p*p;
    if (lx <= r) fs.insert(p);
    for (ll i = lx; i <= r; i += p) {
      int ni = i-l;
      f[ni] /= p;
      while (f[ni]%p == 0) f[ni] /= p;
    }
  }
  rep(i,r-l+1) if (f[i] != 1) fs.insert(f[i]);
  for (ll p : fs) {
    ll now = 0;
    rep(i,n) {
      ll s = a[i]%p;
      if (a[i] >= p) mins(s, p-s);
      else s = (p-s)%p;
      now += s;
      if (now >= ans) break;
    }
    mins(ans, now);
  }
  cout<<ans<<endl;
  return 0;
}