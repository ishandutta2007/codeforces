#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a, b, c[400009], sd[400009], st[400009], p[400009]; vector<int> g[400009];
void dfs1(int pos, int pre) {
	p[pos] = pre;
	c[pos] = 1;
	for (int i : g[pos]) {
		if (i != pre) {
			dfs1(i, pos);
			c[pos] += c[i];
			sd[pos] = max(sd[pos], sd[i]);
		}
	}
	if (c[pos] <= n / 2) sd[pos] = max(sd[pos], c[pos]);
}
void dfs2(int pos, int pre) {
	int mx = 0, mx2 = 0;
	for (int i : g[pos]) {
		if (i != pre) {
			if (mx < sd[i]) mx2 = mx, mx = sd[i];
			else if (mx2 < sd[i]) mx2 = sd[i];
		}
	}
	for (int i : g[pos]) {
		if (i != pre) {
			st[i] = max(st[i], (mx == sd[i] ? mx2 : mx));
			st[i] = max(st[i], st[pos]);
			dfs2(i, pos);
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b; a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs1(0, -1);
	for (int i = 0; i < n; i++) {
		if (n - c[i] <= n / 2) st[i] = n - c[i];
	}
	dfs2(0, -1);
	for (int i = 0; i < n; i++) {
		if (i) cout << ' ';
		bool flag = true;
		for (int j : g[i]) {
			if (j != p[i] && c[j] - sd[j] > n / 2) flag = false;
		}
		if (n - c[i] - st[i] > n / 2) flag = false;
		cout << (flag ? 1 : 0);
	}
	cout << endl;
	return 0;
}