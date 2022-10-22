#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 2e5 + 7;
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

int rev(int a) {
	return power(a, MOD - 2);
}

void add(int &x, int y) {
	x += y;
	if (x >= MOD) {
		x -= MOD;
	}
	if (x < 0) {
		x += MOD;
	}
}

void mul(int &x, int y) {
	x = x * (ll) y % MOD;
}

int n;
vector <pair <int, int> > gr[N];
int par[N];
int dp0[N], dp1[N];
vector <int> dp2[N], dp3[N];

void dfs(int v, int p) {
	par[v] = p;
	for (auto e : gr[v]) {
		int u = e.second;
		if (u == p) continue;
		dfs(u, v);
	}
}

void dfs(int v) {
	dp0[v] = 1, dp1[v] = 1;
	dp2[v].resize(gr[v].size(), 0);
	dp3[v].resize(gr[v].size() + 1, 0);
	for (int i = 0; i < (int) gr[v].size(); i++) {
		int u = gr[v][i].second, tm = gr[v][i].first;
		dfs(u);
		mul(dp1[v], dp0[u]);
	}
	int suf = dp1[v];
	int pref = 1;
	for (int i = 0; i < (int) gr[v].size(); i++) {
		int u = gr[v][i].second, tm = gr[v][i].first;
		int pos = lower_bound(gr[u].begin(), gr[u].end(), make_pair(tm, -1)) - gr[u].begin();
		mul(suf, rev(dp0[u]));
		int value = dp0[u];
		if (pos) {
			add(value, -dp2[u][pos - 1]);
		}
		add(dp2[v][i], pref * (ll) value % MOD * suf % MOD); 
		if (i) {
			add(dp2[v][i], dp2[v][i - 1]);
		}
		int upd = dp3[u][pos];
		if (pos) {
			add(upd, dp2[u][pos - 1]);
		}
		mul(pref, upd);
		dp3[v][i + 1] = pref * (ll) suf % MOD;
	}
	if (dp2[v].size()) {
		dp0[v] = dp2[v].back();
		add(dp0[v], pref);
	}
	dp3[v][0] = dp1[v];
	//cout << v << " " << dp0[v] << " " << dp1[v] << endl;
	//cout << "dp2[v]: ";
	/*for (int x : dp2[v]) {
		cout << x << " ";
	}*/
	//cout << "\n";
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		gr[v].push_back({i, u});
		gr[u].push_back({i, v});
	}
	dfs(0, -1);
	for (int i = 0; i < n; i++) {
		for (auto &e : gr[i]) {
			if (e.second == par[i]) {
				swap(e, gr[i].back());
				gr[i].pop_back();
				break;
			}
		}
		sort(gr[i].begin(), gr[i].end());
	}
	dfs(0);
	cout << dp0[0] << "\n";
}