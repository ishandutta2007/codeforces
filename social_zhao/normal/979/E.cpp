#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 55, P = 1e9 + 7; 
int n, p, a[N], f[N][N][N][N], qpow[N], ans; 

void init() {
	qpow[0] = 1;
	for(int i = 1; i <= n; i++) qpow[i] = qpow[i - 1] * 2 % P;
}

signed main() {
	n = get(), p = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	init();
	if(a[1] == 0 || a[1] == -1) f[1][1][0][0] = 1;
	if(a[1] == 1 || a[1] == -1) f[1][0][0][1] = 1;
	for(int i = 1; i <= n; i++) 
		for(int j = 0; j <= i; j++)
			for(int k = 0; j + k <= i; k++)
				for(int l = 0; j + k + l <= i; l++) {
					if(i == n) { if(((j + l) & 1) == p) (ans += f[i][j][k][l]) %= P; continue; }
					int now = f[i][j][k][l];
					if(a[i + 1] == 0 || a[i + 1] == -1) {
						if(l) {
							(f[i + 1][j + 1][k][l] += now * qpow[l - 1] % P * qpow[i - l] % P) %= P;
							(f[i + 1][j][k + 1][l] += now * qpow[l - 1] % P * qpow[i - l] % P) %= P;
						}
						else {
							(f[i + 1][j + 1][k][l] += now * qpow[i] % P) %= P;
						}
					}
					if(a[i + 1] == 1 || a[i + 1] == -1) {
						if(j) {
							(f[i + 1][j][k][l + 1] += now * qpow[j - 1] % P * qpow[i - j] % P) %= P;
							(f[i + 1][j][k][l]     += now * qpow[j - 1] % P * qpow[i - j] % P) %= P;
						}
						else {
							(f[i + 1][j][k][l + 1] += now * qpow[i] % P) %= P;
						}
					}
				}
	printf("%lld\n", ans);
	return 0;
}

/*
2 0
0 1
*/