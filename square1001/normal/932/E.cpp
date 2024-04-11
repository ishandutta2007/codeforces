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

#include <vector>
#include <iostream>
using namespace std;
using modulo = modint<1000000007>;
int main() {
	int N, K;
	cin >> N >> K;
	vector<vector<modulo> > stirling2(K + 1);
	for (int i = 0; i <= K; ++i) {
		stirling2[i].resize(i + 1);
		if (i == 0) stirling2[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			stirling2[i][j] = stirling2[i - 1][j - 1];
			if (j != i) stirling2[i][j] += stirling2[i - 1][j] * j;
		}
	}
	vector<modulo> fact(K + 1);
	fact[0] = 1;
	for (int i = 1; i <= K; ++i) {
		fact[i] = fact[i - 1] * i;
	}
	vector<vector<modulo> > comb(K + 1);
	for (int i = 0; i <= K; ++i) {
		comb[i].resize(i + 1);
		comb[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			comb[i][j] = comb[i - 1][j - 1];
			if (j != i) comb[i][j] += comb[i - 1][j];
		}
	}
	modulo ans = 0, mul = 1;
	for (int i = 1; i <= K; ++i) {
		mul *= N - i + 1;
		mul *= modulo(i).inv();
		modulo sub = stirling2[K][i] * fact[i] * modulo(2).binpow(N - i);
		ans += sub * mul;
	}
	cout << ans.get() << endl;
	return 0;
}