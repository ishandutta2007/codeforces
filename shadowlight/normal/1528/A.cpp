#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

int n;
vector <vector <int>> gr;
vector <pair <int, int>> a;
vector <int> val;
vector <ll> dp[2];

ll sum = 0;
void dfs(int v, int p, bool maxv) {
	for (int u : gr[v]) {
		if (u == p) continue;
		dfs(u, v, maxv ^ 1);
		dp[0][v] += max(dp[0][u] + abs(a[v].x - a[u].x), dp[1][u] + abs(a[v].x - a[u].y));
		dp[1][v] += max(dp[0][u] + abs(a[v].y - a[u].x), dp[1][u] + abs(a[v].y - a[u].y));
	}
}

void solve() {
	cin >> n;
	val.assign(n, 0);
	gr.assign(n, {});
	a.assign(n, {-1, -1});
	dp[0].assign(n, 0);
	dp[1].assign(n, 0);

	for (int i = 0; i < n; ++i) {
		int v, u;
		cin >> v >> u;
		a[i] = {v, u};
	}
	for (int i = 1; i < n; ++i) {
		int v, u;
		cin >> v >> u;
		--v, --u;
		gr[v].pb(u);
		gr[u].pb(v);
	}
	dfs(0, -1, false);
	cout << max(dp[0][0], dp[1][0]) << "\n";
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		solve();
	}

}