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
using namespace std;
using modulo = modint<998244353>;
int main() {
	int N;
	cin >> N;
	vector<int> deg(N);
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b; --a, --b;
		++deg[a];
		++deg[b];
	}
	vector<modulo> fact(N + 1);
	fact[0] = 1;
	for (int i = 1; i <= N; ++i) fact[i] = fact[i - 1] * i;
	modulo ans = N;
	for (int i = 0; i < N; ++i) {
		ans *= fact[deg[i]];
	}
	cout << ans.get() << endl;
	return 0;
}