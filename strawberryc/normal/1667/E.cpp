#include <bits/stdc++.h>

const int N = 1e6 + 5, wd = 998244353;

int n, ff = 1, tot, rev[N], yg[N], A[N], B[N], fac[N], inv[N], invf[N],
f[N], g[N];

int qpow(int a, int b) {
  int res = 1;
  while (b) {
  	if (b & 1) res = 1ll * res * a % wd;
  	a = 1ll * a * a % wd;
  	b >>= 1;
  }
  return res;
}

void FFT(int n, int *a, int op) {
  for (int i = 0; i < n; i++) if (i < rev[i]) std::swap(a[i], a[rev[i]]);
  yg[n] = qpow(3, (wd - 1) / n); 
  if (op == -1) yg[n] = qpow(yg[n], wd - 2);
  for (int k = n >> 1; k; k >>= 1)
    yg[k] = 1ll * yg[k << 1] * yg[k << 1] % wd;
  for (int k = 1; k < n; k <<= 1) {
  	int x = yg[k << 1];
  	for (int i = 0; i < n; i += k << 1) {
  	  int w = 1;
  	  for (int j = 0; j < k; j++) {
  	    int u = a[i + j], v = 1ll * a[i + j + k] * w % wd;
  	    a[i + j] = (u + v) % wd;
  	    a[i + j + k] = (u - v + wd) % wd;
  	    w = 1ll * w * x % wd;
	  }
	}
  }
  if (op == -1) {
  	int gg = qpow(n, wd - 2);
  	for (int i = 0; i < ff; i++) a[i] = 1ll * a[i] * gg % wd;
  }
}

int main() {
  std::cin >> n;
  while (ff <= (n << 1)) ff <<= 1, tot++;
  for (int i = 1; i < ff; i++)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << tot - 1);
  fac[0] = inv[1] = invf[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % wd;
  for (int i = 2; i <= n; i++) inv[i] = 1ll * (wd - wd / i) * inv[wd % i] % wd;
  for (int i = 1; i <= n; i++) invf[i] = 1ll * invf[i - 1] * inv[i] % wd;
  for (int i = (n + 1 >> 1); i <= n; i++) A[i] = 1ll * fac[n - i - 1] * inv[i] % wd;
  for (int i = 0; i <= n; i++) B[i] = invf[i];
  FFT(ff, A, 1); FFT(ff, B, 1);
  for (int i = 0; i < ff; i++) A[i] = 1ll * A[i] * B[i] % wd;
  FFT(ff, A, -1);
  for (int i = 0; i <= n; i++) f[n - i] = 1ll * fac[i] * A[i] % wd;
  memset(A, 0, sizeof(A));
  for (int i = 0; i <= (n - 3 >> 1); i++) A[i] = fac[n - i - 2];
  FFT(ff, A, 1);
  for (int i = 0; i < ff; i++) A[i] = 1ll * A[i] * B[i] % wd;
  FFT(ff, A, -1);
  for (int i = 0; i <= n; i++) g[n - i] = 1ll * fac[i] * A[i] % wd;
  for (int i = 1; i <= (n + 1 >> 1); i++) {
  	int res = (fac[n - 1] - f[i] + wd) % wd;
  	res = (res - 1ll * (i - 1) * g[i] % wd + wd) % wd;
  	printf("%d ", res);
  }
  for (int i = 1; i <= (n >> 1); i++) printf("0 ");
  return puts(""), 0;
}