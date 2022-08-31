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
typedef pair<int,int> P;

const int MX = 85, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v


int n, m;

// Min cost flow
// Dijkstra
// Graph
struct edge{
	int next, to, co, lim;
	edge(){}
	edge(int next, int to, int co=0, int lim=1):next(next),to(to),co(co),lim(lim){}
};
struct graph{
	vector<int> head; vector<edge> e; int es, vs;
	graph(){}
	graph(int vsz, int esz){ head.resize(vsz); e.resize(esz+1); init(vsz);}
	void init(int vsz){ es = 0; vs = vsz; rep(i,vsz) head[i] = -1;}
	void add(int from, int to, int co=0, int lim=1){ e[es] = edge(head[from],to,co,lim); head[from] = es++;}
	void add2(int from, int to, int co=0, int lim=1){ add(from,to,co,lim); add(to,from,co,lim);}
	void addf(int from, int to, int co=0, int lim=1){ add(from,to,co,lim); add(to,from,-co,0);}
};
//
vector<int> dist, prev;
void dijk(graph& ng, int sv, vector<int>& ndist){
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
int mincost(graph& ng, int sv, int tv, int flow){
	int res = 0, f;
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

int f[MX][MX];

int main(){
	scanf("%d%d",&n,&m);
	int s = n*m, a, b, ni, nj, c, d, t = s+1;
	rep(i,n)rep(j,m) scanf("%d",&f[i][j]);
	graph g(MX*MX,MX*MX*10);
	rep(i,n)rep(j,m){
		c = (i+j&1);
		rep(v,4){
			ni = i+dx[v];
			nj = j+dy[v];
			if(ni<0||nj<0||ni>=n||nj>=m) continue;
			if(f[i][j] == f[ni][nj]) d = 0; else d = 1;
			a = i*m+j;
			b = ni*m+nj;
			if(c) swap(a,b);
			g.addf(a,b,d);
		}
		a = i*m+j;
		if(c) g.addf(a,t); else g.addf(s,a);
	}
	
	printf("%d\n",mincost(g,s,t,s/2));
	
	return 0;
}