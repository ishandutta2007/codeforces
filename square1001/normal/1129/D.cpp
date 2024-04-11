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

#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
using modulo = modint<998244353>;
int main() {
	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i], --A[i];
	}
	int B = sqrt(N);
	vector<int> bdiv(B + 1);
	vector<int> bpos(N + 1);
	for (int i = 0; i <= B; ++i) {
		bdiv[i] = i * N / B;
		if (i >= 1) {
			for (int j = bdiv[i - 1]; j < bdiv[i]; ++j) {
				bpos[j] = i - 1;
			}
		}
	}
	bpos[N] = B;
	vector<vector<int> > G(N, vector<int>({ 0 }));
	vector<modulo> dp(N + 1);
	vector<int> c(N + 1);
	vector<int> d(B);
	vector<vector<int> > sorting(B);
	vector<vector<modulo> > sum(B);
	function<void(int, int)> add = [&](int r, int x) {
		if (r == 0) return;
		int bid = bpos[r - 1];
		for (int i = 0; i < bid; ++i) {
			d[i] += x;
		}
		for (int i = bdiv[bid]; i < bdiv[bid + 1]; ++i) {
			c[i] += d[bid];
			if (i < r) c[i] += x;
		}
		d[bid] = 0;
		sorting[bid] = vector<int>(bdiv[bid + 1] - bdiv[bid]);
		for (int i = bdiv[bid]; i < bdiv[bid + 1]; ++i) {
			sorting[bid][i - bdiv[bid]] = i;
		}
		sort(sorting[bid].begin(), sorting[bid].end(), [&](int i, int j) { return c[i] < c[j]; });
		sum[bid] = vector<modulo>(bdiv[bid + 1] - bdiv[bid] + 1);
		for (int i = 0; i < sorting[bid].size(); ++i) {
			sum[bid][i + 1] = sum[bid][i] + dp[sorting[bid][i]];
		}
		for (int i = 0; i < sorting[bid].size(); ++i) {
			sorting[bid][i] = c[sorting[bid][i]];
		}
	};
	function<modulo(void)> getsum = [&](void) {
		modulo ans = 0;
		for (int i = 0; i < B; ++i) {
			if (sorting[i].empty()) break;
			int ptr = upper_bound(sorting[i].begin(), sorting[i].end(), M - d[i]) - sorting[i].begin();
			ans += sum[i][ptr];
		}
		return ans;
	};
	dp[0] = 1;
	for (int i = 0; i < N; ++i) {
		if (G[A[i]].size() >= 2) {
			add(G[A[i]][G[A[i]].size() - 2], 1);
			add(G[A[i]][G[A[i]].size() - 1], -1);
		}
		G[A[i]].push_back(i + 1);
		add(G[A[i]][G[A[i]].size() - 2], -1);
		add(G[A[i]][G[A[i]].size() - 1], 1);
		dp[i + 1] = getsum();
	}
	cout << dp[N].get() << '\n';
	return 0;
}