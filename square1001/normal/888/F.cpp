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
#include <functional>
using namespace std;
using mint = modint<1000000007>;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int> > g(n, vector<int>(n));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> g[i][j];
		}
	}
	vector<vector<vector<mint> > > dp(n, vector<vector<mint> >(n + 1, vector<mint>(2)));
	vector<vector<vector<bool> > > vis(n, vector<vector<bool> >(n + 1, vector<bool>(2, false)));
	function<mint(int, int, bool)> calc = [&](int l, int r, bool f) {
		if(l + 1 == r) return mint(1);
		if(vis[l][r][f]) return dp[l][r][f];
		mint ans = (f ? calc(l + 1, r, false) : 0);
		for(int i = (f ? r - 2 : r - 1); i > l; --i) {
			if(g[l][i] == 1) {
				ans += calc(l, i + 1, true) * calc(i, r, f);
			}
		}
		vis[l][r][f] = true;
		dp[l][r][f] = ans;
		return ans;
	};
	mint ans = calc(0, n, false);
	cout << ans.get() << endl;
	return 0;
}