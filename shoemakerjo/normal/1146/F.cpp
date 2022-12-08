#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 998244353;
const int maxn = 200010;

int n;
int par[maxn];
vector<int> ch[maxn];

ll mult(ll a, ll b) {
	return (a%mod + 0LL) * (b%mod + 0LL) % mod;
}

void add(ll &a, ll b) {
	a = (a + b)%mod;
}

ll col[maxn];
ll unc[maxn];

ll dp[2][2][3];

void dfs(int u) {
	for (int v : ch[u]) {
		dfs(v);
	}
	if (ch[u].size() == 0) {
		col[u] = 1LL;
		unc[u] = 1LL;
		return;
	}

	// cout << "    " << u << endl;


	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			dp[0][i][j] = dp[1][i][j] = 0LL;
		}
	}
	dp[0][0][0] = 1LL;
	int cur = 0, prev = 1;

	for (int v : ch[u]) {
		swap(prev, cur);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				dp[cur][i][j] = 0LL;
			}
		}
		//this guy is not colored
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				add(dp[cur][i][j], mult(dp[prev][i][j], unc[v]));
			}
		}
		//this guy contributes to parent
		for (int j = 0; j < 3; j++) {
			add(dp[cur][1][j], mult(dp[prev][0][j], col[v]));
			add(dp[cur][1][j], mult(dp[prev][1][j], col[v]));
		}
		//this guy contributes to me
		for (int i = 0; i < 2; i++) {
			add(dp[cur][i][1], mult(dp[prev][i][0], col[v]));
			add(dp[cur][i][2], mult(dp[prev][i][1], col[v]));
			add(dp[cur][i][2], mult(dp[prev][i][2], col[v]));
		}

	}
	col[u] = (dp[cur][1][0])%mod;
	unc[u] = (dp[cur][0][0] + dp[cur][0][2])%mod;

	// cout << dp[cur][0][0] << " : " << dp[cur][0][2] << endl;
	// cout << u << " : " << col[u] << " " << unc[u] << endl;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 2; i <= n; i++) {
		cin >> par[i];
		ch[par[i]].push_back(i);
	}
	dfs(1);
	cout << unc[1] << endl;

}