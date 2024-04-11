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

#include <string>
#include <vector>
#include <iostream>
using namespace std;
using mint = modint<1000000007>;
template<class type>
vector<type> walsh_hadamard_transform(int n, vector<type> a, bool rev) {
	for(int i = 0; i < n; ++i) {
		vector<type> nxt(1 << n);
		for(int j = 0; j < 1 << n; ++j) {
			if(!((j >> i) & 1)) {
				nxt[j] = a[j] + a[j ^ (1 << i)];
			}
			else {
				nxt[j] = a[j ^ (1 << i)] - a[j];
			}
		}
		a = nxt;
	}
	if(rev) {
		for(int i = 0; i < 1 << n; ++i) {
			a[i] /= 1 << n;
		}
	}
	return a;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n; string s;
	cin >> n >> s;
	vector<long long> a(1 << n);
	for(int i = 0; i < 1 << n; ++i) a[i] = s[i] - '0';
	vector<long long> f = walsh_hadamard_transform(n, a, false);
	for(int i = 0; i < 1 << n; ++i) f[i] = f[i] * f[i];
	vector<long long> g = walsh_hadamard_transform(n, f, true);
	mint ans = 0;
	for(int i = 0; i < 1 << n; ++i) {
		int cnt = 0;
		for(int j = 0; j < n; ++j) {
			if(!((i >> j) & 1)) ++cnt;
		}
		ans += mint(2).pow(cnt) * g[i];
	}
	cout << (ans * 3).get() << '\n';
	return 0;
}