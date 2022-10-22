#include <bits/stdc++.h>

#define LL long long
#define pii pair<int,int>
using namespace std;
const int inf = 2147483647;
const int mod = 998244353;
const int N = 100001;

int _max(int x, int y) {return x > y ? x : y;}
int _min(int x, int y) {return x < y ? x : y;}
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x * f;
}
void put(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) put(x / 10);
	putchar(x % 10 + '0');
}

int R[N << 2], A[N << 2], B[N << 2], inv[N << 2], C[N << 2];
int H[N << 2], G[N << 2], D[N << 2];

int add(int x, int y) {
	x += y;
	return x >= mod ? x - mod : x;
}
int dec(int x, int y) {
	x -= y;
	return x < 0 ? x + mod : x;
}
int pow_mod(int a, int k) {
	int ans = 1;
	while(k) {
		if(k & 1) ans = (LL)ans * a % mod;
		a = (LL)a * a % mod, k /= 2;
	} return ans;
}

void NTT(int y[], int len, int on) {
	for(int i = 0; i < len; i++) if(i < R[i]) swap(y[i], y[R[i]]);
	for(int i = 1; i < len; i <<= 1) {
		int wn = pow_mod(3, on == -1 ? (mod - 1 - (mod - 1) / (i << 1)) : (mod - 1) / (i << 1));
		for(int j = 0; j < len; j += i << 1) {
			int w = 1;
			for(int k = 0; k < i; k++, w = (LL)w * wn % mod) {
				int u = y[j + k], v = (LL)y[j + k + i] * w % mod;
				y[j + k] = add(u, v), y[j + k + i] = dec(u, v);
			}
		}
	} if(on == -1) {
		int hh = pow_mod(len, mod - 2);
		for(int i = 0; i < len; i++) y[i] = (LL)y[i] * hh % mod;
	}
}

void getinv(int a[], int b[], int len) {
	if(len == 1) {b[0] = pow_mod(a[0], mod - 2); return ;}
	getinv(a, b, len >> 1);
	for(int i = 0; i < (len << 1); i++) R[i] = (R[i >> 1] >> 1) | ((i & 1) * len);
	for(int i = 0; i < len; i++) A[i] = a[i];
	for(int i = len; i < (len << 1); i++) b[i] = A[i] = 0;
	NTT(b, len << 1, 1), NTT(A, len << 1, 1);
	for(int i = 0; i < (len << 1); i++) b[i] = (LL)b[i] * dec(2, (LL)A[i] * b[i] % mod) % mod;
	NTT(b, len << 1, -1);
	for(int i = len; i < (len << 1); i++) b[i] = 0;
}

void mul(int a[], int b[], int n, int m) {
	int ln = n + m - 1, len = 1;
	for(; len <= ln; len <<= 1);
	for(int i = 0; i < len; i++) R[i] = (R[i >> 1] >> 1) | ((i & 1) * (len >> 1));
	for(int i = n; i < len; i++) a[i] = 0;
	for(int i = m; i < len; i++) b[i] = 0;
	NTT(a, len, 1), NTT(b, len, 1);
	for(int i = 0; i < len; i++) a[i] = (LL)a[i] * b[i] % mod;
	NTT(a, len, -1);
}

void getF(int a[], int b[], int len) {
	if(len == 1) {b[0] = 1; return ;}
	getF(a, b, len >> 1);
	for(int i = 0; i < (len << 1); i++) R[i] = (R[i >> 1] >> 1) | ((i & 1) * len);
	for(int i = 0; i < len; i++) A[i] = a[i];
	NTT(A, len << 1, 1), NTT(b, len << 1, 1);
	for(int i = 0; i < (len << 1); i++) B[i] = (LL)2LL * A[i] * b[i] % mod;
	for(int i = 0; i < (len << 1); i++) b[i] = (LL)A[i] * b[i] % mod * b[i] % mod;
	NTT(B, len << 1, -1); B[0] = dec(B[0], 1);
	NTT(b, len << 1, -1); b[0] = dec(b[0], 1);
	getinv(B, D, len);
	mul(b, D, len, len); for(int i = len; i < (len << 1); i++) b[i] = 0;
}

int main() {
	int m = read(), n = read(), len;
	for(len = 1; len <= n; len <<= 1);
	for(int i = 1; i <= m; i++) H[read()] = 1;
	getF(H, C, len);
	for(int i = 1; i <= n; i++) put(C[i]), puts("");
	return 0;
}