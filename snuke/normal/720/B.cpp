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
#include <cassert>
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
#define dame { puts("0"); return 0;}
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,vector<T>,greater<T> >
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}
template<typename T>istream& operator>>(istream&i,vector<T>&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(vector<T>&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,vector<T>&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

// Max flow
struct Maxflow {
  int n;
  vector<int> to, lim, next, head, dist, it;
  Maxflow(){}
  Maxflow(int n):n(n),head(n,-1),it(n){}
  void add(int a, int b, int c=1) {
    next.push_back(head[a]); head[a] = to.size(); to.push_back(b); lim.push_back(c);
    next.push_back(head[b]); head[b] = to.size(); to.push_back(a); lim.push_back(0); 
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

int n, m;
vvi to, co;
vi used, vs, es;
vvi g;

void dfs(int v, int p=-1) {
  used[v] = 1;
  rep(i,sz(to[v])) {
    int u = to[v][i];
    if (u == p) continue;
    if (used[u]) {
      if (used[u] == 1) {
        g.pb(vi(1,co[v][i]));
        for (int i = sz(vs)-1;; --i) {
          g.back().pb(es[i]); es[i] = -1;
          if (vs[i] == u) break;
        }
      }
    } else {
      vs.pb(v); es.pb(co[v][i]);
      dfs(u,v);
      if (es.back() != -1) g.pb(vi(1,es.back()));
      vs.pop_back(); es.pop_back();
    }
  }
  used[v] = 2;
}

int main() {
  scanf("%d%d",&n,&m);
  to = co = vvi(n);
  rep(i,m) {
    int a, b, c;
    scanf("%d%d%d",&a,&b,&c);
    --a; --b; --c;
    to[a].pb(b); co[a].pb(c);
    to[b].pb(a); co[b].pb(c);
  }
  used = vi(n);
  dfs(0);
  int l = sz(g), sv = m+l, tv = sv+1;
  Maxflow mf(tv+1);
  rep(i,m) mf.add(sv,i);
  rep(i,l) mf.add(m+i,tv,max(1,sz(g[i])-1));
  rep(i,l) {
    for (int j : g[i]) mf.add(j,m+i);
  }
  cout<<mf.solve(sv,tv)<<endl;
  return 0;
}