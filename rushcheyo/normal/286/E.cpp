#include <bits/stdc++.h>
using namespace std;

const int N = 1000005, P = 998244353, G = 3;
const double PI = acos(-1);
int n, m, l, k, a[N], b[4 * N], ans[N], tot;
bool exist[N];

int fpw(int a, int x) {
	int ans = 1;
	for (; x; x >>= 1) {
		if (x & 1) ans = 1ll * ans * a % P;
		a = 1ll * a * a % P;
	}
	return ans;
}

void ntt(int *a, int dft) {
	for (int i = 0; i < l; i++) {
		int t = 0;
		for (int j = 0; j < k; j++) if (i >> j & 1) t |= 1 << k - j - 1;
		if (i < t) swap(a[i], a[t]);
	}
	for (int i = 2; i <= l; i <<= 1) {
		int m = i >> 1, wn = fpw(G, P - 1 + dft * (P - 1) / i);
		for (int *p = a; p < a + l; p += i)
			for (int k = 0, w = 1; k < m; k++) {
				int tmp = 1ll * p[m + k] * w % P;
				p[m + k] = (p[k] + P - tmp) % P;
				p[k] = (p[k] + tmp) % P;
				w = 1ll * w * wn % P;
			}
	}
	if (dft == -1) {
		int tmp = fpw(l, P - 2);
		for (int i = 0; i < l; i++) a[i] = 1ll * a[i] * tmp % P;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		exist[a[i]] = true;
		b[a[i]] = 1;
	}
	k = 0, l = 1;
	while (l < 2 * m) l *= 2, k++;
	ntt(b, 1);
	for (int i = 0; i < l; i++) b[i] = 1ll * b[i] * b[i] % P;
	ntt(b, -1);
	for (int i = 1; i <= m; i++)
		if (b[i] > 0 && !exist[i]) return puts("NO"), 0;
	puts("YES");
	for (int i = 1; i <= n; i++)
		if (b[a[i]] == 0) ans[++tot] = a[i];
	printf("%d\n", tot);
	for (int i = 1; i <= tot; i++) printf("%d%c", ans[i], " \n"[i == tot]);
}