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
const ll LOG = 30;

int n, m, from[MAXN], to[MAXN], col[MAXN];
vector<int> adj[MAXN];
bool* vis;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int f(int ind, int v) {
	return from[ind] ^ to[ind] ^ v;
}

void dfs(int v, int c) {
	queue<int> st;
	st.push(v);
	vis[v] = true;

	while (!st.empty()) {
		int v = st.front();
		st.pop();
		
		for (int ind : adj[v]) {
			int u = f(ind, v);
			if (!vis[u] && col[ind] == c) {
				vis[u] = true, 
				st.push(u);
			}
		}
	}
}

inline int cmp(int c) {
	memset(vis, false, n + 1);
	int ans = 0;

	for (int v = 1; v <= n; v++)
		if (!vis[v])
			dfs(v, c), ans++;
	
	return ans;
}

inline void solve() {
	int ans = MAXN;
	string s;

	for (int i = 0; i <= n + 5; i++)
		adj[i].clear();
	
	cin >> n >> m;
	vis = new bool[n + 2];
	for (int i = 1; i <= m; i++) {
		cin >> from[i] >> to[i];
		adj[from[i]].push_back(i);
		adj[to[i]].push_back(i);
	}

	while (ans > 2 * n - m) {
		for (int i = 0; i <= m / LOG; i++) {
			int x = rng();
			for (int j = 0; j < LOG; j++)
				col[i * LOG + j] = (x >> j & 1);
		}

		int tans = cmp(0) + cmp(1);
		if (tans < ans) {
			ans = tans;
			s.clear();
			for (int i = 1; i <= m; i++)
				s.push_back(char(col[i] + '0'));
		}
	}

	cout << s << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}