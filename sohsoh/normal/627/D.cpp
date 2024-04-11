#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int full[MAXN], dp[MAXN], mid, n, k, A[MAXN],
    val[MAXN], B[MAXN], cnt, dp_up[MAXN];
bool full_up[MAXN];
pll F[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int p) {
	for (int u : adj[v]) {
		if (u == p) continue;
		if (A[u] < mid) {
			B[v]++;
			continue;
		}

		dfs(u, v);
		if (B[u]) {
			B[v] += B[u];
			if (dp[u] > F[v].X) F[v].Y = F[v].X, F[v].X = dp[u];
			else if (dp[u] > F[v].Y) F[v].Y = dp[u];
		} else full[v] += dp[u];
	}

	dp[v] = 1 + full[v] + F[v].X;
}

void dfs_up(int v, int p) {
	if (p) {
		if (B[v] == cnt) {
			dp_up[v] = 1 + full[p] + dp_up[p];
			val[v] = dp_up[v] + full[v] + F[v].X;
			full_up[v] = true;
		} else {
			if (B[v]) {
				if (full_up[p]) {
					dp_up[v] = 1 + dp_up[p] + full[p];
					if (dp[v] == F[p].X) dp_up[v] += F[p].Y;
					else dp_up[v] += F[p].X;
				} else {
					dp_up[v] = 1 + full[p];
					int mx = F[p].X;
					if (dp[v] == mx) mx = F[p].Y;
					dp_up[v] += max(dp_up[p], mx);
				}
			} else {
				if (full_up[p]) {
					dp_up[v] = 1 + dp_up[p] + full[p] + F[p].X - dp[v];
				} else {
					dp_up[v] = 1 + full[p] + max(dp_up[p], F[p].X) - dp[v];
				}	
			}

			full_up[v] = false;
			val[v] = 1 + full[v] + max(F[v].X, dp_up[v] - 1);
		}
	} else {
		dp_up[v] = 1;
		full_up[v] = true;
		val[v] = dp[v];
	}

	for (int u : adj[v])
		if (u != p && A[u] >= mid)
			dfs_up(u, v);
}

// check for min


inline bool can(int m) {
	mid = m;
	cnt = 0;
	for (int i = 1; i <= n; i++) {
		val[i] = 0;
		dp_up[i] = 0;
		dp[i] = 0;
		F[i] = {0, 0};
		B[i] = 0;
		full[i] = 0;
		full_up[i] = 0;
	}

	int mx = 0;
	for (int i = 1; i <= n; i++) {
		if (A[i] < mid) continue;

		if (!dp[i]) {
			dfs(i, 0);
			cnt = B[i];
			dfs_up(i, 0);	
		}

		mx = max(mx, val[i]);
	}

	return mx >= k;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> A[i];

	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int x = *min_element(A + 1, A + n + 1) + 1;
	if (!can(x)) return cout << x - 1 << endl, 0; //

	int l = 1, r = 1e6 + 1;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (can(mid)) l = mid;
		else r = mid - 1;	
	}

	cout << l << endl;
	return 0;
}