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
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("vpt")
mt19937 rnd(time(nullptr));
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define firn(i, n) for (int i = 1; i < (int)n; i++)
#define all(v) v.begin(), v.end()
#define int long long
const int mod = 1e9 + 7;
vector<vector<int>>g;
vector<int>used, dist, par, sz;
void dfs(int v) {
	used[v] = 1;
	sz[v] = 1;
	for (auto u : g[v]) {
		if (!used[u]) {
			dist[u] = dist[v] + 1;
			par[u] = v;
			dfs(u);
			sz[v] += sz[u];
		}
	}
}
signed main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	g.resize(n);
	par.resize(n, -1);
	used.resize(n);
	sz.resize(n);
	dist.resize(n, -1);
	forn(i, n - 1) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dist[0] = 0;
	set<pair<int, int>>s;
	dfs(0);
	firn(i, n) {
		if (g[i].size() == 1) {
			s.insert({ -dist[i], i });
		}
	}
	int ans = 0;
	forn(i, k) {
		auto v = *s.begin();
		ans -= v.first;
		s.erase(v);
		s.insert({ -dist[par[v.second]] + sz[par[v.second]] -1, par[v.second] });
	}
	cout << ans;
	return 0;
}