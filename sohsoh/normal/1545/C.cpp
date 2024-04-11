// Sohsoh84 :)
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

const ll MAXN = 2000 + 10;
const ll MOD = 998244353;

int n, A[MAXN][MAXN], vis[MAXN], cnt[MAXN][MAXN], col[MAXN], c;
vector<int> ans_v, adj[MAXN], C[MAXN][3];

inline void Remove(int ind) {
	if (vis[ind]) return;
	vis[ind] = true;
	for (int i = 1; i <= n; i++)
		cnt[i][A[ind][i]]--;
}

inline bool T(int i, int j) {
	for (int k = 1; k <= n; k++)
		if (A[i][k] == A[j][k])
			return true;
	return false;
}

void dfs(int v) {
	int t = 1;
	if (col[v] == t) t = 2;
	C[c][col[v]].push_back(v);

	for (int u : adj[v]) {
		if (!col[u]) {
			col[u] = t;
			dfs(u);
		}
	}
}

inline int solve() {
	cin >> n;
	for (int i = 1; i <= 2 * n; i++)
		for (int j = 1; j <= n; j++) 
			cin >> A[i][j], cnt[j][A[i][j]]++;

	while (true) {
		int ind = 0;
		for (int j = 1; j <= 2 * n; j++) {
			if (vis[j]) continue;
			bool flag = false;
			for (int k = 1; k <= n; k++) {
				if (cnt[k][A[j][k]] == 1) {
					flag = true;
					break;
				}
			}	

			if (flag) {
				ind = j;
				break;
			}
		}

		if (!ind) break;
		
		ans_v.push_back(ind);
		for (int i = 1; i <= 2 * n; i++)
			if (T(i, ind))
				Remove(i);
	}

	for (int i = 1; i <= 2 * n; i++) {
		for (int j = 1; j < i; j++) {
			if (!vis[i] && !vis[j] && T(i, j)) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	for (int i = 1; i <= 2 * n; i++) {
		if (vis[i] || col[i]) continue;
		col[i] = 1;
		c++;
		dfs(i);
	}

	for (int i = 1; i <= c; i++)
		for (int e : C[i][1]) 
			ans_v.push_back(e);
	

	ll ans = 1;
	while (c--) ans = ans * 2 % MOD;

	assert(ans_v.size() == n);	
	cout << ans << endl;
	for (int e : ans_v) cout << e << sep;
	cout << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		c = 0;
		ans_v.clear();

		for (int i = 0; i < 2 * n + 10; i++) {
			vis[i] = false;
			col[i] = 0;
			for (int j = 0; j < n + 10; j++) A[i][j] = cnt[i][j] = 0;
			adj[i].clear();
			C[i][0].clear();
			C[i][1].clear();
			C[i][2].clear();
		}
		
		solve();
	}
	return 0;
}