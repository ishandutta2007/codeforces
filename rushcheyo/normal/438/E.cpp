#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005, G = 3, P = 998244353, inv2 = P + 1 >> 1;
typedef vector<int> poly;

int power(int a, int x)
{
	int ans = 1;
	for (; x; x >>= 1, a = 1ll * a * a % P)
		if (x & 1) ans = 1ll * ans * a % P;
	return ans;
}

void fft(int *a, int n, int inv)
{
	for (int i = 0, j = 0; i < n; i++)
	{
		if (i > j) swap(a[i], a[j]);
		for (int k = n >> 1; (j ^= k) < k; k >>= 1);
	}
	for (int i = 2; i <= n; i <<= 1)
	{
		int m = i >> 1, wn = power(G, (P - 1) + inv * (P - 1) / i);
		for (int *p = a; p < a + n; p += i)
			for (int j = 0, w = 1; j < m; j++, w = 1ll * w * wn % P)
			{
				int t = 1ll * p[j + m] * w % P;
				p[j + m] = (p[j] - t) % P;
				p[j] = (p[j] + t) % P;
			}
	}
	if (inv == -1)
		for (int i = 0, t = power(n, P - 2); i < n; i++) a[i] = 1ll * a[i] * t % P;
}
poly operator+(const poly &a, const poly &b)
{
	poly ans(max(a.size(), b.size()));
	for (int i = 0; i < ans.size(); i++)
	{
		if (i < a.size()) ans[i] = a[i];
		if (i < b.size()) ans[i] = (ans[i] + b[i]) % P;
	}
	return ans;
}
poly operator*(const poly &a, const poly &b)
{
	static int ta[maxn << 2], tb[maxn << 2];
	copy(a.begin(), a.end(), ta);
	copy(b.begin(), b.end(), tb);
	int l = 1;
	for (; l < a.size() + b.size() - 1; l <<= 1);
	fft(ta, l, 1), fft(tb, l, 1);
	for (int i = 0; i < l; i++) ta[i] = 1ll * ta[i] * tb[i] % P;
	fft(ta, l, -1);
	poly ans(ta, ta + a.size() + b.size() - 1);
	for (int i = 0; i < l; i++) ta[i] = tb[i] = 0;
	return ans;
}

poly inverse(const poly &a, int n)
{
	if (n == 1) return {power(a[0], P - 2)};
	poly b = inverse(a, n >> 1);
	static int ta[maxn << 2], tb[maxn << 2];
	for (int i = 0; i < n; i++)
	{
		if (i < a.size()) ta[i] = a[i];
		if (i < n >> 1) tb[i] = b[i];
	}
	fft(ta, n << 1, 1), fft(tb, n << 1, 1);
	for (int i = 0; i < n << 1; i++)
		ta[i] = (2 * tb[i] - 1ll * ta[i] * tb[i] % P * tb[i]) % P;
	fft(ta, n << 1, -1);
	poly ans(ta, ta + n);
	for (int i = 0; i < n << 1; i++) ta[i] = tb[i] = 0;
	return ans;
}
poly sqrt(const poly &a, int n)
{
	if (n == 1) return {1};
	poly b = sqrt(a, n >> 1);
	poly ta(a.begin(), a.begin() + n);
	poly ans = b + ta * inverse(b, n);
	while (ans.size() > n) ans.pop_back();
	for (int i = 0; i < n; i++) ans[i] = 1ll * ans[i] * inv2 % P;
	return ans;
}

int main()
{
	int n, m, k = 0;
	static bool inc[maxn];
	scanf("%d%d", &n, &m);
	for (int i = 0, x; i < n; i++)
		scanf("%d", &x), inc[x] = true, k = max(k, x);
	int l = 1;
	for (; l <= m || l <= k; l <<= 1);
	poly c(l);
	for (int i = 1; i <= k; i++)
		if (inc[i]) c[i] = -4;
	c[0] = 1;
	c = sqrt(c, l);
	c[0]++;
	c = inverse(c, l);
	for (int i = 1; i <= m; i++)
	{
		int ans = c[i] * 2ll % P;
		printf("%d\n", (ans + P) % P);
	}
	return 0;
}