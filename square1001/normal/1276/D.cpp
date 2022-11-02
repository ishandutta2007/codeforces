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
#include <algorithm>
using namespace std;
using mint = modint<998244353>;
class edge {
public:
	int to, id;
	edge() : to(-1), id(-1) {};
	edge(int to_, int id_) : to(to_), id(id_) {};
};
vector<mint> calc(int pos, int pre, vector<vector<edge> >& G) {
	// returns # of ways by (in, out, forced absent, non-forced absent)
	edge par;
	vector<edge> child;
	for (edge e : G[pos]) {
		if (e.to != pre) {
			child.push_back(e);
		}
		else {
			par = e;
		}
	}
	int S = child.size();
	vector<vector<mint> > dp(S);
	for (int i = 0; i < S; ++i) {
		dp[i] = calc(child[i].to, pos, G);
	}
	// part #1. calculate "in"
	mint res_in = 1;
	for (int i = 0; i < S; ++i) {
		if (child[i].id < par.id) {
			res_in *= dp[i][0] + dp[i][2];
		}
		else {
			res_in *= dp[i][3];
		}
	}
	// part #2. calculate "out"
	mint res_out = 0;
	vector<mint> pmul1(S + 1), pmul2(S + 1);
	pmul1[0] = 1; pmul2[S] = 1;
	for (int i = 0; i < S; ++i) pmul1[i + 1] = pmul1[i] * (dp[i][0] + dp[i][2]);
	for (int i = S - 1; i >= 0; --i) pmul2[i] = pmul2[i + 1] * dp[i][3];
	for (int i = 0; i < S; ++i) {
		if (child[i].id > par.id) {
			res_out += pmul1[i] * dp[i][1] * pmul2[i + 1];
		}
	}
	res_out += pmul1[S];
	// step #3. calculate "forced absent"
	mint res_fa = 0;
	for (int i = 0; i < S; ++i) {
		if (child[i].id < par.id) {
			res_fa += pmul1[i] * dp[i][1] * pmul2[i + 1];
		}
	}
	// step #4. calculate "non-forced absent"
	mint res_nfa = res_out + res_fa;
	return vector<mint>({ res_in, res_out, res_fa, res_nfa });
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<vector<edge> > G(N);
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b; --a, --b;
		G[a].push_back(edge(b, i));
		G[b].push_back(edge(a, i));
	}
	for (int i = 0; i < N; ++i) {
		sort(G[i].begin(), G[i].end(), [&](const edge& e1, const edge& e2) { return e1.id < e2.id; });
	}
	int S = G[0].size();
	vector<vector<mint> > dp(S);
	for (int i = 0; i < S; ++i) {
		dp[i] = calc(G[0][i].to, 0, G);
	}
	vector<mint> pmul1(S + 1), pmul2(S + 1);
	pmul1[0] = 1; pmul2[S] = 1;
	for (int i = 0; i < S; ++i) pmul1[i + 1] = pmul1[i] * (dp[i][0] + dp[i][2]);
	for (int i = S - 1; i >= 0; --i) pmul2[i] = pmul2[i + 1] * dp[i][3];
	mint ans = 0;
	for (int i = 0; i < S; ++i) {
		ans += pmul1[i] * dp[i][1] * pmul2[i + 1];
	}
	ans += pmul1[S];
	cout << ans.get() << endl;
	return 0;
}