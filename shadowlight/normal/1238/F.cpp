#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n;
vector <vector <int> > gr;
vector <int> dp;

int res;

void dfs(int v, int p) {
	vector <int> sons;
	for (int u : gr[v]) {
		if (u == p) continue;
		dfs(u, v);
		sons.push_back(dp[u]);
	}
	sort(sons.rbegin(), sons.rend());
	if (sons.size() >= 2) {
		res = max(res, sons[0] + sons[1] + (int) (sons.size() - 2) + 1 + (p != -1));
	}
	if (!sons.size()) {
		dp[v] = 1;
	} else {
		dp[v] = sons[0] + (int) (sons.size() - 1) + 1;
	}
	res = max(res, dp[v]);
}

void solve() {
	gr.clear();
	dp.clear();
	res = 0;
	cin >> n;
	gr.resize(n);
	dp.resize(n, 0);

	for (int i = 1; i < n; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		gr[v].push_back(u);
		gr[u].push_back(v);
	}
	dfs(0, -1);
	cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		solve();
	}

}