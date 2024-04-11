#include <bits/stdc++.h>
using namespace std;

#define TOP_N 2005
#define mod 1000000007

int n, k;
char s[TOP_N];
long long f[TOP_N][TOP_N], g[TOP_N][TOP_N], ans;

int main(){
	scanf("%d %d ", &n, &k);
	gets(&s[1]);
	f[0][0] = g[0][0] = 1;
	for(int i = 1; i <= n; i ++)
	for(int j = 0; j <= k; j ++){
		f[i][j] = (g[i - 1][j] * (s[i] - 'a')) % mod;
		for(int p = 1; p <= i && j >= p * (n - i + 1); p ++)	f[i][j] += f[i - p][j - p * (n - i + 1)] * ('z' - s[i]), f[i][j] %= mod;
		g[i][j] = g[i - 1][j] + f[i][j], g[i][j] %= mod;
	}
	printf("%I64d", g[n][k] + f[0][k] - g[0][k]);
}