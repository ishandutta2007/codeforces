#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

const int MAXN = 1e5 + 10;
const int MAXLOG = 20;
int n;
vector<int> g[MAXN];
int tin[MAXN], tout[MAXN], dp[MAXN][MAXLOG], timer = 0, h[MAXN];

void dfs(int v, int p, int len) {
	tin[v] = timer++;
	dp[v][0] = p;
	for (int i = 1; i < MAXLOG; i++)
		dp[v][i] = dp[dp[v][i - 1]][i - 1];
	h[v] = len++;
	for (auto i : g[v]) {
		if (i != p) {
			dfs(i, v, len);
		}
	}
	tout[v] = timer++;
}

bool is_upper(int v, int u) {
	return tin[v] <= tin[u] && tout[v] >= tout[u];
}

int lca(int v, int u) {
	if (is_upper(v, u)) return v;
	if (is_upper(u, v)) return u;
	for (int i = MAXLOG - 1; i >= 0; i--)
		if (!is_upper(dp[v][i], u))
			v = dp[v][i];
	return dp[v][0];
}

int dist(int v, int u) {
	return h[v] + h[u] - 2 * h[lca(v, u)];
}

int calc(int a, int la, int b, int lb) {
	int x = lca(a, b);
	return min(abs(h[la] - h[x]), abs(h[lb] - h[x]));
}

int dist(int s, int f, int t) {
	int l1 = lca(s, f);
	int l2 = lca(f, t);
	//cout << l1 << " " << l2 << endl;
	int ans = calc(s, l1, t, l2) + calc(s, l1, f, l2) + calc(f, l1, f, l2) + calc(f, l1, t, l2);
	
	return ans + 1;
}

int q;

void solve() {
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int p;
		cin >> p;
		p--;
		g[p].push_back(i);
		g[i].push_back(p);
	}
	dfs(0, 0, 0);
	//cout << dist(0, 2, 1) << endl;
	//return;
	while (q--) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		c--;
		vector<int> have = {a, b, c};
		int ans = 0;
		sort(all(have));
		do {
			chkmax(ans, dist(have[0], have[1], have[2]));
		} while (next_permutation(all(have)));
		cout << ans << "\n";
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}