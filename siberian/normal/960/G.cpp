#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) (x).begin(),(x).end()

const int MOD = 998244353;

int add(int a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
	return a;
}

int sub(int a, int b) {
	a -= b; 
	if (a < 0) {
		a += MOD;
	}
	return a;
}

int mul(int a, int b) {
	return (ll) a * b % MOD;
}

int binpow(int a, int n) {
	int ans = 1;
	while (n) {
		if (n & 1) {
			ans = mul(ans, a);
		}
		a = mul(a, a);
		n >>= 1;
	}
	return ans;
}

int inv(int a) {
	return binpow(a, MOD - 2);
}

const int MAXLOG = 18;
const int N = 1 << MAXLOG;
const int MAXN = N + 228;

int fact[MAXN], rfact[MAXN];

void initFacts() {
	fact[0] = 1;
	rfact[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fact[i] = mul(i, fact[i - 1]);
		rfact[i] = inv(fact[i]);
	}
}

int w[MAXN];
int rev[MAXN];

void initFFT() {
	int g = 2;
	for (;; g++) {
		int y = g;
		for (int i = 0; i < MAXLOG - 1; i++) {
			y = mul(y, y);
		}
		if (y == MOD - 1) {
			break;
		}
	}
	w[0] = 1;
	set<int> used;
	used.insert(1);
	for (int i = 1; i < N; i++) {
		w[i] = mul(w[i - 1], g);
		assert(!used.count(w[i]));
		used.insert(w[i]);
	}
	assert(mul(w[N - 1], g) == 1);
	rev[0] = 0;
	for (int i = 1; i < N; i++) {
		rev[i] = (rev[i >> 1] >> 1) ^ ((i & 1) << (MAXLOG - 1));
	}
}

void FFT(int * a, int n) {
	int k = 1;
	while (1 << (k + 1) <= n) k++;

	//cerr << "n = " << n << " k = " << k << endl;

	for (int i = 0; i < n; i++) {
		if (i < (rev[i] >> (MAXLOG - k))) {
			swap(a[i], a[(rev[i] >> (MAXLOG - k))]);
		}
	}
	for (int lvl = 0; lvl < k; lvl++) {
		int len = 1 << lvl;
		for (int st = 0; st < n; st += len << 1) {
			for (int i = 0; i < len; i++) {
				int x = a[st + i], y = mul(a[st + i + len], w[i << (MAXLOG - 1 - lvl)]);
				a[st + i] = add(x, y);
				a[st + i + len] = sub(x, y);
			}
		}
	}
}

int fans[MAXN];

void mul(int * a, int * b, int len) {
	FFT(a, len);
	FFT(b, len);
	for (int i = 0; i < len; i++) {
		a[i] = mul(a[i], b[i]);
	}
	FFT(a, len);
	int Inv = inv(len);
	for (int i = 0; i < len; i++) {
		fans[i] = mul(a[i], Inv);
	}
	reverse(fans + 1, fans + len);
	//for (int i = 0; i < 2 * len; i++) {
	//	fans[i] = 0;
	//}
	//for (int i = 0; i < len; i++) {
	//	for (int j = 0; j < len; j++) {
	//		fans[i + j] = add(fans[i + j], mul(a[i], b[j]));
	//	}
	//}
}

int poly[MAXN];
int a[MAXN];
int b[MAXN];

void solve(int l, int r) {
	if (l == r - 2) return;
	int m = (l + r) / 2;
	solve(l, m);
	solve(m, r);
	for (int i = 0; i < (r - l); i++) {
		a[i] = b[i] = 0;
	}
	for (int i = l; i < m; i++) {
		a[i - l] = poly[i];
	}
	for (int i = m; i < r; i++) {
		b[i - m] = poly[i];
	}
	mul(a, b, r - l);
	for (int i = l; i < r; i++) {
		poly[i] = fans[i - l];
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20);
	initFacts();
	initFFT();
	int n, a, b;
	cin >> n >> a >> b;
	if (min(a, b) == 0 || a + b - 1 > n) {
		cout << 0 << endl;
		return 0;
	}
	n--;
	a--;
	b--;
	for (int i = 0; i < n; i++) {
		poly[2 * i] = i;
		poly[2 * i + 1] = 1;
	}
	while (__builtin_popcount(n) != 1) {
		poly[2 * n] = 1;
		poly[2 * n + 1] = 0;
		n++;
	}
	/*cout << "poly = " << endl;
	for (int i = 0; i < 2 * n; i++) {
		cout << poly[i] << " ";
	}
	cout << endl;*/
	solve(0, 2 * n);
	/*cout << "poly = " << endl;
	for (int i = 0; i < 2 * n; i++) {
		cout << poly[i] << " ";
	}
	cout << endl;*/
	int ans = poly[a + b];
	ans = mul(ans, fact[a + b]);
	ans = mul(ans, mul(rfact[a], rfact[b]));
	cout << ans << endl;
	return 0;
}