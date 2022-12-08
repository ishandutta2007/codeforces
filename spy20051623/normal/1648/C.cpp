#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
const int mod = 998244353;
int c[N], t[N];
long long d[N], inv[N], fac[N], ifac[N];

int lowbit(int x) { return x & -x; }

void upd(int x, long long k) { for (; x < N; x += lowbit(x)) d[x] += k; }

long long qry(int x) {
	long long s = 0;
	for (; x > 0; x -= lowbit(x)) s += d[x];
	s = (s % mod + mod % mod);
	return s;
}

inline void invWork() {
	inv[1] = 1;
	for (int i = 2; i < 200005; ++i) {
		inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	}
}

void facWork() {
	fac[0] = ifac[0] = 1;
	for (int i = 1; i < N; ++i) {
		fac[i] = fac[i - 1] * i % mod;
		ifac[i] = ifac[i - 1] * inv[i] % mod;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	invWork();
	facWork();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		++c[p];
	}
	for (int i = 0; i < m; ++i) {
		cin >> t[i];
	}
	long long w = fac[n - 1];
	for (int i = 1; i < N; ++i) {
		w = w * ifac[c[i]] % mod;
		upd(i, c[i]);
	}
	long long ans = 0;
	for (int i = 0; i < m; ++i) {
		if (!c[t[i]]) {
			if (i == n) ans = (ans + 1) % mod;
			else ans = (ans + w * qry(t[i] - 1)) % mod;
			break;
		}
		ans = (ans + qry(t[i] - 1) * w) % mod;
		w = w * inv[n - i - 1] % mod * (c[t[i]]--) % mod;
		upd(t[i], -1);
	}
	ans %= mod;
	cout << ans;
	return 0;
}