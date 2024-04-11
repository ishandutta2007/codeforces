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

const int INF = 1000000000;

class MaximumFlow {
	int s, f;
public:
	struct edge {
		int u, v;
		int capacity, flow;
		edge() { u = v = capacity = flow = 0;}
		edge(int u_, int v_, int capacity_, int flow_) :
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

	void addEdge(int u, int v, int capacity) {
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

	int pushFlow(int v, int flow) {
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

	int dinicFlow(int start, int finish) {
		s = start, f = finish;
		int result = 0;
		while (true) {
			updateLevels();
			if (level[f] == -1) {
				break;
			}
			while (true) {
				int pushed = pushFlow(start, INF);
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

const int maxN = 25;
int n, m, male, female;
string s[maxN];
int r[2 * maxN * maxN], c[2 * maxN * maxN], t[2 * maxN * maxN];

int d[maxN][maxN][maxN][maxN];
int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};

bool isValid(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m && s[x][y] == '.';
}

void calc(int d[maxN][maxN], int u, int v) {
	memset(d, -1, sizeof(d));
	d[u][v] = 0;
	queue < pair < int, int > > q;
	q.push(make_pair(u, v));
	while (!q.empty()) {
		pair < int, int > p = q.front();
		q.pop();
		int x = p.first;
		int y = p.second;
		for (int i = 0; i < 4; ++i) {
			if (isValid(x + dx[i], y + dy[i]) && d[x + dx[i]][y + dy[i]] == -1) {
				d[x + dx[i]][y + dy[i]] = d[x][y] + 1;
				q.push(make_pair(x + dx[i], y + dy[i]));
			}
		}
	}
}

bool check(long long value) {
	{
		MaximumFlow F(male + female + 1 + 2 * n * m + 2);
		int start = male + female + 1 + 2 * n * m;
		int finish = start + 1;
		for (int i = (male < female ? 0 : 1); i <= male; ++i) {
			for (int x = 0; x < n; ++x) {
				for (int y = 0; y < m; ++y) {
					if (d[r[i]][c[i]][x][y] == -1) {
						continue;
					}
					if ((long long)(d[r[i]][c[i]][x][y]) * (long long)(t[i]) <= value) {
						F.addEdge(i, male + female + 1 + x * m + y, 1);
					}
				}
			}
			F.addEdge(start, i, 1);
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (isValid(i, j)) {
					F.addEdge(male + female + 1 + i * m + j, male + female + 1 + n * m + i * m + j, 1);
				}
			}
		}
		for (int i = 0; i <= male + female; ++i) {
			if (i < male + 1) {
				if (female < male && i == 0) {
				} else {
					continue;
				}
			}
			for (int x = 0; x < n; ++x) {
				for (int y = 0; y < m; ++y) {
					if (d[r[i]][c[i]][x][y] == -1) {
						continue;
					}
					if ((long long)(d[r[i]][c[i]][x][y]) * (long long)(t[i]) <= value) {
						F.addEdge(male + female + 1 + n * m + x * m + y, i, 1);
					}
				}
			}
			F.addEdge(i, finish, 1);
		}
		return F.dinicFlow(start, finish) == (male + female + 1) / 2;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m >> male >> female;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	cin >> r[0] >> c[0] >> t[0];
	--r[0];
	--c[0];
	for (int i = 1; i <= male; ++i) {
		cin >> r[i] >> c[i] >> t[i];
		--r[i];
		--c[i];
	}
	for (int i = male + 1; i <= male + female; ++i) {
		cin >> r[i] >> c[i] >> t[i];
		--r[i];
		--c[i];
	}

	memset(d, -1, sizeof(d));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (isValid(i, j)) {
				calc(d[i][j], i, j);
			}
		}
	}

	if (male + 1 != female && male != female + 1) {
		cout << -1 << endl;
		return 0;
	}

	long long left_bound = 0, right_bound = 1000000000000LL;
	if (!check(right_bound)) {
		cout << -1 << endl;
		return 0;
	}
	while (right_bound - left_bound > 1) {
		long long middle = (left_bound + right_bound) / 2;
		if (check(middle)) {
			right_bound = middle;
		} else {
			left_bound = middle;
		}
	}

	if (check(left_bound)) {
		cout << left_bound << endl;
	} else {
		cout << right_bound << endl;
	}

	return 0;
}