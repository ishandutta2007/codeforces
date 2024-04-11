#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 165;
int n, p, q;
unsigned int C[N];
unsigned int up[N], dwn[N];

void init() {
	for(int i = 0; i <= min(n - 1, p); i++) {
		for(int j = 1; j <= i; j++) up[j] = n - j + 1, dwn[j] = j;
		for(int j = 1; j <= i; j++)
			for(int k = 1; k <= i; k++) {
				int d = __gcd(up[j], dwn[k]);
				up[j] /= d, dwn[k] /= d;
			}
		C[i] = 1;
		for(int j = 1; j <= i; j++) C[i] *= up[j];
	}
}

unsigned int qpow(unsigned int x, int y) {
	unsigned int res = 1;
	while(y) res = res * ((y & 1)? x : 1), x = x * x, y >>= 1;
	return res;
}

unsigned int solve(int k) {
	unsigned int ans = 0;
	for(int i = 0; i <= min(n - 1, p); i++) 
		ans = ans + C[i] * qpow(k, i);
	return k * ans;
}

int main() {
	n = get(), p = get(), q = get();
	unsigned int ans = 0;
	init();
	for(int k = 1; k <= q; k++) 
		ans ^= solve(k);
	cout << ans;
	return 0;
}