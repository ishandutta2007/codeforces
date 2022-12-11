#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef int_fast64_t ll;

void start() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

bool check(string& s, int n) {
	for (int i = 0; i < n; ++i) {
		if (s[i] != s[i + n]) {
			return false;
		}
	}
	return true;
}

vector<int> bfs(vector<vector<int>>& a, int v) {
	vector<int> res(a.size(), 1e9);
	res[v] = 0;
	queue<int> q;
	q.push(v);
	while (!q.empty()) {
		v = q.front();
		for (int i = 0; i < a[v].size(); ++i) {
			int u = a[v][i];
			if (res[u] > res[v] + 1) {
				res[u] = res[v] + 1;
				q.push(u);
			}
		}
		q.pop();
	}
	return res;
}

int main() {
	start();
	int n, m;
	cin >> n >> m;
	int s, t;
	cin >> s >> t;
	--s;
	--t;
	vector<vector<int>> a(n);
	vector<vector<bool>> used(n, vector<bool>(n));
	vector<vector<int>> dist(n);
	for (int i = 0; i < m; ++i) {
		int v, u;
		cin >> v >> u;
		a[v - 1].push_back(u - 1);
		a[u - 1].push_back(v - 1);
		used[v - 1][u - 1] = used[u - 1][v - 1] = true;
	}
	for (int i = 0; i < n; ++i) {
		dist[i] = bfs(a, i);
	}
	int res = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (!used[i][j] && (dist[s][t] <= dist[s][i] + 1 + dist[j][t] && dist[s][t] <= dist[s][j] + 1 + dist[i][t])) {
				++res;
			}
		}
	}
	cout << res;

	return 0;
}