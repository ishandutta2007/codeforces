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
	std::uint32_t get() const { return n; }
	bool operator==(const modint& m) const { return n == m.n; }
	bool operator!=(const modint& m) const { return n != m.n; }
	modint& operator+=(const modint& m) { n += m.n; n = (n < mod ? n : n - mod); return *this; }
	modint& operator-=(const modint& m) { n += mod - m.n; n = (n < mod ? n : n - mod); return *this; }
	modint& operator*=(const modint& m) { n = std::uint64_t(n) * m.n % mod; return *this; }
	modint operator+(const modint& m) const { return modint(*this) += m; }
	modint operator-(const modint& m) const { return modint(*this) -= m; }
	modint operator*(const modint& m) const { return modint(*this) *= m; }
	modint pow(std::uint64_t b) const {
		modint ans = 1, m = modint(*this);
		while (b) {
			if (b & 1) ans *= m;
			m *= m;
			b >>= 1;
		}
		return ans;
	}
	modint inv() const { return (*this).pow(mod - 2); }
};

#endif // CLASS_MODINT

#include <vector>
#include <iostream>
using namespace std;
using modulo = modint<998244353>;
int main() {
	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	vector<modulo> W(N);
	for(int i = 0; i < N; ++i) cin >> A[i];
	modulo iw0 = 0, iw1 = 0;
	for(int i = 0; i < N; ++i) {
		int w;
		cin >> w;
		W[i] = w;
		if(A[i] == 0) iw0 += W[i];
		else iw1 += W[i];
	}
	vector<vector<modulo> > dp(M + 1);
	dp[0] = { modulo(1) };
	for(int i = 1; i <= M; ++i) {
		dp[i].resize(i + 1);
		for(int j = 0; j < i; ++j) {
			modulo w0 = iw0 - modulo(j), w1 = iw1 + (modulo(i - 1 - j));
			dp[i][j] += dp[i - 1][j] * w1 * (w0 + w1).inv();
			dp[i][j + 1] += dp[i - 1][j] * w0 * (w0 + w1).inv();
		}
	}
	modulo exp0 = 0, exp1 = 0;
	for(int i = 0; i <= M; ++i) {
		modulo w0 = iw0 - modulo(i), w1 = iw1 + (modulo(M - i));
		exp0 += w0 * dp[M][i];
		exp1 += w1 * dp[M][i];
	}
	for(int i = 0; i < N; ++i) {
		modulo ans;
		if(A[i] == 0) ans = exp0 * W[i] * iw0.inv();
		else ans = exp1 * W[i] * iw1.inv();
		cout << ans.get() << '\n';
	}
	return 0;
}