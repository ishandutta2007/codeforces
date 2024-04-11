#include<bits/stdc++.h>
using namespace std;

const int maxnodes = 1000;

int nodes = maxnodes, src, dest;
int dist[maxnodes], q[maxnodes], work[maxnodes];
int n, m, x, a[maxnodes], b[maxnodes], c[maxnodes];

struct Edge{
	int to, rev;
	int f, cap;
};

vector <Edge> g[maxnodes];

void Init(){
	for(int i = 0; i < maxnodes; i ++) g[i].clear();
}

void addEdge(int s, int t, int cap){
	Edge a = {t, g[t].size(), 0, cap};
	Edge b = {s, g[s].size(), 0, 0};
	g[s].push_back(a);
	g[t].push_back(b);
}

bool dinic_bfs(){
	fill(dist, dist + nodes, -1);
	dist[src] = 0;
	int qt = 0;
	q[qt ++] = src;
	for(int qh = 0; qh < qt; qh ++){
		int u = q[qh];
		for(int j = 0; j < (int) g[u].size(); j ++){
			Edge &e = g[u][j];
			int v = e.to;
			if(dist[v] < 0 and e.f < e.cap){
				dist[v] = dist[u] + 1;
				q[qt ++] = v;
			}
		}
	}
	return dist[dest] >= 0;
}

int dinic_dfs(int u, int f){
	if(u == dest) return f;
	for(int &i = work[u]; i < (int) g[u].size(); i ++){
		Edge &e = g[u][i];
		if(e.cap <= e.f) continue;
		int v = e.to;
		if(dist[v] == dist[u] + 1){
			int df = dinic_dfs(v, min(f, e.cap - e.f));
			if(df > 0){
				e.f += df;
				g[v][e.rev].f -= df;
				return df;
			}
		}
	}
	return 0;
}

int maxFlow(int _src, int _dest){
	src = _src;
	dest = _dest;
	int result = 0;
	while(dinic_bfs()){
		fill(work, work + nodes, 0);
		while(int delta = dinic_dfs(src, INT_MAX))
		result += delta;
	}
	return result;
}

bool check(double wg){
	Init();
	for(int i = 0; i < m; i ++){
		addEdge(a[i], b[i], (int)min(1.*x, c[i]*wg));
	}
	if(maxFlow(1, n) >= x) return true;
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	//freopen("d2.in", "r", stdin);
	int src, dst;
	cin >> n >> m >> x;
	for(int i = 0; i < m; i ++){
		cin >> a[i] >> b[i] >> c[i];
	}
	double st = 0, en = 1e9, mid;
	bool fg;
	for(int i = 0; i < 100; i ++){
		mid = (st + en) / 2;
		if(check(mid)) en = mid;
		else st = mid;
	}
	printf("%.12lf\n", x / mid);
}