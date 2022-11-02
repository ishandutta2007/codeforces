#ifndef CLASS_MODINT
#define CLASS_MODINT

#include <cstdint>

template<std::uint32_t mod>
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

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using modulo = modint<998244353>;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> P(N);
	for (int i = 1; i < N; ++i) cin >> P[i], --P[i];
	vector<vector<int> > G(N);
	for (int i = 1; i < N; ++i) {
		G[P[i]].push_back(i);
	}
	vector<modulo> dp1(N), dp2(N), dp3(N);
	for (int i = N - 1; i >= 0; --i) {
		if (G[i].empty()) {
			dp2[i] = 1;
		}
		else {
			vector<modulo> ndp(3);
			ndp[0] = 1;
			for (int j : G[i]) {
				vector<modulo> nndp(3);
				for (int k = 0; k < 3; ++k) {
					nndp[k] += ndp[k] * (dp1[j] + dp2[j]);
					nndp[min(k + 1, 2)] += ndp[k] * (dp2[j] + dp3[j]);
				}
				ndp = nndp;
			}
			dp1[i] = ndp[0];
			dp2[i] = ndp[2];
			dp3[i] = ndp[1];
		}
	}
	cout << (dp1[0] + dp2[0]).get() << endl;
	return 0;
}