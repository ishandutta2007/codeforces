#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], b[N], c[N];
void add(int u, int d) {
	for(; u < N; u += u & - u) c[u] += d;
}
int calc(int u, int ans = 0) {
	for(; u > 0; u -= u & - u) ans += c[u];
	return ans;
}
const int mod = 998244353;
int ch[N];
int power(int a, int b, int ans = 1) {
	for(; b; b >>= 1, a = 1ll * a * a % mod) {
		if(b & 1) ans = 1ll * ans * a % mod;
	}
	return ans;
}
int main() {
#ifdef TRUE
	freopen("in.in", "r", stdin);
#endif
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		scanf("%d", a + i);
		add(a[i], 1);
	}
	for(int i = 1; i <= m; i ++) {
		scanf("%d", b + i);
	}
	for(int i = ch[0] = 1; i < N; i ++) {
		ch[i] = 1ll * ch[i - 1] * i % mod;
	}
	int tot = 1;
	for(int i = 1; i < N; i ++) {
		tot = 1ll * tot * power(ch[calc(i) - calc(i - 1)], mod - 2) % mod;
	}
	int ans = 0, mx = 0;
	for(int i = 1; i <= min(n, m); i ++) {
		ans = (ans + 1ll * ch[n - i] * tot % mod * calc(b[i] - 1)) % mod;
		if(calc(b[i]) == calc(b[i] - 1)) {
			break;
		}
		tot = 1ll * tot * (calc(b[i]) - calc(b[i] - 1)) % mod;
		add(b[i], -1);
		mx = i;
	}
	if(n < m && mx == n) {
		ans = (ans + 1) % mod;
	}
	cout << ans << endl;
	return 0;
}