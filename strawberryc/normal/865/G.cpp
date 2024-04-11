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

typedef long long ll;

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

const int E = 12, N = 255, M = N << 1, rqy = 1e9 + 7;

int F, B, p[E], mc, cnt[N], poly[M], tmp[M], pmt[M], ax[M], f[M];
ll n;

void getmod(int len, int *a)
{
	for (int i = len; i >= mc; i--)
	{
		int x = a[i]; a[i] = 0;
		for (int j = 1; j <= mc; j++)
			a[i - j] = (1ll * x * cnt[j] % rqy + a[i - j]) % rqy;
	}
}

int main()
{
	int x;
	read(F); read(B); read(n);
	for (int i = 1; i <= F; i++) read(p[i]);
	for (int i = 1; i <= B; i++) read(x), mc = Max(mc, x), cnt[x]++;
	for (int T = 1; T <= F; T++)
	{
		memset(tmp, 0, sizeof(tmp)); memset(pmt, 0, sizeof(pmt));
		tmp[0] = pmt[1] = 1;
		if (mc == 1) pmt[pmt[1] = 0] = cnt[1];
		while (p[T])
		{
			if (p[T] & 1)
			{
				memset(ax, 0, sizeof(ax));
				for (int i = 0; i < mc; i++)
					for (int j = 0; j < mc; j++)
						ax[i + j] = (1ll * tmp[i] * pmt[j] + ax[i + j]) % rqy;
				getmod(mc - 1 << 1, ax);
				for (int i = 0; i < mc; i++) tmp[i] = ax[i];
			}
			memset(ax, 0, sizeof(ax));
			for (int i = 0; i < mc; i++)
				for (int j = 0; j < mc; j++)
					ax[i + j] = (1ll * pmt[i] * pmt[j] + ax[i + j]) % rqy;
			getmod(mc - 1 << 1, ax);
			for (int i = 0; i < mc; i++) pmt[i] = ax[i];
			p[T] >>= 1;
		}
		for (int i = 0; i < mc; i++) poly[i] = (poly[i] + tmp[i]) % rqy;
	}
	f[0] = 1;
	while (n)
	{
		if (n & 1)
		{
			memset(ax, 0, sizeof(ax));
			for (int i = 0; i < mc; i++)
				for (int j = 0; j < mc; j++)
					ax[i + j] = (1ll * f[i] * poly[j] + ax[i + j]) % rqy;
			getmod(mc - 1 << 1, ax);
			for (int i = 0; i < mc; i++) f[i] = ax[i];
		}
		memset(ax, 0, sizeof(ax));
		for (int i = 0; i < mc; i++)
			for (int j = 0; j < mc; j++)
				ax[i + j] = (1ll * poly[i] * poly[j] + ax[i + j]) % rqy;
		getmod(mc - 1 << 1, ax);
		for (int i = 0; i < mc; i++) poly[i] = ax[i];
		n >>= 1;
	}
	for (int i = mc - 1; i >= 1; i--)
		for (int j = 1; j <= i; j++)
			f[i - j] = (1ll * f[i] * cnt[j] + f[i - j]) % rqy;
	return std::cout << f[0] << std::endl, 0;
}