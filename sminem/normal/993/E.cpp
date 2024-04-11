#include <bits/stdc++.h>
using namespace std;

namespace fft1 {

	const int mod = 167772161;
	const int root = 243;
	const int root_1 = 114609789;
	const int root_pw = 1 << 25;

	template<class T>
	T eea(T a, T b, T& x, T& y) {
		if (!b) {
			x = 1;
			y = 0;
			return a;
		}
	
		T x1, y1;
		T g = eea(b, a % b, x1, y1);
		x = y1;
		y = x1 - (a / b) * y1;
		return g;
	}

	int inverse(int n) {
		int x, y;
		eea(n, mod, x, y);
		x %= mod;
		if (x < 0)
			x += mod;
		return x;
	}

	void fft(vector<int>& a, bool invert) {
		int n = a.size();

		for (int i = 1, j = 0; i < n; i++) {
			int bit = n >> 1;
			for (; j & bit; bit >>= 1)
				j ^= bit;
			j ^= bit;

			if (i < j)
				swap(a[i], a[j]);
		}

		for (int len = 2; len <= n; len <<= 1) {
			int wlen = invert ? root_1 : root;
			for (int i = len; i < root_pw; i <<= 1)
				wlen = 1LL * wlen * wlen % mod;

			for (int i = 0; i < n; i += len) {
				int w = 1;
				for (int j = 0; j < len / 2; j++) {
					int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
					a[i+j] = u + v < mod ? u + v : u + v - mod;
					a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
					w = 1LL * w * wlen % mod;
				}
			}
		}

		if (invert) {
			int n_1 = inverse(n);
			for (int& x : a)
				x = 1LL * x * n_1 % mod;
		}
	}
}

namespace fft2 {

	const int mod = 23068673;
	const int root = 177147;
	const int root_1 = 17187657;
	const int root_pw = 1 << 21;

	template<class T>
	T eea(T a, T b, T& x, T& y) {
		if (!b) {
			x = 1;
			y = 0;
			return a;
		}
	
		T x1, y1;
		T g = eea(b, a % b, x1, y1);
		x = y1;
		y = x1 - (a / b) * y1;
		return g;
	}

	int inverse(int n) {
		int x, y;
		eea(n, mod, x, y);
		x %= mod;
		if (x < 0)
			x += mod;
		return x;
	}

	void fft(vector<int>& a, bool invert) {
		int n = a.size();

		for (int i = 1, j = 0; i < n; i++) {
			int bit = n >> 1;
			for (; j & bit; bit >>= 1)
				j ^= bit;
			j ^= bit;

			if (i < j)
				swap(a[i], a[j]);
		}

		for (int len = 2; len <= n; len <<= 1) {
			int wlen = invert ? root_1 : root;
			for (int i = len; i < root_pw; i <<= 1)
				wlen = 1LL * wlen * wlen % mod;

			for (int i = 0; i < n; i += len) {
				int w = 1;
				for (int j = 0; j < len / 2; j++) {
					int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
					a[i+j] = u + v < mod ? u + v : u + v - mod;
					a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
					w = 1LL * w * wlen % mod;
				}
			}
		}

		if (invert) {
			int n_1 = inverse(n);
			for (int& x : a)
				x = 1LL * x * n_1 % mod;
		}
	}
}

int sol[600005];

int n, x;
int a[200005];
int b[200005];

long long bigmod(long long x, long long y, long long m) {
	long long z = 0;
	for (int i=60; i>=0; i--) {
		z += z;
		if (z >= m)
			z -= m;
		if (x & (1ll << i)) {
			z += y;
			if (z >= m)
				z -= m;
		}
	}
	return z;
}

const long long mm = fft1::mod * 1ll * fft2::mod;
long long i1, i2;

long long crt(long long x, long long y) {
	x = bigmod(x, i2, mm);
	y = bigmod(y, i1, mm);
	return (bigmod(x, fft2::mod, mm) + bigmod(y, fft1::mod, mm)) % mm;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	fft1::eea<long long>(fft1::mod, fft2::mod, i1, i2);
	i1 = (i1 % mm + mm) % mm;
	i2 = (i2 % mm + mm) % mm;

	cin >> n >> x;
	for (int i=1; i<=n; i++) {
		int y;
		cin >> y;
		a[i] = y < x;
		b[i] = b[i-1] + a[i];
	}

	int st2 = 1;
	while (st2 <= 2*n+2) st2 *= 2;
	vector<int> aa(st2, 0), bb(st2, 0);
	for (int i=0; i<=n; i++) {
		aa[b[i]]++;
		bb[n - b[i]]++;
	}

	vector<int> cc = aa, dd = bb;
	
	fft1::fft(aa, false);
	fft1::fft(bb, false);
	for (int i=0; i<st2; i++)
		aa[i] = aa[i] * 1ll * bb[i] % fft1::mod;

	fft1::fft(aa, true);

	fft2::fft(cc, false);
	fft2::fft(dd, false);
	for (int i=0; i<st2; i++)
		cc[i] = cc[i] * 1ll * dd[i] % fft2::mod;

	fft2::fft(cc, true);

	long long sol0 = 0;
	int streak = 1;
	for (int i=1; i<=n; i++) {
		if (b[i] == b[i-1])
			streak++;
		else
			streak = 1;
		sol0 += streak - 1;
	}

	cout << sol0 << ' ';

	for (int i=1; i<=n; i++) {
		cout << crt(aa[n+i], cc[n+i]) << ' ';
	}

}