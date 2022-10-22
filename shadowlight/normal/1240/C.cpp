#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n, k;

vector <vector <pair <int, ll> > > gr;
vector <vector <ll> > dp;

void dfs(int v, int p) {
	vector <ll> values;
	ll res = 0;
	for (auto e : gr[v]) {
		int u = e.first;
		ll w = e.second;
		if (u == p) continue;
		dfs(u, v);
		res += dp[u][0];	
		ll now = dp[u][1] - dp[u][0] + w;
		if (now <= 0) continue;
		values.push_back(now);
	}
	sort(values.rbegin(), values.rend());
	for (ll i = 0; i < min(k - 1, (int) values.size()); i++) {
		res += values[i];
	}
	if (values.size() < k) {
		dp[v][0] = dp[v][1] = res;
	} else {
		dp[v][1] = res;
		dp[v][0] = res + values[k - 1];
	}
}

void solve() {
	cin >> n >> k;
	gr.clear();
	dp.clear();
	gr.resize(n);
	dp.resize(n, vector <ll> (2, 0));
	for (int i = 1; i < n; i++) {
		int v, u, w;
		cin >> v >> u >> w;
		v--, u--;
		gr[v].push_back({u, w});
		gr[u].push_back({v, w});
	}
	dfs(0, -1);
	cout << dp[0][0] << "\n";
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		solve();
	}

}