#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i ++)
using namespace std;
const int MN = 300005;
#define endl '\n'
typedef long long LL;
typedef pair<int, int> pii;

int n;
int a[MN], mn[MN], mx[MN], dp[MN], prt[MN];
vector<int> con[MN], adj[MN];
bool flg = 0;
LL rlt = 0;

void find(int u, int p) {
	prt[u] = p;
	mn[u] = a[u], mx[u] = a[u];
	if (a[u] < a[1]) rlt += dp[u];
	for (auto v : con[u]) if (v != p) {
		dp[v] = dp[u] + 1;
		find(v, u);
		adj[u].push_back(v);
		mn[u] = min(mn[u], mn[v]);
		mx[u] = max(mx[u], mx[v]);
	}
	sort(adj[u].begin(), adj[u].end(), [](const int v1, const int v2) {
		return mn[v1] < mn[v2];
	});
	for (int i = 1; i < adj[u].size(); i++) {
		int v1 = adj[u][i - 1], v2 = adj[u][i];
		if (mx[v1] > mn[v2]) flg = 1;
	}
}

int id[MN], idn = 0;
int cnt = 0;
void find1(int u) {
	id[u] = ++idn;
	for (int v : adj[u]) find1(v);
	cnt++;
	if (cnt == a[1] - 1) {
		bool ok = 0;
		for (int v = u; v != -1; v = prt[v]) {
			if (cnt == a[v]) ok = 1;
		}
		if (!ok) flg = 1;
	}
	if (cnt >= a[1] - 1) return;
	if (cnt != a[u]) flg = 1;
}

bool solve() {
	dp[1] = 0;
	find(1, -1);
	if (flg) return 0;
	find1(1);
	if (flg) return 0;
	for (int i = 2; i <= n; i++) {
		if (a[i] < a[1]) continue;
		if (a[i] < a[prt[i]]) flg = 1;
	}
	if (flg) return 0;
	return 1;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		con[u].push_back(v);
		con[v].push_back(u);
	}
	if (!solve()) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		cout << rlt << endl;
		for (int i = 1; i <= n; i++) cout << id[i] << ' '; cout << endl;
	}

	return 0;

}