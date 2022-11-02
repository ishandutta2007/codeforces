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
#include <algorithm>
using namespace std;
using modulo = modint<1000000007>;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> L(N), R(N);
	for (int i = 0; i < N; ++i) cin >> L[i];
	for (int i = 0; i < N; ++i) cin >> R[i], ++R[i];
	modulo ex = 0;
	vector<modulo> seq(N - 1);
	for (int i = 0; i < N - 1; ++i) {
		modulo comb = modulo(R[i] - L[i]) * modulo(R[i + 1] - L[i + 1]), all = comb;
		int pl = max(L[i], L[i + 1]), pr = min(R[i], R[i + 1]);
		if (pl < pr) comb -= modulo(pr - pl);
		seq[i] = comb * all.inv();
		ex += seq[i];
	}
	modulo ans = ex * ex;
	for (int i = 0; i < N - 1; ++i) {
		modulo comb = modulo(R[i] - L[i]) * modulo(R[i + 1] - L[i + 1]), all = comb;
		int pl = max(L[i], L[i + 1]), pr = min(R[i], R[i + 1]);
		if (pl < pr) comb -= modulo(pr - pl);
		ans -= seq[i] * seq[i];
		ans += comb * all.inv();
	}
	for (int i = 0; i < N - 2; ++i) {
		modulo comb = modulo(R[i] - L[i]) * modulo(R[i + 1] - L[i + 1]) * modulo(R[i + 2] - L[i + 2]), all = comb;
		int pl1 = max(L[i], L[i + 1]), pr1 = min(R[i], R[i + 1]);
		int pl2 = max(L[i + 1], L[i + 2]), pr2 = min(R[i + 1], R[i + 2]);
		int pl3 = max(pl1, pl2), pr3 = min(pr1, pr2);
		if (pl1 < pr1) comb -= modulo(pr1 - pl1) * modulo(R[i + 2] - L[i + 2]);
		if (pl2 < pr2) comb -= modulo(pr2 - pl2) * modulo(R[i] - L[i]);
		if (pl3 < pr3) comb += modulo(pr3 - pl3);
		ans -= seq[i] * seq[i + 1] * 2;
		ans += comb * all.inv() * 2;
	}
	ans += ex * 2 + 1;
	cout << ans.get() << '\n';
	return 0;
}