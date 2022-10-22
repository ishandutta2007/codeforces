#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 19;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[1 << MAXN][MAXN], n, m, ans;
bool adj[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u][v] = adj[v][u] = true;
	}

	int MASK = (1 << n);
	for (int msk = 1; msk < MASK; msk++) {
		int v = __builtin_ctz(msk);
		if ((1 << v) == msk) {
			dp[msk][v] = 1;
			continue;
		}

		for (int u = v + 1; u < n; u++) {
			if (msk & (1 << u))
				for (int w = v; w < n; w++)
					if (adj[w][u] && (msk & (1 << w)))
						dp[msk][u] += dp[msk ^ (1 << u)][w];
			if (adj[v][u] && __builtin_popcount(msk) > 2)
				ans += dp[msk][u];
		}	
	}
	
	cout << (ans >> 1ll) << endl;
	return 0;
}