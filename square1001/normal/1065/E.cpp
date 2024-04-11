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
	int N, M, A;
	cin >> N >> M >> A;
	vector<int> seq(M);
	for(int i = 0; i < M; ++i) cin >> seq[i];
	seq.insert(seq.begin(), 0);
	modulo ans = modulo(A).pow(N - seq.back() * 2);
	for(int i = 0; i < M; ++i) {
		ans *= modulo(A).pow(seq[i + 1] - seq[i]);
		ans *= modulo(A).pow(seq[i + 1] - seq[i]) + 1;
		ans *= modulo(2).inv();
	}
	cout << ans.get() << endl;
	return 0;
}