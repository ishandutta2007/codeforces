#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MX = 200005;

int Tc, N, M;
LL val[MX], valt[MX], dp[MX];
bool chk[MX];
vector<int> adj[MX];

bool DFS(int u, int p) {
	dp[u] = dp[p] + 1;
	chk[u] = 1;
	for (int v : adj[u]) {
		if (v == p) continue;
		if (chk[v]) {
			if ((dp[u] + dp[v]) % 2 == 0) return v;
			continue;
		}
		int tmp = DFS(v, u);
		if (tmp) return tmp;
	}
	return 0;
}

LL DFS_final(int u, int p) {
	chk[u] = 1;
	LL cnt = 0;
	for (int v : adj[u]) {
		if (v == p) continue;
		if (chk[v]) continue;
		cnt += DFS_final(v, u);
	}
	return valt[u] - val[u] - cnt;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("I", "r", stdin);
	freopen("O", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int i, j;
	for (cin >> Tc; Tc--; ) {
		cin >> N >> M;
		for (i = 1; i <= N; i++) cin >> val[i];
		for (i = 1; i <= N; i++) cin >> valt[i];
		for (i = 1; i <= N; i++) adj[i].clear(), chk[i] = 0;
		while (M--) {
			cin >> i >> j;
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
		int pos = DFS(1, 0);
		for (i = 1; i <= N; i++) chk[i] = 0;
		LL tmp;
		if (pos) tmp = DFS_final(pos, 0);
		else tmp = DFS_final(1, 0);
		if (pos) {
			if (tmp % 2) cout << "NO\n";
			else cout << "YES\n";
		} else {
			if (!tmp) cout << "YES\n";
			else cout << "NO\n";
		}
	}

	return 0;

}