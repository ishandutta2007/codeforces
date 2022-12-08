#include <bits/stdc++.h>

const int p = 998244353;
#define mk make_pair
#define ll long long
#define pb push_back
#define Poly std::vector<int>
#define len(A) ((int) (A).size())

ll pow_mod(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}

namespace Pol {
	inline int add(int a, int b) { return (a += b) >= p ? a -= p : a; }

	inline int sub(int a, int b) { return (a -= b) < 0 ? a += p : a; }

	inline int mul(int a, int b) { return 1ll * a * b % p; }

	Poly operator-(const int &v, const Poly &a) {
		Poly res(a);
		for (int i = 0; i < len(res); ++i) res[i] = p - res[i];
		res[0] = add(res[0], v);
		return res;
	}

	Poly operator-(const Poly &a, const int &v) {
		Poly res(a);
		res[0] = add(res[0], p - v);
		return res;
	}

	Poly operator*(const Poly &a, const int &v) {
		Poly res(a);
		for (int i = 0; i < len(res); ++i) res[i] = mul(res[i], v);
		return res;
	}

	const int N = 4200000;
	int P[N];

	void init_P(int n) {
		int l = 0;
		while ((1 << l) < n) ++l;
		for (int i = 0; i < n; ++i) P[i] = (P[i >> 1] >> 1) | ((i & 1) << l - 1);
	}

	void NTT(Poly &a, int type) {
		static int w[N];
		ll G = 3, Gi = pow_mod(G, p - 2);
		int n = len(a);
		for (int i = 0; i < n; ++i) if (i < P[i]) std::swap(a[i], a[P[i]]);
		for (int i = 2, m = 1; i <= n; m = i, i *= 2) {
			ll wn = pow_mod(type > 0 ? G : Gi, (p - 1) / i);
			w[0] = 1;
			for (int j = 1; j < m; ++j) w[j] = wn * w[j - 1] % p;
			for (int j = 0; j < n; j += i)
				for (int k = 0; k < m; ++k) {
					int t1 = a[j + k], t2 = 1ll * a[j + k + m] * w[k] % p;
					a[j + k] = add(t1, t2);
					a[j + k + m] = add(t1, p - t2);
				}
		}
		if (type < 0) {
			int inv = pow_mod(n, p - 2);
			for (int i = 0; i < n; ++i) a[i] = mul(a[i], inv);
		}
	}

	Poly operator*(const Poly &A, const Poly &B) {
		int n = 1, n1 = len(A), n2 = len(B);
		while (n < n1 + n2 - 1) n <<= 1;
		init_P(n);
		Poly a(n), b(n);
		for (int i = 0; i < n1; ++i) a[i] = add(A[i], p);
		for (int i = 0; i < n2; ++i) b[i] = add(B[i], p);
		NTT(a, 1);
		NTT(b, 1);
		for (int i = 0; i < n; ++i) a[i] = mul(a[i], b[i]);
		NTT(a, -1);
		return a;
	}

	Poly Der(const Poly &a) {
		Poly res(a);
		for (int i = 0; i < len(a) - 1; ++i) res[i] = mul(i + 1, res[i + 1]);
		res[len(a) - 1] = 0;
		return res;
	}

	Poly Int(const Poly &a) {
		static int inv[N];
		if (!inv[1]) {
			inv[1] = 1;
			for (int i = 2; i < N; ++i) inv[i] = mul(p - p / i, inv[p % i]);
		}
		Poly res(a);
		res.resize(len(a) + 1);
		for (int i = len(a); i; --i) res[i] = mul(res[i - 1], inv[i]);
		res[0] = 0;
		return res;
	}

	Poly Inv(const Poly &a) {
		Poly res(1, pow_mod(a[0], p - 2));
		int n = 1;
		while (n < len(a)) n <<= 1;
		for (int k = 2; k <= n; k <<= 1) {
			int L = 2 * k;
			init_P(L);
			Poly t(L);
			copy_n(a.begin(), std::min(k, len(a)), t.begin());
			t.resize(L);
			res.resize(L);
			NTT(res, 1);
			NTT(t, 1);
			for (int i = 0; i < L; ++i) res[i] = mul(res[i], add(2, p - mul(t[i], res[i])));
			NTT(res, -1);
			res.resize(k);
		}
		res.resize(len(a));
		return res;
	}

