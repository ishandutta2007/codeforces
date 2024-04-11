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
using modulo = modint<1000000007>;
int main() {
	int N;
	cin >> N;
	vector<int> initial(N + 1);
	vector<modulo> dp(N + 1);
	for (int i = 1; i <= N; ++i) {
		vector<int> pds;
		int x = i, mul = 1;
		for (int j = 2; j * j <= x; ++j) {
			if (x % j == 0) {
				mul *= j;
				pds.push_back(j);
				while (x % j == 0) x /= j;
			}
		}
		if (x > 1) mul *= x, pds.push_back(x), x = 1;
		initial[i] = mul;
		if (mul == i && i != 1) {
			vector<int> mulpds(1 << pds.size());
			mulpds[0] = 1;
			for (int j = 0; j < pds.size(); ++j) {
				for (int k = 1 << j; k < 2 << j; ++k) {
					mulpds[k] = mulpds[k - (1 << j)] * pds[j];
				}
			}
			vector<int> prob(1 << pds.size());
			for (int j = 0; j < 1 << pds.size(); ++j) {
				prob[j] = N / mulpds[j];
			}
			for (int j = 0; j < pds.size(); ++j) {
				for (int k = 0; k < 1 << pds.size(); ++k) {
					if ((k >> j) & 1) prob[k - (1 << j)] -= prob[k];
				}
			}
			modulo coeff = (modulo(N - prob.back())).inv();
			for (int j = 0; j < (1 << pds.size()) - 1; ++j) {
				dp[i] += coeff * prob[j] * dp[mulpds[j]];
			}
			dp[i] += coeff * N;
		}
	}
	modulo ans = 0;
	for (int i = 1; i <= N; ++i) {
		ans += dp[initial[i]];
	}
	ans *= modulo(N).inv();
	cout << (ans + 1).get() << endl;
	return 0;
}