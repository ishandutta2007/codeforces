#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
vector<int> tsort(vector<vector<int> > &G) {
	int n = G.size();
	vector<int> ret, vis(n);
	function<bool(int)> dfs = [&](int v) {
		vis[v] = true;
		for (auto &e : G[v]) if (!vis[e] && !dfs(e)) return false;
		ret.push_back(v);
		return true;
	};
	for (int i = 0; i < n; i++) if (!vis[i] && !dfs(i)) return{};
	reverse(ret.begin(), ret.end());
	return ret;
}
int n, m, x, a, b, c;
int main() {
	cin >> n >> m >> x;
	vector<vector<int> > G(n), W(n);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c; a--, b--;
		G[a].push_back(b);
		W[a].push_back(c);
	}
	vector<int> t = tsort(G);
	vector<vector<long long> > dp(n, vector<long long>(n + 1, 1LL << 60));
	vector<vector<short> > pre(n, vector<short>(n + 1, -1));
	for (int i : t) {
		if (i == 0) dp[i][0] = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < G[i].size(); k++) {
				if (dp[G[i][k]][j + 1] > dp[i][j] + W[i][k]) {
					dp[G[i][k]][j + 1] = dp[i][j] + W[i][k];
					pre[G[i][k]][j + 1] = i;
				}
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (dp[n - 1][i] <= x) ret = i;
	}
	cout << ret + 1 << endl;
	int pos = n - 1;
	vector<int> r; r.push_back(pos);
	while (ret > 0) {
		pos = pre[pos][ret--];
		r.push_back(pos);
	}
	reverse(r.begin(), r.end());
	for (int i = 0; i < r.size(); i++) {
		if (i) cout << ' ';
		cout << r[i] + 1;
	}
	cout << endl;
	return 0;
}