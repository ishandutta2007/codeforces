#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
#define int ll

int n, m;
const int MAXN = 5000;
vector<int> g[MAXN];
bool used[MAXN];

void dfs(int v) {
	used[v] = true;
	for (auto i : g[v])
		if (!used[i])
			dfs(i);
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			c++;
			dfs(i);
		}
	}
	cout << (1LL << (n - c));
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