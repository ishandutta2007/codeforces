#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
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
const int MX = 200005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;
const int M = 1000000000;

// Max flow
// !! Be care of double and INF !!
struct Maxflow {
  typedef int TT;
  int n;
  vi to, next, head, dist, it;
  vector<TT> lim;
  Maxflow(){}
  Maxflow(int n):n(n),head(n,-1),it(n){}
  void add(int a, int b, TT c=1) {
    next.pb(head[a]); head[a] = sz(to); to.pb(b); lim.pb(c);
    next.pb(head[b]); head[b] = sz(to); to.pb(a); lim.pb(0); 
  }
  // void add2(int a, int b, int c=1) {
  //   next.pb(head[a]); head[a] = sz(to); to.pb(b); lim.pb(c);
  //   next.pb(head[b]); head[b] = sz(to); to.pb(a); lim.pb(c); 
  // }
  void bfs(int sv) {
    dist = vi(n,INF); // INF !!
    queue<int> q;
    dist[sv] = 0; q.push(sv);
    while (!q.empty()){
      int v = q.front(); q.pop();
      for (int i = head[v]; i != -1; i = next[i]) {
        if (lim[i] && dist[to[i]] == INF) { // double INF !!
          dist[to[i]] = dist[v]+1; q.push(to[i]);
        }
      }
    }
  }
  TT dfs(int v, int tv, TT nf=INF) { // INF !!
    if (v == tv) return nf;
    for (; it[v] != -1; it[v] = next[it[v]]) {
      int u = to[it[v]]; TT f;
      if (!lim[it[v]] || dist[v] >= dist[u]) continue;
      if (f = dfs(u, tv, min(nf, lim[it[v]])), f) { // double !!
        lim[it[v]] -= f;
        lim[it[v]^1] += f;
        return f;
      }
    }
    return 0;
  }
  int solve(int sv, int tv) {
    TT flow = 0, f;
    while (1) {
      bfs(sv);
      if (dist[tv] == INF) return flow; // INF !!
      rep(i,n) it[i] = head[i];
      while (f = dfs(sv,tv), f) flow += f;
    }
  }

  vi used;
  set<P> get(int v) {
    used = vi(n);
    queue<int> q;
    used[v] = 1; q.push(v);
    while (sz(q)) {
      v = q.front(); q.pop();
      for (int i = head[v]; i != -1; i = next[i]) {
        int u = to[i];
        if (!lim[i]) continue;
        if (used[u]) continue;
        used[u] = 1; q.push(u);
      }
    }
    set<P> res;
    rep(v,n) {
      if (!used[v]) continue;
      for (int i = head[v]; i != -1; i = next[i]) {
        int u = to[i];
        if (used[u]) continue;
        if (i%2 == 0) res.insert(P(v,u));
      }
    }
    return res;
  }
};
//

int main() {
  int n,m,sv,tv;
  scanf("%d%d%d%d",&n,&m,&sv,&tv);
  --sv; --tv;
  vvi es;
  rep(i,m) {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    --a; --b;
    es.pb({a,b,c});
  }

  // bool up = true;
  // while (up) {
  //   up = false;
  //   vi ind(n);
  //   vi oud(n);
  //   ind[sv] = oud[tv] = 1;
  //   rep(i,m) {
  //     int a = es[i][0];
  //     int b = es[i][1];
  //     int c = es[i][2];
  //     if (!c) continue;
  //     ind[b] = 1;
  //     oud[a] = 1;
  //   }
  //   rep(i,m) {
  //     int a = es[i][0];
  //     int b = es[i][1];
  //     int c = es[i][2];
  //     if (!c) continue;
  //     if (!ind[a] || !oud[b]) {
  //       es[i][2] = 0;
  //       up = true;
  //     }
  //   }
  //   assert(!up);
  // }


  Maxflow g(n);
  rep(i,m) {
    int a = es[i][0];
    int b = es[i][1];
    int c = es[i][2];
    g.add(a,b,c?1:INF);
    if (c) g.add(b,a,INF);
  }
  int ans = g.solve(sv,tv);

  set<P> mc = g.get(sv);
  // for (P p : mc) cout<<p<<endl;
  assert(sz(mc) == ans);

  rep(i,m) {
    int a = es[i][0];
    int b = es[i][1];
    if (mc.count(P(a,b))) {
      es[i][2] = -1;
    }
  }

  vi x(m);
  vvi pre(n,vi(n,INF));
  vvi nxt(n,vi(n,INF));

  {
    vvi to(n), id(n);
    rep(i,m) {
      int a = es[i][0];
      int b = es[i][1];
      int c = es[i][2];
      if (!c) continue;
      to[a].pb(b); id[a].pb(i);
    }
    rep(r,n) {
      queue<int> q;
      pre[r][r] = -1;
      q.push(r);
      while (sz(q)) {
        int v = q.front(); q.pop();
        rep(i,sz(to[v])) {
          int u = to[v][i];
          if (pre[r][u] != INF) continue;
          pre[r][u] = id[v][i];
          q.push(u);
        }
      }
    }
  }
  {
    vvi to(n), id(n);
    rep(i,m) {
      int a = es[i][0];
      int b = es[i][1];
      int c = es[i][2];
      if (!c) continue;
      to[b].pb(a); id[b].pb(i);
    }
    rep(r,n) {
      queue<int> q;
      nxt[r][r] = -1;
      q.push(r);
      while (sz(q)) {
        int v = q.front(); q.pop();
        rep(i,sz(to[v])) {
          int u = to[v][i];
          if (nxt[r][u] != INF) continue;
          nxt[r][u] = id[v][i];
          q.push(u);
        }
      }
    }
  }

  rep(i,m) {
    int a = es[i][0];
    int b = es[i][1];
    int c = es[i][2];
    if (!c) continue;
    if (x[i]) continue;
    bool done = false;
    {
      int j = i;
      int r = sv;
      if (pre[b][a] != INF) r = b, done = true;
      while (j != -1) {
        x[j]++;
        j = pre[r][es[j][0]];
      }
    }
    if (!done) {
      int j = i;
      int r = tv;
      while (j != -1) {
        x[j]++;
        j = nxt[r][es[j][1]];
      }
      x[i]--;
    }
  }

  printf("%d\n",ans);

  rep(i,m) {
    int c = es[i][2];
    if (c) {
      if (c == -1) printf("%d %d\n",x[i],x[i]);
      else printf("%d %d\n",x[i],M);
    } else {
      printf("%d %d\n",0,M);
    }
  }
  return 0;
}