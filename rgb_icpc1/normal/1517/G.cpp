#include<bits/stdc++.h>
 
using namespace std;
 
typedef pair<int ,int> pii;
 
typedef long long t_flow;
 
struct Dinic {
	struct edge {
		int to, rev;
		long long cap;
		edge(int to = 0, int rev = 0, long long cap = 0) : to(to), rev(rev), cap(cap) {}
	};
	vector <vector <edge>> g;
	vector <vector <edge> :: iterator> nowi;
	vector <long long> dist;
	int nodes, src, dst;
	queue <int> q;
	void init(int _nodes) {
		nodes = _nodes;
		g.resize(_nodes);
		nowi.resize(_nodes);
		for(int i = 0; i < _nodes; i ++) g[i].clear();
		dist.resize(_nodes);
	}
	int add_node() {
		g.resize(nodes + 1);
		nowi.resize(nodes + 1);
		g[nodes].clear();
		dist.resize(nodes + 1);
		return nodes++;
	}
	void add_edge(int _from, int _to, long long _cap) {
		g[_from].push_back(edge(_to, g[_to].size(), _cap));
		g[_to].push_back(edge(_from, g[_from].size() - 1, 0));
	}
	bool dinic_bfs() {
		fill(dist.begin(), dist.end(), -1);
		dist[src] = 0;
		q.push(src);
		while(!q.empty()) {
			int u = q.front(); q.pop();
			for(int i = 0; i < g[u].size(); i ++) {
				edge e = g[u][i];
				if(e.cap) {
					int v = e.to;
					if(dist[v] < 0) dist[v] = dist[u] + 1, q.push(v);
				}
			}
		}
		return dist[dst] >= 0;
	}
	long long dinic_dfs(int u, long long f) {
		if(u == dst) return f;
		long long ret = 0;
		for(vector<edge>::iterator &it = nowi[u]; it != g[u].end(); it ++) if(it->cap) {
			int v = it->to;
			if(dist[v] == dist[u] + 1) {
				int tmp = dinic_dfs(v, min(f, it->cap));
				it->cap -= tmp, f -= tmp, ret += tmp, g[v][it->rev].cap += tmp;
				if(!f) return ret;
			}
		}
		return ret;
	}
	t_flow max_flow(int _src, int _dst) {
		src = _src, dst = _dst;
		t_flow flow = 0;
		while(dinic_bfs()) {
			for(int i = 0; i < nodes; i ++) nowi[i] = g[i].begin();
			flow += dinic_dfs(_src, 1e9);
		}
		return flow;
	}
}Flow;
 
map<pii, int> mp;
 
int n, x[1005], y[1005], w[1005];
int dx[9][3] = {{1, 1, 0}, {0, -1, -1}, {-1, -1, 0}, {0, 1, 1}, {-1, 0, 1}, {1, 0, -1}, {1, 0, -1}, {-1, 0, 1}};
int dy[9][3] = {{0, 1, 1}, {1, 1, 0}, {0, -1, -1}, {-1, -1, 0}, {0, 1, 1}, {0, 1, 1}, {0, -1, -1}, {0, -1, -1}};
long long rlt;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i =0 ; i < n ; i ++) {
		cin >> x[i] >> y[i] >> w[i];
		mp[pii(x[i], y[i])] = i;
		rlt += w[i];
	}
	Flow.init(2 * n + 2);
	for (int i = 0; i < n; i ++) Flow.add_edge(i, i + n, w[i]);
	Flow.src = n * 2;
	Flow.dst = n * 2 + 1;
	for (int i = 0; i < n; i ++) {
		if (x[i] % 2 || y[i] % 2) continue;
		for (int d = 0; d < 8; d ++) {
			int ip[5], ok = 0, xx, yy;
			for (int id = 0; id < 3; id ++) {
				xx = x[i] + dx[d][id];
				yy = y[i] + dy[d][id];
				if (mp.count(pii(xx, yy))) {
					if (yy == y[i])ip[0] = mp[pii(xx, yy)];
					else if(xx == x[i])ip[2] = mp[pii(xx, yy)];
					else ip[3] = mp[pii(xx, yy)];
				}
				else ok = 1;
			}
			if (ok) continue;
			ip[1] = i;
			int nw = Flow.add_node();
			Flow.add_edge(Flow.src, ip[0], 10000000000ll);
			for (int i = 0; i < 3; i ++) Flow.add_edge(ip[i] + n, ip[i + 1], 10000000000ll);
			Flow.add_edge(ip[3] + n, Flow.dst, 10000000000ll);
		}
	}
	cout << rlt - Flow.max_flow(n * 2, n * 2 + 1) << endl;
	return 0;
}