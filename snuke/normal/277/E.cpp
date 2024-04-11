#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<map>
#include<set>
#include<bitset>
#include<iostream>
#include<sstream>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define each(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define pb push_back
#define snuke srand((unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<double,int> P;

const int MX = 405, mod = 1000000009;
const double INF = 2000000000, eps = 0.0000001;
const ll LINF = 1000000000000000000ll;

// Min cost flow
// Dijkstra
// Graph
struct edge{
	int next, to; double co; int lim;
	edge(){}
	edge(int next, int to, double co=0, int lim=1):next(next),to(to),co(co),lim(lim){}
};
struct graph{
	vector<int> head; vector<edge> e; int es, vs;
	graph(){}
	graph(int vsz, int esz){ head.resize(vsz); e.resize(esz+1); init(vsz);}
	void init(int vsz){ es = 0; vs = vsz; rep(i,vsz) head[i] = -1;}
	void add(int from, int to, double co=0, int lim=1){ e[es] = edge(head[from],to,co,lim); head[from] = es++;}
	void add2(int from, int to, double co=0, int lim=1){ add(from,to,co,lim); add(to,from,co,lim);}
	void addf(int from, int to, double co=0, int lim=1){ add(from,to,co,lim); add(to,from,-co,0);}
};
//
vector<double> dist; vector<int> prev;
void dijk(graph& ng, int sv, vector<double>& ndist){
	ndist.resize(ng.vs); fill(rng(ndist),INF); prev.resize(ng.vs); fill(rng(prev),-1);
	priority_queue<P, vector<P>, greater<P> > q;
	P p; int v; ng.e[ng.es].to = sv; q.push(P(0,ng.es));
	while(!q.empty()){
		p = q.top(); q.pop(); v = ng.e[p.se].to;
		if(prev[v] != -1) continue;
		ndist[v] = p.fi; prev[v] = p.se^1;
		for(int i = ng.head[v]; i != -1; i = ng.e[i].next)
			if(ng.e[i].lim > 0 && p.fi+ng.e[i].co < ndist[ng.e[i].to]){
				ndist[ng.e[i].to] = p.fi+ng.e[i].co; q.push(P(p.fi+ng.e[i].co,i));}
	}
}
//
double mincost(graph& ng, int sv, int tv, int flow){
	double res = 0; int f;
	while(flow>0){
		dijk(ng,sv,dist);
		if(dist[tv] == INF) return -1;
		rep(i,ng.vs)for(int j = ng.head[i]; j != -1; j = ng.e[j].next)
			ng.e[j].co += dist[i] - dist[ng.e[j].to];
		f = flow;
		for(int i = tv; i != sv; i = ng.e[prev[i]].to) mins(f,ng.e[prev[i]^1].lim);
		for(int i = tv; i != sv; i = ng.e[prev[i]].to)
			ng.e[prev[i]^1].lim -= f, ng.e[prev[i]].lim += f;
		res += dist[tv]*flow; flow -= f;
	}
	return res;
}
//

int x[MX], y[MX];

int main(){
	int n, dx, dy, s, t;
	scanf("%d",&n);
	graph g(n*2+5,n*n+n*4+10);
	
	rep(i,n) scanf("%d%d",&x[i],&y[i]);
	
	rep(i,n)rep(j,n){
		if(y[i] <= y[j]) continue;
		dx = x[i]-x[j]; dy = y[i]-y[j];
		g.addf(j,i+n,sqrt(dx*dx+dy*dy));
	}
	
	s = n*2; t = s+1;
	rep(i,n) g.addf(s,i,0);
	rep(i,n) g.addf(i+n,t,0,2);
	
	double ans = mincost(g,s,t,n-1);
	
	if(ans == -1){ puts("-1"); return 0;}
	printf("%.8f\n",ans);
	
	return 0;
}