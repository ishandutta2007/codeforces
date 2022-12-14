// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)

const int N = 3005, mod = 0;

int d[N][N], mark[N], q[N];
vector<int> adj[N];

void bfs(int source, int dis[N]) {
	rep(i, N) dis[i] = -1e6;
	int h = 0, t = 0;
	memset(mark, 0, sizeof mark);
	mark[source] = 1;
	dis[source] = 0;
	q[t++] = source;
	while (h != t) {
		int v = q[h++];
		for (int u : adj[v]) if (!mark[u]++) {
			dis[u] = dis[v] + 1;
			q[t++] = u;
		}
	}
}

pair<int, int> top[2][N][6];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	rep(x, 2) rep(i, n) rep(j, 6) top[x][i][j] = make_pair(-1e6, -1);
	rep(e, m) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
	}
	rep(i, n)
		bfs(i, d[i]);
	rep(x, 2) rep(v, n) {
		rep(u, n)
			if (u != v)
				top[x][v][3] = make_pair(d[x? v: u][x? u: v], u), sort(top[x][v], top[x][v] + 4), reverse(top[x][v], top[x][v] + 4);
	}
	int best = -1;
	vector<int> res(4);
	rep(p2, n)
		rep(p3, n) if (p2 != p3) {
			rep(i, 3) if (p3 != top[0][p2][i].second)
				rep(j, 3) if (p2 != top[1][p3][j].second && top[0][p2][i].second != top[1][p3][j].second) {
					int val = d[p2][p3] + top[0][p2][i].first + top[1][p3][j].first;
					if (val >= best) {
						res[0] = top[0][p2][i].second;
						res[1] = p2;
						res[2] = p3;
						res[3] = top[1][p3][j].second;
						best = val;

					}
				}
		}
	cerr << best << '\n';
	cerr << d[1][0] << ' ' << d[0][7] << ' ' << d[7][6] << endl;
	for (int x : res)	
		cout << x + 1 << ' ';
	return 0;
}