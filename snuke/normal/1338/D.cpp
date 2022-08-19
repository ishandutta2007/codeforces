#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cerr<<#x<<" = "<<x<<endl;
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
int getInt(){int x;scanf("%d",&x);return x;}
template<typename T>istream& operator>>(istream&i,v(T)&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v){stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const v(T)&v){if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.fi<<","<<v.se;}
template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}
template<typename T>bool maxs(T& x,const T&y){if(x<y){x=y;return true;}else return false;}
template<typename T>ll suma(const v(T)&a){ll res(0);for(auto&&x:a)res+=x;return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;

struct Solver {
  vvi to;
  int n;
  int ans = 0;
  vi dfs(int v, int p=-1) {
    int deg = sz(to[v]);
    vi dp(2);
    vi ds = {1,1}, es = {0,0};
    for (int u : to[v]) {
      if (u == p) continue;
      vi d = dfs(u,v);
      maxs(dp[0], d[1]+1);
      maxs(dp[1], d[0]+deg-2);
      ds.pb(d[0]);
      es.pb(d[1]);
    }
    sort(rrng(ds));
    sort(rrng(es));
    maxs(ans, ds[0]+ds[1]+deg-2);
    maxs(ans, es[0]+es[1]+1);
    maxs(dp[0], 1);
    maxs(dp[1], deg-1);
    maxs(dp[0],dp[1]);
    maxs(ans,dp[0]);
    return dp;
  }
  void solve() {
    scanf("%d",&n);
    to = vvi(n);
    rep(i,n-1) {
      int a, b;
      scanf("%d%d",&a,&b);
      --a; --b;
      to[a].pb(b);
      to[b].pb(a);
    }
    dfs(0);
    cout<<ans<<endl;
  }
};

int main() {
  int ts = 1;
  // scanf("%d",&ts);
  rrep(ti,ts) {
    Solver solver;
    solver.solve();
  }
  return 0;
}