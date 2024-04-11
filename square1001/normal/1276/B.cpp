#ifndef CLASS_DISJOINT_SET
#define CLASS_DISJOINT_SET

#include <vector>
#include <cstdint>
#include <cstring>
#include <algorithm>

class disjoint_set {
private:
	typedef std::int32_t value_type;
	std::vector<value_type> val;
public:
	explicit disjoint_set() : val() {};
	explicit disjoint_set(std::size_t n) : val(n, -1) {};
	std::size_t size() const { return val.size(); }
	std::size_t size(std::size_t elem) { return std::size_t(-val[root(elem)]); }
	std::size_t root(std::size_t elem) {
		// path halving
		while (val[elem] >= 0 && val[val[elem]] >= 0) {
			val[elem] = val[val[elem]];
			elem = val[elem];
		}
		return std::size_t(val[elem] >= 0 ? val[elem] : elem);
	}
	void link(std::size_t elemx, std::size_t elemy) {
		elemx = root(elemx);
		elemy = root(elemy);
		if (elemx == elemy) return;
		if (val[elemx] > val[elemy]) {
			std::swap(elemx, elemy);
		}
		val[elemx] += val[elemy];
		val[elemy] = elemx;
	}
	bool connected(std::size_t elemx, std::size_t elemy) {
		return root(elemx) == root(elemy);
	}
};

#endif // CLASS_DISJOINT_SET

#include <map>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int Q;
	cin >> Q;
	while (Q--) {
		int N, M, A, B;
		cin >> N >> M >> A >> B; --A, --B;
		vector<int> ea(M), eb(M);
		for (int i = 0; i < M; ++i) {
			cin >> ea[i] >> eb[i]; --ea[i], --eb[i];
		}
		disjoint_set ufa(N), ufb(N), ufc(N);
		for (int i = 0; i < M; ++i) {
			if (ea[i] != A && eb[i] != A) {
				ufa.link(ea[i], eb[i]);
			}
			if (ea[i] != B && eb[i] != B) {
				ufb.link(ea[i], eb[i]);
			}
		}
		vector<int> c1(N), c2(N);
		map<pair<int, int>, int> c3;
		for (int i = 0; i < N; ++i) {
			if (i == A || i == B) continue;
			int xc = ufa.root(i), yc = ufb.root(i);
			++c1[xc];
			++c2[yc];
			++c3[make_pair(xc, yc)];
		}
		long long ans = 1LL * (N - 2) * (N - 3) / 2;
		for (int i = 0; i < N; ++i) {
			ans -= 1LL * c1[i] * (c1[i] - 1) / 2;
			ans -= 1LL * c2[i] * (c2[i] - 1) / 2;
		}
		for (pair<pair<int, int>, int> i : c3) {
			ans += 1LL * i.second * (i.second - 1) / 2;
		}
		cout << ans << '\n';
	}
	return 0;
}