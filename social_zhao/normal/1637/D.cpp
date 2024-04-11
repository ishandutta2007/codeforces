#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 105;
int n, a[N], b[N], f[N][N * N], sum[N];

void qmin(int &x, int y) { x = min(x, y); }

void solve() {
	n = get();
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= n; i++) a[i] = get();
	for(int i = 1; i <= n; i++) b[i] = get();
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i] + b[i];
	f[0][0] = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= sum[i]; j++) {
			qmin(f[i + 1][j + a[i + 1]], f[i][j] + 2 * a[i + 1] * j + 2 * b[i + 1] * (sum[i] - j));
			qmin(f[i + 1][j + b[i + 1]], f[i][j] + 2 * b[i + 1] * j + 2 * a[i + 1] * (sum[i] - j));
		}
	}
	int ans = 0x3f3f3f3f;
	for(int i = 0; i <= sum[n]; i++) ans = min(ans, f[n][i]);
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			ans += a[i] * a[i] + a[j] * a[j] + b[i] * b[i] + b[j] * b[j];
	cout << ans << endl;
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}