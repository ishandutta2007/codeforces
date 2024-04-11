#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cctype>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rrep(i,n) for (int i = 1; i <= n; ++i)
#define drep(i,n) for (int i = n-1; i >= 0; --i)
#define df(x) int x = in()
#define sz(x) int(x.size())
#define fi first
#define se second
#define rng(x) x.begin(),x.end()
#define pb push_back
#define dame {puts("No"); return 0;}
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
using namespace std;
inline int in() { int x; scanf("%d",&x); return x;}
typedef long long ll;
typedef pair<int,int> P;
typedef vector<P> vp;
typedef vector<int> vi;
typedef vector<string> vs;

const int MX = 3005;
const int INF = 1001001001;

struct Mincost {
  typedef int TC;
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
    dist = vector<TC>(n,INF);
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
        if (e[i].lim && d+e[i].co < dist[u]) {
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
      if (dist[tv] == INF) return -1;
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

int main() {
	df(n);
	df(s); df(t);
	vp a(n);
	rep(i,n) a[i].fi = in();
	rep(i,n) a[i].se = in();
	int sv = n+2, tv = sv+1;
	Mincost mc(tv+1);
	rep(i,n) mc.add(i,n,MX-a[i].fi);
	rep(i,n) mc.add(i,n+1,MX-a[i].se);
	rep(i,n) mc.add(sv,i);
	mc.add(n,tv,0,s);
	mc.add(n+1,tv,0,t);
	int ans = MX*(s+t)-mc.solve(sv,tv,s+t);
	cout << ans << endl;
	int id = 0;
	vi as;
	rep(i,n) {
		if (!mc.e[id].lim) {
			as.pb(i+1);
		}
		id += 2;
	}
	rep(i,sz(as)) printf("%d%c", as[i], i==sz(as)-1?'\n':' ');
	as = vi();
	rep(i,n) {
		if (!mc.e[id].lim) {
			as.pb(i+1);
		}
		id += 2;
	}
	rep(i,sz(as)) printf("%d%c", as[i], i==sz(as)-1?'\n':' ');
	return 0;
}