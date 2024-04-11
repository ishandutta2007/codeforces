#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector <vector<int>> gr;
vector <vector<int>> rgr;

const int INF = 1e9 + 7;

const int N = 2e5 + 7;
const int LOGN = 27;

int dp[N][LOGN];

pair <int, int> dp2[N][2];

const int MOD = 998244353;

int power(int a, int k) {
	if (!k) {
		return 1;
	}
	int b = power(a, k / 2);
	b = b * (ll) b % MOD;
	if (k % 2) {
		return a * (ll) b % MOD;
	} else {
		return b;
	}
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	gr.resize(n);
	rgr.resize(n);

	for (int i = 0; i < m; ++i) {
		int v, u;
		cin >> v >> u;
		--v, --u;
		gr[v].pb(u);
		rgr[u].pb(v);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < LOGN; ++j) {
			dp[i][j] = INF;
		}
	}

	set <pair <int, pair <int, int>>> q;
	dp[0][0] = 0;
	q.insert({0, {0, 0}});

	while (!q.empty()) {
		auto t = q.begin()->y;
		q.erase(q.begin());
		
		int v = t.x, i = t.y;
		if (i + 1 < LOGN && dp[v][i + 1] > dp[v][i] + (1 << i)) {
			q.erase({dp[v][i + 1], {v, i + 1}});
			dp[v][i + 1] = dp[v][i] + (1 << i);
			q.insert({dp[v][i + 1], {v, i + 1}});
		}
		//cout << "VAL: " << v << " " << i << "\n";

		if (i % 2) {
			for (int u : rgr[v]) {
				if (dp[u][i] > dp[v][i] + 1) {
					q.erase({dp[u][i], {u, i}});
					dp[u][i] = dp[v][i] + 1;
					q.insert({dp[u][i], {u, i}});
				}
			}
		} else {
			for (int u : gr[v]) {
				if (dp[u][i] > dp[v][i] + 1) {
					q.erase({dp[u][i], {u, i}});
					dp[u][i] = dp[v][i] + 1;
					q.insert({dp[u][i], {u, i}});
				}
			}
		}
	}

	int res = INF;

	for (int i = 0; i < LOGN; ++i) {
		res = min(res, dp[n - 1][i]);
	}

	if (res < INF) {
		cout << res << "\n";
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j) {
			dp2[i][j] = {INF, INF};
		}
	}

	set <pair <pair <int, int>, pair <int, int> > > qq;
	dp2[0][0] = {0, 0};
	qq.insert({dp2[0][0], {0, 0}});
	while (qq.size()) {
		auto t = qq.begin()->second;
		qq.erase(qq.begin());

		int v = t.x, i = t.y;
		auto val = dp2[v][i];
		
		++val.x;
		int j = i ^ 1;
		if (dp2[v][j] > val) {
			qq.erase({dp2[v][j], {v, j}});
			dp2[v][j] = val;
			qq.insert({dp2[v][j], {v, j}});
		}
		--val.x;

		++val.y;
		if (i) {
			for (int u : rgr[v]) {
				if (dp2[u][i] > val) {
					qq.erase({dp2[u][i], {u, i}});
					dp2[u][i] = val;
					qq.insert({dp2[u][i], {u, i}});
				}
			}
		} else {
			for (int u : gr[v]) {
				if (dp2[u][i] > val) {
					qq.erase({dp2[u][i], {u, i}});
					dp2[u][i] = val;
					qq.insert({dp2[u][i], {u, i}});
				}
			}
		}
	}

	auto val1 = dp2[n - 1][0], val2 = dp2[n - 1][1];
	auto val = min(val1, val2);

	//cout << val1.x << " " << val1.y << "\n";
	//cout << val2.x << " " << val2.y << "\n";

	res = power(2, val.x) - 1;
	res += val.y;
	if (res > MOD) {
		res -= MOD;
	}
	cout << res << "\n";

}