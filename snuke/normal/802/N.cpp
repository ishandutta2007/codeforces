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
const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

// Min cost flow
// !! Be care of double and INF !!
struct Mincost {
  typedef ll TC;
  typedef int TL;
  typedef pair<TC,int> TP;
  struct Edge {
    int to, nxt; TC co; TL lim;
    Edge(){}
    Edge(int to, int nxt, TC co, TL lim):to(to),nxt(nxt),co(co),lim(lim){}
  };
  int n;
  vi head, pre; vector<TC> dist;
  vector<Edge> e;
  Mincost(int n):n(n),head(n,-1) {}
  void add(int f, int t, TC c=0, TL l=1) {
    e.pb(Edge(t,head[f],c,l)); head[f] = sz(e)-1;
    e.pb(Edge(f,head[t],-c,0)); head[t] = sz(e)-1;
  }
  void dijk(int sv){
    dist = vector<TC>(n,INF); // INF !!
    pre = vi(n,-1);
    priority_queue<TP, vector<TP>, greater<TP>> q;
    int v; TC d;
    q.push(TP(0,sv));
    dist[sv] = 0;
    while (sz(q)) {
      d = q.top().fi; v = q.top().se; q.pop();
      if (dist[v] != d) continue;
      for (int i = head[v]; i != -1; i = e[i].nxt) {
        int u = e[i].to;
        if (e[i].lim && d+e[i].co < dist[u]) { // double !!
          dist[u] = d+e[i].co;
          pre[u] = i^1;
          q.push(TP(dist[u],u));
        }
      }
    }
  }
  TC solve(int sv, int tv, TL flow) {
    TC res = 0; TL f;
    while (flow>0) {
      dijk(sv);
      if (dist[tv] == INF) return -1; // (double) INF !!
      rep(i,n)for (int j = head[i]; j != -1; j = e[j].nxt) {
        e[j].co += dist[i] - dist[e[j].to];
      }
      f = flow;
      for (int i = tv; i != sv; i = e[pre[i]].to) f = min(f,e[pre[i]^1].lim);
      for (int i = tv; i != sv; i = e[pre[i]].to) {
        e[pre[i]^1].lim -= f, e[pre[i]].lim += f;
      }
      res += dist[tv]*flow; flow -= f;
    }
    return res;
  }
};
//



int main() {
  int n,m;
  scanf("%d%d",&n,&m);
  vi a(n), b(n);
  cin>>a>>b;

  int sv = n*2, tv = sv+1;
  Mincost g(tv+1);
  rep(i,n) {
    g.add(sv,i,a[i],1);
  }
  rep(i,n) {
    g.add(i,n+i,0,1);
  }
  rep(i,n-1) {
    g.add(n+i,n+i+1,0,m);
  }
  rep(i,n) {
    g.add(n+i,tv,b[i],1);
  }
  cout<<g.solve(sv,tv,m)<<endl;
  return 0;
}