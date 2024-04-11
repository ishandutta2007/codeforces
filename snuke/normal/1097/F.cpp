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
const int M = 7001;
const int MX = 100005;

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

vi meb;
void mebinit(int n) {
  sieve(n+1);
  meb = vi(n+1,1);
  meb[0] = 0;
  for (int p : ps) {
    for (int i = p; i <= n; i += p) meb[i] = -meb[i];
    ll p2 = (ll)p*p;
    for (ll i = p2; i <= n; i += p2) meb[i] = 0;
  }
}
typedef bitset<M> bs;

bs b[M], ib[M];
bs a[MX];

int main() {
  for (int i = 1; i < M; ++i) {
    for (int j = i; j < M; j += i) b[j][i] = 1;
  }
  // for (int i = 1; i < M; ++i) {
  //   bs t = b[i];
  //   ib[i][i] = 1;
  //   drep(j,i) if (t[j]) {
  //     t ^= b[j];
  //     ib[j][i] = 1;
  //   }
  // }
  mebinit(M);
  for (int i = 1; i < M; ++i) {
    for (int j = i, k = 1; j < M; j += i, ++k) ib[i][j] = !!meb[k];
  }

  int q;
  scanf("%*d%d",&q);
  string ans;
  rep(qi,q) {
    int ty;
    scanf("%d",&ty);
    if (ty == 1) {
      int x,v;
      scanf("%d%d",&x,&v);
      a[x] = b[v];
    }
    if (ty == 2) {
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      a[x] = a[y]^a[z];
    }
    if (ty == 3) {
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      a[x] = a[y]&a[z];
    }
    if (ty == 4) {
      int x,v;
      scanf("%d%d",&x,&v);
      // cout<<a[x]<<" "<<ib[v]<<endl;
      int res = (a[x]&ib[v]).count()&1;
      ans += '0'+res;
    }
  }
  cout<<ans<<endl;
  return 0;
}