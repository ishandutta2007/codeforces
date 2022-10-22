#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n;

const int N = 1507;
const int NN = N * N / 2;

pair <int, int> edge[NN]; 

const int MOD = 998244353;

void add(int &x, int y) {
	x += y;
	if (x >= MOD) {
		x -= MOD;
	}
}

struct DSU {
	int n;
	vector <int> p, r, sz, edges;
	vector <vector <int>> dp;

	DSU(int n) : r(n, 0), p(n), dp(n), sz(n, 1), edges(n, 0) {
		iota(all(p), 0);
		for (int i = 0; i < n; ++i) {
			dp[i] = {0, 1};
		}
	}

	int get(int v) {
		return (p[v] == v ? v : p[v] = get(p[v]));
	}

	bool uni(int v, int u) {
		v = get(v);
		u = get(u);
		if (v == u) {
			++edges[v];
			if (2 * edges[v] == sz[v] * (sz[v] - 1)) {
				add(dp[v][1], 1);
			}
			return false;
		}
		if (r[v] == r[u]) ++r[u];
		if (r[v] > r[u]) swap(v, u);
		p[v] = u;

		int szv = dp[v].size(), szu = dp[u].size();
		vector <int> res(szv + szu - 1, 0);

		for (int i = 0; i < szv; ++i) {
			for (int j = 0; j < szu; ++j) {
				add(res[i + j], dp[v][i] * (ll) dp[u][j] % MOD);
			}
		}

		/*cout << "RES: ";
		for (int i = 0; i < szv + szu - 1; ++i) {
			cout << res[i] << " ";
		}
		cout << endl;*/

		dp[u] = res;
		sz[u] += sz[v];
		edges[u] += edges[v] + 1;

		if (2 * edges[u] == sz[u] * (sz[u] - 1)) {
			add(dp[u][1], 1);
		}

		return true;
	}
};

int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int x;
			cin >> x;
			if (x && i < j) {
				edge[x] = {i, j};
			}
		}
	}

	DSU dsu(n);

	for (int i = 1; i <= n * (n - 1) / 2; ++i) {
		int v = edge[i].x, u = edge[i].y;
		//cout << v << " " << u << endl;
		dsu.uni(v, u);
	}

	int v = dsu.get(0);
	for (int i = 1; i <= n; ++i) {
		cout << dsu.dp[v][i] << " ";
	}
	cout << "\n";
}