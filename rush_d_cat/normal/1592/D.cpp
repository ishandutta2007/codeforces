#include <bits/stdc++.h>
using namespace std;
const int N = 1002;
vector<int> g[N];
int a[N], tot, fa[N];
void dfs(int u, int p) {
	a[++tot] = u; fa[u] = p;
	for (auto v: g[u]) {
		if (v == p) continue;
		dfs(v, u);
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 1);

	auto gen = [&](int l, int r) {
		set<int> s;
		for (int i = l; i <= r; i ++) s.insert(a[i]);
		for (int i = l; i <= r; i ++) if (s.count(fa[a[i]]) == 0)
			s.insert(fa[a[i]]);
		return s;		
	};
	int cnt = 0;
	auto ask = [&](int l, int r) {
		set<int> s = gen(l, r);
		if (s.size() <= 1) return 0;
		cout << "? " << s.size() << " ";
		for (auto x: s) cout << x << " ";
		cout << endl;
		int x; cin >> x;
		cnt ++;
		assert(cnt < 12);
		return x;
	};

	int mx = ask(1, n);
	function<void(int,int)> solve = [&](int l, int r) {
		int mid = (l + r) >> 1;
		if (ask(l, mid) == mx) {
			if (gen(l, mid).size() == 2) {
				cout << "! " << *(gen(l, mid).begin()) << " " << *(gen(l, mid).rbegin());
				return;
			}
			solve(l, mid);
		} else {
			if (gen(mid + 1, r).size() == 2) {
				cout << "! " << *(gen(mid + 1, r).begin()) << " " << *(gen(mid + 1, r).rbegin());
				return;
			}
			solve(mid + 1, r);
		}
	};
	solve(1, n);
}