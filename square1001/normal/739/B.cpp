#ifndef CLASS_FENWICKTREE
#define CLASS_FENWICKTREE

#include <cstddef>

template <class type>
class fenwick_tree {
private:
	std::size_t n, sz;
	type* val;
public:
	fenwick_tree() : n(0), sz(0) {};
	fenwick_tree(std::size_t n_) : n(n_) {
		sz = 1; while (sz < n) sz *= 2;
		val = new type[sz + 1]();
	}
	template <class InputIterator>
	fenwick_tree(InputIterator first, InputIterator last) : n(last - first) {
		sz = 1; while (sz < n) sz *= 2;
		val = new type[sz + 1]();
		std::size_t cur = 0;
		for (InputIterator it = first; it != last; ++it) val[++cur] += *it;
		for (std::size_t i = 1; i < sz; ++i) val[i + (i & ~(i - 1))] += val[i];
	}
	~fenwick_tree() { delete[] val; }
	void add(std::size_t pos, type delta) {
		for (std::size_t i = pos + 1; i <= sz; i += i & ~(i - 1)) {
			val[i] += delta;
		}
	}
	type getsum(std::size_t r) const {
		type ans = 0;
		for (std::size_t i = r; i >= 1; i -= i & ~(i - 1)) {
			ans += val[i];
		}
		return ans;
	}
	type getsum(std::size_t l, std::size_t r) const {
		return getsum(r) - getsum(l);
	}
	std::size_t binary_search(type threshold) const {
		std::size_t ans = 0;
		for(std::size_t i = sz / 2; i >= 1; i >>= 1) {
			if(threshold >= val[ans + i]) {
				threshold -= val[ans + i];
				ans += i;
			}
		}
		return ans;
	}
};

#endif // CLASS_FENWICKTREE

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
struct edge {
	int to; long long cost;
};
struct query {
	int tp, pos; long long x;
};
bool operator<(const query& q1, const query& q2) {
	if(q1.x != q2.x) return q1.x < q2.x;
	return q1.tp < q2.tp;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<long long> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	vector<vector<edge> > G(n);
	for(int i = 1; i < n; ++i) {
		int p, w;
		cin >> p >> w; --p;
		G[p].push_back(edge{i, w});
		G[i].push_back(edge{p, w});
	}
	int cnt = 0;
	vector<long long> d(n);
	vector<int> l(n), r(n);
	function<void(int, int, long long)> dfs = [&](int pos, int pre, long long depth) {
		l[pos] = cnt++;
		d[pos] = depth;
		for(edge e : G[pos]) {
			if(e.to == pre) continue;
			dfs(e.to, pos, depth + e.cost);
		}
		r[pos] = cnt;
	};
	dfs(0, -1, 0);
	fenwick_tree<int> fen(n);
	vector<int> ans(n);
	vector<query> qs;
	for(int i = 0; i < n; ++i) {
		qs.push_back(query{1, i, d[i] - a[i]});
		qs.push_back(query{2, i, d[i]});
	}
	sort(qs.begin(), qs.end());
	for(query i : qs) {
		if(i.tp == 1) {
			fen.add(l[i.pos], 1);
		}
		else {
			ans[i.pos] = fen.getsum(l[i.pos], r[i.pos]);
		}
	}
	for(int i = 0; i < n; ++i) {
		if(i) cout << ' ';
		cout << ans[i] - 1;
	}
	cout << '\n';
	return 0;
}