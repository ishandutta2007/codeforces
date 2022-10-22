#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
namespace Module {
	using namespace std;
#define ll long long
#define ull unsigned ll
	const int N = 1 << 20, P = 998244353;
	int Pow(ll x, int y = P - 2) {
		int ans = 1;
		for (; y; y >>= 1, x = x * x % P)
			if (y & 1) ans = ans * x % P;
		return ans;
	}
	int w[N];
	ull F[N];
	struct init {
		init() {
			for (int i = 1; i < N; i <<= 1) {
				w[i] = 1;
				int t = Pow(3, (P - 1) / i / 2);
				for (int j = 1; j < i; ++j) w[i + j] = (ll)w[i + j - 1] * t % P;
			}
		}
	} foo;
	int Get(int x) {
		int n = 1;
		while (n <= x) n <<= 1;
		return n;
	}
	void DFT(vector<int>& f, int n) {
		if ((int)f.size() != n) f.resize(n);
		for (int i = 0, j = 0; i < n; ++i) {
			F[i] = f[j];
			for (int k = n >> 1; (j ^= k) < k; k >>= 1)
				;
		}
		for (int i = 1; i < n; i <<= 1)
			for (int j = 0; j < n; j += i << 1) {
				int* W = w + i;
				ull *F0 = F + j, *F1 = F + j + i;
				for (int k = j; k < j + i; ++k, ++W, ++F0, ++F1) {
					ull t = (*F1) * *W % P;
					(*F1) = *F0 + P - t, (*F0) += t;
				}
			}
		for (int i = 0; i < n; ++i) f[i] = F[i] % P;
	}
	void IDFT(vector<int>& f, int n) {
		f.resize(n), reverse(f.begin() + 1, f.end()), DFT(f, n);
		int I = 1;
		for (int i = 1; i < n; i <<= 1) I = (ll)I * (P + 1) / 2 % P;
		for (int i = 0; i < n; ++i) f[i] = (ll)f[i] * I % P;
	}
	vector<int> operator+(const vector<int>& f, const vector<int>& g) {
		vector<int> ans = f;
		ans.resize(max(f.size(), g.size()));
		for (int i = 0; i < (int)g.size(); ++i) (ans[i] += g[i]) %= P;
		return ans;
	}
	vector<int> operator*(const vector<int>& f, const vector<int>& g) {
		vector<int> F, G;
		F = f, G = g;
		int p = Get(f.size() + g.size() - 2);
		DFT(F, p), DFT(G, p);
		for (int i = 0; i < p; ++i) F[i] = (ll)F[i] * G[i] % P;
		IDFT(F, p);
		return F.resize(f.size() + g.size() - 1), F;
	}
	vector<int> Inv(const vector<int>& f, int n = -1) {
		if (n == -1) n = f.size();
		if (n == 1) return { Pow(f[0]) };
		vector<int> ans = Inv(f, (n + 1) / 2), tmp(f.begin(), f.begin() + n);
		int p = Get(n * 2 - 2);
		DFT(tmp, p), DFT(ans, p);
		for (int i = 0; i < p; ++i) ans[i] = (2 - (ll)ans[i] * tmp[i] % P + P) * ans[i] % P;
		IDFT(ans, p);
		return ans.resize(n), ans;
	}
	vector<int> Mod(const vector<int>& a, const vector<int>& b) {
		if (b.size() > a.size()) return a;
		vector<int> A = a, B = b, iB;
		int n = a.size(), m = b.size();
		reverse(A.begin(), A.end()), reverse(B.begin(), B.end());
		B.resize(n - m + 1), iB = Inv(B, n - m + 1);
		vector<int> d = A * iB;
		d.resize(n - m + 1), reverse(d.begin(), d.end());
		vector<int> r = b * d;
		r.resize(m - 1);
		for (int i = 0; i < m - 1; ++i) r[i] = (a[i] - r[i] + P) % P;
		return r;
	}
	vector<int> Prod(const vector<int>& a, const vector<int>& b) {
		return a * b;
	}
#undef ll
#undef ull
}
using Module::Prod;
const int P = 998244353;
int power(int a, int b) {
	int c = 1;
	while (b) {
		if (b & 1) c = 1LL * c * a % P;
		b >>= 1;
		a = 1LL * a * a % P;
	}
	return c;
}
const int N = 200005;
int fac[N], ifac[N], inv[N];
int C(int n, int m) {
	if (m < 0 || n < m) return 0;
	return 1LL * fac[n] * ifac[m] % P * ifac[n - m] % P;
}
int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	int n;
	fac[0] = fac[1] = 1;
	rep(i, 2, N - 1) fac[i] = 1LL * fac[i - 1] * i % P;
	ifac[N - 1] = power(fac[N - 1], P - 2);
	per(i, N - 1, 1) ifac[i - 1] = 1LL * ifac[i] * i % P;
	inv[0] = inv[1] = 1;
	rep(i, 2, N - 1) inv[i] = 1LL * (P - P / i) * inv[P % i] % P;
	scanf("%d", &n);
	vector<int> f1(n + 1), f2(n + 1);
	rep(i, 0, n) {
		if (i < n) f1[i] = ifac[n - i];
		if (i >= n / 2 && n - 2 - i >= 0) f2[i] = fac[n - 2 - i];
	}
	reverse(f2.begin(), f2.end());
	vector<int> f3 = Prod(f1, f2);
	f3.erase(f3.begin(), f3.begin() + n);
	rep(i, 1, n) {
		f3[i] = 1LL * f3[i] * fac[n - i] % P * (i - 1) % P;
	}
	rep(i, 1, n) {
		int j = n - i;
		if (j >= n / 2) {
			(f3[i] += 1LL * C(n - i, j) * fac[j] % P * fac[n - 1 - j] % P) %= P;
		}
	}
	int tmp = 0;
	per(i, n, 1) {
		int old = tmp;
		(tmp += 1LL * f3[i] * inv[i - 1] % P) %= P;
		(f3[i] -= old) %= P;
	}
	rep(i, 1, n) printf("%d ", (f3[i] + P) % P);
}