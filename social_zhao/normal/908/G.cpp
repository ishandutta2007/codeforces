#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 705, P = 1e9 + 7;
char s[N];
int n, a[N], f[N][N][10][2], sum[N];

signed main() {
	scanf("%s", s + 1); n = strlen(s + 1);
	for(int i = 1; i <= n; i++) a[i] = s[i] - '0';
	for(int i = 0; i <= 9; i++) f[0][0][i][0] = 1;
	for(int i = 1; i <= n; i++) sum[i] = (sum[i - 1] * 10 + 1) % P;
	for(int i = 0; i < n; i++)
	  for(int j = 0; j <= i; j++)
		for(int k = 1; k <= 9; k++)
		  for(int l = 0; l < 2; l++)
			for(int p = 0; p <= (l? 9 : a[i + 1]); p++) 
			  f[i + 1][j + (p >= k)][k][l | (p < a[i + 1])] = (f[i + 1][j + (p >= k)][k][l | (p < a[i + 1])] + f[i][j][k][l]) % P;
	int ans = 0;
	for(int k = 1; k <= 9; k++) 
		for(int j = 1; j <= n; j++) 
			ans = (ans + 1ll * sum[j] * (f[n][j][k][0] + f[n][j][k][1]) % P) % P;
	printf("%lld", (ans + P) % P);
	return 0;
}