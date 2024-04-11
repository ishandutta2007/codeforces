#include <vector>
#include <iostream>
using namespace std;
const int mod = 1000000007;
int n; vector<int> v, d, du, e, eu, p; vector<vector<int> > g;
void dfs1(int pos, int pre) {
	p[pos] = pre;
	for (int i : g[pos]) {
		if (i == pre) continue;
		dfs1(i, pos);
		d[pos] += d[i];
		e[pos] -= e[i];
	}
	++d[pos];
	++e[pos];
}
void dfs2(int pos, int pre) {
	int es = 0;
	for (int i : g[pos]) {
		if (i != pre) es += e[i];
	}
	for (int i : g[pos]) {
		if (i == pre) continue;
		du[i] = n - d[i];
		eu[i] = 1 - (eu[pos] + es - e[i]);
		dfs2(i, pos);
	}
}
int reduce(long long x) {
	if (x < 0) x = (mod - (-x) % mod);
	return x % mod;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n;
	v.resize(n);
	g.resize(n);
	d.resize(n);
	du.resize(n);
	e.resize(n);
	eu.resize(n);
	p.resize(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b; --a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs1(0, -1);
	dfs2(0, -1);
	int ret = 0;
	for (int i = 0; i < n; ++i) {
		long long val = 0;
		for (int j : g[i]) {
			if (j == p[i]) continue;
			val = -1LL * e[j] * (n - d[j]);
			val = reduce(val);
			val = 1LL * val * v[i];
			val = reduce(val);
			ret = (ret + val) % mod;
		}
		val = 1LL * n * v[i];
		val = reduce(val);
		ret = (ret + val) % mod;
		if (i != 0) {
			val = -1LL * eu[i] * d[i];
			val = reduce(val);
			val = 1LL * val * v[i];
			val = reduce(val);
			ret = (ret + val) % mod;
		}
	}
	cout << ret << '\n';
	return 0;
}