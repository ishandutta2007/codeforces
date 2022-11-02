#ifndef CLASS_FAST_MODINT
#define CLASS_FAST_MODINT

#include <cstddef>
#include <cstdint>

static constexpr std::size_t digit_level = 8 * sizeof(std::uint32_t);
static constexpr std::uint32_t find_inv(std::uint32_t n, int d = 6, std::uint32_t x = 1) {
	return d == 0 ? x : find_inv(n, d - 1, x * (2 - x * n));
}
template <std::uint32_t mod> class fast_modint {
	// Fast Modulo Integer, Assertion: mod < 2^(bits of singlebit - 1) and mod is prime
private:
	std::uint32_t n;
	static constexpr std::uint32_t r2 = (((std::uint64_t(1) << digit_level) % mod) << digit_level) % mod;
	static constexpr std::uint32_t ninv = std::uint32_t(-1) * find_inv(mod);
	std::uint32_t reduce(std::uint64_t x) const {
		std::uint32_t res = (x + std::uint64_t(std::uint32_t(x) * ninv) * mod) >> digit_level;
		return res < mod ? res : res - mod;
	}
public:
	fast_modint() : n(0) {};
	fast_modint(std::uint32_t n_) { n = reduce(std::uint64_t(n_) * r2); };
	static constexpr std::uint32_t get_mod() { return mod; }
	std::uint32_t get() const { return reduce(n); }
	bool operator==(const fast_modint& x) const { return n == x.n; }
	bool operator!=(const fast_modint& x) const { return n != x.n; }
	fast_modint& operator+=(const fast_modint& x) { n += x.n; n -= (n < mod ? 0 : mod); return *this; }
	fast_modint& operator-=(const fast_modint& x) { n += mod - x.n; n -= (n < mod ? 0 : mod); return *this; }
	fast_modint& operator*=(const fast_modint& x) { n = reduce(std::uint64_t(n) * x.n); return *this; }
	fast_modint operator+(const fast_modint& x) const { return fast_modint(*this) += x; }
	fast_modint operator-(const fast_modint& x) const { return fast_modint(*this) -= x; }
	fast_modint operator*(const fast_modint& x) const { return fast_modint(*this) *= x; }
	fast_modint inv() const { return pow(mod - 2); }
	fast_modint pow(std::uint64_t b) const {
		fast_modint ans(1), cur(*this);
		while (b > 0) {
			if (b & 1) ans *= cur;
			cur *= cur;
			b >>= 1;
		}
		return ans;
	}
};

#endif // CLASS_FAST_MODINT

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using modulo = fast_modint<998244353>;
int main() {
	int N, K, L;
	cin >> N >> K >> L;
	vector<modulo> fact(N + 1), inv(N + 1), factinv(N + 1);
	fact[0] = 1, inv[1] = 1, factinv[0] = 1;
	for (int i = 1; i <= N; ++i) fact[i] = fact[i - 1] * i;
	for (int i = 2; i <= N; ++i) inv[i] = inv[modulo::get_mod() % i] * (modulo::get_mod() - modulo::get_mod() / i);
	for (int i = 1; i <= N; ++i) factinv[i] = factinv[i - 1] * inv[i];
	vector<modulo> poly(N + 1), comb(N + 1);
	for (int i = 0; i <= N; ++i) {
		comb[i] = fact[N] * factinv[i] * factinv[N - i];
		poly[i] = comb[i] * modulo(i & 1 ? modulo::get_mod() - 4 : 4).pow(i);
	}
	vector<modulo> sum(N + 1);
	for (int i = N; i >= K; --i) {
		for (int j = 0; j <= N; ++j) {
			sum[j] += poly[j] * comb[i];
		}
		for (int j = 0; j < N; ++j) {
			poly[j + 1] += poly[j] * 4;
		}
		for (int j = N - 1; j >= 0; --j) {
			poly[j + 1] += poly[j] * 4;
		}
	}
	modulo ans = 0;
	for (int i = 0; i <= N; ++i) {
		ans += sum[i] * modulo(2 * i + 1).inv() * modulo(2).inv().pow(2 * i + 1) * 2;
	}
	ans *= modulo(2).inv().pow(N);
	cout << (ans * L).get() << endl;
	return 0;
}