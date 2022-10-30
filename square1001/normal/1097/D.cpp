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
#include <algorithm>
using namespace std;
const int mod = 1000000007;
using modulo = modint<mod>;
int main() {
	long long N; int K;
	cin >> N >> K;
	vector<pair<long long, int> > d;
	for (int i = 2; 1LL * i * i <= N; ++i) {
		if (N % i == 0) {
			int cnt = 0;
			while (N % i == 0) N /= i, ++cnt;
			d.push_back(make_pair(i, cnt));
		}
	}
	if (N >= 2) {
		d.push_back(make_pair(N, 1));
		N /= N;
	}
	modulo mul = 1;
	for (pair<long long, int> i : d) {
		vector<vector<modulo> > dp(K + 1, vector<modulo>(i.second + 1));
		dp[0][i.second] = 1;
		for (int j = 0; j < K; ++j) {
			for (int k = 0; k <= i.second; ++k) {
				modulo delta = dp[j][k] * modulo(k + 1).inv();
				for (int l = 0; l <= k; ++l) {
					dp[j + 1][l] += delta;
				}
			}
		}
		modulo expect = 0, submul = 1;
		for (int j = 0; j <= i.second; ++j) {
			expect += dp[K][j] * submul;
			submul *= modulo(i.first % mod);
		}
		mul *= expect;
	}
	cout << mul.get() << endl;
	return 0;
}