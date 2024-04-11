#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

const int N = 1e5 + 5, M = 105, ZZQ = 998244353;

int n, k, len, a[N], f[N][M], sums[N], sum[N][M], lst[M];

int main()
{
	int i, j;
	n = read(); k = read(); len = read();
	For (i, 1, n) a[i] = read();
	if (len == 1) return puts("0"), 0;
	len--;
	f[0][0] = sums[0] = 1;
	For (i, 1, n)
	{
		int tmp;
		if (a[i] != -1)
		{
			tmp = Max(i - len - 1, lst[a[i]] - 1);
			f[i][a[i]] = ((sums[i - 1] - (tmp == -1 ? 0 :
				sums[tmp]) + ZZQ) % ZZQ - (sum[i - 1][a[i]] - (tmp == -1 ? 0 :
				sum[tmp][a[i]]) + ZZQ) % ZZQ + ZZQ) % ZZQ;
			For (j, 1, k) if (j != a[i]) lst[j] = i;
		}
		else For (j, 1, k)
		{
			tmp = Max(i - len - 1, lst[j] - 1);
			f[i][j] = ((sums[i - 1] - (tmp == -1 ? 0 : sums[tmp])
			+ ZZQ) % ZZQ - (sum[i - 1][j] - (tmp == -1 ? 0 : sum[tmp][j])
			+ ZZQ) % ZZQ + ZZQ) % ZZQ;
		}
		sums[i] = sums[i - 1];
		For (j, 0, k)
		{
			sums[i] = (sums[i] + f[i][j]) % ZZQ;
			sum[i][j] = (sum[i - 1][j] + f[i][j]) % ZZQ;
		}
	}
	std::cout << (sums[n] - sums[n - 1] + ZZQ) % ZZQ << std::endl;
	return 0;
}