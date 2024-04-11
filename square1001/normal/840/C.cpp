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
#include <algorithm>
using namespace std;
using modulo = modint<1000000007>;
vector<modulo> convolve(vector<modulo> v1, vector<modulo> v2) {
	vector<modulo> ans(v1.size() + v2.size() - 1);
	for (int i = 0; i < v1.size(); ++i) {
		for (int j = 0; j < v2.size(); ++j) {
			ans[i + j] += v1[i] * v2[j];
		}
	}
	return ans;
}
int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		for (int j = 2; j * j <= A[i]; ++j) {
			while (A[i] % (j * j) == 0) {
				A[i] /= j * j;
			}
		}
	}
	vector<int> c;
	for (int i = 0; i < N; ++i) {
		if (A[i] != 0) {
			int cnt = 1;
			for (int j = i + 1; j < N; ++j) {
				if (A[i] == A[j]) ++cnt, A[j] = 0;
			}
			c.push_back(cnt);
		}
	}
	vector<modulo> fact(N + 1), factinv(N + 1);
	fact[0] = 1;
	for (int i = 1; i <= N; ++i) fact[i] = fact[i - 1] * i;
	for (int i = 0; i <= N; ++i) factinv[i] = fact[i].inv();
	vector<modulo> poly = { 1 };
	for (int i = 0; i < c.size(); ++i) {
		vector<modulo> sub(c[i] + 1);
		for (int j = 1; j <= c[i]; ++j) {
			sub[j] = fact[c[i] - 1] * factinv[j - 1] * factinv[c[i] - j] * factinv[j];
		}
		poly = convolve(poly, sub);
	}
	modulo ans = 0;
	for (int i = 1; i <= N; ++i) {
		ans += fact[i] * poly[i] * modulo((N - i) & 1 ? -1 : 1);
	}
	for (int i = 0; i < c.size(); ++i) {
		ans *= fact[c[i]];
	}
	cout << ans.get() << endl;
	return 0;
}