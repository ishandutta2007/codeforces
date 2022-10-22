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

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

inline bool comp(const int &a, const int &b)
{
	return a > b;
}

const int N = 4e5 + 5;

int n, n00, n01, n10, n11, a00[N], a01[N], a10[N], a11[N], delta, tot, ans;

int main()
{
	int i, x, y;
	n = read();
	For (i, 1, n)
	{
		x = read(); y = read();
		if (!x) a00[++n00] = y;
		else if (x == 1) a01[++n01] = y;
		else if (x == 10) a10[++n10] = y;
		else a11[++n11] = y;
	}
	std::sort(a00 + 1, a00 + n00 + 1, comp);
	std::sort(a01 + 1, a01 + n01 + 1, comp);
	std::sort(a10 + 1, a10 + n10 + 1, comp);
	For (i, 1, n11) delta += a11[i], tot++;
	For (i, 2, n00) a00[i] += a00[i - 1];
	For (i, 2, n01) a01[i] += a01[i - 1];
	For (i, 2, n10) a10[i] += a10[i - 1];
	For (i, 0, n01)
	{
		if (tot + i < n10 || tot + n10 < i) continue;
		ans = Max(ans, a01[i] + a10[n10] +
			a00[Min(n00, Min(tot + i - n10, tot + n10 - i))]);
	}
	For (i, 0, n10)
	{
		if (tot + i < n01 || tot + n01 < i) continue;
		ans = Max(ans, a10[i] + a01[n01] +
			a00[Min(n00, Min(tot + i - n01, tot + n01 - i))]);
	}
	std::cout << ans + delta << std::endl;
	return 0;
}