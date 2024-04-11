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
const int mod = 1000000007;
using modulo = modint<mod>;
int N, K, A[109]; modulo ans[55][55], mat[55][55], tmp[55][55];
int main() {
	cin >> N >> K;
	int zeros = 0, ones = 0;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		if (A[i] == 0) ++zeros;
		else ++ones;
	}
	int inidiff = 0;
	for (int i = 0; i < N; ++i) {
		if (A[i] == 0 && i >= zeros) ++inidiff;
	}
	modulo allposs = modulo(N * (N - 1) / 2);
	int md = min(zeros, ones);
	for (int i = 0; i <= md; ++i) {
		for (int j = 0; j <= md; ++j) {
			if (i - j == 1) {
				mat[i][j] = modulo(i * i) * allposs.inv();
			}
			if (i - j == 0) {
				mat[i][j] = modulo(allposs - i * i - (zeros - i) * (ones - i)) * allposs.inv();
			}
			if (i - j == -1) {
				mat[i][j] = modulo((zeros - i) * (ones - i)) * allposs.inv();
			}
		}
	}
	for (int i = 0; i <= md; ++i) {
		ans[i][i] = modulo(1);
	}
	while (K > 0) {
		if (K & 1) {
			for (int i = 0; i <= md; ++i) {
				for (int j = 0; j <= md; ++j) {
					tmp[i][j] = 0;
				}
			}
			for (int i = 0; i <= md; ++i) {
				for (int j = 0; j <= md; ++j) {
					for (int k = 0; k <= md; ++k) {
						tmp[i][j] += ans[i][k] * mat[k][j];
					}
				}
			}
			for (int i = 0; i <= md; ++i) {
				for (int j = 0; j <= md; ++j) {
					ans[i][j] = tmp[i][j];
				}
			}
		}
		for (int i = 0; i <= md; ++i) {
			for (int j = 0; j <= md; ++j) {
				tmp[i][j] = 0;
			}
		}
		for (int i = 0; i <= md; ++i) {
			for (int j = 0; j <= md; ++j) {
				for (int k = 0; k <= md; ++k) {
					tmp[i][j] += mat[i][k] * mat[k][j];
				}
			}
		}
		for (int i = 0; i <= md; ++i) {
			for (int j = 0; j <= md; ++j) {
				mat[i][j] = tmp[i][j];
			}
		}
		K >>= 1;
	}
	cout << ans[inidiff][0].get() << endl;
	return 0;
}