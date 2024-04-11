#include <iostream>
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

#ifndef _LOCAL
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
const int INF = 0x3f3f3f3f;

#define maxn 1005

int n, m;
ll all[maxn][maxn], odd[maxn][maxn];
ll hor[maxn][maxn], ver[maxn][maxn];
ll all_sum;

ll get_hor(const int x, const int y)
{
	if (x < 0 || y < 0)
	{
		return 0;
	}
	ll res = 0;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
	{
		for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
		{
			res ^= hor[i][j];
		}
	}
	return res;
}

ll get_ver(const int x, const int y)
{
	if (x < 0 || y < 0)
	{
		return 0;
	}
	ll res = 0;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
	{
		for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
		{
			res ^= ver[i][j];
		}
	}
	return res;
}

ll get_all(const int x, const int y)
{
	if (x < 0 || y < 0)
	{
		return 0;
	}
	ll res = 0;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
	{
		for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
		{
			res ^= all[i][j];
		}
	}
	return res;
}

ll get_odd(const int x, const int y)
{
	if (x < 0 || y < 0)
	{
		return 0;
	}
	ll res = 0;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
	{
		for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
		{
			res ^= odd[i][j];
		}
	}
	return res;
}

ll get_rec(const int l, const int r)
{
	if (l < 0 || r < 0)
	{
		return 0;
	}
	ll res = get_odd(l, r);
	int cl = l + 1, cr = r + 1;
	if (cl & cr & 1)
	{
		res ^= all_sum ^ get_all(l, n - 1) ^ get_all(n - 1, r) ^ get_all(l, r);
	}
	if (cr & 1)
	{
		res ^= get_hor(l, n - 1) ^ get_hor(l, r);
	}
	if (cl & 1)
	{
		res ^= get_ver(n - 1, r) ^ get_ver(l, r);
	}
#ifdef _DEBUG
	//fprintf(stderr, "ans(%d, %d) = " LLD "\n", l, r, res);
#endif
	return res;
}

inline ll get_ans(const int l, const int t, const int r, const int b)
{
#ifdef _DEBUG
	//fprintf(stderr, "get_ans[%d, %d] -> [%d, %d]\n", l, t, r, b);
#endif
	return (get_rec(r, b) ^ get_rec(l - 1, b) ^ get_rec(r, t - 1) ^ get_rec(l - 1, t - 1));
}

void upd_rec(const int x, const int y, const ll v)
{
	if (x < 0 || y < 0)
	{
		return;
	}
#ifdef _DEBUG
	fprintf(stderr, "upd %d %d " LLD "\n", x, y, v);
#endif
	all_sum ^= v;
	for (int i = x; i < n; i = (i | (i + 1)))
	{
		for (int j = y; j < n; j = (j | (j + 1)))
		{
			all[i][j] ^= v;
		}
	}
	if ((x + 1) & (y + 1) & 1)
	{
		for (int i = x; i < n; i = (i | (i + 1)))
		{
			for (int j = y; j < n; j = (j | (j + 1)))
			{
				odd[i][j] ^= v;
			}
		}
	}
	if ((x + 1) & 1)
	{
		for (int i = x; i < n; i = (i | (i + 1)))
		{
			for (int j = y; j < n; j = (j | (j + 1)))
			{
				hor[i][j] ^= v;
			}
		}
	}
	if ((y + 1) & 1)
	{
		for (int i = x; i < n; i = (i | (i + 1)))
		{
			for (int j = y; j < n; j = (j | (j + 1)))
			{
				ver[i][j] ^= v;
			}
		}
	}
}

inline void upd(const int l, const int t, const int r, const int b, const int v)
{
	upd_rec(l - 1, t - 1, v);
	upd_rec(l - 1, b, v);
	upd_rec(r, t - 1, v);
	upd_rec(r, b, v);
}

#ifdef _DEBUG
bool
#else
void
#endif
input_data()
{
#ifndef _DEBUG
	scanf("%d%d", &n, &m);
#else
	if (scanf("%d%d", &n, &m) != 2)
	{
		return false;
	}
#endif
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			all[i][j] = odd[i][j] = hor[i][j] = ver[i][j] = 0LL;
		}
	}
	all_sum = 0LL;
	for (int i = 0; i < m; ++i)
	{
		int t, x0, y0, x1, y1;
		ll v;
		scanf("%d%d%d%d%d", &t, &x0, &y0, &x1, &y1);
		if (t == 2)
		{
			scanf(LLD, &v);
			upd(x0 - 1, y0 - 1, x1 - 1, y1 - 1, v);
		}
		else
		{
			printf(LLD "\n", get_ans(x0 - 1, y0 - 1, x1 - 1, y1 - 1));
		}
#ifdef _DEBUG
		for (int it = 0; it < n; ++it)
		{
			for (int it1 = 0; it1 < n; ++it1)
			{
				fprintf(stderr, LLD " ", get_ans(it, it1, it, it1));
			}
			fprintf(stderr, "\n");
		}
		fprintf(stderr, "\n");
#endif
	}
#ifdef _DEBUG
	return true;
#endif
}

int main()
{
#ifdef _DEBUG
	while (input_data()) {
#else
	input_data();
#endif

#ifdef _DEBUG
	}
#endif
	return 0;
}