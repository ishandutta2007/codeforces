#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int MAXN = 2 * 1e5 + 10;
vector <int> g[MAXN];
int n, k;
void read() {
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int v, u, cost;
		cin >> v >> u >> cost;
		v--;
		u--;
		if (cost != 1) {
			g[v].push_back(u);
			g[u].push_back(v);
		}
	}
}

int comp = 1;
int comps[MAXN];

void dfs(int v, int p) {
	comps[v] = comp;
	for (auto i : g[v]) {
		if (i != p) {
			dfs(i, v);
		}
	}
}

int pows(int a, int n) {
	int x = 1;
	for (int i = 0; i < n; i++) {
		x *= a;
		x %= MOD;
	}
	return x;
}

void run() {
	for (int i = 0; i < n; i++) {
		if (!comps[i]) {
			dfs(i, -1);
			comp++;
		}
	}
	map <int, int> help;
	for (int i = 0; i < n; i++)
		help[comps[i]]++;
	int ans = pows(n, k);
	for (auto i : help) {
		ans -= pows(i.second, k);
		ans %= MOD;
		ans += MOD;
		ans %= MOD;
	}
	cout << ans << endl;
}

void write() {

}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}