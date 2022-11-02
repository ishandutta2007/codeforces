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
	int N, D;
	cin >> N >> D;
	vector<int> p(N, -1);
	for (int i = 1; i < N; ++i) cin >> p[i], --p[i];
	vector<vector<modulo> > points(N, vector<modulo>(N + 1, modulo(1)));
	for (int i = N - 1; i >= 0; --i) {
		for (int j = 0; j < N; ++j) {
			points[i][j + 1] += points[i][j];
		}
		if (p[i] != -1) {
			for (int j = 0; j <= N; ++j) {
				points[p[i]][j] *= points[i][j];
			}
		}
	}
	vector<vector<modulo> > tri(N + 1);
	tri[0] = points[0];
	for (int i = 1; i <= N; ++i) {
		tri[i].resize(N - i + 1);
		for (int j = 0; j <= N - i; ++j) {
			tri[i][j] = tri[i - 1][j + 1] - tri[i - 1][j];
		}
	}
	modulo comb = 1, ans = 0;
	for (int i = 0; i <= N; ++i) {
		ans += comb * tri[i][0];
		comb *= D - i - 1;
		comb *= modulo(i + 1).inv();
	}
	cout << ans.get() << endl;
	return 0;
}