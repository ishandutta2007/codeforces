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

using modulo = modint<1000000007>;
const int limit = 300;

#include <string>
#include <vector>
#include <iostream>
using namespace std;
class segmenttree {
private:
	int sz;
	int num_primes;
	// data
	vector<modulo> mul;
	vector<long long> bit;
	vector<modulo> lazymul;
	vector<long long> lazybit;
	vector<int> weight;
	// primes
	vector<modulo> plist;
	vector<modulo> pinv;
	vector<long long> pb;
public:
	segmenttree() : sz(0), mul(vector<modulo>()), bit(vector<long long>()) {};
	segmenttree(int sz_) {
		sz = 1;
		while (sz < sz_) sz *= 2;
		num_primes = 0;
		for (int i = 2; i <= limit; ++i) {
			bool flag = true;
			for (int j = 2; j * j <= i && flag; ++j) {
				if (i % j == 0) flag = false;
			}
			if (flag) plist.push_back(modulo(i));
		}
		num_primes = plist.size();
		pb = vector<long long>(limit + 1, 0);
		for (int i = 1; i <= limit; ++i) {
			for (int j = 0; j < num_primes; ++j) {
				if (i % plist[j].get() == 0) {
					pb[i] |= 1LL << j;
				}
			}
		}
		pinv = vector<modulo>(num_primes);
		for (int i = 0; i < num_primes; ++i) {
			pinv[i] = plist[i].inv();
		}
		mul = vector<modulo>(sz * 2, modulo(1));
		bit = vector<long long>(sz * 2, 0);
		lazymul = vector<modulo>(sz * 2, modulo(1));
		lazybit = vector<long long>(sz * 2, 0);
		weight = vector<int>(sz * 2, 0);
		for (int i = sz; i < sz * 2; ++i) weight[i] = 1;
		for (int i = sz - 1; i >= 1; --i) weight[i] = weight[i * 2] + weight[i * 2 + 1];
	}
	void push(int pos) {
		if (lazybit[pos] == 0) return;
		mul[pos] *= lazymul[pos].binpow(weight[pos]);
		bit[pos] |= lazybit[pos];
		if (pos < sz) {
			lazymul[pos * 2] *= lazymul[pos];
			lazybit[pos * 2] |= lazybit[pos];
			lazymul[pos * 2 + 1] *= lazymul[pos];
			lazybit[pos * 2 + 1] |= lazybit[pos];
		}
		lazymul[pos] = modulo(1);
		lazybit[pos] = 0;
	}
	void multiply(int a, int b, int x, int k, int l, int r) {
		push(k);
		if (r <= a || b <= l) return;
		if (a <= l && r <= b) {
			lazymul[k] *= modulo(x);
			lazybit[k] |= pb[x];
			push(k);
			return;
		}
		multiply(a, b, x, k * 2, l, (l + r) >> 1);
		multiply(a, b, x, k * 2 + 1, (l + r) >> 1, r);
		mul[k] = mul[k * 2] * mul[k * 2 + 1];
		bit[k] = bit[k * 2] | bit[k * 2 + 1];
	}
	modulo get_multiple(int a, int b, int k, int l, int r) {
		push(k);
		if (r <= a || b <= l) return modulo(1);
		if (a <= l && r <= b) return mul[k];
		modulo lc = get_multiple(a, b, k * 2, l, (l + r) >> 1);
		modulo rc = get_multiple(a, b, k * 2 + 1, (l + r) >> 1, r);
		mul[k] = mul[k * 2] * mul[k * 2 + 1];
		bit[k] = bit[k * 2] | bit[k * 2 + 1];
		return lc * rc;
	}
	long long get_bitor(int a, int b, int k, int l, int r) {
		push(k);
		if (r <= a || b <= l) return 0;
		if (a <= l && r <= b) return bit[k];
		long long lc = get_bitor(a, b, k * 2, l, (l + r) >> 1);
		long long rc = get_bitor(a, b, k * 2 + 1, (l + r) >> 1, r);
		mul[k] = mul[k * 2] * mul[k * 2 + 1];
		bit[k] = bit[k * 2] | bit[k * 2 + 1];
		return lc | rc;
	}
	void multiply(int l, int r, int x) {
		multiply(l, r, x, 1, 0, sz);
	}
	modulo get_totient(int l, int r) {
		modulo resmul = get_multiple(l, r, 1, 0, sz);
		long long resbit = get_bitor(l, r, 1, 0, sz);
		for (int i = 0; i < num_primes; ++i) {
			if ((resbit >> i) & 1) {
				resmul *= (plist[i] - 1) * pinv[i];
			}
		}
		return resmul;
	}
};
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	segmenttree seg(N);
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		seg.multiply(i, i + 1, x);
	}
	for (int i = 0; i < Q; ++i) {
		string tp;
		cin >> tp;
		if (tp == "MULTIPLY") {
			int l, r, x;
			cin >> l >> r >> x; --l;
			seg.multiply(l, r, x);
		}
		if (tp == "TOTIENT") {
			int l, r;
			cin >> l >> r; --l;
			modulo res = seg.get_totient(l, r);
			cout << res.get() << '\n';
		}
	}
	return 0;
}