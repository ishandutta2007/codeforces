#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - '0');
	return bo ? ~res + 1 : res;
}

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 5005;

int m, b[N], n, a[N], f[N][N];

int main()
{
	m = read();
	for (int i = 1; i <= m; i++) b[i] = read();
	for (int i = 1; i <= m; i++)
		if (i == 1 || b[i] != b[i - 1]) a[++n] = b[i];
	for (int l = n; l >= 1; l--)
		for (int r = l + 1; r <= n; r++)
			if (a[l] == a[r]) f[l][r] = f[l + 1][r - 1] + 1;
			else f[l][r] = Min(f[l + 1][r], f[l][r - 1]) + 1;
	std::cout << f[1][n] << std::endl;
	return 0;
}