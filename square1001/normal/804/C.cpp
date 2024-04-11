#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, c, a, b, cnt; vector<int> col; vector<vector<int> > v, g;
void rec(int pos, int pre) {
	set<int> s;
	for (int i : v[pos]) {
		if (col[i]) s.insert(col[i]);
	}
	int z = 1;
	for (int i : v[pos]) {
		if (!col[i]) {
			while (s.count(z)) z++;
			col[i] = z++;
		}
	}
	for (int i : g[pos]) {
		if (i != pre) rec(i, pos);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> c; v[i].resize(c);
		for (int j = 0; j < c; j++) cin >> v[i][j], v[i][j]--;
	}
	g.resize(n);
	for (int i = 1; i < n; i++) {
		cin >> a >> b; a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	col.resize(m);
	rec(0, -1);
	for (int i = 0; i < m; i++) {
		if (!col[i]) col[i] = 1;
	}
	cout << *max_element(col.begin(), col.end()) << endl;
	for (int i = 0; i < m; i++) cout << col[i] << ' ';
	return 0;
}