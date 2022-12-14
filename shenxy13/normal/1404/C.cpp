#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> query;
const int INF = 1000000000;
int a[300001];
struct seg {
	int s, e, m, lazy;
	ii v;
	seg *l, *r;
	seg(int _s, int _e) {
		s = _s, e = _e, m = (s + e) / 2, lazy = 0;
		if (s != e) {
			l = new seg(s, m);
			r = new seg(m + 1, e);
			v = max(l -> v, r -> v);
		} else v = ii(a[s], s);
	}
	void prop() {
		if (lazy != 0) {
			v.first += lazy;
			if (s != e) {
				l -> lazy += lazy;
				r -> lazy += lazy;
			}
			lazy = 0;
		}
	}
	void update(int a, int b, int dv) {
		if (s != a || e != b) {
			if (a > m) r -> update(a, b, dv);
			else if (b <= m) l -> update(a, b, dv);
			else l -> update(a, m, dv), r -> update(m + 1, b, dv);
			l -> prop(), r -> prop();
			v = max(l -> v, r -> v);
		} else lazy += dv;
	}
	ii rmax(int a, int b) {
		prop();
		if (s == a && e == b) return v;
		if (a > m) return r -> rmax(a, b);
		if (b <= m) return l -> rmax(a, b);
		return max(l -> rmax(a, m), r -> rmax(m + 1, b));
	}
} *root;
struct Fenwick {
	vector<int> tree;
	Fenwick(int N) {
		for (int i = 0; i <= N; ++i) tree.push_back(0);
	}
	void update(int i, int dv) {
		for (; i < tree.size(); i += i & -i) tree[i] += dv;
	}
	int psum(int a) {
		int ans = 0;
		for (; a > 0; a -= a & -a) ans += tree[a];
		return ans;
	}
};
int main() {
	int n, q, x, y;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) a[i] -= i;
	root = new seg(1, n);
	for (int i = 1; i <= n; ++i) {
		if (a[i] > 0) root -> update(i, i, -INF);
	}
	vector<query> queries;
	int ans[q];
	for (int i = 0; i < q; ++i) {
		scanf("%d %d", &x, &y);
		queries.push_back(query(ii(x, y), i));
	}
	sort(queries.begin(), queries.end());
	Fenwick ft(n);
	for (int i = n; i > 0; --i) {
		ii x = root -> rmax(i, n);
		while (x.first >= 0) {
			ft.update(x.second, 1);
			root -> update(x.second, n, 1);
			root -> update(x.second, x.second, -INF);
			x = root -> rmax(i, n);
		}
		while (!queries.empty() && queries.back().first.first == i - 1) {
			ans[queries.back().second] = ft.psum(n - queries.back().first.second);
			queries.pop_back();
		}
	}
	for (int i = 0; i < q; ++i) printf("%d\n", ans[i]);
	return 0;
}