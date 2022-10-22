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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 20;

int n, m, par[MAXN][LOG], mx_w[MAXN][LOG], T[MAXN], S[MAXN], H[MAXN], c = 0;
pair<int, pair<int, int>> Q[MAXN];
vector<int> adj[MAXN];

void dfs(int v) {
	for (int u : adj[v]) {
		H[u] = H[v] + 1;
		dfs(u);
	}
}

inline pll Par(int v, int k) {
	int x = 0;
	for (int i = LOG - 1; i >= 0; i--) {
		if (k & (1 << i)) {
			x = max(x, mx_w[v][i]);
			v = par[v][i];
			k ^= (1 << i);
		}
	}

	return {v, x};
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int q = 1; q <= m; q++) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, y;
			cin >> x >> y;
			Q[q] = {1, {x, y}};
			par[x][0] = y;
			mx_w[x][0] = q;
			adj[y].push_back(x);
		} else if (t == 2) {
			int x;
			cin >> x;
			Q[q] = {2, {x, 0}};
			c++;
			T[c] = q;
			S[c] = x;
		} else {
			int x, i;
			cin >> x >> i;
			Q[q] = {3, {x, i}};
		}
	}

	for (int i = 1; i < LOG; i++) {
		for (int v = 1; v <= n; v++) {
			par[v][i] = par[par[v][i - 1]][i - 1];
			mx_w[v][i] = max(mx_w[v][i - 1], mx_w[par[v][i - 1]][i - 1]);
		}
	}

	for (int i = 1; i <= n; i++) 
		if (par[i][0] == 0)
			dfs(i);
	
	for (int q = 1; q <= m; q++) {
		if (Q[q].X != 3) continue;
		int i = Q[q].Y.Y;
		int v = S[i], u = Q[q].Y.X;
		if (H[v] < H[u]) cout << "NO" << endl;	
		else {
			pll p = Par(v, H[v] - H[u]);
			if (p.Y > T[i] || p.X != u) cout << "NO" << endl;
			else cout << "YES" << endl;
		}	
	}
	return 0;
}