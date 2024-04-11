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

#include <string>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;
const int maximum = 100000;
const int limit = 400;
using modulo = modint<1000000007>;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	vector<modulo> fact(maximum + 1);
	fact[0] = 1;
	for (int i = 1; i <= maximum; ++i) {
		fact[i] = fact[i - 1] * i;
	}
	vector<modulo> factinv(maximum + 1);
	for (int i = 0; i <= maximum; ++i) {
		factinv[i] = fact[i].inv();
	}
	function<modulo(int, int)> comb = [&](int a, int b) {
		if (b < 0 || a < b) return modulo(0);
		return fact[a] * factinv[b] * factinv[a - b];
	};
	int Q;
	cin >> Q;
	string S;
	vector<modulo> ans;
	for (int i = 0; i < Q + 1; ++i) {
		int tp;
		if (i >= 1) cin >> tp;
		else tp = 1;
		if (tp == 1) {
			cin >> S;
			if (S.size() > limit) {
				ans = vector<modulo>(maximum + 1, 0);
				ans[S.size()] = 1;
				for (int j = S.size() + 1; j <= maximum; ++j) {
					ans[j] = ans[j - 1] * 26 + comb(j - 1, S.size() - 1) * modulo(25).binpow(j - S.size());
				}
			}
		}
		else {
			int N;
			cin >> N;
			if (S.size() <= limit) {
				modulo sub = modulo(26).binpow(N);
				for (int j = 0; j < S.size(); ++j) {
					sub -= modulo(25).binpow(N - j) * comb(N, j);
				}
				cout << sub.get() << '\n';
			}
			else {
				cout << ans[N].get() << '\n';
			}
		}
	}
	return 0;
}