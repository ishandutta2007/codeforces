#pragma GCC optimize("fast-math")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) (x).begin(),(x).end()

const ld PI = acos(-1);
using cd = complex<float>;

const int MAXLOG = 20;
const int N = (1 << MAXLOG);
const int MAXN = (1 << MAXLOG) + 228;
int rev[MAXN];
cd w[MAXN];

void initFFT() {
	for (int i = 0; i < N; i++) {
		w[i] = cd(cos(2 * PI * i / N), sin(2 * PI * i / N));
	}
	rev[0] = 0;
	for (int i = 1; i < N; i++) {
		rev[i] = (rev[i >> 1] >> 1) ^ ((i & 1) << (MAXLOG - 1));
	}
}

void FFT(int n, int LOG, cd * a) {
	for (int i = 0; i < n; i++) {
		if (i < (rev[i] >> (MAXLOG - LOG))) {
			swap(a[i], a[(rev[i] >> (MAXLOG - LOG))]);
		}
	}
	for (int lvl = 0; lvl < LOG; lvl++) {
		int len = 1 << lvl;
		for (int st = 0; st < n; st += len << 1) {
			for (int i = 0; i < len; i++) {
				cd x = a[st + i], y = a[st + len + i] * w[i << (MAXLOG - 1 - lvl)];
				a[st + i] = x + y;
				a[st + i + len] = x - y;
			}
		}
	}
}

int n;
string s;

cd a[MAXN];
cd b[MAXN];
int fans[MAXN];

void mul() {
	int LOG = 0;
	while ((1 << LOG) < 2 * n) LOG++;
	int sz = 1 << LOG;
	for (int i = n; i < sz; i++) {
		a[i] = b[i] = 0;
	}
	FFT(sz, LOG, a);
	FFT(sz, LOG, b);
	for (int i = 0; i < sz; i++) {
		a[i] *= b[i];
	}
	FFT(sz, LOG, a);
	for (int i = 0; i < sz; i++) {
		fans[i] = (int) (a[i].real() / sz + 0.5);
	}
	reverse(fans + 1, fans + sz);
}

void solve() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		a[i] = b[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == 'V') a[i] = 1;
		if (s[i] == 'K') b[n - i - 1] = 1;
 	}
 	mul();
 	reverse(fans, fans + 2 * n);
 	vector<int> ans;
 	for (int k = 1; k <= n; k++) {
 		bool ok = true;
 		for (int x = k; x < n; x += k) {
 			ok &= fans[n + x] == 0 && fans[n - x] == 0;
 		}
 		if (ok) {
 			ans.push_back(k);
 		}
 	}
 	cout << ans.size() << endl;
 	for (auto i : ans) {
 		cout << i << " ";
 	}
 	cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20);
	initFFT();
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}