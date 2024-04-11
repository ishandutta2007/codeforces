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

const long long INF = 1000000000000000000LL;

struct rib {
	long long b, u, c, f;
	size_t back;
};

void add_rib (vector < vector<rib> > & g, long long a, long long b, long long u, long long c) {
	rib r1 = { b, u, c, 0, g[b].size() };
	rib r2 = { a, 0, -c, 0, g[a].size() };
	g[a].push_back (r1);
	g[b].push_back (r2);
}

long long solve(vector < vector < rib > > &g, long long s, long long t, long long k = INF) {
	int n = g.size();
	long long flow = 0,  cost = 0;
	while (flow < k) {
		vector<long long> id (n, 0);
		vector<long long> d (n, INF);
		vector<long long> q (n);
		vector<long long> p (n);
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
		long long addflow = k - flow;
		for (int v=t; v!=s; v=p[v]) {
			int pv = p[v];  size_t pr = p_rib[v];
			addflow = min (addflow, g[pv][pr].u - g[pv][pr].f);
		}
		for (int v=t; v!=s; v=p[v]) {
			int pv = p[v];  size_t pr = p_rib[v],  r = g[pv][pr].back;
			g[pv][pr].f += addflow;
			g[v][r].f -= addflow;
			cost += g[pv][pr].c * addflow;
		}
		flow += addflow;
	}
	return cost;
}

const int maxN = 300;
int n, m;
int a[maxN];

int getBits(int n) {
	int res = 0;
	while (n) {
		res += n % 2;
		n /= 2;
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector < vector < rib > > g(2 * n + m + 2);
	int s = 2 * n + m;
	int t = s + 1;

	for (int i = 0; i < m; ++i) {
		add_rib(g, s, 2 * n + i, 1, 0);
		add_rib(g, 2 * n + i, t, 1, 0);
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			add_rib(g, 2 * n + i, 2 * j, 1, getBits(a[j]));
		}
	}

	for (int j = 0; j < n; ++j) {
		add_rib(g, 2 * j, 2 * j + 1, 1, -1000000000LL);
		add_rib(g, 2 * j + 1, t, 1, 0);

		for (int k = j + 1; k < n; ++k) {
			if (a[k] == a[j]) {
				add_rib(g, 2 * j + 1, 2 * k, 1, 0);
			} else {
				add_rib(g, 2 * j + 1, 2 * k, 1, getBits(a[k]));
			}
		}
	}

	long long res = solve(g, s, t);

	vector < pair < int, int > > commands;
	for (int i = 0; i < m; ++i) {
		int start = 2 * n + i, value = -1;
		while (start != t) {
			for (int j = 0; j < g[start].size(); ++j) {
				if (g[start][j].f <= 0) {
					continue;
				}
				int v = g[start][j].b;
				if (v == t || (v < 2 * n && v % 2 == 0)) {
					if (v == t) {
						start = t;
						break;
					}
					if (a[v / 2] != value) {
						commands.push_back(make_pair(v, i));
						value = a[v / 2];
					}
					commands.push_back(make_pair(v + 1, i));
					start = v + 1;
					break;
				}
			}
		}
	}

	sort(commands.begin(), commands.end());
	cout << commands.size() << " " << res + 1000000000LL * (long long)(n) << endl;
	for (int i = 0; i < commands.size(); ++i) {
		int u = commands[i].first;
		int v = commands[i].second;
		if (u % 2 == 0) {
			cout << (char)('a' + v) << "=" << a[u / 2] << endl;
		} else {
			cout << "print(" << (char)('a' + v) << ")" << endl;
		}
	}

	return 0;
}