#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

// 7*17*2^23+1
#define P 998244353
// primitive root
#define PR 846930887
#define N 262144
// PR^(P/N)
#define PE 33051301
// PE^-1
#define IE 641732713

const int I2 = (P+1)/2;
const int I4 = ((ll)P*3+1)/4;

int pow(int x, int y) {
	int s = 1, t = x;
	while (y) {
		if (y&1) s = (ll)s*t%P;
		y /= 2;
		t = (ll)t*t%P;
	}
	return s;
}

int prim() {
	while (true) {
		int x = rand()%(P-1)+1;
		if (pow(x, P/7) != 1 && pow(x, P/17) != 1 && pow(x, P/2) != 1) return x;
	}
	return -1;
}

int pe[N];
int E[N];

void fft(int n, int t, int* a) {
	for (int m = n; m >= 2; ) {
		int h = m/2;
		if (!t) {
			for (int i = 0; i < h; i ++)
				E[i] = pe[N/m*i];
		} else {
			E[0] = 1;
			for (int i = 1; i < h; i ++)
				E[i] = pe[N/m*(m-i)];
		}
		for (int j = 0; j < n; j += m)
			for (int i = 0; i < h; i ++) {
				int x = (a[j+i]-a[j+i+h]+P)%P;
				(a[j+i] += a[j+i+h]) %= P;
				a[j+i+h] = (ll)E[i]*x%P;
			}
		m = h;
	}
	int i = 0;
	for (int j = 1; j < n-1; j ++) {
		for (int k = n/2; k > (i^=k); k /= 2);
		if (j < i) swap(a[i], a[j]);
	}
}

int aa[N];

void mul(int* a, int* b, int n) {
	memcpy(aa, a, sizeof(int)*n);
	memset(aa+n, 0, sizeof(int)*n);
	memset(b+n, 0, sizeof(int)*n);
	fft(n*2, 0, aa);
	fft(n*2, 0, b);
	for (int i = 0; i < n*2; i ++)
		b[i] = (ll)aa[i]*b[i]%P;
	fft(n*2, 1, b);
	int INVn = pow(n*2, P-2);
	for (int i = 0; i < n*2; i ++)
		b[i] = (ll)b[i]*INVn%P;
}

void inv(int* a, int* b, int n) {
	if (n == 1) {
		// b[0] = 1/a[0]
		b[0] = pow(a[0], P-2);
		return;
	}
	// have done inv(a, b, n/2)
	inv(a, b, n/2);
	memcpy(aa, a, sizeof(int)*n);
	memset(aa+n, 0, sizeof(int)*n);
	memset(b+n/2, 0, sizeof(int)*(n+n/2));
	fft(n*2, 0, aa);
	fft(n*2, 0, b);
	for (int i = 0; i < n*2; i ++)
		b[i] = (ll)b[i]*(2-(ll)aa[i]*b[i]%P+P)%P;
	fft(n*2, 1, b);
	int INVn = pow(n*2, P-2);
	for (int i = 0; i < n; i ++)
		b[i] = (ll)b[i]*INVn%P;
}

int c[N], d[N];

void sqrt(int* a, int* b, int n) {
	if (n == 1) {
		// b[0] = sqrt(a[0])
		b[0] = I2;
		return;
	}
	sqrt(a, b, n/2);
	memset(b+n/2, 0, sizeof(int)*(n/2));
	inv(b, c, n);
	mul(a, c, n);
	for (int i = 0; i < n; i ++)
		b[i] = (ll)(b[i]+c[i])*I2%P;
}

int p[N], f[N];

int main() {
	pe[0] = 1;
	for (int i = 1; i < N; i ++) pe[i] = (ll)pe[i-1]*PE%P;
	
	int n, m;
	scanf("%d%d", &n, &m);
	m++;
	for (int i = 0; i < n; i ++) {
		int x;
		scanf("%d", &x);
		p[x] = P-1;
	}
	p[0] = I4;
	int mm = 1;
	while (mm < m) mm *= 2;
	sqrt(p, f, mm);
	f[0] = (f[0] + I2)%P;
	inv(f, p, mm);
	for (int i = 1; i < m; i ++)
		printf ("%d\n", p[i]);
	return 0;
}