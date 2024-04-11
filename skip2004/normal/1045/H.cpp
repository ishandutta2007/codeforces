#include<bits/stdc++.h>
const int mod = 1e9 + 7;
const int maxn = 500100;
using std::cin;
using std::cout;
typedef long long ll;
char A[maxn], B[maxn];
int fac[maxn], ifac[maxn], inv[maxn];
inline int C(int n ,int m) {
	if(n == m) return 1;
	if(m > n) return 0;
	return (ll) fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
int c00, c01, c10, c11;
int L;
inline int chk(char * a, int c00, int c01, int c10, int c11) {
	int bak[4] = {c00, c01, c10, c11};
	for(int i = 0;i + 1 < L;++i) -- bak[a[i] % 2 << 1 | a[i + 1] % 2];
	return bak[0] == 0 && bak[1] == 0 && bak[2] == 0 && bak[3] == 0;
}
inline int calc(int a, int b, int c, int d) {
	const int c0 = a + c + 1, c1 = b + d;
	return (ll) C(c0 - 1, c) * C(c1 - 1, b - 1) % mod;
}
inline int calc(char * s, int c00, int c01, int c10, int c11) {
	int a[2][2] = {c00, c01, c10, c11}, L = strlen(s), su = c00 + c01 + c10 + c11 + 1;
	if(L < su || c01 != c10 && c01 != c10 - 1) return 0;
	if(L > su) return calc(c11, c10, c01, c00);
	for(int i = 0;i < L;++i) s[i] &= 1;
	ll ans = 0;
	for(int i = 1;i < L;++i) {
		if(s[i]) {
			if(--a[s[i - 1]][0] >= 0) ans += calc(a[0][0], a[0][1], a[1][0], a[1][1]);
			++ a[s[i - 1]][0];
		}
		if(--a[s[i - 1]][s[i]] < 0) break;
	}
	return ans % mod;
}
int main() {
	fac[0] = ifac[0] = fac[1] = ifac[1] = inv[1] = 1;
	for(int i = 2;i < maxn;++i) {
		inv[i] = ll(mod - mod / i) * inv[mod % i] % mod;
		fac[i] = (ll) fac[i - 1] * i % mod;
		ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
	}
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> A >> B;
	cin >> c00 >> c01 >> c10 >> c11;
	L = strlen(B);
	int ans = calc(B, c00, c01, c10, c11) - calc(A, c00, c01, c10, c11) + chk(B, c00, c01, c10, c11);
	cout << ans + (ans >> 31 & mod) << '\n';
}