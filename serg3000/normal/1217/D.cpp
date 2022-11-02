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
//#define int long long
using namespace std;
vector < vector<pair<int, int>>>g;
vector<int>used1, used, dist, en;
int ch = 0;
void dfs(int v) {
	used1[v] = 1;
	for (auto u : g[v]) {
		if (!used1[u.first]) {
			dfs(u.first);
		}
		else {
			if (!en[u.first]) {
				ch = 1;
				return;
			}
		}
	}
	en[v] = 1;
}
signed main() {
	int n, m;
	cin >> n >> m;
	g.resize(n);
	used1.resize(n);
	used.resize(n);
	en.resize(n);
	dist.resize(n, -1);
	map<pair<int, int>, int>mp;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back({ b, 0 });
		mp[{a, b}] = i;
	}
	for (int i = 0; i < n; i++) {
		if (!used1[i]) {
			dfs(i);
		}
	}
	if (ch == 0) {
		cout << 1 << '\n';
		for (int i = 0; i < m; i++) {
			cout << 1 << " ";
		}
		return 0;
	}
	for (int e = 0; e < n; e++) {
		queue<int>q;
		q.push(e);
		for (int j = 0; j < n; j++) {
			dist[j] = -1;
		}
		dist[e] = 0;
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (auto u : g[v]) {
				if (dist[u.first] == -1) {
					q.push(u.first);
					dist[u.first] = dist[v] + 1;
				}
			}
		}
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < g[j].size(); i++) {
				if (g[j][i].second == 0) {
					if (dist[g[j][i].first] > dist[j]) {
						g[j][i].second = 1;
					}
					if (dist[g[j][i].first] < dist[j]) {
						g[j][i].second = 2;
					}
				}
			}
		}
	}
	vector<int>ans(m);
	for (int v = 0; v < n; v++) {
		for (auto u : g[v]) {
			ans[mp[{v, u.first}]] = u.second;
		}
	}
	cout << 2 << '\n';
	for (int i = 0; i < m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}