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
	if (a >= MOD) a -= MOD;
	return a;
}

int mul(int a, int b) {
	return (ll) a * b % MOD;
}

int binpow(int a, int n) {
	if (n == 0) return 1;
	if (n & 1) {
		return mul(a, binpow(a, n - 1));
	}
	else {
		return binpow(mul(a, a), n / 2);
	}
}

int inv(int a) {
	return binpow(a, MOD - 2);
}

int n, m;

void read() {
	cin >> n >> m;
}

const int MAXN = 2e5 + 10;

int fact[MAXN], rfact[MAXN];

void build() {
	fact[0] = rfact[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fact[i] = mul(i, fact[i - 1]);
		rfact[i] = inv(fact[i]);
	}
}

int ans;

int c_n_k(int n, int k) {
	if (n < k) return 0;
	//cout << n << " " << k << endl; 
	//cout << fact[n] << endl;
	//cout << rfact[k] << " " << rfact[n - k] << endl;
	return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

int calc(int x) {
	ll ans = 1;
	ans = mul(ans, mul(c_n_k(x - 1, n - 2), n - 2));
	if (n > 2)
	ans = mul(ans, binpow(2, n - 3));
	return ans;
}

void run() {
	build();
	ans = 0;
	//cout << calc(3) << endl;
	//exit(0);
	for (int x = 2; x <= m; x++) {
		ans = add(ans, calc(x));
	}
}

void write() {
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}