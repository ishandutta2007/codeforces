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
const int mod = 1000000007;
using modulo = modint<mod>;
vector<modulo> fact, inv, factinv;
int solve(int n, vector<int> arr) {
	vector<int> num(arr.size() + 1);
	for(int i = 0; i < arr.size(); ++i) {
		num[i] = n / arr[i];
	}
	for(int i = 0; i < arr.size(); ++i) {
		num[i] -= num[i + 1];
	}
	int cur = 0;
	modulo ans = 1;
	for(int i = 0; i < arr.size(); ++i) {
		ans *= fact[cur + num[i] - 1] * factinv[cur] * num[i];
		cur += num[i];
	}
	return ans.get();
}
int main() {
	int N;
	cin >> N;
	fact.resize(N + 1); fact[0] = 1;
	inv.resize(N + 1); inv[1] = 1;
	factinv.resize(N + 1); factinv[0] = 1;
	for(int i = 1; i <= N; ++i) fact[i] = fact[i - 1] * i;
	for(int i = 2; i <= N; ++i) inv[i] = inv[mod % i] * (mod - mod / i);
	for(int i = 1; i <= N; ++i) factinv[i] = factinv[i - 1] * inv[i];
	if(N == 1) {
		cout << 1 << endl;
	}
	else {
		int b = 0;
		while((1 << (b + 1)) <= N) ++b;
		vector<int> seq = { 1 };
		for(int i = 0; i < b; ++i) seq.push_back(seq.back() * 2);
		modulo ans = solve(N, seq);
		if((3 << (b - 1)) <= N) {
			for(int i = seq.size() - 1; i >= 1; --i) {
				seq[i] = seq[i] * 3 / 2;
				ans += solve(N, seq);
			}
		}
		cout << ans.get() << endl;
	}
	return 0;
}