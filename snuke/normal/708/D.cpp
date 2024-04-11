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
typedef pair<ll,int> P;
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

/*
// Min cost flow
struct Mincost {
  struct Edge{
    int to, co, lim, nxt;
    Edge(){}
    Edge(int to, int co, int lim, int nxt):to(to),co(co),lim(lim),nxt(nxt){}
  };
  int n;
  vector<int> head, dist, pre;
  vector<Edge> e;
  Mincost(int n):n(n),head(n,-1),dist(n),pre(n){}
  void add(int f, int t, int c=0, int l=1){
    // if (!c) cout<<f<<" "<<t<<" "<<l<<endl;
    e.push_back(Edge(t,c,l,head[f])); head[f] = e.size()-1;
    e.push_back(Edge(f,-c,0,head[t])); head[t] = e.size()-1;
  }
  void dijk(int sv){
    fill(dist.begin(),dist.end(),INF);
    fill(pre.begin(),pre.end(),-1);
    priority_queue<P, vector<P>, greater<P> > q;
    int v, d;
    q.push(P(0,sv));
    dist[sv] = 0;
    while(!q.empty()){
      d = q.top().fi; v = q.top().se; q.pop();
      if(dist[v] != d) continue;
      for(int i = head[v]; i != -1; i = e[i].nxt){
        int u = e[i].to;
        if(e[i].lim && d+e[i].co < dist[u]){
          dist[u] = d+e[i].co;
          pre[u] = i^1;
          q.push(P(dist[u],u));
        }
      }
    }
  }
  ll solve(int sv, int tv, int flow){
    ll res = 0; int f;
    while(flow>0){
      dijk(sv);
      if(dist[tv] == INF) assert(false);
      rep(i,n)for(int j = head[i]; j != -1; j = e[j].nxt){
        e[j].co += dist[i] - dist[e[j].to];
      }
      f = flow;
      for(int i = tv; i != sv; i = e[pre[i]].to) f = min(f,e[pre[i]^1].lim);
      for(int i = tv; i != sv; i = e[pre[i]].to){
        e[pre[i]^1].lim -= f, e[pre[i]].lim += f;
      }
      res += (ll)dist[tv]*flow; flow -= f;
    }
    return res;
  }
};
/*/
// Min cost flow
struct Mincost {
  struct Edge{
    int to; ll co, lim; int nxt;
    Edge(){}
    Edge(int to, ll co, ll lim, int nxt):to(to),co(co),lim(lim),nxt(nxt){}
  };
  int n;
  vector<int> head, pre; vl dist;
  vector<Edge> e;
  Mincost(int n):n(n),head(n,-1),pre(n),dist(n){}
  void add(int f, int t, ll c=0, ll l=1){
    // cout<<f<<" "<<t<<" "<<c<<" "<<l<<endl;
    e.push_back(Edge(t,c,l,head[f])); head[f] = e.size()-1;
    e.push_back(Edge(f,-c,0,head[t])); head[t] = e.size()-1;
  }
  void dijk(int sv){
    fill(dist.begin(),dist.end(),LINF);
    fill(pre.begin(),pre.end(),-1);
    priority_queue<P, vector<P>, greater<P> > q;
    int v; ll d;
    q.push(P(0,sv));
    dist[sv] = 0;
    while(!q.empty()){
      d = q.top().fi; v = q.top().se; q.pop();
      if(dist[v] != d) continue;
      for(int i = head[v]; i != -1; i = e[i].nxt){
        int u = e[i].to;
        if(e[i].lim && d+e[i].co < dist[u]){
          dist[u] = d+e[i].co;
          pre[u] = i^1;
          q.push(P(dist[u],u));
        }
      }
    }
  }
  ll solve(int sv, int tv, ll flow){
    ll res = 0; ll f;
    while(flow>0){
      dijk(sv);
      if(dist[tv] == LINF) assert(false);
      rep(i,n)for(int j = head[i]; j != -1; j = e[j].nxt){
        e[j].co += dist[i] - dist[e[j].to];
      }
      f = flow;
      for(int i = tv; i != sv; i = e[pre[i]].to) f = min(f,(ll)e[pre[i]^1].lim);
      for(int i = tv; i != sv; i = e[pre[i]].to){
        e[pre[i]^1].lim -= f, e[pre[i]].lim += f;
      }
      res += dist[tv]*flow; flow -= f;
    }
    return res;
  }
};
//
//*/

int n, m;
vvi to, co, f;

int main() {
  scanf("%d%d",&n,&m);
  to = co = f = vvi(n);
  rep(i,m) {
    int a, b, c, d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    --a; --b;
    to[a].pb(b); co[a].pb(c); f[a].pb(d);
  }
  int sv = n, tv = n+1;
  Mincost g(n+2);
  vl x(n);
  ll ans = 0;
  rep(v,n) {
    rep(i,sz(to[v])) {
      int u = to[v][i], c = co[v][i], d = f[v][i];
      if (c < d) {
        x[v] += c; x[u] -= c;
        ans += d-c;
        g.add(v,u,0,d-c);
        g.add(v,u,2,INF);
        g.add(u,v,1,c);
      } else {
        x[v] += d; x[u] -= d;
        g.add(v,u,1,c-d);
        g.add(v,u,2,INF);
        g.add(u,v,1,d);
      }
    }
  }
  g.add(0,n-1,0,INF);
  g.add(n-1,0,0,INF);
  ll flow = 0;
  ll dif = x[0]+x[n-1];
  if (dif < 0) {
    g.add(sv,n-1,0,-dif);
  } else {
    flow += dif;
    g.add(0,tv,0,dif);
  }
  rrep(v,n-2) {
    if (x[v] > 0) {
      flow += x[v];
      g.add(v,tv,0,x[v]);
    }
    if (x[v] < 0) {
      g.add(sv,v,0,-x[v]);
    }
  }
  ll res = g.solve(sv, tv, flow);
  // cout<<ans<<" "<<res<<" "<<flow<<endl;
  // rep(i,sz(g.e)) if (i&1) {
  //   if (g.e[i].lim) {
  //     cout<<g.e[i].to<<" "<<g.e[i^1].to<<" "<<g.e[i].lim<<endl;
  //   }
  // }
  ans += res;
  cout<<ans<<endl;
  return 0;
}