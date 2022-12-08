#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e3 + 5, K = 1e6 + 5;
int n, m, k, p, a[N][N], f[K], g[K], now = 0;
priority_queue<int> q;

signed main() {
	n = get(), m = get(), k = get(), p = get();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			a[i][j] = get();
	for(int i = 1; i <= n; i++) {
		int sum = 0;
		for(int j = 1; j <= m; j++) sum += a[i][j];
		q.push(sum);
	}
	now = 0;
	for(int i = 1; i <= k; i++) {
		int x = q.top(); q.pop();
		now += x, q.push(x - m * p), f[i] = now;
	}
	while(q.size()) q.pop();
	for(int i = 1; i <= m; i++) {
		int sum = 0;
		for(int j = 1; j <= n; j++) sum += a[j][i];
		q.push(sum);
	}
	now = 0;
	for(int i = 1; i <= k; i++) {
		int x = q.top(); q.pop();
		now += x, q.push(x - n * p), g[i] = now;
	}
	int ans = -0x3f3f3f3f3f3f3f3f;
	for(int i = 0; i <= k; i++) ans = max(ans, f[i] + g[k - i] - i * (k - i) * p);
	cout << ans;
	return 0;
}