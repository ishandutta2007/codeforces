#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 5e3 + 10;

int n, m;
vector<pair <int, int> > g[MAXN];
void read() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back({v, i});
	}
}

int ans[MAXN];
int k = 1;
int used[MAXN];

void dfs(int v) {
	used[v] = 1;
	for (auto i : g[v]) {
		if (used[i.first] == 1) {
			ans[i.second] = 2;
			k = 2;
		}
		else {
			ans[i.second] = 1;
		}
		if (used[i.first] == 0)
			dfs(i.first);
	}
	used[v] = 2;
}


void run() {
	for (int i = 0; i < n; i++) {
		if (!used[i])
			dfs(i);
	}
}

void write() {
	cout << k << endl;
	for (int i = 0; i < m; i++) {
		cout << ans[i] << " ";
	}
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