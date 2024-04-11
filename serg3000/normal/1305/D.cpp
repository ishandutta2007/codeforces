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
#define int long long
int n;
vector<vector<int>>g;
vector<int>dist;
vector<int>used, ch, par;
void cl() {
	for (int i = 0; i < n; i++) {
		dist[i] = -1;
		par[i] = -1;
		used[i] = -1;
	}
}
void dfs(int v, int pred = -1) {
	if (ch[v] == 0) {
		if (pred != -1) {
			dist[v] = dist[pred] + 1;
		}
		for (auto u : g[v]) {
			if (dist[u] == -1) {
				dfs(u, v);
			}
		}
		
	}
}
void dfs2(int v, int m, int pred = -1) {
	if (ch[v] == 0) {
		if (pred != -1) {
			dist[v] = dist[pred] + 1;
		}
		for (auto u : g[v]) {
			if (dist[u] == -1) {
				par[u] = v;
				dfs2(u, m, v);
			}
		}
	}
}
signed main() {
	cin >> n;
	g.resize(n);
	dist.resize(n, -1);
	par.resize(n);
	ch.resize(n);
	used.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int l = 0;
	int ans = 0;
	for (int q = 0; q < n / 2; q++) {
		cl();
		dist[l] = 0;
		dfs(l);
		int ma = -1, ima = 0;
		for (int i = 0; i < n; i++) {
			if (ma < dist[i]) {
				ima = i;
				ma = dist[i];
			}
		}
		cl();
		dist[ima] = 0;
		dfs(ima);
		l = ima;
		ma = -1, ima = 0;
		for (int i = 0; i < n; i++) {
			if (ma < dist[i]) {
				ima = i;
				ma = dist[i];
			}
		}
		cout << "? " << l + 1 << " " << ima + 1 << '\n';
		cout.flush();
		int m;
		cin >> m;
		m--;
		cl();
		dist[l] = 0;
		int m2 = m;
		dfs2(l, m);
		while (m2 != l && par[m2] != -1) {
			ch[par[m2]] = 1;
			m2 = par[m2];
		}
		cl();
		int m3 = m;
		dfs2(ima, m);
		while (m3 != ima) {
			if (par[m3] != -1) {
				ch[par[m3]] = 1;
				m3 = par[m3];
			}
			else {
				break;
			}
		}
		ans = m;
		l = m;
	}
	cout << "! " << ans + 1;
	return 0;
}