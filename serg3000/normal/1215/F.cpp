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
vector<vector<int>>g1;
vector<vector<int>>g2;
vector<int>used, order, comp;
void dfs1(int v) {
	used[v] = true;
	for (auto u : g1[v]) {
		if (!used[u]) {
			dfs1(u);
		}
	}
	order.push_back(v);
}
void dfs2(int v, int c) {
	used[v] = 1;
	comp[v] = c;
	for (auto u : g2[v]) {
		if (!used[u]) {
			dfs2(u, c);
		}
	}
}
int main() {
	int n, p, M, m;
	cin >> n >> p >> M >> m;
	g1.resize(2 * (p + M + 1));
	g2.resize(2 * (p + M + 1));
	used.resize(2 * (p + M + 1));
	comp.resize(2 * (p + M + 1));
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		g1[2 * x + 1].push_back(2 * y);
		g2[2 * y].push_back(2 * x + 1);
		g1[2 * y + 1].push_back(2 * x);
		g2[2 * x].push_back(2 * y + 1);
	}
	vector<int>ll(p);
	for (int i = 0; i < p; i++) {
		int l, r;
		cin >> l >> r;
		ll[i] = l;
		l--; r--;
		g1[2 * i].push_back(2 * p + 2 * l);
		g2[2 * p + 2 * l].push_back(2 * i);
		g1[2 * i].push_back(2 * p + 2 * (r + 1) + 1);
		g2[2 * p + 2 * (r + 1) + 1].push_back(2 * i);
		g1[2 * p + 2 * (r + 1)].push_back(2 * i + 1);
		g2[2 * i + 1].push_back(2 * p + 2 * (r + 1));
		g1[2 * l + 2 * p + 1].push_back(2 * i + 1);
		g2[2 * i + 1].push_back(2 * l + 2 * p + 1);
	}
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g1[2 * u].push_back(2 * v + 1);
		g2[2 * v + 1].push_back(2 * u);
		g1[2 * v].push_back(2 * u + 1);
		g2[2 * u + 1].push_back(2 * v);
	}
	for (int i = p; i < p + M; i++) {
		//g1[2 * i + 1].push_back(2 * i + 2);
		//g2[2 * i + 2].push_back(2 * i + 1);
		//g1[2 * i + 2 + 1].push_back(2 * i);
		//g2[2 * i].push_back(2 * i + 2 + 1);
		g1[2 * i + 2].push_back(2 * i);
		g2[2 * i].push_back(2 * i + 2);
		g1[2 * i + 1].push_back(2 * i + 2 + 1);
		g2[2 * i + 1 + 2].push_back(2 * i + 1);
	}

	int c = 1;
	for (int i = 0; i < 2 * p + 2 * M + 2; i++) {
		if (!used[i]) {
			dfs1(i);
		}
	}
	for (int i = 0; i < 2 * p + 2 * M + 2; i++) {
		used[i] = 0;
	}
	for (int i = 2 * p + 2 * M + 2 - 1; i > -1; i--) {
		if (!used[order[i]]) {
			dfs2(order[i], c);
			c++;
		}
	}
	vector<int>ans;
	for (int i = 0; i < p + M + 1; i++) {
		if (comp[2 * i] == comp[2 * i + 1]) {
			cout << -1;
			return 0;
		}
		else {
			if (i < p) {
				if (comp[2 * i + 1] < comp[2 * i]) {
					ans.push_back(i);
				}
			}
		}
	}
	int k = (int)ans.size();
	int f = 0;
	for (int i = 0; i < k; i++) {
		f = max(ll[ans[i]], f);
	}
	cout << k << " " << f << '\n';
	for (auto u : ans) {
		cout << u + 1 << " ";
	}
	
	return 0;
}