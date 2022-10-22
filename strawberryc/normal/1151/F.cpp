#include <bits/stdc++.h>

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

const int N = 105, ZZQ = 1e9 + 7;

int n, k, a[N], cnt, c0, c1, st, I;

int qpow(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = 1ll * res * a % ZZQ;
		a = 1ll * a * a % ZZQ;
		b >>= 1;
	}
	return res;
}

struct matrix
{
	int n, m, a[N][N];
	
	matrix() {}
	matrix(int _n, int _m) :
		n(_n), m(_m) {memset(a, 0, sizeof(a));}
	
	friend inline matrix operator * (matrix a, matrix b)
	{
		matrix res = matrix(a.n, b.m);
		for (int i = 1; i <= res.n; i++)
			for (int j = 1; j <= res.m; j++)
				for (int k = 1; k <= a.m; k++)
					res.a[i][j] = (1ll * a.a[i][k] * b.a[k][j] + res.a[i][j]) % ZZQ;
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
} A, St;

int main()
{
	n = read(); k = read();
	for (int i = 1; i <= n; i++) a[i] = read(), cnt += !a[i];
	I = qpow(n * (n - 1) >> 1, ZZQ - 2);
	c0 = cnt; c1 = n - cnt;
	if (n - cnt < cnt) cnt = n - cnt;
	A = matrix(cnt + 1, cnt + 1); St = matrix(cnt + 1, 1);
	for (int i = 1; i <= c0; i++) if (a[i]) st++;
	St.a[st + 1][1] = 1;
	for (int i = 0; i <= cnt; i++)
	{
		int cur = n * (n - 1) >> 1;
		if (i) A.a[i][i + 1] = 1ll * i * i * I % ZZQ, cur -= i * i;
		if (i < cnt) A.a[i + 2][i + 1] = 1ll * (c0 - i) * (c1 - i) * I % ZZQ,
			cur -= (c0 - i) * (c1 - i);
		A.a[i + 1][i + 1] = 1ll * cur * I % ZZQ;
	}
	std::cout << ((A ^ k) * St).a[1][1] << std::endl;
	return 0;
}
//