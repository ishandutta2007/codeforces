#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 5005, P = 998244353;
int n, m, k, fac[N], S[N][N];

int qpow(int x, int y) {
	int res = 1;
	while(y) res = res * ((y & 1)? x : 1) % P, x = x * x % P, y >>= 1;
	return res;
}

void init(int k) {
	fac[0] = 1;
	for(int i = 1; i <= k; i++) fac[i] = fac[i - 1] * (n - i + 1) % P;
	S[0][0] = 1;
	for(int i = 1; i <= k; i++) {
		S[i][1] = 1;
		for(int j = 2; j <= i; j++)
			S[i][j] = (S[i - 1][j - 1] + S[i - 1][j] * j) % P;
	}
//	for(int i = 0; i <= k; i++, printf("\n"))
//		for(int j = 0; j <= i; j++)
//			printf("%lld ", S[i][j]);
//	for(int i = 0; i <= k; i++) printf("%lld ", fac[i]); printf("\n");
//	for(int i = 0; i <= k; i++) printf("%lld ", inv[i]); printf("\n");
}

signed main() {
	n = get(), m = get(), k = get();
	init(k);
	int res = 0;
	for(int j = 0; j <= min(n, k); j++) 
		res = (res + fac[j] * S[k][j] % P * qpow(m, n - j) % P) % P;
	res = res * qpow(qpow(m, n), P - 2) % P;
	printf("%lld\n", res);
	return 0;
}