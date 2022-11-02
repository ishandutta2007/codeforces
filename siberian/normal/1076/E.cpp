#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()
#define fadd fadd228
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

struct fenvik{
	vector<int> tree;
	int n;
	fenvik() {}
	fenvik(int sz) {
		n = sz + 1;
		tree.assign(n, 0);
	}

	void upd(int pos, int val) {
		//tree[pos] += val;
		for (; pos < n; pos |= pos + 1)
			tree[pos] += val;
	}

	int get(int r) {
		chkmin(r, n - 1);
		int ans = 0;
		//for (int i = 0; i <= r; i++)
		//	ans += tree[i];
		for (; r >= 0; r = (r & (r + 1)) - 1)
			ans += tree[r];
		return ans;
	}

	int get(int l, int r) {
		return get(r) - get(l - 1);
	}
};

int n;
const int MAXN = 3e5 + 10;
vector<int> g[MAXN];
int q;
vector<pair<int, int>> fadd[MAXN];
fenvik tree;
int ans[MAXN];

void dfs(int v, int p, int len){
	for (auto i : fadd[v]) {
		tree.upd(len, i.second);
		tree.upd(len + i.first + 1, -i.second);		
	}
	
	ans[v] = tree.get(len);

	for (auto i : g[v]) {
		if (i == p) continue;
		dfs(i, v, len + 1);
	}

	for (auto i : fadd[v]) {
		tree.upd(len, -i.second);
		tree.upd(len + i.first + 1, i.second);		
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int q;
	cin >> q;
	while (q--) {
		int v, d, x;
		cin >> v >> d >> x;
		v--;
		fadd[v].push_back({d, x});
	}
	tree = fenvik(n);
	dfs(0, 0, 0);
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << endl;
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