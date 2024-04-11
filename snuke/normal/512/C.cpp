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
inline int in() { int x; scanf("%d", &x); return x; }
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 205, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int di[] = {-1,0,1,0}, dj[] = {0,-1,0,1}; //^<v>

// Max flow
struct Maxflow {
  int n;
  vector<int> to, lim, next, head, dist, it;
  Maxflow(){}
  Maxflow(int n):n(n),head(n,-1),it(n){}
  void addEdge(int a, int b, int c=1) {
    next.push_back(head[a]); head[a] = to.size(); to.push_back(b); lim.push_back(c);
    next.push_back(head[b]); head[b] = to.size(); to.push_back(a); lim.push_back(0); 
  }
  void addEdge2(int a, int b, int c=1) {
    next.push_back(head[a]); head[a] = to.size(); to.push_back(b); lim.push_back(c);
    next.push_back(head[b]); head[b] = to.size(); to.push_back(a); lim.push_back(c); 
  }
  void bfs(int sv){
    dist = vector<int>(n,INF);
    queue<int> q;
    dist[sv] = 0; q.push(sv);
    while(!q.empty()){
      int v = q.front(); q.pop();
      for(int i = head[v]; i != -1; i = next[i]) {
        if(lim[i] && dist[to[i]] == INF){
          dist[to[i]] = dist[v]+1; q.push(to[i]);
        }
      }
    }
  }
  int dfs(int v, int tv, int nf=INF){
    if(v == tv) return nf;
    for(; it[v] != -1; it[v] = next[it[v]]){
      int u = to[it[v]], f;
      if(!lim[it[v]] || dist[v] >= dist[u]) continue;
      if(f = dfs(u, tv, min(nf, lim[it[v]])), f){
        lim[it[v]] -= f;
        lim[it[v]^1] += f;
        return f;
      }
    }
    return 0;
  }
  int solve(int sv, int tv){
    int flow = 0, f;
    while(1){
      bfs(sv);
      if(dist[tv] == INF) return flow;
      rep(i,n) it[i] = head[i];
      while(f = dfs(sv,tv), f) flow += f;
    }
  }
};
//

// Eratosthenes' sieve
vector<int> ps; vector<bool> pf;
void sieve(int mx){
	pf.resize(mx+1); fill(rng(pf),true); pf[0] = pf[1] = false;
	for(ll i = 2; i <= mx; i++){
		if(!pf[i]) continue;
		ps.pb(i);
		for(ll j = i*i; j <= mx; j+=i) pf[j] = false;
	}
}
//
int n;
int a[MX], b[MX], ai, bi;
int ax[MX], bx[MX];

bool used[MX];
int g[MX][MX];

vi d;
void dfs(int v, int p);
void efs(int v, int p) {
  d.pb(v);
  rep(i,n) {
    if (i == p) continue;
    if (g[i][v] == 0) {
      dfs(i,v);
      return;
    }
  }
}
void dfs(int v, int p) {
  if (used[v]) return;
  used[v] = true;
  d.pb(v);
  rep(i,n) {
    if (i == p) continue;
    if (g[v][i] == 0) {
      efs(i,v);
      return;
    }
  }
}

int main(){
  cin >> n;
  rep(i,n) {
    int x;
    cin >> x;
    if (x&1) {
      ax[ai] = i+1;
      a[ai++] = x;
    } else {
      bx[bi] = i+1;
      b[bi++] = x;
    }
  }
  if (ai != bi) {
    puts("Impossible");
    return 0;
  }
  n = ai;
  Maxflow mf(n*2+2);
  sieve(20005);
  int sv = n*2, tv = sv+1;
  rep(i,n) mf.addEdge(sv,i,2);
  rep(i,n)rep(j,n) g[i][j] = -1;
  rep(i,n)rep(j,n){
    if (pf[a[i]+b[j]]) {
      g[i][j] = mf.to.size();
      mf.addEdge(i,n+j);
    }
  }
  rep(i,n) mf.addEdge(n+i,tv,2);
  if (mf.solve(sv,tv) != n*2) {
    puts("Impossible");
    return 0;
  }
  vector<vi> ans;
  rep(i,n)rep(j,n){
    if (g[i][j] == -1) continue;
    if (mf.lim[g[i][j]] == 0) {
      g[i][j] = 0;
    } else g[i][j] = -1;
  }
  //cout << "ok" << endl;
  rep(i,n) {
    if (used[i]) continue;
    d.clear();
    dfs(i,-1);
    ans.pb(vi());
    rep(j,d.size()) {
      if (j&1) {
        ans.back().pb(bx[d[j]]);
      } else {
        ans.back().pb(ax[d[j]]);
      }
    }
  }
  cout << ans.size() << endl;
  rep(i,ans.size()) {
    cout << ans[i].size();
    rep(j,ans[i].size()) {
      cout << " " << ans[i][j];
    }
    cout << endl;
  }
  return 0;
}