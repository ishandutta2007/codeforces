#include <bits/stdc++.h>
using namespace std;

const int N = 1011;

struct DSU {
	int p[N];
	void init() {
		iota(p, p + N, 0);
	}
	int find(int x) {
		if(p[x] == x) return x;
		return p[x] = find(p[x]);
	}
	bool query(int x, int y) {
		return find(x) == find(y);
	}
	void merge(int x, int y) {
		p[find(x)] = find(y);
	}
}dsu;

int w[N], b[N];
int dp[N][N];

void upd(int &x, int y) {
	if(x < y)
		x = y;
}

void solve(int now, vector <int> &v) {
	//for(int i : v) cout << i << ' '; cout << '\n';
	int sw = 0, sb = 0;
	for(int i : v) {
		sw += w[i];
		sb += b[i];
		for(int j = 0; j < N; j ++) {
			upd(dp[now + 1][j], dp[now][j]);
			if(j + w[i] < N)
				upd(dp[now + 1][j + w[i]], dp[now][j] + b[i]);
		}
	}
	for(int j = 0; j < N; j ++)
		if(j + sw < N)
			upd(dp[now + 1][j + sw], dp[now][j] + sb);
}

int main() {
	ios :: sync_with_stdio(false);
	int n, m, W; cin >> n >> m >> W;
	dsu.init();
	for(int i = 1; i <= n; i ++)
		cin >> w[i];
	for(int i = 1; i <= n; i ++)
		cin >> b[i];
	for(int i = 0; i < m; i ++) {
		int u, v; cin >> u >> v;
		if(!dsu.query(u, v))
			dsu.merge(u, v);
	}
	int now = 0;
	for(int i = 1; i <= n; i ++) if(dsu.find(i) == i) {
		vector <int> v;
		for(int j = 1; j <= n; j ++)
			if(dsu.find(j) == i) v.push_back(j);
		solve(now, v); now ++;
	}
	int ans = 0;
	for(int i = 0; i <= W; i ++)
		ans = max(ans, dp[now][i]);
	cout << ans << '\n';
	return 0;
}