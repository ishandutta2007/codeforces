#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m, A[MAXN];
ll ans, ans_c = 1, mn, mn_cnt;
vector<int> adj[MAXN], adj_r[MAXN];
bool vis[MAXN];
stack<int> st;

void dfs(int v) {
	vis[v] = true;
	for (int u : adj[v]) 
		if (!vis[u])
			dfs(u);
	st.push(v);
}

void sfd(int v) {
	vis[v] = true;
	for (int u : adj_r[v])
		if (!vis[u])
			sfd(u);

	if (A[v] < mn) mn = A[v], mn_cnt = 1;
	else if (A[v] == mn) mn_cnt++;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj_r[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) 
		if (!vis[i])
			dfs(i);

	memset(vis, false, sizeof vis);
	while (!st.empty()) {
		int i = st.top();
		st.pop();
		if (!vis[i]) {
			mn = INF, mn_cnt = 1;
			sfd(i);
			ans += mn;
			ans_c = ans_c * mn_cnt % MOD;
		}
	}

	cout << ans << sep << ans_c << endl;
	return 0;
}