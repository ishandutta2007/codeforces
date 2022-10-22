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

const int N = 4e5 + 5;

int n, a[N], m, tmp[N], cnt[N], ans, w, h;
std::vector<int> res[N];

struct xzz
{
	int num, c;
} o[N];

inline bool comp(xzz a, xzz b)
{
	return a.c < b.c;
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]), tmp[i] = a[i];
	std::sort(tmp + 1, tmp + n + 1);
	m = std::unique(tmp + 1, tmp + n + 1) - tmp - 1;
	for (int i = 1; i <= n; i++)
		cnt[a[i] = std::lower_bound(tmp + 1, tmp + m + 1, a[i]) - tmp]++;
	for (int i = 1; i <= m; i++) o[i] = (xzz) {i, cnt[i]};
	std::sort(o + 1, o + m + 1, comp);
	int tt = 1, lw = 0;
	for (int i = 1; i <= n; i++)
	{
		while (tt <= m && o[tt].c <= i) lw += o[tt++].c;
		int siz = (lw + (m - tt + 1) * i) / i;
		if (i * siz > ans && i <= siz) ans = i * siz, w = i, h = siz;
	}
	std::cout << ans << std::endl << w << " " << h << std::endl;
	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++) res[i].push_back(0);
	int x = 0, y = 0;
	for (int i = m; i >= 1; i--)
	{
		bool is = 0;
		for (int j = 1; j <= w && j <= o[i].c; j++)
		{
			res[x][y] = tmp[o[i].num];
			x = (x + 1) % w; y = x ? (y + 1) % h : (y - w + 2 + h) % h;
			if (!x && !y) {is = 1; break;}
		}
		if (is) break;
	}
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++) printf("%d ", res[i][j]);
		puts("");
	}
	return 0;
}