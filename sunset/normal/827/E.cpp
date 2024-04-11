#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair < int, int > pii;

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

const int MAXN = 1048580;
const int MAXM = 25;

namespace FFT
{
	const double pi = acos(-1);

	struct E
	{
		double x, y;
		E() {}
		E(double _x, double _y = 0) { x = _x; y = _y; }
		E operator + (const E &b) const { return E(x + b.x, y + b.y); }
		E operator - (const E &b) const { return E(x - b.x, y - b.y); }
		E operator * (const E &b) const { return E(x * b.x - y * b.y, x * b.y + y * b.x); }
		E operator / (const double &b) const { return E(x / b, y / b); }
	}wn[MAXM], x[MAXN], y[MAXN];

	int R[MAXN], L, n;

	inline void Ini(int len)
	{
		for (n = 1, L = 0; n < len; n <<= 1, L ++);
		for (int i = 1; i < n; i ++)
			R[i] = (R[i >> 1] >> 1) | ((i & 1) << L - 1);
		wn[0] = E(cos(pi / (1 << L - 1)), sin(pi / (1 << L - 1)));
		for (int i = 1; i < L; i ++)
			wn[i] = wn[i - 1] * wn[i - 1];
	}

	inline void Ini_Inv()
	{
		wn[0] = E(cos(pi / (1 << L - 1)), -sin(pi / (1 << L - 1)));
		for (int i = 1; i < L; i ++)
			wn[i] = wn[i - 1] * wn[i - 1];
	}

	inline void FFT(E *x)
	{
		for (int i = 0; i < n; i ++)
			if (i < R[i])
				swap(x[i], x[R[i]]);
		for (int i = 1, l = L - 1; i < n; i <<= 1, l --)
			for (int j = 0; j < n; j += i << 1)
			{
				E w(1, 0);
				for (int k = 0; k < i; k ++, w = w * wn[l])
				{
					E u = x[j + k], v = w * x[j + k + i];
					x[j + k] = u + v, x[j + k + i] = u - v;	
				}
			}
	}

	inline void Cpy(int *x, int n, E *y, int m)
	{
		for (int i = 0; i < n; i ++)
			y[i] = E(x[i], 0);
		for (int i = n; i < m; i ++)
			y[i] = E(0, 0);
	}

	inline void Mul(int *a, int n, int *b, int m, int *ret)
	{
		Ini(n + m - 1);
		Cpy(a, n, x, FFT::n); Cpy(b, m, y, FFT::n);
		FFT(x); FFT(y);
		for (int i = 0; i < FFT::n; i ++)
			x[i] = x[i] * y[i];
		Ini_Inv();
		FFT(x);
		for (int i = 0; i < FFT::n; i ++)
			ret[i] = (x[i] / n).x + 0.5;
	}
}

using namespace FFT;
int m, a[MAXN], b[MAXN], c[MAXN];
char s[MAXN];
vector < int > ans;

inline void Sol()
{
	m = Read(); ans.clear();
	scanf("%s", s);
	for (int i = 0; i < m; i ++)
		a[i] = s[i] == 'V', b[i] = s[m - i - 1] == 'K', c[i + 1] = 1;
	Mul(a, m, b, m, a);
	for (int i = 0; i < n; i ++)
		if (a[i] && abs(i - m + 1) <= m)
			c[abs(i - m + 1)] = 0;
	for (int i = 1; i <= m; i ++)
	{
		for (int j = i; j <= m; j += i)
			c[i] &= c[j];
		if (c[i])
			ans.pb(i);
	}
	printf("%d\n", ans.size());
	for (auto x : ans)
		printf("%d ", x);
	putchar(10);
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	for (int T = Read(); T; T --)
		Sol();
	return 0;
}