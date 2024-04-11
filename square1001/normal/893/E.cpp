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
#include <functional>
using namespace std;
using modulo = modint<1000000007>;
const int limit = 1000000;
int main() {
	vector<modulo> fact(limit * 2 + 1), inv(limit * 2 + 1), factinv(limit * 2 + 1);
	fact[0] = 1; inv[1] = 1; factinv[0] = 1;
	for (int i = 1; i <= limit * 2; ++i) fact[i] = fact[i - 1] * i;
	for (int i = 2; i <= limit * 2; ++i) inv[i] = inv[modulo::get_mod() % i] * (modulo::get_mod() - modulo::get_mod() / i);
	for (int i = 1; i <= limit * 2; ++i) factinv[i] = factinv[i - 1] * inv[i];
	function<modulo(int, int)> comb = [&](int n, int m) {
		if (m < 0 || n < m) return modulo(0);
		return fact[n] * factinv[m] * factinv[n - m];
	};
	vector<bool> prime(limit + 1, true); prime[0] = false, prime[1] = false;
	vector<vector<int> > divs(limit + 1);
	for (int i = 2; i <= limit; ++i) {
		if (!prime[i]) continue;
		for (int j = i * 2; j <= limit; j += i) {
			prime[j] = false;
		}
	}
	for (int i = 2; i <= limit; ++i) {
		if (!prime[i]) continue;
		long long cur = i;
		for (int j = 1; cur <= limit; cur *= i, ++j) {
			for (int k = cur; k <= limit; k += cur) {
				if ((k / cur) % i != 0) divs[k].push_back(j);
			}
		}
	}
	int Q;
	cin >> Q;
	while (Q--) {
		int X, Y;
		cin >> X >> Y;
		modulo ans = 1;
		for (int i : divs[X]) {
			ans *= comb(i + Y - 1, i);
		}
		ans *= modulo(2).pow(Y - 1);
		cout << ans.get() << '\n';
	}
	return 0;
}