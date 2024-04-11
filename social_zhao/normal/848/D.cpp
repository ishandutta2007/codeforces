#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int P = 1e9 + 7, N = 55;
int n, m;
int f[N][N], g[N][N], suf[N][N], h[N][N], inv[N];

void inc(int &x, int y) { x = (x + y) % P; }

main() {
	n = get(), m = get();
	if(m == n + 1) return printf("1"), 0;
	f[0][1] = suf[0][1] = 1;
	inv[0] = inv[1] = 1;
	for(int i = 2; i <= n; i++) inv[i] = (P - P / i) * inv[P % i] % P;
	for(int i = 1; i <= n; i++) {
		memset(h, 0, sizeof(h));
		for(int j = 1; j <= n; j++)
			for(int k = 0; k <= n - 1; k++)
				inc(h[i][j], suf[k][j] * suf[i - 1 - k][j]);
		for(int j = 1; j <= n; j++) g[i][j] = (h[i][j] - h[i][j + 1] + P) % P;
		for(int j = 1; j <= n; j++)
			for(int k = n; k >= 0; k--)
				for(int l = n; l >= 1; l--) {
					int C = 1;
					for(int x = 1; k - i * x >= 0 && l - j * x >= 0; ++x) {
						C = C * inv[x] % P * (g[i][j] + x - 1) % P;
						inc(f[k][l], f[k - x * i][l - x * j] * C); 
					}
				}
		for(int j = n; j >= 1; j--) suf[i][j] = (suf[i][j + 1] + f[i][j]) % P;
	}
	cout << f[n][m];
	return 0;
}