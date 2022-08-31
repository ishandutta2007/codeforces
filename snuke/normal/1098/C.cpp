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
#define dame { puts("NO"); return 0;}
#define yn {puts("YES");}else{puts("NO");}
const int MX = 200005;

ll f(ll n, ll c) {
  ll res = 0;
  ll x = 1, d = 1;
  while (n) {
    ll s = min(n,x);
    n -= s; x -= s;
    res += d*s;
    x = s*c; ++d;
  }
  return res;
}
ll sm(ll l, ll n) {
  return (l+(l+n-1))*n/2;
}

int main() {
  int n;
  ll x;
  scanf("%d%lld",&n,&x);
  int sn = n;
  ll mx = ll(n+1)*n/2;
  ll mn = n*2-1;
  if (x > mx || x < mn) dame;
  puts("YES");
  int l = 0, r = n-1;
  while (l+1<r) {
    int c = (l+r)>>1;
    if (f(n,c) <= x) r = c; else l = c;
  }
  vi a;
  a.pb(1);
  n--; x -= 1;
  ll d = 2;
  while (n) {
    ll m = (ll)a.back()*r;
    a.pb(0);
    while (n && m) {
      if (x <= sm(d,n)) {
        x -= d;
        n--; m--;
        a.back()++;
      } else break;
    }
    ++d;
  }
  // cout<<a<<endl;
  // cout<<x<<endl;
  assert(!x);

  vi ans;
  vvi vs(sz(a));
  rep(i,sz(a)) {
    rep(j,a[i]) vs[i].pb(++n);
  }
  rrep(i,sz(a)-1) {
    int j = 0, d = r;
    for (int v : vs[i]) {
      ans.pb(vs[i-1][j]);
      --d;
      if (!d) ++j, d = r;
    }
  }
  cout<<ans<<endl;
  return 0;
}