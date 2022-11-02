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
using modulo = modint<998244353>;
const int limit = 200;
int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		if (A[i] != -1) --A[i];
	}
	vector<modulo> dp1(limit), dp2(limit);
	for (int i = 0; i < limit; ++i) {
		if (A[0] != -1 && A[0] != i) continue;
		for (int j = i; j < limit; ++j) {
			if ((A[1] != -1 && A[1] != j) || (N == 2 && i < j)) continue;
			if (i < j) dp2[j] += 1;
			else dp1[j] += 1;
		}
	}
	for (int i = 2; i < N; ++i) {
		vector<modulo> ndp1(limit), ndp2(limit);
		modulo cursum = 0;
		if (i != N - 1) {
			for (int j = 0; j < limit; ++j) {
				if (A[i] == -1 || A[i] == j) {
					ndp2[j] += cursum;
				}
				cursum += dp1[j] + dp2[j];
			}
		}
		cursum = 0;
		for (int j = limit - 1; j >= 0; --j) {
			cursum += dp1[j];
			if (A[i] == -1 || A[i] == j) {
				ndp1[j] += cursum + dp2[j];
			}
		}
		dp1 = ndp1;
		dp2 = ndp2;
	}
	modulo ans = 0;
	for (int i = 0; i < limit; ++i) {
		ans += dp1[i] + dp2[i];
	}
	cout << ans.get() << endl;
	return 0;
}