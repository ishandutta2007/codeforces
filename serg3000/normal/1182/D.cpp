#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include<unordered_map>
#include <bitset>
#include <random>
#include <ctime>
using namespace std;
mt19937 rnd(time(NULL));
//#define int long long
vector<vector<int>>g;
vector<int>used, dist, par, sz, la, col;
void dfs(int v) {
	used[v] = true;
	for (auto u : g[v]) {
		if (!used[u]) {
			dist[u] = dist[v] + 1;
			par[u] = v;
			dfs(u);
			sz[v] += sz[u];
			la[v] = la[u];
		}
	}
	if (g[v].size() > 2) {
		sz[v] += 1;
	}
	if (la[v] == -1) {
		la[v] = v;
	}
}
bool check(int c, int n) {
	vector<int>x(n, -1);
	for (int i = 0; i < n; i++) {
		if (x[dist[i]] == -1) {
			x[dist[i]] = g[i].size();
		}
		else {
			if (x[dist[i]] != g[i].size()) {
				return false;
			}
		}
	}
	return true;
}
signed main() {
	int n;
	cin >> n;
	g.resize(n);
	par.resize(n);
	col.resize(n);
	sz.resize(n);
	la.resize(n, -1);
	used.resize(n);
	dist.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int v, u;
		cin >> v >> u;
		v--;
		u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(0);
	int ma = 0;
	int ima = 0;
	for (int i = 0; i < n; i++) {
		if (dist[i] > ma) {
			ma = dist[i];
			ima = i;
		}
	}
	for (int i = 0; i < n; i++) {
		used[i] = 0;
		dist[i] = 0;
		par[i] = -1;
		la[i] = -1;
		sz[i] = 0;
	}
	dfs(ima);
	ma = 0;
	int ima2 = 0;
	for (int i = 0; i < n; i++) {
		if (dist[i] > ma) {
			ma = dist[i];
			ima2 = i;
		}
	}

	if (ma % 2 != 0) {
		if (check(ima, n)) {
			cout << ima + 1;
			return 0;
		}
		else {
			for (int i = 0; i < n; i++) {
				used[i] = 0;
				dist[i] = 0;
				par[i] = -1;
				la[i] = -1;
				sz[i] = 0;
			}
			dfs(ima2);
			if (check(ima2, n)) {
				cout << ima2 + 1;
				return 0;
			}
		}
	}
	else {
		int v = ima2;
		while (dist[v] != ma / 2) {
			v = par[v];
		}
		for (int i = 0; i < n; i++) {
			used[i] = 0;
			dist[i] = 0;
			par[i] = -1;
			la[i] = -1;
			sz[i] = 0;
		}
		dfs(v);
		
		if (check(v, n)) {
			cout << v + 1;
			return 0;
		}
		else {
			int cnt = 0;
			for (auto u : g[v]) {
				if (sz[u] == 0) {
					int x = la[u];
					if (dist[x] != dist[ima]) {
						for (int i = 0; i < n; i++) {
							used[i] = 0;
							dist[i] = 0;
							par[i] = -1;
							la[i] = -1;
							sz[i] = 0;
						}
						dfs(x);
						if (check(x, n)) {
							cout << x + 1;
							return 0;
						}
						for (int i = 0; i < n; i++) {
							used[i] = 0;
							dist[i] = 0;
							par[i] = -1;
							la[i] = -1;
							sz[i] = 0;
						}
						dfs(v);
						
					}
					else {
						if (cnt == 0) {
							int x = la[u];
							if (dist[x] == dist[ima]) {
								for (int i = 0; i < n; i++) {
									used[i] = 0;
									dist[i] = 0;
									par[i] = -1;
									la[i] = -1;
									sz[i] = 0;
								}
								dfs(x);
								if (check(x, n)) {
									cout << x + 1;
									return 0;
								}
								for (int i = 0; i < n; i++) {
									used[i] = 0;
									dist[i] = 0;
									par[i] = -1;
									la[i] = -1;
									sz[i] = 0;
								}
								dfs(v);
							}
							cnt++;
						}
					}
				}
			}
		}
	}
	cout << -1;
	return 0;
}