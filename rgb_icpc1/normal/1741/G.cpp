#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long LL;
typedef pair<int, int> pii;

const int MX = 10005;
const int MOD = 1000000007;
vector <int> adj[MX];
queue <int> Q;
int h[MX], p[MX];
int dp[1 << 6], dp_[1 << 6];
int cnt[MX];
int up[MX];
set <int> val[MX];
int vis[MX];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i ++) {
			adj[i].clear();
			val[i].clear();
			up[i] = 0;
			cnt[i] = 0;
		}
		while (m --) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int f;
		cin >> f;
		for (int i = 1; i <= f; i ++) {
			cin >> h[i];
			cnt[h[i]] ++;
		}
		int k;
		cin >> k;
		int tot = 0;
		for (int i = 0; i < k; i ++) {
			cin >> p[i];
			cnt[h[p[i]]] --;
		}
		for (int i = 0; i < k; i ++) {
			up[h[p[i]]] |= (1 << i);
		}
		memset(vis, 0, sizeof vis);
		vis[1] = 1;
		val[1].insert(0);
		Q.push(1);
		while (!Q.empty()) {
			int tp = Q.front();
			Q.pop();
			for (auto v : adj[tp]) {
				if (!vis[v]) {
					vis[v] = vis[tp] + 1;
					for (auto vv : val[tp]) val[v].insert(vv | up[v]), val[v].insert(vv);
					Q.push(v);
				}
				else if (vis[v] == vis[tp] + 1) {
					for (auto vv : val[tp]) val[v].insert(vv), val[v].insert(vv | up[v]);
				}
			}
		}
		memset(dp, 0, sizeof dp);
		dp[0] = 1;
		for (int i = 1; i <= n; i ++) {
			while (cnt[i] --) {
				memset(dp_, 0, sizeof dp_);
				for (int s = 0; s < (1 << k); s ++) {
					if (!dp[s]) continue;
					for (auto v : val[i]) {
						dp_[s | v] = 1;
					}
				}
				for (int s = 0; s < (1 << k); s ++) dp[s] = dp_[s];
			}
		}
		int rlt = 0;
		for (int s = 0; s < (1 << k); s ++) if (dp[s]) rlt = max (rlt, __builtin_popcount(s));
		cout << k - rlt << endl;
	}
	return 0;
}