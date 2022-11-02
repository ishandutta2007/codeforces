#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
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

const int maxN = 210;
int n, a[maxN];

bool isPrime(int n) {
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

vector < int > g[maxN];
bool used[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	MaximumFlow F(n + 2);
	int s = n;
	int t = n + 1;
	for (int i = 0; i < n; ++i) {
		if (a[i] % 2 == 0) {
			F.addEdge(s, i, 2);
		} else {
			F.addEdge(i, t, 2);
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[i] % 2 == 0 && a[j] % 2 != 0 && isPrime(a[i] + a[j])) {
				F.addEdge(i, j, 1);
			}
		}
	}

	int res = F.dinicFlow(s, t);
	if (res != n) {
		printf("Impossible\n");
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < F.graph[i].size(); ++j) {
			int index = F.graph[i][j];
			if (F.edges[index].flow > 0 && F.edges[index].v < n) {
				g[i].push_back(F.edges[index].v);
				g[F.edges[index].v].push_back(i);
			}
		}
	}

	vector < vector < int > > path;
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			continue;
		}
		vector < int > current;
		int j = i;
		while (true) {
			current.push_back(j);
			used[j] = true;

			int nj = -1;
			for (int k = 0; k < g[j].size(); ++k) {
				if (!used[g[j][k]]) {
					nj = g[j][k];
					break;
				}
			}
			if (nj == -1) {
				break;
			}
			j = nj;
		}
		path.push_back(current);
	}
	printf("%d\n", path.size());
	for (int i = 0; i < path.size(); ++i) {
		printf("%d", path[i].size());
		for (int j = 0; j < path[i].size(); ++j) {
			printf(" %d", path[i][j] + 1);
		}
		printf("\n");
	}

	return 0;
}