#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct query {
	int e, id;
	query() : e(-1), id(-1) {};
	query(int e_, int id_) : e(e_), id(id_) {};
};
bool operator<(const query& q1, const query& q2) {
	return q1.id < q2.id;
}
int n, m, q, a[500009], b[500009], c[500009], cs[500009]; bool ans[500009]; vector<int> es[500009]; vector<query> qs[500009];
int ct, par[500009], parx[500009], v[500009];
int root(int x) { return x == par[x] ? x : par[x] = root(par[x]); }
int rootx(int x) {
	if (x == parx[x]) return x;
	parx[x] = rootx(parx[x]);
	return parx[x];
}
void unitex(int x, int y) {
	x = rootx(x);
	y = rootx(y);
	if (x == parx[x]) v[ct++] = x;
	parx[x] = y;
}
void refresh() {
	for (int i = 0; i < ct; i++) {
		parx[v[i]] = v[i];
	}
	ct = 0;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--, b[i]--;
	}
	copy(c, c + m, cs);
	sort(cs, cs + m);
	int mc = unique(cs, cs + m) - cs;
	for (int i = 0; i < m; i++) {
		es[lower_bound(cs, cs + mc, c[i]) - cs].push_back(i);
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		int sz;
		cin >> sz;
		for (int j = 0; j < sz; j++) {
			int x;
			cin >> x; x--;
			qs[lower_bound(cs, cs + mc, c[x]) - cs].push_back(query(x, i));
		}
	}
	fill(ans, ans + q, true);
	for (int i = 0; i < n; i++) {
		par[i] = i;
		parx[i] = i;
	}
	for (int i = 0; i < mc; i++) {
		sort(qs[i].begin(), qs[i].end());
		for (int j = 0; j < qs[i].size(); j++) {
			if (j == 0 || qs[i][j - 1].id != qs[i][j].id) {
				refresh();
			}
			int e = qs[i][j].e;
			if (rootx(root(a[e])) == rootx(root(b[e]))) ans[qs[i][j].id] = false;
			unitex(root(a[e]), root(b[e]));
		}
		for (int j = 0; j < es[i].size(); j++) {
			par[root(a[es[i][j]])] = root(b[es[i][j]]);
		}
	}
	for (int i = 0; i < q; i++) {
		cout << (ans[i] ? "YES\n" : "NO\n");
	}
	return 0;
}