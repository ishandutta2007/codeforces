#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 1e5 + 10;
int n, m, k;
vector<int> g[MAXN];

void read() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

bool used[MAXN];
int h[MAXN];
int p[MAXN];

void dfs(int v) {
	used[v] = true;
	for (auto i : g[v]) {
		if (used[i]) continue;
		h[i] = h[v] + 1;
		p[i] = v;
		dfs(i);
	}
}

void SolveTree() {
	vector<int> ans;
	int cnt0 = 0;
	for (int i = 0; i < n; i++) {
		cnt0 += h[i] % 2 == 0;
	}
	if (cnt0 >= (k + 1) / 2) {
		for (int i = 0; i < n; i++) {
			if (h[i] % 2 == 0) {
				ans.push_back(i);
			}
		}
	} else {
		for (int i = 0; i < n; i++) {
			if (h[i] % 2 == 1) {
				ans.push_back(i);
			}
		}
	}
	while (ans.size() > (k + 1) / 2) ans.pop_back();
	cout << 1 << endl;
	for (auto i : ans)
		cout << i + 1 << " ";
	cout << endl;
	exit(0);
}

void solve(int v, int u) {
	if (h[v] - h[u] + 1 <= k) {
		vector<int> ans;
		int now = v;
		while (now != u) {
			ans.push_back(now);
			now = p[now];
		//	cout << "now = " << now << endl;
		}
		ans.push_back(u);
		assert(ans.size() <= k);
		cout << 2 << endl;
		cout << ans.size() << endl;
		for (auto i : ans) {
			cout << i + 1 << " ";
		}
		cout << endl;
	} else {
		vector<int> ans;
		int now = v;
		int it = 0;
		while (now != u) {
			if (!it) {
				ans.push_back(now);
			} 
			now = p[now];
			it ^= 1;
		}
		while (ans.size() > (k + 1) / 2) {
			ans.pop_back();
		}
		assert(ans.size() == (k + 1) / 2);
		cout << 1 << endl;
		for (auto i : ans) 
			cout << i + 1 << " ";
		cout << endl;
	}
	exit(0);
}

void run() {
	dfs(0);
	p[0] = -1;
	if (m == n - 1) {
		SolveTree();
	}
	/*
	cout << "h = " << endl;
	for (int i = 0; i < n; i++) {
		cout << h[i] << " ";
	}
	cout << endl;
	cout << "p = " << endl;
	for (int i = 0; i < n; i++) {
		cout << p[i] << " ";
	}
	cout << endl;*/
	int ansV = -1, ansU = -1;
	for (int v = 1; v < n; v++) {
		for (auto u : g[v]) {
			if (abs(h[v] - h[u]) <= 1) continue;
			if (h[u] > h[v]) continue;
			if (ansV == -1 || h[ansV] - h[ansU] > h[v] - h[u]) {
				ansV = v;
				ansU = u;
			}
		}
	}
	assert(ansV != -1);
	solve(ansV, ansU);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	return 0;
}