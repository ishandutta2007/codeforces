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
using modulo = modint<1000003>;
const int limit = 10;
int main() {
	vector<vector<modulo> > a(limit + 2, vector<modulo>(modulo::get_mod()));
	for (int i = 0; i <= limit; ++i) {
		cout << "? " << i << endl;
		int x;
		cin >> x;
		a[0][i] = modulo(x);
	}
	for (int i = 1; i <= limit; ++i) {
		for (int j = 0; j <= limit - i; ++j) {
			a[i][j] = a[i - 1][j + 1] - a[i - 1][j];
		}
	}
	for (int i = limit + 1; i < modulo::get_mod(); ++i) {
		for (int j = limit; j >= 0; --j) {
			a[j][i - j] = a[j][i - j - 1] + a[j + 1][i - j - 1];
		}
	}
	int root = -1;
	for (int i = 0; i < modulo::get_mod(); ++i) {
		if (a[0][i].get() == 0) {
			root = i;
			break;
		}
	}
	cout << "! " << root << endl;
	return 0;
}