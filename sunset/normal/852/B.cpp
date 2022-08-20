#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

inline int Read()
{
	int x = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

const int MAXN = 105;
const int MAXM = 1000005;
const int mod = 1e9 + 7;

int n, l, m, f[MAXN], p[MAXM], q[MAXM], ans;

struct Matrix
{
	int a[MAXN][MAXN];

	Matrix()
	{
		mset(a, 0);
	}

	inline void Init()
	{
		for (int i = 0; i < m; i ++)
			a[i][i] = 1;
	}

	Matrix operator * (const Matrix &b) const
	{
		Matrix c;
		for (int k = 0; k < m; k ++)
			for (int i = 0; i < m; i ++)
				for (int j = 0; j < m; j ++)
					c.a[i][j] = (1LL * a[i][k] * b.a[k][j] + c.a[i][j]) % mod;
		return c;
	}

	Matrix operator ^ (int y) const
	{
		Matrix r, x = *this;
		for (r.Init(); y; y >>= 1, x = x * x)
			if (y & 1)
				r = r * x;
		return r;
	}
} a, b;

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), l = Read(), m = Read();
	for (int i = 1; i <= n; i ++)
		f[Read() % m] ++;
	for (int i = 0; i < m; i ++)
		for (int j = 0; j < m; j ++)
			a.a[i][(i + j) % m] = f[j];
	mset(f, 0);
	for (int i = 1; i <= n; i ++)
		f[p[i] = Read() % m] ++;
	for (int i = 0; i < m; i ++)
		for (int j = 0; j < m; j ++)
			b.a[i][(i + j) % m] = f[j];
	for (int i = 1; i <= n; i ++)
		q[i] = Read() % m;
	a = a * (b ^ (l - 2));
	for (int i = 1; i <= n; i ++)
		ans = (ans + a.a[0][(m - (p[i] + q[i]) % m) % m]) % mod;
	return printf("%d\n", ans), 0;
}