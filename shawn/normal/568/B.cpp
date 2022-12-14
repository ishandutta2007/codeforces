#include <bits/stdc++.h>

using namespace std;

const int N = 4010;
const int mod = 1e9 + 7;
long long C[N][N], B[N][N], ans;
int n;

int main(){
	scanf("%d", &n);
	C[0][0] = 1;
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j <= i; j ++) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
		}
	}
	B[0][0] = B[1][1] = 1;
	for (int i = 2; i <= n; i ++) {
		B[i][1] = B[i - 1][i - 1];
		for (int j = 2; j <= i; j ++) {
			B[i][j] = (B[i - 1][j - 1] + B[i][j - 1]) % mod;
		}
	}
	
	for (int i = 0; i < n; i ++) 
		ans = (ans + C[n][i] * B[i][i] % mod) % mod;
	printf("%I64d", ans % mod);
	return 0;
}