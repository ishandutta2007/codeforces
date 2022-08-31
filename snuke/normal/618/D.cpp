#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <numeric>
#include <cctype>
#include <bitset>
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
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define df(x) int x = in()
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 200005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

int n, x, y;
vi to[MX];

vi dp[MX];

void dfs(int v, int p=-1) {
  dp[v] = vi(3);
  for (int u : to[v]) if (u != p) {
    dfs(u,v);
    vi d = dp[v];
    dp[v] = vi(3);
    rep(i,3)rep(j,2) {
      if (i+j >= 3) continue;
      maxs(dp[v][i+j], d[i]+dp[u][j]+j);
    }
  }
  vi d = dp[v];
  dp[v] = {max(d[0],max(d[1],d[2])), max(d[0],d[1])};
}

int main() {
  scanf("%d%d%d",&n,&x,&y);
  rep(i,n-1) {
    int a, b;
    scanf("%d%d",&a,&b);
    --a; --b;
    to[a].pb(b);
    to[b].pb(a);
  }
  if (x > y) {
    ll ans = (ll)y*(n-1);
    rep(i,n) {
      if (sz(to[i]) == n-1) {
        ans += (x-y);
        break;
      }
    }
    cout<<ans<<endl;
    return 0;
  }
  dfs(0);
  int as = dp[0][0];
  ll ans = (ll)x*as+(ll)y*(n-1-as);
  cout<<ans<<endl;
  return 0;
}