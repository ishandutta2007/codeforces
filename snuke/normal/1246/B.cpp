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
#define yn {puts("Yes");}else{puts("No");}
const int MX = 100005;

// Run Length Encoding
namespace RLE {
  vp f(const vi& a) {
    if (!sz(a)) return vp();
    vp res(1,P(a[0],1));
    for (int i = 1; i < sz(a); ++i) {
      if (res.back().fi == a[i]) res.back().se++;
      else res.eb(a[i],1);
    }
    return res;
  }
  typedef pair<char,int> CP;
  v(CP) f(const string& a) {
    if (!sz(a)) return v(CP)();
    v(CP) res(1,CP(a[0],1));
    for (int i = 1; i < sz(a); ++i) {
      if (res.back().fi == a[i]) res.back().se++;
      else res.eb(a[i],1);
    }
    return res;
  }
};
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



int main() {
  sieve(MX);
  int n,k;
  scanf("%d%d",&n,&k);
  vi a(n);
  cin>>a;
  vi b;
  rep(i,n) {
    vp x = RLE::f(factor(a[i]));
    // cerr<<x<<endl;
    ll now = 1, inv = 1;
    for (auto p : x) {
      p.se %= k;
      rep(j,p.se) now *= p.fi;
      rep(j,(k-p.se)%k) {
        inv *= p.fi;
        mins(inv,(ll)MX);
      }
    }
    // cerr<<now<<" "<<inv<<endl;
    a[i] = now;
    b.pb(inv);
  }
  vi cnt(MX+5);
  ll ans = 0;
  rep(i,n) {
    ans += cnt[a[i]];
    cnt[b[i]]++;
  }
  cout<<ans<<endl;
  return 0;
}