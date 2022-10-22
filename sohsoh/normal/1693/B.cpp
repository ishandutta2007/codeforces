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

const ll MAXN = 1e6 + 10;

vector<int> adj[MAXN];
ll n, A[MAXN], L[MAXN], R[MAXN], ans;

void dfs(int v) {
	ll s = 0;
	for (int u : adj[v]) {
		dfs(u);
		s += A[u];
	}

	A[v] = min(s, R[v]);
	if (A[v] < L[v]) {
		ans++;
		A[v] = R[v];
	}
}
	
inline void solve() {
	ans = 0;
	for (int i = 0; i < n + 10; i++)
		adj[i].clear(), A[i] = 0;

	cin >> n;
	for (int i = 2; i <= n; i++) {
		int p;
		cin >> p;
		adj[p].push_back(i);
	}

	for (int i = 1; i <= n; i++) cin >> L[i] >> R[i];
	dfs(1);
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}