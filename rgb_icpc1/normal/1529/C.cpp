#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
long long l[N], r[N];
vector<int> con[N];
int n;
long long dp[N][2];

void dfs(int u, int p) {
	dp[u][0] = dp[u][1] = 0LL;
	for (int v : con[u]) {
		if (v == p) continue;
		dfs(v, u);
		dp[u][1] += max(dp[v][0] + abs(l[v] - r[u]), dp[v][1] + abs(r[v] - r[u]));
		dp[u][0] += max(dp[v][0] + abs(l[v] - l[u]), dp[v][1] + abs(r[v] - l[u]));
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int T; cin >> T;
	while (T --) {
		cin >> n;
		for (int i = 0; i < n; i ++) cin >> l[i] >> r[i];
		for (int i = 0; i < n; i ++) con[i].clear();
		for (int i = 0; i < n - 1; i ++) {
			int u, v; cin >> u >> v;
			u --, v --;
			con[u].push_back(v);
			con[v].push_back(u);
		}
		dfs(0, -1);
		cout << max(dp[0][0], dp[0][1]) << endl;
	}
}