//In the name of God
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1500 + 49;
vector <int> al[N];
int adr[N], sz[N];
int p[N];
pii pnt[N], cur;
long long cross(pii a, pii b) {
	return a.first * 1LL *  b.second - a.second * 1LL *  b.first;
}
bool cmp(const int &x, const int &y) {
	return cross(pnt[x], pnt[y]) < 0;
}
void dfs(int v, int p = -1) {
	sz[v] = 1;
	for (auto u : al[v])
		if (u != p)
			dfs(u, v), sz[v] += sz[u];	
}
void solve(int v, int fa, int l, int r) {
	int id = -1;
	for (int i = l; i < r; ++i) {
		if (id == -1 || pnt[id].second > pnt[p[i]].second || pnt[id].second == pnt[p[i]].second && pnt[id].first > pnt[p[i]].first)
			id = p[i], swap(p[i], p[l]);
	}
	adr[id] = v;
	for (int i = l + 1; i < r; ++i)
		pnt[p[i]].first -= pnt[p[l]].first, pnt[p[i]].second -= pnt[p[l]].second;
	sort(p + l + 1, p + r, cmp);
	for (int i = l + 1; i < r; ++i)
		pnt[p[i]].first += pnt[p[l]].first, pnt[p[i]].second += pnt[p[l]].second;
	int ptr = l + 1;
	for (auto u : al[v]) if (u != fa) {
		solve(u, v, ptr, sz[u] + ptr);
		ptr += sz[u];
	}
	return;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v; cin >> u >> v; --u, --v;
		al[u].push_back(v);
		al[v].push_back(u);
	}
	for (int i = 0; i < n; ++i)
		cin >> pnt[i].first >> pnt[i].second, p[i] = i;
	dfs(0);
	solve(0, -1, 0, n);
	for (int i = 0; i < n; ++i)
		cout << adr[i] + 1 << ' ';
	return 0;
}