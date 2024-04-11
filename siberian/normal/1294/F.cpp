#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 2e5 + 10;
vector<int> g[MAXN];
int n;

void read() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

int par[MAXN];

pair<int, int> dfs(int v, int p) {
	par[v] = p;
	pair<int, int> ans = {0, v};
	for (auto i : g[v]) {
		if (i == p) continue;
		auto x = dfs(i, v);
		x.first++;
		chkmax(ans, x);
	}
	return ans;
}

int ans;
vector<int> fans;
int dist[MAXN];
bool used[MAXN];

void bfs() {
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (used[i]) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto i : g[v]) {
			if (used[i]) continue;
			dist[i] = dist[v] + 1;
			used[i] = true;
			q.push(i);
		}
	}
}

void run() {
	int v = dfs(0, 0).second;
	int u = dfs(v, -1).second;
	int x = u;
	while (x != v) {
		used[x] = true;
		x = par[x];
		ans++;
	}
	used[v] = true;
	bfs();
	pair<int, int> z = {0, 0};
	for (int i = 0; i < n; i++) {
		if (u == i || v == i) continue;
		chkmax(z, make_pair(dist[i], i));
	}
	ans += z.first;
	fans = {v, u, z.second};
}

void write() {
	cout << ans << endl;
	for (auto i : fans)
		cout << i + 1 << " ";
	cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}