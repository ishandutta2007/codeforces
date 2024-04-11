#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

const int C = 4100, N = 2005, E = 15;

int n, m, a[E][E], Cm, b[E][N], f[E][C], real[C], imag[C];

struct elem
{
	int id, mx;
} tm[N];

inline bool comp(elem a, elem b)
{
	return a.mx > b.mx;
}

void work()
{
	read(n); read(m); Cm = 1 << n;
	for (int i = 0; i < n; i++)
		for (int j = 1; j <= m; j++) read(b[i][j]);
	for (int i = 1; i <= m; i++)
	{
		tm[i].mx = 0; tm[i].id = i;
		for (int j = 0; j < n; j++) tm[i].mx = Max(tm[i].mx, b[j][i]);
	}
	std::sort(tm + 1, tm + m + 1, comp);
	if (m > n) m = n;
	for (int i = 1; i <= m; i++)
		for (int j = 0; j < n; j++) a[j][i] = b[j][tm[i].id];
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= m; i++)
	{
		for (int S = 0; S < Cm; S++)
		{
			real[S] = 0;
			for (int j = 0; j < n; j++)
				if ((S >> j) & 1) real[S] += a[j][i];
		}
		for (int S = 0; S < Cm; S++)
		{
			imag[S] = 0;
			for (int j = 0; j < n; j++)
				imag[S] = Max(imag[S], real[(S >> j) |
					((S & (1 << j) - 1) << n - j)]);
		}
		for (int S = 0; S < Cm; S++)
			for (int T = (Cm - 1 ^ S); ; T = (T - 1) & (Cm - 1 ^ S))
			{
				f[i][S | T] = Max(f[i][S | T], f[i - 1][S] + imag[T]);
				if (!T) break;
			}
	}
	printf("%d\n", f[m][Cm - 1]);
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}