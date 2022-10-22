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
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 1e5 + 5, INF = 0x3f3f3f3f;

int n, a[N], f[N], mark, minf;

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) f[i] = INF;
	f[0] = minf = 1;
	for (int i = 2; i <= n; i++)
	{
		mark += a[i] != a[i - 1];
		f[a[i - 1]] = Min(f[a[i - 1]], Min(minf + 1, f[a[i]])
			- (a[i] != a[i - 1]));
		minf = Min(minf, f[a[i - 1]]);
	}
	return std::cout << minf + mark << std::endl, 0;
}