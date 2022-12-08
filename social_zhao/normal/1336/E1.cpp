#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5, M = 37, P = 998244353, inv2 = (P + 1) / 2;
int n, m, fail, ans[M], a[M];
int lo[M], hi[M], cl, ch, cnt[1 << 20];
int f[1 << 20], g[20][1 << 20];

int qpow(int x, int y) {
	int res = 1;
	while(y) res = res * ((y & 1)? x : 1) % P, x = x * x % P, y >>= 1;
	return res;
}

int insert(int x) {
	for(int i = m; i >= 0; i--) {
		if(x >> i & 1) {
			if(!a[i]) {
				a[i] = x;
				for(int j = i + 1; j <= m; j++) if(a[j] >> i & 1) a[j] ^= x;
				return 0;
			}
			else x ^= a[i];
		}
	}
	return 1;
}

void FWT(int *A, int type, int lim) {
	for(int mid = 1; mid < lim; mid <<= 1)
		for(int i = 0; i < lim; i += mid << 1)
			for(int j = 0; j < mid; j++) {
				int x = A[i + j], y = A[i + mid + j];
				A[i + j] = (x + y) * type % P, A[i + mid + j] = (x - y + P) * type % P;
			}
}

main() {
	n = get(), m = get();
	for(int i = 1, a; i <= n; i++) a = get(), fail += insert(a);
	fail = qpow(2, fail);
	int mid = m >> 1;
	for(int i = 1; i <= 2 << mid; i++) cnt[i] = cnt[i >> 1] + (i & 1);
	for(int i = 0; i <= mid; i++) if(a[i]) lo[++cl] = a[i];
	for(int i = mid + 1; i <= m; i++) if(a[i]) hi[++ch] = a[i];
	for(int i = 0, sum = 0; i < 1 << cl; i++) {
		for(int j = 1; j <= cl; j++) if(i >> (j - 1) & 1) sum ^= lo[j];
		++f[sum], sum = 0;
	}
	for(int i = 0, sum = 0; i < 1 << ch; i++) {
		for(int j = 1; j <= ch; j++) if(i >> (j - 1) & 1) sum ^= hi[j];
		++g[cnt[sum >> (mid + 1)]][sum & ((2 << mid) - 1)], sum = 0;
	}
	FWT(f, 1, 2 << mid);
	for(int i = 0; i <= mid; i++) {
		FWT(g[i], 1, 2 << mid);
		for(int j = 0; j < 2 << mid; j++) g[i][j] = g[i][j] * f[j] % P;
		FWT(g[i], inv2, 2 << mid);
		for(int j = 0; j < 2 << mid; j++) ans[i + cnt[j]] = (ans[i + cnt[j]] + g[i][j]) % P;
	}
	for(int i = 0; i <= m; i++) printf("%lld ", (ans[i] * fail % P + P) % P);
	return 0;
}