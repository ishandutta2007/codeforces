#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MOD = 998244353;

int add(int a, int b) {
	a += b;
	if (a >= MOD)
		a -= MOD;
	return a;
}

int sub(int a, int b) {
	a -= b;
	if (a < 0)
		a += MOD;
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

const int MAXN = 1e6 + 10;

int fact[MAXN], rfact[MAXN];

void build() {
	fact[0] = rfact[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fact[i] = mul(fact[i - 1], i);
		rfact[i] = inv(fact[i]);
	}
}

int cnk(int n, int k) {
	if (n < k || k < 0) return 0;
	return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

int n, k;

void read() {
	cin >> n >> k;
	swap(n, k);
}

int calc(int len, int mx) {
	//cout << len << " " << mx << endl;
	return cnk(mx - 1, len - 1);
}

int ans;

void run() {
	ans = 0;
	for (int i = 1; i <= k; i++) {
		ans = add(ans, calc(n, k / i));
	}
}

void write() {
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	build();
	read();
	run();
	write();
	return 0;
}