#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const long long INF = 1000000000000000LL;

class MaximumFlow {
	int s, f;
public:
	struct edge {
		int u, v;
		long long capacity, flow;
		edge() { u = v = capacity = flow = 0;}
		edge(int u_, int v_, long long capacity_, long long flow_) :
		  u(u_), v(v_), capacity(capacity_), flow(flow_) {}
	};

	vector <edge> edges;
	vector <vector <int> > graph;
	vector <int> ptr, level;
	queue <int> q;
	int n;

	MaximumFlow() {}

	MaximumFlow(int number) {
		n = number;
		graph.resize(n);
		ptr.assign(n, 0);
		level.resize(n);
	}

	void addEdge(int u, int v, long long capacity) {
		int sz = (int)(edges.size());
		edges.push_back(edge(u, v, capacity, 0));
		edges.push_back(edge(v, u, 0, 0));
		graph[u].push_back(sz);
		graph[v].push_back(sz + 1);
	}

	void updateLevels() {
		level.assign(n, -1);
		q.push(s);
		level[s] = 0;
		while (!q.empty()) {
			int topq = q.front();
			q.pop();
			for (int index = 0; index < graph[topq].size(); ++index) {
				int i = graph[topq][index];
				int to = edges[i].v;
				if (edges[i].capacity - edges[i].flow == 0) {
					continue;
				}
				if (level[to] == -1) {
					level[to] = level[topq] + 1;
					q.push(to);
				}
			}
		}
	}

	long long pushFlow(int v, long long flow) {
		if (v == f || flow == 0) {
			return flow;
		}
		for (; ptr[v] < graph[v].size(); ++ptr[v]) {
			int index = graph[v][ptr[v]];
			int to = edges[index].v;
			if (level[v] + 1 == level[to]) {
				int pushed = pushFlow(to, min(flow, edges[index].capacity - edges[index].flow));
				if (pushed > 0) {
					edges[index].flow += pushed;
					edges[index ^ 1].flow -= pushed;
					return pushed;
				}
			}
		}
		return 0;
	}

	long long dinicFlow(int start, int finish) {
		s = start, f = finish;
		long long result = 0;
		while (true) {
			updateLevels();
			if (level[f] == -1) {
				break;
			}
			while (true) {
				long long pushed = pushFlow(start, INF);
				if (pushed == 0) {
					break;
				}
				result += pushed;
			}
			ptr.assign(n, 0);
		}
		return result;
	}
};

const int maxN = 110;
int a[maxN];
vector < pair < int, int > > b[maxN];
int start[maxN];
int n, m;

vector < pair < int, int > > factor(int n) {
	vector < pair < int, int > > res;
	int m = n;
	int i = 2;
	while (i * i <= n) {
		int q = 0;
		while (n % i == 0) {
			++q;
			n /= i;
		}
		if (q > 0) {
			res.push_back(make_pair(i, q));
		}
		++i;
	}
	if (n > 1) {
		res.push_back(make_pair(n, 1));
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	int pos = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		start[i] = pos;
		b[i] = factor(a[i]);
		pos += b[i].size();
	}

	MaximumFlow F(pos + 2);
	int s = pos;
	int t = pos + 1;
	
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) {
			for (int j = 0; j < b[i].size(); ++j) {
				F.addEdge(s, start[i] + j, b[i][j].second);
			}
		} else {
			for (int j = 0; j < b[i].size(); ++j) {
				F.addEdge(start[i] + j, t, b[i][j].second);
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		if (u % 2 != 0) {
			swap(u, v);
		}
		for (int x = 0; x < b[u].size(); ++x) {
			for (int y = 0; y < b[v].size(); ++y) {
				if (b[u][x].first == b[v][y].first) {
					F.addEdge(start[u] + x, start[v] + y, min(b[u][x].second, b[v][y].second));
				}
			}
		}
	}

	int res = F.dinicFlow(s, t);
	printf("%d\n", res);
	
	return 0;
}