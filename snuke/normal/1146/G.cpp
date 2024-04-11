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

int n, m;
int dp[55][55][55];

struct Q {
  int l, r, x, c;
  int cost(int i, int h) {
    if (l <= i && i < r && h > x) return c;
    return 0;
  }
};
v(Q) q;

int dfs(int l, int r, int h) {
  if (l == r) return 0;
  int& now = dp[l][r][h];
  if (now != -1) return now;
  now = 0;
  if (h) now = dfs(l,r,h-1);
  srep(i,l,r) {
    int c = h*h;
    rep(k,m) {
      if (l <= q[k].l && q[k].r <= r) c -= q[k].cost(i,h);
    }
    c += dfs(l,i,h) + dfs(i+1,r,h);
    maxs(now,c);
  }
  return now;
}

int main() {
  int h;
  cin>>n>>h>>m;
  q = v(Q)(m);
  rep(i,m) {
    int l,r,x,c;
    scanf("%d%d%d%d",&l,&r,&x,&c);
    --l;
    q[i] = (Q){ l, r, x, c};
  }
  rep(i,n)rep(j,n+1)rep(k,h+1) dp[i][j][k] = -1;
  int ans = dfs(0,n,h);
  cout<<ans<<endl;
  return 0;
}