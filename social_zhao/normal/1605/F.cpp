#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 85, sgn[2] = { 1, -1 };
int n, k, P, C[N][N];
int f[N][N], g[N][N], h[N][N], ans[N][N];

int qpow(int x, int y) {
	int res = 1;
	while(y) res = res * ((y & 1)? x : 1) % P, x = x * x % P, y >>= 1;
	return res;
}

void init(int n) {
	for(int i = 0; i <= n; i++) {
		C[i][0] = 1;
		for(int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
	}
}

void inc(int &x, int y) { x = (x + y) % P; }

int calcF(int n, int m) {
	int ans = 0;
	for(int i = 0; i <= m; i++)
		inc(ans, sgn[(m - i) & 1] * C[m][i] * qpow(qpow(2, i), n));
	return (ans % P + P) % P;
}

int calcH(int n, int m) {
	int ans = 0;
	for(int i = 0; i <= m; i++) {
		int dwn = 1, base = qpow(2, i) - 1;
		for(int j = 1; j <= n; j++) dwn = dwn * (base - j + 1) % P;
		inc(ans, sgn[(m - i) & 1] * C[m][i] * dwn);
	}
	return (ans % P + P) % P;
}

main() {
	n = get(), k = get(), P = get();
	init(80);
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= k; j++)
			f[i][j] = calcF(i, j);
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= k; j++)
			h[i][j] = calcH(i, j);
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= k; j++) {
			int now = ans[i][j] = (f[i][j] - g[i][j] + P) % P;
			for(int a = i + 1; a <= n; a++)
				for(int b = j + 1; b <= k; b++) {
					if(i == n - 1 && !(i & 1) && a == i + 1) continue;
					inc(g[a][b], now * C[a][i] % P * C[b][j] % P * qpow(2, j * (a - i)) % P * h[a - i][b - j]);
				}
		}
	int res = 0;
	for(int i = 0; i <= k; i++) inc(res, C[k][i] * ans[n][i]);
	cout << res << endl;
	return 0;
}