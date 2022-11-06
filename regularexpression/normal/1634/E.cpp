#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int M = 1e5 + 7;
const int N = 2e5 + 5;

int m;
int n[M];
vector <int> a[M];
vector <int> id[M];
vector <int> arr;
vector <pair <int, int> > g[M + N];
int ans[N], lol = 0;
bool vis[M + N], used[N];

void dfs(int v) {
	vis[v] = true;
	while (!g[v].empty()) {
		int ind = g[v].back().second;
		int to = g[v].back().first;
		g[v].pop_back();
		if (!used[ind]) {
			used[ind] = true;
			dfs(to);
			ans[ind] = lol;
			lol ^= 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> m;
	int kek = 0;
	for (int i = 0; i < m; ++i) {
		cin >> n[i];
		a[i].resize(n[i]);
		id[i].resize(n[i]);
		for (int j = 0; j < n[i]; ++j) {
			cin >> a[i][j];
			id[i][j] = kek++;
			arr.push_back(a[i][j]);
		}
	}
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n[i]; ++j) {
			a[i][j] = lower_bound(arr.begin(), arr.end(), a[i][j]) - arr.begin();
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n[i]; ++j) {
			g[i].push_back({a[i][j] + m, id[i][j]});
			g[a[i][j] + m].push_back({i, id[i][j]});
		}
	}
	for (int i = 0; i < m + arr.size(); ++i) {
		if (g[i].size() & 1) {
			cout << "NO" << endl;
			return 0;
		}
	}
	for (int i = 0; i < m + arr.size(); ++i) {
		if (!vis[i]) {
			dfs(i);
		}
	}
	cout << "YES\n";
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n[i]; ++j) {
			cout << (ans[id[i][j]] ? "L" : "R");
		}
		cout << "\n";
	}
	return 0;
}