#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
struct edge { int v, w; };
const int INF = INT_MAX / 2;
const int MOD = 1e9 + 7;

int main() {
	int N, M; cin >> N >> M;
	vector<int> type(N);
	rep(u, N) scanf("%d", &type[u]);
	vector<vector<int>> G(N);
	vector<int> indeg(N);
	while (M--) {
		int u, v; scanf("%d%d", &u, &v);
		G[u].pb(v), indeg[v]++;
	}
	vector<queue<int>> q(2);
	rep(u, N) if (!indeg[u]) q[type[u]].push(u);
	int ans = 0;
	for (;;) {
		while (q[0].size()) {
			int u = q[0].front(); q[0].pop();
			for (int v: G[u]) {
				indeg[v]--;
				if (!indeg[v]) q[type[v]].push(v);
			}
		}
		if (q[1].empty()) break;
		ans++;
		while (q[1].size()) {
			int u = q[1].front(); q[1].pop();
			for (int v: G[u]) {
				indeg[v]--;
				if (!indeg[v]) q[type[v]].push(v);
			}
		}
	}
	cout << ans << endl;
}