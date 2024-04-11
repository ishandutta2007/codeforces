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
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

typedef long long ll;

int n, m, X1, Y1, X2, Y2, X3, Y3, X4, Y4;
ll w, b;

ll rects(int xl, int yl, int xr, int yr)
{
	if (!(1ll * (xr - xl + 1) * (yr - yl + 1) & 1))
		return 1ll * (xr - xl + 1) * (yr - yl + 1) >> 1;
	if (xl + yl & 1) return 1ll * (xr - xl + 1) * (yr - yl + 1) >> 1;
	return (1ll * (xr - xl + 1) * (yr - yl + 1) >> 1) + 1;
}

ll stcer(int xl, int yl, int xr, int yr)
{
	return 1ll * (xr - xl + 1) * (yr - yl + 1) - rects(xl, yl, xr, yr);
}

void work()
{
	n = read(); m = read();
	X1 = read(); Y1 = read(); X2 = read(); Y2 = read();
	X3 = read(); Y3 = read(); X4 = read(); Y4 = read();
	if (1ll * n * m & 1) w = (1ll * n * m >> 1) + 1, b = w - 1;
	else w = b = 1ll * n * m >> 1;
	w -= rects(X1, Y1, X2, Y2) + rects(X3, Y3, X4, Y4);
	b -= stcer(X1, Y1, X2, Y2) + stcer(X3, Y3, X4, Y4);
	w += 1ll * (X2 - X1 + 1) * (Y2 - Y1 + 1);
	b += 1ll * (X4 - X3 + 1) * (Y4 - Y3 + 1);
	if (Max(X1, X3) <= Min(X2, X4) && Max(Y1, Y3) <= Min(Y2, Y4))
	{
		w += rects(Max(X1, X3), Max(Y1, Y3), Min(X2, X4), Min(Y2, Y4));
		b += stcer(Max(X1, X3), Max(Y1, Y3), Min(X2, X4), Min(Y2, Y4));
		w -= 1ll * (Min(X2, X4) - Max(X1, X3) + 1)
			* (Min(Y2, Y4) - Max(Y1, Y3) + 1);
	}
	std::cout << w << " " << b << std::endl;
}

int main()
{
	int T = read();
	while (T--) work();
	return 0;
}