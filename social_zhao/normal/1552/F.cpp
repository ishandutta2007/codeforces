#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5, P = 998244353;
int n, x[N], y[N], s[N], f[N], g[N], sum[N];
// g:  

signed main() {
	n = get();
	for(int i = 1; i <= n; i++) x[i] = get(), y[i] = get(), s[i] = get();
	for(int i = 1; i <= n; i++) {
		int pos = lower_bound(x + 1, x + 1 + n, y[i]) - x;
		g[i] = ((sum[i - 1] - sum[pos - 1] + x[i] - y[i]) % P + P) % P, sum[i] = (sum[i - 1] + g[i]) % P;
	}
	int ans = x[n] + 1;
	for(int i = 1; i <= n; i++) ans = (ans + s[i] * g[i]) % P;
	printf("%lld\n", ans);
	return 0;
}