#include <bits/stdc++.h>

using namespace std;
#define int long long
#define double long double
const int MAXN = 1e6 + 10;
int n;
vector<int> g[MAXN];
int color[MAXN];

void read() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

int ans = 1;

void dfs(int v, int p) {
	set <int> col;
	for (int i = 1; i <= (int) g[v].size() + 1; i++)
		if (i != color[p] && i != color[v])
			col.insert(i);

	for (auto i : g[v]) {
		if (i != p) {
			color[i] = *col.begin();
			ans = max(ans, color[i]);
			col.erase(col.begin());
			dfs(i, v);
		}
	}	
}

void run() {
	color[0] = 1;
	dfs(0, 0);
} 

void write() {
	cout << ans << endl;
	for (int i = 0; i < n; i++)
		cout << color[i] << " ";
	cout << endl;
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