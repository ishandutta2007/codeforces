#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
bool leaf[N], vis[N];
int w[N], a[N], mx[N], fa[N];
vector<int> g[N];

int dfs1(int p, int f) {
	fa[p] = f;
	mx[p] = w[p];
	for (int i: g[p]) {
		if (i == f) continue;
		mx[p] = max(mx[p], dfs1(i, p));
	}
	return mx[p];
}

void dfs2(int p, int f, int d) {
	vis[p] = true;
	if (leaf[p]) {
		a[p] = max(a[p], d);
		return;
	}
	int t = 0;
	for (int i: g[p]) {
		if (i == f) continue;
		if (mx[i] > mx[t]) t = i;
	}
	dfs2(t, p, d);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> w[i];
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i = 1; i <= n; ++i) {
		if (g[i].size() == 1) {
			leaf[i] = true;
			a[i] = w[i];
		}
	}
	if (n == 2) {
		cout << 2 * max(w[1], w[2]) << '\n';
		return 0;
	}
	vector<int> v;
	for (int i = 1; i <= n; ++i) {
		if (!leaf[i]) v.push_back(i);
	}
	sort(v.begin(), v.end(), [&](int x, int y) { return w[x] > w[y]; });
	dfs1(v[0], 0);
	vector<int> u = g[v[0]];
	sort(u.begin(), u.end(), [&](int x, int y) { return mx[x] > mx[y]; });
	dfs2(u[0], v[0], w[v[0]]);
	dfs2(u[1], v[0], w[v[0]]);
	vis[v[0]] = true;
	for (int i = 1; i < v.size(); ++i) {
		if (vis[v[i]]) continue;
		dfs2(v[i], fa[v[i]], w[v[i]]);
	}
	vector<int> A;
	for (int i = 1; i <= n; ++i) {
		if (leaf[i]) A.push_back(a[i]);
	}
	sort(A.begin(), A.end(), greater<int>());
	int MX = 0;
	for (int i = 1; i <= n; ++i) {
		MX = max(MX, w[i]);
	}
	A[1] = max(A[1], MX);
	long long ans = 0;
	for (int i: A) {
		ans += i;
	}
	cout << ans << '\n';
	return 0;
}