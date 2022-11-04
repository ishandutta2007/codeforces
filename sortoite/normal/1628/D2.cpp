#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int power(int a, int b, int ans = 1) {
	for(; b; b >>= 1, a = 1ll * a * a % mod) if(b & 1) ans = 1ll * ans * a % mod;
	return ans;
}
int ch[N], hc[N];
int c(int n, int m) {
	return 1ll * ch[n] * hc[m] % mod * hc[n - m] % mod;
}
int solve() {
	int n, m, k; scanf("%d %d %d", &n, &m, &k);
	int ans = 0;
	for(int i = 1; i <= m; i ++) {
		ans = (ans + 1ll * i * c(n, m - i)) % mod;
	}
	return 1ll * ans * power(power(2, n - 1), mod - 2) % mod * k % mod;
}
int main() {
#ifdef TRUE
	freopen("in.in", "r", stdin);
#endif
	for(int i = ch[0] = 1; i < N; i ++) ch[i] = 1ll * ch[i - 1] * i % mod;
	hc[N - 1] = power(ch[N - 1], mod - 2);
	for(int i = N - 2; i >= 0; i --) hc[i] = 1ll * (i + 1) * hc[i + 1] % mod;
	int T; cin >> T;
	while(T --) {
		printf("%d\n", solve());
	}
	return 0;
}