#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
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
typedef vector<vl> vvl;
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
const int MX = 5005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

vi to[MX];
int c[MX], d[MX];
vvi dp[MX];

int dfs(int v) {
  int s = 1;
  dp[v] = vvi(2,vi(s+1,INF));
  {
    dp[v][0][0] = 0;
    dp[v][0][1] = c[v];
    dp[v][1][1] = c[v]-d[v];
  }
  for (int u : to[v]) {
    int t = dfs(u);
    vvi p(2,vi(s+t+1,INF));
    swap(dp[v],p);
    rep(si,2)rep(i,s+1)rep(sj,si+1)rep(j,t+1) {
      mins(dp[v][si][i+j], p[si][i]+dp[u][sj][j]);
    }
    s += t;
  }
  // cerr<<v<<endl;
  // cerr<<dp[v][0]<<endl;
  // cerr<<dp[v][1]<<endl;
  return s;
}

int main() {
  int n,r;
  scanf("%d%d",&n,&r);
  rep(i,n) {
    scanf("%d%d",&c[i],&d[i]);
    if (i) {
      int x;
      scanf("%d",&x);
      --x;
      to[x].pb(i);
    }
  }
  dfs(0);
  int ans = 0;
  rep(i,n+1)rep(j,2) if (dp[0][j][i] <= r) ans = i;
  cout<<ans<<endl;
  return 0;
}