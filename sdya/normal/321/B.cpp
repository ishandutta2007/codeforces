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

const int INF = 1000*1000*1000;

struct rib {
	int b, u, c, f;
	size_t back;
};

void add_rib (vector < vector<rib> > & g, int a, int b, int u, int c) {
	rib r1 = { b, u, c, 0, g[b].size() };
	rib r2 = { a, 0, -c, 0, g[a].size() };
	g[a].push_back (r1);
	g[b].push_back (r2);
}

pair < int, int > solve(vector < vector < rib > > g, int s, int t, bool br = true, int k = INF) {
	int n = g.size();
	int flow = 0, cost = 0;
	while (flow < k) {
		vector<int> id (n, 0);
		vector<int> d (n, INF);
		vector<int> q (n);
		vector<int> p (n);
		vector<size_t> p_rib (n);
		int qh=0, qt=0;
		q[qt++] = s;
		d[s] = 0;
		while (qh != qt) {
			int v = q[qh++];
			id[v] = 2;
			if (qh == n)  qh = 0;
			for (size_t i=0; i<g[v].size(); ++i) {
				rib & r = g[v][i];
				if (r.f < r.u && d[v] + r.c < d[r.b]) {
					d[r.b] = d[v] + r.c;
					if (id[r.b] == 0) {
						q[qt++] = r.b;
						if (qt == n)  qt = 0;
					}
					else if (id[r.b] == 2) {
						if (--qh == -1)  qh = n-1;
						q[qh] = r.b;
					}
					id[r.b] = 1;
					p[r.b] = v;
					p_rib[r.b] = i;
				}
			}
		}
		if (d[t] == INF)  break;
		int addflow = k - flow;
		for (int v=t; v!=s; v=p[v]) {
			int pv = p[v];  size_t pr = p_rib[v];
			addflow = min (addflow, g[pv][pr].u - g[pv][pr].f);
		}
		int addcost = 0;
		for (int v=t; v!=s; v=p[v]) {
			int pv = p[v];  size_t pr = p_rib[v],  r = g[pv][pr].back;
			g[pv][pr].f += addflow;
			g[v][r].f -= addflow;
			addcost += g[pv][pr].c * addflow;
		}
		if (addcost > 0 && br) {
			break;
		}
		cost += addcost;
		flow += addflow;
	}
	return make_pair(flow, cost);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;
	vector < vector < rib > > g(max(n, m) + max(n, m) + 2);
	vector < vector < rib > > h(max(n, m) + max(n, m) + 2);
	vector < int > mode(n), a(n);
	vector < int > b(m);
	int u = 2 * max(n, m);
	int v = u + 1;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s >> a[i];
		if (s == "ATK") {
			mode[i] = 0;
		} else {
			mode[i] = 1;
		}
		add_rib(g, max(n, m) + i, v, 1, 0); 
		add_rib(h, max(n, m) + i, v, 1, 0);
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
		add_rib(g, u, i, 1, 0);
		add_rib(h, u, i, 1, 0);
	}

	for (int i = n; i < m; ++i) {
		add_rib(h, max(n, m) + i, v, 1, 0);
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (mode[j] == 0) {
				if (b[i] >= a[j]) {
					add_rib(g, i, max(n, m) + j, 1, a[j] - b[i]);
					add_rib(h, i, max(n, m) + j, 1, a[j] - b[i]);
				}
			} else {
				if (b[i] > a[j]) {
					add_rib(g, i, max(n, m) + j, 1, 0);
					add_rib(h, i, max(n, m) + j, 1, 0);
				}
			}
		}
		for (int j = n; j < m; ++j) {
			add_rib(h, i, max(n, m) + j, 1, -b[i]);
		}
	}

	int value = solve(g, u, v).second;
	int res = -value;

	pair < int, int > t = solve(h, u, v, false);
	if (t.first == m) {
		res = max(res, - t.second);
	}
	printf("%d\n", res);


	return 0;
}