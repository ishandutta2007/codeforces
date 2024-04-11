#ifndef CLASS_MODINT
#define CLASS_MODINT

#include <cstdint>

template <std::uint32_t mod>
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
using namespace std;
using mint = modint<998244353>;
int main() {
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<vector<mint> > dp(N + 1, vector<mint>(2));
	dp[0][0] = 1;
	dp[0][1] = 0;
	for (int i = 1; i <= N; ++i) {
		dp[i][0] = dp[i - 1][0] * (K - 2) + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0] * (K - 1);
	}
	mint ans = 1;
	for (int parity = 0; parity < 2; ++parity) {
		vector<int> seq;
		for (int i = parity; i < N; i += 2) {
			seq.push_back(A[i]);
		}
		if (seq.empty()) continue;
		if (seq == vector<int>(seq.size(), -1)) {
			ans *= mint(K) * mint(K - 1).pow(seq.size() - 1);
		}
		else {
			while (seq.back() == -1) {
				ans *= K - 1;
				seq.pop_back();
			}
			int l = 0;
			while (seq[l] == -1) {
				ans *= K - 1;
				++l;
			}
			seq = vector<int>(seq.begin() + l, seq.end());
			int cont = 0, side = 0;
			for (int i = 0; i < seq.size(); ++i) {
				if (seq[i] != -1) {
					ans *= dp[cont][side != seq[i] ? 0 : 1];
					cont = 0;
					side = seq[i];
				}
				else ++cont;
			}
		}
	}
	cout << ans.get() << endl;
	return 0;
}