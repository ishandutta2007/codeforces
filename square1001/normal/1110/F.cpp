#include <limits>
#include <vector>
#include <algorithm>

template<typename Type> class RangeAddMinSegmentTree {
private:
	unsigned size_; std::vector<Type> dat1, dat2;
	inline void update_(unsigned a, unsigned b, Type x, unsigned k, unsigned l, unsigned r) {
		if (r <= a || b <= l) return;
		if (a <= l && r <= b) {
			dat2[k] += x; return;
		}
		update_(a, b, x, (k << 1), l, (l + r) >> 1);
		update_(a, b, x, (k << 1) + 1, (l + r) >> 1, r);
		dat1[k] = std::min(dat1[k << 1] + dat2[k << 1], dat1[(k << 1) + 1] + dat2[(k << 1) + 1]);
	}
	inline Type query_(unsigned a, unsigned b, unsigned k, unsigned l, unsigned r) {
		if (r <= a || b <= l) return std::numeric_limits<Type>::max();
		if (a <= l && r <= b) return dat1[k] + dat2[k];
		Type lc = query_(a, b, (k << 1), l, (l + r) >> 1);
		Type rc = query_(a, b, (k << 1) + 1, (l + r) >> 1, r);
		return std::min(lc, rc) + dat2[k];
	}
public:
	RangeAddMinSegmentTree() : size_(0), dat1(std::vector<Type>()), dat2(std::vector<Type>()) {};
	RangeAddMinSegmentTree(int size__) {
		for (size_ = 1; size_ < size__; ) size_ <<= 1;
		dat1.resize(size_ << 1, 0);
		dat2.resize(size_ << 1, 0);
	}
	inline unsigned size() { return size_; }
	inline void add(unsigned i, Type x) {
		update_(i, i + 1, x, 1, 0, size_);
	}
	inline void add(unsigned l, unsigned r, Type x) {
		update_(l, r, x, 1, 0, size_);
	}
	inline Type query(unsigned l, unsigned r) {
		return query_(l, r, 1, 0, size_);
	}
};

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
const long long inf = 1LL << 61;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	vector<vector<pair<int, long long> > > child(N);
	for(int i = 1; i < N; ++i) {
		int p; long long w;
		cin >> p >> w; --p;
		child[p].push_back(make_pair(i, w));
	}
	for(int i = 0; i < N; ++i) {
		sort(child[i].begin(), child[i].end());
	}
	vector<int> l(N), r(N);
	RangeAddMinSegmentTree<long long> seg(N);
	for(int i = 0; i < N; ++i) {
		seg.add(i, inf);
	}
	int cnt = 0;
	function<void(int, long long)> set_euler_tour = [&](int pos, long long depth) {
		if(child[pos].empty()) {
			seg.add(pos, depth - inf);
		}
		l[pos] = cnt++;
		for(pair<int, long long> i : child[pos]) {
			set_euler_tour(i.first, depth + i.second);
		}
		r[pos] = cnt;
	};
	set_euler_tour(0, 0);
	vector<int> V(Q), L(Q), R(Q);
	vector<vector<int> > G(N);
	for(int i = 0; i < Q; ++i) {
		cin >> V[i] >> L[i] >> R[i]; --V[i], --L[i];
		G[V[i]].push_back(i);
	}
	vector<long long> ans(Q);
	function<void(int)> answer_queries = [&](int pos) {
		for(int i : G[pos]) {
			ans[i] = seg.query(L[i], R[i]);
		}
		for(pair<int, long long> i : child[pos]) {
			seg.add(0, N, i.second);
			seg.add(l[i.first], r[i.first], -2 * i.second);
			answer_queries(i.first);
			seg.add(0, N, -i.second);
			seg.add(l[i.first], r[i.first], 2 * i.second);
		}
	};
	answer_queries(0);
	for(int i = 0; i < Q; ++i) {
		cout << ans[i] << '\n';
	}
	return 0;
}