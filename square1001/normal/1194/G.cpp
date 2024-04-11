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

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using modulo = modint<998244353>;
modulo dp[110][12][12][259];
int main() {
	string s;
	cin >> s;
	int n = s.size();
	reverse(s.begin(), s.end());
	s += "0000000000";
	modulo ans = 0;
	for(int x = 1; x <= 9; ++x) {
		for(int y = 1; y < x; ++y) {
			int g = __gcd(x, y);
			if(g != 1) continue;
			modulo subans = 0;
			for(int z = 0; z < n; ++z) {
				dp[0][0][0][0] = 1;
				for(int i = 0; i <= n; ++i) {
					for(int j = 0; j < x; ++j) {
						for(int k = 0; k < y; ++k) {
							for(int l = 0; l < 1 << (2 * (9 / x)); ++l) {
								dp[i + 1][j][k][l] = 0;
							}
						}
					}
					for(int j = 0; j < x; ++j) {
						for(int k = 0; k < y; ++k) {
							for(int l = 0; l < 10; ++l) {
								for(int m = 0; m < 1 << (2 * (9 / x)); ++m) {
									int nxtj = j + l * x, nxtk = k + l * y, bit = m;
									if(i == z && nxtj % 10 >= int(s[i] - '0') + (z == 0 ? 1 : 0)) continue;
									if(i > z && nxtj % 10 != s[i] - '0') continue;
									for(int p = 0; (p + 1) * x <= 9; ++p) {
										if(nxtj % 10 == (p + 1) * x) bit |= 1 << (2 * p);
										if(nxtk % 10 == (p + 1) * y) bit |= 1 << (2 * p + 1);
									}
									dp[i + 1][nxtj / 10][nxtk / 10][bit] += dp[i][j][k][m];
								}
							}
						}
					}
				}
				modulo subsum = 0;
				for(int i = 0; i < 1 << (2 * (9 / x)); ++i) {
					bool ok = false;
					for(int j = 0; j < 2 * (9 / x); j += 2) {
						if((i & (3 << j)) == (3 << j)) ok = true;
					}
					if(ok) subsum += dp[n + 1][0][0][i];
				}
				subans += subsum;
			}
			ans += subans * 2;
		}
	}
	modulo mul = 1;
	for(int i = 0; i < n; ++i) {
		ans += modulo(int(s[i] - '0')) * mul;
		mul *= 10;
	}
	cout << ans.get() << endl;
	return 0;
}