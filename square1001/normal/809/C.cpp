#ifndef ___CLASS_MODINT
#define ___CLASS_MODINT

#include <cstdint>

template<std::uint32_t mod>
class modint {
private:
	std::uint32_t n;
public:
	modint() : n(0) {};
	modint(std::uint64_t n_) : n(n_ % mod) {};
	bool operator==(const modint& m) const { return n == m.n; }
	bool operator!=(const modint& m) const { return n != m.n; }
	std::uint32_t get() const { return n; }
	modint& operator+=(const modint& m) { n += m.n; n = (n < mod ? n : n - mod); return *this; }
	modint& operator-=(const modint& m) { n += mod - m.n; n = (n < mod ? n : n - mod); return *this; }
	modint& operator*=(const modint& m) { n = std::uint64_t(n) * m.n % mod; return *this; }
	modint operator+(const modint& m) const { return modint(*this) += m; }
	modint operator-(const modint& m) const { return modint(*this) -= m; }
	modint operator*(const modint& m) const { return modint(*this) *= m; }
	modint binpow(std::uint64_t b) const {
		modint ans = 1, m = modint(*this);
		while (b) {
			if (b & 1) ans *= m;
			m *= m;
			b >>= 1;
		}
		return ans;
	}
	modint inv() { return (*this).binpow(mod - 2); }
};

#endif // ___CLASS_MODINT

#include <iostream>
#include <algorithm>
using namespace std;
using modulo = modint<1000000007>;
modulo solve(int x, int y, int c) {
	modulo ans = 0;
	for (int i = x; i > 0; i -= i & (-i)) {
		for (int j = y; j > 0; j -= j & (-j)) {
			int lx = i - (i & (-i));
			int ly = j - (j & (-j));
			int z = lx ^ ly;
			int rng = max(i & (-i), j & (-j));
			z &= ~(rng - 1);
			if (z <= c) {
				int mult = min(i & (-i), j & (-j));
				int common = min(z + rng, c);
				modulo sub = modulo(z + common + 1) * modulo(common - z) * modulo(2).inv() * mult;
				ans += sub;
			}
		}
	}
	return ans;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int xa, ya, xb, yb, c;
		cin >> xa >> ya >> xb >> yb >> c; --xa, --ya;
		modulo sa = solve(xa, ya, c);
		modulo sb = solve(xb, yb, c);
		modulo sc = solve(xa, yb, c);
		modulo sd = solve(xb, ya, c);
		cout << (sa + sb - sc - sd).get() << '\n';
	}
	return 0;
}