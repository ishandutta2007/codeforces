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
const int mod = 998244353;
using modulo = modint<mod>;
modulo solve(long long n, int m) {
	vector<vector<modulo> > dp(1024, vector<modulo>(4));
	vector<vector<modulo> > ways(1024, vector<modulo>(4));
	ways[0][0] = 1;
	// (leading zero) = true --> 0, 2 / (maximum) = true --> 0, 1
	long long mul = 1;
	for (int i = 0; i < 18; ++i) mul *= 10;
	for (int i = 18; i >= 0; --i) {
		int digit = n / mul % 10;
		vector<vector<modulo> > ndp(1024, vector<modulo>(4));
		vector<vector<modulo> > nways(1024, vector<modulo>(4));
		for (int j = 0; j < 1024; ++j) {
			for (int k = 0; k <= 9; ++k) {
				for (int l = 0; l < 4; ++l) {
					if (!(l & 2) && k > digit) continue;
					ndp[j | (!(l & 1) && k == 0 ? 0 : (1 << k))][l | (k < digit ? 2 : 0) | (k >= 1 ? 1 : 0)] += dp[j][l] + modulo(k * mul % mod) * ways[j][l];
					nways[j | (!(l & 1) && k == 0 ? 0 : (1 << k))][l | (k < digit ? 2 : 0) | (k >= 1 ? 1 : 0)] += ways[j][l];
				}
			}
		}
		dp = ndp;
		ways = nways;
		mul /= 10;
	}
	modulo ans = 0;
	for (int i = 1; i < 1024; ++i) {
		int cnt = 0;
		for (int j = 0; j <= 9; ++j) {
			if ((i >> j) & 1) ++cnt;
		}
		if (cnt <= m) {
			ans += dp[i][1] + dp[i][3];
		}
	}
	return ans;
}
int main() {
	long long l, r; int m;
	cin >> l >> r >> m;
	modulo ans1 = solve(l - 1, m);
	modulo ans2 = solve(r, m);
	cout << (ans2 - ans1).get() << endl;
	return 0;
}