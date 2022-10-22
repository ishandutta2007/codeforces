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

const int N = 105;

int n, m, a[N][N], Cm, sm[N][N], f[N][N], ka[N][N];

bool judge(int S, int T)
{
	for (int i = 0; i < n; i++)
	{
		bool is = 1;
		for (int j = 0; j < n; j++)
			if (((S >> j) & 1) ^ ((T >> (j + i) % n) & 1))
				{is = 0; break;}
		if (is) return 1;
	}
	return 0;
}

void work()
{
	read(n); read(m); Cm = 1 << n;
	for (int i = 0; i < n; i++)
		for (int j = 1; j <= m; j++) read(a[i][j]);
	memset(sm, 0, sizeof(sm));
	memset(f, 0, sizeof(f)); memset(ka, 0, sizeof(ka));
	for (int i = 1; i <= m; i++)
	{
		for (int S = 0; S < Cm; S++)
			for (int j = 0; j < n; j++)
				if ((S >> j) & 1) sm[i][S] += a[j][i];
		for (int S = 0; S < Cm; S++)
			for (int T = 0; T < Cm; T++)
				if (judge(S, T)) ka[i][S] = Max(ka[i][S], sm[i][T]);
		for (int S = 0; S < Cm; S++)
			for (int T = S; ; T = (T - 1) & S)
			{
				f[i][S] = Max(f[i][S], f[i - 1][T] + ka[i][S ^ T]);
				if (!T) break;
			}
	}
	std::cout << f[m][Cm - 1] << std::endl;
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}