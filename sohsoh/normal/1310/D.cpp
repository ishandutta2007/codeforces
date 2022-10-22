#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 80 + 10;
const ll INF = 1e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int C[MAXN], n, k, A[MAXN][MAXN];
ll dp[MAXN][MAXN];

inline ll solve() {
	fill(dp[0] + 2, dp[0] + MAXN, INF);
	for (int i = 1; i <= k; i++) { 
		for (int v = 1; v <= n; v++) {
			dp[i][v] = INF;
			for (int u = 1; u <= n; u++)
				if (C[u] ^ C[v])
					dp[i][v] = min(dp[i][v], dp[i - 1][u] + A[u][v]);
		}
	}

	return dp[k][1];
} 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> A[i][j];

	int t = 5000;
	ll ans = INF;
	while (t--) {
		for (int i = 1; i <= n; i++)
			C[i] = rng() % 2;
		ans = min(ans, solve());
	}

	cout << ans << endl;
	return 0;
}