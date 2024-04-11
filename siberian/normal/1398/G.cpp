#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

const int MOD = 998244353;

int add(int a, int b) {
	a += b;
	if (a >= MOD) return a - MOD;
	return a;
}

int sub(int a, int b) {
	a -= b;
	if (a < 0) return a + MOD;
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

const int LOG = 19;
const int N = 1 << LOG;
const int MAXN = N + 228;
//using cd = complex<double>;
//const ld PI = acos(-1);

int rev[MAXN];
//cd w[MAXN];
int w[MAXN];

void initFFT() {
	int x;
	for (x = 2; ; x++) {
		int y = x;
		for (int i = 1; i < LOG; i++) {
			y = mul(y, y);
		}
		if (y == MOD - 1) break;
	}
	w[0] = 1;
	//for (int i = 0; i < N; i++) {
	//	w[i] = cd(cos(2 * PI * i / N), sin(2 * PI * i / N));
	//}
	for (int i = 1; i < N; i++) {
		w[i] = mul(w[i - 1], x);
	}
	rev[0] = 0;
	for (int mask = 1; mask < N; mask++) {
		rev[mask] = (rev[mask >> 1] >> 1) ^ ((mask & 1) << (LOG - 1));
	}
}

void FFT(int * a) {
	for (int i = 0; i < N; i++) {
		if (i < rev[i]) {
			swap(a[i], a[rev[i]]);
		}
	}
	for (int l = 0; l < LOG; l++) {
		int len = 1 << l;
		for (int st = 0; st < N; st += len << 1) {
			for (int i = 0; i < len; i++) {
				int x = a[st + i], y = mul(a[st + i + len], w[i << (LOG - 1 - l)]);
				a[st + i] = add(x, y);
				a[st + i + len] = sub(x, y);
			}
		}
	}
}

int A[MAXN], B[MAXN];

vector<int> mul(vector<int> a, vector<int> b) {
	initFFT();
	for (int i = 0; i < (int)a.size(); i++) {
		A[i] = a[i];
	}
	for (int i = 0; i < (int)b.size(); i++) {
		B[i] = b[i];
	}
	FFT(A);
	FFT(B);
	for (int i = 0; i < N; i++) {
		A[i] = mul(A[i], B[i]);
	}
	FFT(A);
	reverse(A + 1, A + N);
	vector<int> ans(N);
	int x = inv(N);
	for (int i = 0; i < N; i++) {
		ans[i] = mul(A[i], x);
	}
	return ans;
}

int n, x, y;
vector<int> a;

void read() {
	cin >> n >> x >> y;
	a.resize(x + 1);
	for (int i = 0; i <= n; i++) {
		int have;
		cin >> have;
		a[have] = 1;
	}
}

const int L = 1e6 + 10;
int ans[L];

void build() {
	vector<int> b = a;
	reverse(all(b));
	auto fans = mul(a, b);
	fill(ans, ans + L, -1);
	for (int i = 1; i <= x; i++) {
		if (fans[x + i]) {
			ans[i * 2 + 2 * y] = i * 2 + 2 * y;
		}
	}
	for (int i = 1; i < L; i++) {
		for (int j = i; j < L; j += i) {
			chkmax(ans[j], ans[i]);
		}
	}
}

void run() {
	build();
	int q;
	cin >> q;
	while (q--) {
		int l;
		cin >> l;
		cout << ans[l] << " ";
	}
	cout << "\n";
}

void write() {

}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
	read();
	run();
	write();
	return 0;
}