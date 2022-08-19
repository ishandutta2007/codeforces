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
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int di[] = {-1,0,1,0}, dj[] = {0,-1,0,1}; //^<v>

// SCC
struct scc { // n, k, to, d, g
  int n, k;
  vector<vi> to, ot, d; vi g, used, kv;
  scc(int n=0):n(n),to(n),ot(n),d(n),g(n,-1){}
  void addEdge(int a, int b) { to[a].pb(b); ot[b].pb(a);}
  void dfs(int v) {
    if (used[v]) return;
    used[v] = 1;
    rep(i,to[v].size()) dfs(to[v][i]);
    kv[--k] = v;
  }
  void rfs(int v) {
    if (g[v] != -1) return;
    g[v] = k; d[k].pb(v);
    rep(i,ot[v].size()) rfs(ot[v][i]);
  }
  void init() {
    k = n;
    used = kv = vi(n,0);
    rep(i,n) dfs(i);
    rep(i,n) {
      if (g[kv[i]] != -1) continue;
      d.pb(vi());
      rfs(kv[i]);
      k++;
    }
    to.clear(); to.resize(k);
    rep(i,n)rep(j,ot[i].size()) {
      int v = g[ot[i][j]], u = g[i];
      if (v != u) to[v].pb(u);
    }
    rep(i,k) {
      sort(rng(to[i]));
      to[i].erase(unique(rng(to[i])),to[i].end());
    }
    ot.clear(); used.clear(); kv.clear();
    ot.resize(k);
    rep(i,k) {
      for (int u : to[i]) ot[u].pb(i);
    }
  }
  int now;
  int ufs(int v) {
    if (used[v]) return 0;
    used[v] = true;
    int a = d[v].size();
    int res = a;
    now++;
    //printf("%d %d\n",v,a);
    if (a != 1) now += a;
    for (int u : to[v]) res += ufs(u);
    for (int u : ot[v]) res += ufs(u);
    return res;
  }
};
//

bool ud[MX];

int main(){
  int n, m;
  scanf("%d%d",&n,&m);
  scc g(n);
  rep(i,m) {
    int a, b;
    scanf("%d%d",&a,&b);
    a--; b--;
    g.addEdge(a,b);
  }
  g.init();
  int ans = 0;
  rep(i,g.k) g.used[i] = false;
  rep(i,g.k) {
    if (g.used[i]) continue;
    g.now = 0;
    //for(int u : g.to[i]) printf("%d ",u);puts("");
    int x = g.ufs(i);
    ans += min(x,g.now-1);
  }
  cout << ans << endl;
  return 0;
}