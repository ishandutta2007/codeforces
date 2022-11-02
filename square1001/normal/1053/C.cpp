#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 1000000007;

class fenwicktree {
private:
	int sz, realsz;
	vector<long long> val;
public:
	fenwicktree() : sz(0), val(vector<long long>(1, 0)) {};
	fenwicktree(int sz_) : realsz(sz_) {
		sz = 1;
		while (sz <= sz_) sz *= 2;
		val = vector<long long>(sz + 1, 0);
	}
	void add(int pos, long long delta) {
		for (int i = pos + 1; i <= sz; i += i & (-i)) {
			val[i] += delta;
		}
	}
	long long sum(int pos) {
		long long ans = 0;
		for (int i = pos; i >= 1; i -= i & (-i)) {
			ans += val[i];
		}
		return ans;
	}
	int bsearch(long long x) {
		if (x == 0) return 0;
		int ans = 0;
		for (int i = sz / 2; i >= 1; i >>= 1) {
			if (val[ans + i] < x) {
				ans += i;
				x -= val[ans];
			}
		}
		if (ans > realsz) ans = realsz;
		return ans + 1;
	}
};

class fenwicktree_mod {
private:
	int sz, realsz;
	vector<int> val;
public:
	fenwicktree_mod() : sz(0), val(vector<int>(1, 0)) {};
	fenwicktree_mod(int sz_) : sz(sz_) {
		val = vector<int>(sz + 1, 0);
	}
	void add(int pos, long long delta) {
		if (delta < 0) delta = (mod - (-delta) % mod);
		delta %= mod;
		for (int i = pos + 1; i <= sz; i += i & (-i)) {
			val[i] += delta;
			if (val[i] >= mod) val[i] -= mod;
		}
	}
	int sum(int pos) {
		int ans = 0;
		for (int i = pos; i >= 1; i -= i & (-i)) {
			ans += val[i];
			if (ans >= mod) ans -= mod;
		}
		return ans;
	}
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	vector<int> A(N), W(N);
	for (int i = 0; i < N; ++i) cin >> A[i], A[i] -= i;
	for (int i = 0; i < N; ++i) cin >> W[i];
	fenwicktree seg(N);
	fenwicktree_mod sum(N);
	for (int i = 0; i < N; ++i) {
		seg.add(i, W[i]);
		sum.add(i, 1LL * W[i] * A[i]);
	}
	for (int i = 0; i < Q; ++i) {
		int x, y;
		cin >> x >> y;
		if (x < 0) {
			x *= -1;
			--x;
			seg.add(x, -W[x]);
			sum.add(x, -1LL * W[x] * A[x]);
			W[x] = y;
			seg.add(x, W[x]);
			sum.add(x, 1LL * W[x] * A[x]);
		}
		else {
			--x;
			long long sl = seg.sum(x);
			long long sr = seg.sum(y);
			int med = seg.bsearch((sl + sr + 1) / 2);
			int suml = sum.sum(x);
			int summ = sum.sum(med);
			int sumr = sum.sum(y);
			long long sm = seg.sum(med);
			int lcost = (1LL * (sm - sl) % mod * A[med - 1] - (summ - suml) + mod) % mod;
			int rcost = ((sumr - summ) - 1LL * (sr - sm) % mod * A[med - 1] % mod + 2LL * mod) % mod;
			cout << (lcost + rcost) % mod << '\n';
		}
	}
	return 0;
}