#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

const int MAXN = 1e6 + 10;
vector<int> g[MAXN];
int n;
bool used[MAXN];
vector<int> ans;

void dfs(int v) {
	used[v] = true;
	for (auto i : g[v]) {
		if (!used[i]) {
			dfs(i);
			return;
		}
	}
	ans.push_back(v);
}

void solve() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int v = 0;
	for (int i = 0; i < n; i++) {
		if (g[i].size() > g[v].size())
			v = i;
	}
	used[v] = true;
	for (auto i : g[v]) {
		dfs(i);
	}
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
	cout << ans.size() << endl;
	for (auto i : ans) {
		cout << v + 1 << " " << i + 1 << endl; 
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}