//============================================================================
// Name        : E.cpp
// Author      : CGS
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define N 65536
#define M 70000

int g[M], F[M], inv[M], rlt[M], f[M], rev[M];


const int magic[5] = {998244353, 1004535809, 104857601, 111149057, 136314881};
//const int magic[5] = {119<<23|1, 479<<21|1, 25<<22|1, 53<<21|1, 65<<21|1};
const int mod = 1000000007;
int P;
const int G = 3;
int r[5][5];

int quick_mod(int x, int k, int mod) {
	int ans = 1;
	while (k) {
		if (k&1) ans = 1LL * ans * x % mod;
		x = 1LL * x * x % mod;
		k >>= 1;
	}
	return ans;
}

void init() {
	F[0] = inv[0] = F[1] = inv[1] = rev[1] = 1;
	for(int i = 2; i <= N; i ++) {
		rev[i] = 1ll * rev[mod % i] * (mod - mod/i) % mod;
		F[i] = 1ll * F[i - 1] * i % mod;
		inv[i] = 1ll * inv[i - 1] * rev[i] % mod;
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			r[i][j] = quick_mod(magic[i], magic[j] - 2, magic[j]);
		}
	}
}

void change(int *y, int len) {
	int i, j, k;
	for(i = 1, j = len / 2; i < len - 1; i++) {
		if(i < j) swap(y[i], y[j]);
		k = len / 2;
		while(j >= k) {
			j -= k;
			k /= 2;
		}
		if(j < k) j += k;
	}
}

void ntt(int *y, int len, int on) {
	change(y, len);
	int id = 0;
	for(int h = 2; h <= len; h <<= 1) {
		id++;
		int wn = quick_mod(G, (P - 1) / (1<<id), P);
		for(int j = 0; j < len; j += h) {
			int w = 1;
			for(int k = j; k < j + h / 2; k++) {
				int u = y[k] % P;
				int t = 1LL * w * y[k + h / 2] % P;
				y[k] = (u + t) % P;
				y[k + h / 2] = ((u - t) % P + P) % P;
				w = 1LL * w * wn % P;
			}
		}
	}
	if(on == -1) {
		for (int i = 1; i < len / 2; i++)
			swap(y[i], y[len - i]);
		int inv = quick_mod(len, P - 2, P);
		for(int i = 0; i < len; i++)
			y[i] = 1LL * y[i] * inv % P;
	}
}

int x1[M], x2[M], tmp[M][5];


int CRT(int *a, int pcnt) {
	int sb[5];
	for(int i = 0; i < pcnt; ++i) {
		sb[i] = a[i];
		for(int j = 0; j < i; ++j) {
			int t = (sb[i] - sb[j]) % magic[i];
			if(t < 0) t += magic[i];
			sb[i] = 1LL * t * r[j][i] % magic[i];
		}
	}
	int mul = 1, ans = sb[0] % mod;
	for(int i = 1; i < pcnt; ++i) {
		mul = 1LL * mul * magic[i - 1] % mod;
		ans = (ans + 1LL * sb[i] * mul % mod) % mod;
	}
	return ans;
}

int t1[M], t2[M];
void gao(int *a, int na, int *b, int nb, int pcnt) {
	int len = 1;
	while (len <= na + nb) len <<= 1;
	for (int ti = 0; ti < pcnt; ti++) {
		P = magic[ti];
		for (int i = 0; i < len; i++) {
			x1[i] = i >= na ? 0 : a[i];
            x2[i] = i >= nb ? 0 : b[i];
		}
		ntt(x1, len, 1); ntt(x2, len, 1);
		for (int i = 0; i < len; i++)
			x1[i] = 1LL * x1[i] * x2[i] % P;
		ntt(x1, len, -1);
		for (int i = 0; i < len; i++)
			tmp[i][ti] = x1[i];
	}
	for (int i = 0; i < len; i++)
		a[i] = CRT(tmp[i], pcnt);
}

ll po(ll a, ll b) {
	ll rlt = 1;
	while(b) {
		if(b & 1) rlt = rlt * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return rlt;
}

ll n;

int MM = 3;

void doit(int nn) {
	if(nn == 1) {
		for(int i = 0; i < n; i ++) rlt[i] = f[i];
		return ;
	}
	int m = nn / 2;
	doit(m);
	for(int i = 0; i < n; i ++) g[i] = 1ll * po(2, 1ll * m * i % (mod - 1)) * rlt[i] % mod;
	gao(rlt, n, g, n, MM);
	if(nn & 1) {
		for(int i =0 ; i < n; i ++) g[i] = 1ll * f[i] * po(2, 1ll * (nn - 1) * i % (mod - 1)) % mod;
		gao(rlt, n, g, n, MM);
	}
	return ;
}

int main() {
	//freopen("1.in", "r", stdin);
	int k;
	init();
	scanf("%I64d%d", &n, &k);
	if(n > k) {
		puts("0");
		return 0;
	}
	f[0] = 0;
	int xx = n;
	n = k + 1;
	for(int i = 1; i < n; i ++) f[i] = inv[i];
	doit(xx);
	f[0] = 1;
	gao(rlt, n, f, n, MM);
	ll ans = 0;
	ans = 1ll * rlt[k] * F[k];
	ans %= mod;
	printf("%I64d\n", ans);
	return 0;
}