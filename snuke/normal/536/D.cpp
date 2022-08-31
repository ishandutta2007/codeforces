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
#include <cctype>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rrep(i,n) for(int i = 1; i <= n; ++i)
#define drep(i,n) for(int i = n-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi& a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 2005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int di[] = {-1,0,1,0}, dj[] = {0,-1,0,1}; //^<v>
//I64d
// Dijkstra
struct Dijk {
  typedef ll TT;
  const TT TINF = LINF;
  struct dat {
    TT d; int v;
    bool operator<(const dat& a)const{return d>a.d;}
  };
  int n;
  vector< vector<dat> > to;
  Dijk(int n):n(n),to(n){}
  void add(int a, int b, TT c) {
    to[a].pb((dat){c,b}); to[b].pb((dat){c,a});
  }
  vector<TT> dist; vi pre;
  void solve(int sv) {
    dist = vector<TT>(n,TINF); pre = vi(n,-1);
    priority_queue<dat> q;
    dist[sv] = 0;
    q.push((dat){0,sv});
    while (q.size()) {
      dat a = q.top(); q.pop();
      TT d = a.d; int v = a.v;
      if (dist[v] > d) continue;
      rep(i,to[v].size()) {
        int u = to[v][i].v;
        TT nd = d+to[v][i].d;
        if (nd < dist[u]) {
          dist[u] = nd;
          q.push((dat){nd,u});
        }
      }
    }
  }
};
//

int n, m, s[2];
int p[MX];
int g[MX][MX];
int dv[2][MX];
vi d[2][MX]; int ds[2];
ll dp[MX][MX][2][2];

int up;
ll calc(int i, int j) {
  up = 0;
  ll res = 0;
  for (int x : d[0][i]) {
    if (dv[1][x] < j) continue;
    up = 1;
    res += p[x];
  }
  return res;
}
ll calc2(int i, int j) {
  up = 0;
  ll res = 0;
  for (int x : d[1][j]) {
    if (dv[0][x] < i) continue;
    up = 1;
    res += p[x];
  }
  return res;
}

ll dfs(int i, int j, int k, int l) {
  if (i >= ds[0] || j >= ds[1]) return 0;
  if (dp[i][j][k][l] != -LINF) return dp[i][j][k][l];
  ll res = -LINF;
  if (k == 0) {
    ll ap = calc(i,j);
    maxs(res,dfs(i+1,j,k,l|up)+ap);
    if (l) maxs(res,-dfs(i,j,k^1,0));
  } else {
    ll ap = calc2(i,j);
    maxs(res,dfs(i,j+1,k,l|up)+ap);
    if (l) maxs(res,-dfs(i,j,k^1,0));
  }
  return dp[i][j][k][l] = res;
}

int main(){
  scanf("%d%d%d%d",&n,&m,&s[0],&s[1]);
  rep(i,2) s[i]--;
  rep(i,n) scanf("%d",&p[i]);
  rep(i,n)rep(j,n) g[i][j] = INF;
  rep(i,m) {
    int a, b, w;
    scanf("%d%d%d",&a,&b,&w);
    a--; b--;
    if (a > b) swap(a,b);
    if (a == b) continue;
    mins(g[a][b],w);
  }
  Dijk dijk(n);
  rep(i,n)rep(j,n) if (g[i][j] != INF) {
    dijk.add(i,j,g[i][j]);
  }
  rep(k,2){
    dijk.solve(s[k]);
    {
      map<ll,int> mp;
      rep(i,n) mp[dijk.dist[i]] = 0;
      int mi = 0;
      for (auto it = mp.begin(); it != mp.end(); ++it) {
        it->se = mi++;
      }
      ds[k] = sz(mp);
      rep(i,n) d[k][mp[dijk.dist[i]]].pb(i);
      rep(i,n) dv[k][i] = mp[dijk.dist[i]];
    }
  }
  rep(i,ds[0]+1)rep(j,ds[1]+1)rep(k,2)rep(l,2) dp[i][j][k][l] = -LINF;
  ll res = dfs(0,0,0,0);
  if (res < 0) puts("Cry");
  if (res == 0) puts("Flowers");
  if (res > 0) puts("Break a heart");
  return 0;
}