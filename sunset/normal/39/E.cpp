#include <cstdio>
#define lld "%lld"
typedef long long lnt;
int T, m, k;
lnt n, c;
inline lnt pow(lnt a, int k)
{
	register lnt w = 1;
	while (k-- && w < c) w *= a;
	return w;
}
inline int cal(lnt n, int m)
{
	bool v[2] = {false, false};
	while (pow(n + 1, m + 1) < c) ++n, ++m;
	if (pow(n, m + 1) < c)
	{
		register int k = m + 1;
		for (register lnt x = pow(n, m + 2); x < c; x *= n, ++k);
		v[((k - m) & 1) ^ 1] = true;
	}
	if (pow(n + 1, m) < c)
	{
		register lnt l = n + 1, r = c - 1, w, x;
		while (l <= r)
			pow(w = (l + r) >> 1, m) < c ? l = (x = w) + 1 : r = w - 1;
		v[((x - n) & 1) ^ 1] = true;
	}
	register int g = 0;
	while (g < 2 && v[g]) ++g;
	return g;
}
int main()
{
	T = 1;
	while (T--)
	{
		scanf(lld "%d" lld, &n, &m, &c);
		if (n > 1) puts(cal(n, m) ? "Masha" : "Stas");
		else
		{
			for (n = 1LL << m, k = 1; n < c && cal(2, m); n <<= 1, k ^= 1, ++m);
			puts(n >= c ? "Missing" : k ? "Masha" : "Stas");
		}
	}
	return 0;
}