	std::pair<Poly, Poly > Divide(const Poly &a, const Poly &b) {
		int n = len(a), m = len(b);
		Poly t1(a.rbegin(), a.rbegin() + n - m + 1), t2(b.rbegin(), b.rend());
		t2.resize(n - m + 1);
		Poly Q = Inv(t2) * t1;
		Q.resize(n - m + 1);
		reverse(Q.begin(), Q.end());
		Poly R = Q * b;
		R.resize(m - 1);
		for (int i = 0; i < len(R); ++i) R[i] = add(a[i], p - R[i]);
		return make_pair(Q, R);
	}

	Poly Ln(const Poly &a) {
		Poly res = Int(Der(a) * Inv(a));
		res.resize(len(a));
		return res;
	}

	Poly Exp(const Poly &a) {
		Poly res(1, 1);
		int n = 1;
		while (n < len(a)) n <<= 1;
		for (int k = 2; k <= n; k <<= 1) {
			Poly t(res.begin(), res.end());
			t.resize(k);
			t = Ln(t);
			for (int i = 0; i < std::min(len(a), k); ++i) t[i] = add(a[i], p - t[i]);
			t[0] = add(t[0], 1);
			res = res * t;
			res.resize(k);
		}
		res.resize(len(a));
		return res;
	}

	Poly Sqrt(const Poly &a) { // a[0] = 1
		Poly res(1, 1);
		ll inv2 = pow_mod(2, p - 2);
		int n = 1;
		while (n < len(a)) n <<= 1;
		for (int k = 2; k <= n; k <<= 1) {
			Poly t(res.begin(), res.end()), ta(a.begin(), a.begin() + std::min(len(a), k));
			t.resize(k);
			t = Inv(t) * ta;
			res.resize(k);
			for (int i = 0; i < k; ++i) res[i] = mul(add(res[i], t[i]), inv2);
		}
		res.resize(len(a));
		return res;
	}

	Poly Pow(const Poly &a, int k) { // a[0] = 1
		return Exp(Ln(a) * k);
	}

	Poly Pow(const Poly &a, int k, int kk) {
		int n = len(a), t = n, m, v, inv, powv;
		Poly res(n);
		for (int i = n - 1; ~i; --i) if (a[i]) t = i, v = a[i];
		if (k && t >= (n + k - 1) / k) return res;
		if (t == n) {
			if (!k) res[0] = 1;
			return res;
		}
		m = n - t * k;
		res.resize(m);
		inv = pow_mod(v, p - 2);
		powv = pow_mod(v, kk);
		for (int i = 0; i < m; ++i) res[i] = mul(a[i + (k > 0) * t], inv);
		res = Exp(Ln(res) * k);
		res.resize(n);
		for (int i = m - 1; ~i; --i) {
			ll tmp = mul(res[i], powv);
			res[i] = 0, res[i + t * k] = tmp;
		}
		return res;
	}
}  // namespace Pol

using namespace Pol;

void solve() {
	int n, k, f;
	std::cin >> n >> k >> f;
	Poly dp[20];
	dp[n] = Poly(k + k + 1);
	for (int i = 0; i <= k; ++i) {
		dp[n][i] = 1;
	}
	for (int i = n - 1; i > 0; --i) {
		Poly tmp = dp[i + 1] * dp[i + 1];
		Poly pre(k + k + 1);
		pre[0] = tmp[0];
		for (int j = 1; j <= k + k; ++j) {
			pre[j] = add(pre[j - 1], tmp[j]);
		}
		dp[i] = Poly(k + k + 1);
		for (int j = 0; j <= k; ++j) {
			dp[i][j] = add(mul(tmp[j], k - j), sub(pre[k + k], j ? pre[j - 1] : 0));
		}
	}
	dp[0] = dp[1] * dp[1];
	std::cout << (f <= k + k ? dp[0][f] : 0) << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#else
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
#endif
	int t = 1;
//	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}