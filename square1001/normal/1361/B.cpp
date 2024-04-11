#ifndef CLASS_MODINT
#define CLASS_MODINT

#include <cstdint>

template <std::uint32_t mod>
class modint {
private:
	std::uint32_t n;
public:
	modint() : n(0) {};
	modint(std::int64_t n_) : n((n_ >= 0 ? n_ : mod - (-n_) % mod) % mod) {};
	static constexpr std::uint32_t get_mod() { return mod; }
	std::uint32_t get() const { return n; }
	bool operator==(const modint& m) const { return n == m.n; }
	bool operator!=(const modint& m) const { return n != m.n; }
	modint& operator+=(const modint& m) { n += m.n; n = (n < mod ? n : n - mod); return *this; }
	modint& operator-=(const modint& m) { n += mod - m.n; n = (n < mod ? n : n - mod); return *this; }
	modint& operator*=(const modint& m) { n = std::uint64_t(n) * m.n % mod; return *this; }
	modint operator+(const modint& m) const { return modint(*this) += m; }
	modint operator-(const modint& m) const { return modint(*this) -= m; }
	modint operator*(const modint& m) const { return modint(*this) *= m; }
	modint inv() const { return (*this).pow(mod - 2); }
	modint pow(std::uint64_t b) const {
		modint ans = 1, m = modint(*this);
		while (b) {
			if (b & 1) ans *= m;
			m *= m;
			b >>= 1;
		}
		return ans;
	}
};

#endif // CLASS_MODINT

#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using mint = modint<1000000007>;
const int inf = 1012345678;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int Q;
	cin >> Q;
	while (Q--) {
		int N, P;
		cin >> N >> P;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		if (P == 1) {
			cout << N % 2 << '\n';
		}
		else {
			sort(A.begin(), A.end());
			map<int, int> d;
			for (int i = 0; i < N; ++i) {
				++d[A[i]];
			}
			map<int, int>::iterator it = d.begin();
			while (it != d.end()) {
				if (it->second >= P) {
					d[(it->first) + 1] += d[it->first] / P;
					d[it->first] %= P;
				}
				++it;
			}
			map<int, int> d2;
			for (int i = 0; i < N; ++i) {
				++d2[A[i]];
			}
			map<int, int>::iterator it2 = d.end();
			int cur = 0, pre = inf;
			mint ans = 0;
			for (int i = 0; i < N; ++i) {
				ans += mint(P).pow(A[i]);
			}
			while (it2 != d.begin()) {
				--it2;
				if (cur > 0) {
					for (int j = pre; j > it2->first; --j) {
						if (1LL * cur * P >= inf) {
							cur = inf;
							break;
						}
						cur *= P;
					}
				}
				cur += it2->second;
				int use = min(cur / 2, d2[it2->first]);
				cur -= 2 * use;
				ans -= mint(P).pow(it2->first) * 2 * use;
				pre = it2->first;
			}
			cout << ans.get() << '\n';
		}
	}
	return 0;
}