#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 5005, P = 998244353;
int n, E[N][N], C[N][N], fac[N], ans[N];

void init(int n) {
	for(int i = 0; i <= n; i++) {
		C[i][0] = 1;
		for(int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
	}
	for(int i = 1; i <= n; i++) {
		E[i][1] = 1;
		for(int j = 2; j <= i; j++) {
			E[i][j] = (1ll * E[i - 1][j - 1] * (i - j + 1) + 1ll * E[i - 1][j] * j) % P;
		}
	}
	fac[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % P;
}

main() {
	n = get();
	init(n);
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			ans[i] = (ans[i] + 1ll * E[j][i] * C[n][j] % P * fac[n - j] % P) % P;
		}
		cout << ans[i] << " ";
	}
	return 0;
}