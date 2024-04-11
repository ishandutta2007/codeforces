#include <bits/stdc++.h>

typedef long long ll;

const int N = 205, M = N << 1, djq = 1e4 + 7;

int n, l, f[N][N][N], cnt[N][N], ans;
char s[N];

struct matrix
{
	int n, m, a[M][M];
	
	matrix() {}
	matrix(int _n, int _m) :
		n(_n), m(_m) {memset(a, 0, sizeof(a));}
	
	friend inline matrix operator * (matrix a, matrix b)
	{
		matrix res = matrix(a.n, b.m);
		for (int i = 1; i <= a.n; i++)
			for (int j = i; j <= b.m; j++)
			{
				ll tmp = 0;
				for (int k = i; k <= j; k++) tmp += a.a[i][k] * b.a[k][j];
				res.a[i][j] = tmp % djq;
			}
		return res;
	}
	
	friend inline matrix operator ^ (matrix a, int b)
	{
		matrix res = matrix(a.n, a.m);
		for (int i = 1; i <= res.n; i++) res.a[i][i] = 1;
		while (b)
		{
			if (b & 1) res = res * a;
			a = a * a;
			b >>= 1;
		}
		return res;
	}
} A;

int get_p(int i, int j)
{
	if (!i && !j) return A.a[A.n][A.n];
	if (!i) return A.a[n + 1][n + (n + 1 >> 1) + j];
	if (!j) return A.a[n - i + 1][A.n];
	return A.a[n - i + 1][n + (n + 1 >> 1) + j];
}

int main()
{
	scanf("%s%d", s + 1, &l); n = strlen(s + 1);
	f[0][0][0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; i + j < n; j++)
			if (s[i + 1] == s[n - j]) for (int k = 0; k <= (n + 1 >> 1); k++)
			{
				if ((f[i + 1][j + 1][k + 1] += f[i][j][k]) >= djq)
					f[i + 1][j + 1][k + 1] -= djq;
			}	
			else for (int k = 0; k <= (n + 1 >> 1); k++)
			{
				if ((f[i + 1][j][k] += f[i][j][k]) >= djq) f[i + 1][j][k] -= djq;
				if ((f[i][j + 1][k] += f[i][j][k]) >= djq) f[i][j + 1][k] -= djq;
			}
	for (int i = 0; i <= n; i++)
		for (int k = 0; k <= (n + 1 >> 1); k++)
		{
			if ((k << 1) <= n)
				cnt[n - (k << 1)][k] = (cnt[n - (k << 1)][k] + f[i][n - i][k]) % djq;
			cnt[n - (k << 1) + 1][k] = (cnt[n - (k << 1) + 1][k]
				+ f[i][n - i + 1][k]) % djq;
		}
	A = matrix(n + (n + 1 >> 1) * 2 + 1, n + (n + 1 >> 1) * 2 + 1);
	for (int i = 1; i <= n; i++) A.a[i][i] = 24, A.a[i][i + 1] = 1;
	for (int i = 1; i <= (n + 1 >> 1); i++) A.a[i + n][i + n] = 25,
		A.a[A.n - i][A.n - i] = 26, A.a[i + n][i + n + (n + 1 >> 1)] = 1;
	for (int i = n; i < n + (n + 1 >> 1); i++) A.a[i][i + 1] = 1;
	A.a[n][A.n] = 1; A.a[A.n][A.n] = 26;
	A = A ^ (n + l >> 1);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= (n + 1 >> 1); j++)
			ans = (1ll * cnt[i][j] * get_p(i, j) + ans) % djq;
	if (n + l & 1)
	{
		ans = 26ll * ans % djq;
		for (int i = 0; i < n; i++) for (int j = 0; j <= (n - 1 >> 1); j++)
			ans = (1ll * f[i][n - i - 1][j] * A.a[j + 1 << 1][n + j + 1] + ans) % djq;
	}
	return std::cout << ans << std::endl, 0;
}