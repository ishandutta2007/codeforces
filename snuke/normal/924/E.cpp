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
const ll LINF = 1e18;
const int INF = 1001001001;
#define dame { puts("0"); return 0;}
#define yn {puts("YES");}else{puts("NO");}
const int MX = 10005;

int dp[MX];

int main() {
  int n,l,r;
  scanf("%d%d%d",&n,&l,&r);
  vi ab(n);
  cin>>ab;
  int s = suma(ab);
  l = s-l; r = s-r; swap(l,r);
  if (r < 0) dame;
  maxs(r,0);
  vi a, b;
  rep(i,n) {
    int f;
    cin>>f;
    if (f) a.pb(ab[i]);
    else b.pb(ab[i]);
  }
  sort(rng(a)); reverse(rng(a));
  rep(i,r+1) dp[i] = -INF;
  dp[0] = 0;
  rep(i,sz(b))drep(j,r-b[i]+1) maxs(dp[j+b[i]], dp[j]);
  rep(i,sz(a)) {
    drep(j,r-a[i]+1) {
      int nj = j+a[i];
      int x = (l <= nj && nj <= r);
      maxs(dp[nj], dp[j]+x);
    }
  }
  int ans = 0;
  rep(i,r+1) maxs(ans, dp[i]);
  cout<<ans<<endl;
  return 0;
}